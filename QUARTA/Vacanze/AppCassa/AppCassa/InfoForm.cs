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
        ClsUDPServer clsServer;
        ClsMessagge clsMsg;
        ClasUDPClient clientCucina, clientMobile;

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
            clsServer = new ClsUDPServer((IPAddress)cmbIndirizziIp.SelectedItem, Convert.ToInt32(nudPorta.Value));
            clsServer.Avvia();

            clsMsg = new ClsMessagge();

            clientCucina = new ClasUDPClient(IPAddress.Parse(txtCucina.Text), Convert.ToInt32(nudCucina.Value));
            clientCucina.Invia(clsMsg);

            clientMobile = new ClasUDPClient(IPAddress.Parse(txtMobile.Text), Convert.ToInt32(nudMobile.Value));
            clientMobile.Invia(clsMsg);

            btnStart.Enabled = false;
            btnStop.Enabled = true;
        }
        private void btnStop_Click(object sender, EventArgs e)
        {
            clsServer.Chiudi();

            foreach (var item in Controls)
            {
                if (item is Button)
                {
                    (item as Button).Text = "";
                }
            }

            btnStart.Enabled = true;
            btnStart.Text = "START";
            btnStop.Enabled = false;
            btnStop.Text = "STOP";
        }
    }
}
