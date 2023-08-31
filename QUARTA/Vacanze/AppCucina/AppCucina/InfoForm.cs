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

namespace AppCucina
{
    public partial class InfoForm : Form
    {
        public InfoForm()
        {
            InitializeComponent();
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            Form1.tls.clsServer = new ClsUDPServer((IPAddress)cmbIndirizziIp.SelectedItem, Convert.ToInt32(nudPorta.Value));
            Form1.tls.clsServer.Avvia();
            Form1.tls.clsServer.datiRicevutiEvent += GestisciRicezione;

            Form1.ip = cmbIndirizziIp.SelectedItem.ToString();
            Form1.port = nudPorta.Value.ToString();

            Form1.tls.clientCucina = new ClasUDPClient(IPAddress.Parse(txtCassa.Text), Convert.ToInt32(nudCassa.Value));

            txtCassa.Enabled = false;

            btnStart.Enabled = false;
            btnStop.Enabled = true;
        }
        private void btnStop_Click(object sender, EventArgs e)
        {
            Form1.tls.clsServer.Chiudi();

            foreach (var item in Controls)
            {
                if (item is Button)
                {
                    (item as Button).Text = "";
                }
            }

            txtCassa.Enabled = true;

            btnStart.Enabled = true;
            btnStart.Text = "START";
            btnStop.Enabled = false;
            btnStop.Text = "STOP";
        }

        private void GestisciRicezione(ClsMessagge msg)
        {
            throw new NotImplementedException();
        }
    }
}
