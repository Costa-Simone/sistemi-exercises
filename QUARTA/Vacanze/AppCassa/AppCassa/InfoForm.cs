using Ex02_Socket_Tris.Classi;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppCassa
{
    public partial class InfoForm : Form
    {
        public InfoForm()
        {
            InitializeComponent();
        }

        private void Info_Load(object sender, EventArgs e)
        {
            ClsAddress.CercaIP();

            cmbIndirizziIp.DataSource = ClsAddress.ipList;
        }
        private void btnStart_Click(object sender, EventArgs e)
        {
            Form1.dbTools.clsServer = new ClsUDPServer((IPAddress)cmbIndirizziIp.SelectedItem, Convert.ToInt32(nudPorta.Value));
            Form1.dbTools.clsServer.Avvia();

            Form1.dbTools.clsServer.datiRicevutiEvent += GestisciRicezione;

            Form1.ip = cmbIndirizziIp.SelectedItem.ToString();
            Form1.port = nudPorta.Value.ToString();

            Form1.dbTools.clientCucina = new ClasUDPClient(IPAddress.Parse(txtCucina.Text), Convert.ToInt32(nudCucina.Value));
            Form1.dbTools.clientMobile = new ClasUDPClient(IPAddress.Parse(txtMobile.Text), Convert.ToInt32(nudMobile.Value));

            txtCucina.Enabled = false; txtMobile.Enabled = false;

            btnStart.Enabled = false;
            btnStop.Enabled = true;
        }
        private void btnStop_Click(object sender, EventArgs e)
        {
            Form1.dbTools.clsServer.Chiudi();

            foreach (var item in Controls)
            {
                if (item is Button)
                {
                    (item as Button).Text = "";
                }
            }

            txtCucina.Enabled = true; txtMobile.Enabled = true;

            btnStart.Enabled = true;
            btnStart.Text = "START";
            btnStop.Enabled = false;
            btnStop.Text = "STOP";
        }

        public void GestisciRicezione(ClsMessagge msg)
        {
            switch (msg.Reparto)
            {
                default:
                    break;

                case "1":
                    Form1.dbTools.CreaOrdine(msg.Categoria, msg.Messaggio);
                    break;
            }
        }
    }
}
