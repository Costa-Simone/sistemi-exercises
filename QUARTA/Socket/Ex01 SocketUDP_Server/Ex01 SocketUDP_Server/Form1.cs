using Ex01_SocketUDP_Server.Classi;
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

namespace Ex01_SocketUDP_Server
{
    public partial class Form1 : Form
    {
        ClsUDPServer clsServer;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ClsAddress.CercaIP();

            cmbIP.DataSource = ClsAddress.ipList;

            dgv.ColumnCount = 3;
            dgv.Columns[0].HeaderText = "IP";
            dgv.Columns[1].HeaderText = "PORT";
            dgv.Columns[2].HeaderText = "MESSAGGIO";
        }
        private void btnStart_Click(object sender, EventArgs e)
        {
            clsServer = new ClsUDPServer((IPAddress)cmbIP.SelectedItem, Convert.ToInt32(nudPort.Value));
            clsServer.datiRicevutiEvent += StampaDatiRicevuti;

            clsServer.Avvia();

            btnStart.Enabled = false;
            btnStop.Enabled = true;
        }
        private void btnStop_Click(object sender, EventArgs e)
        {
            clsServer.Chiudi();

            btnStart.Enabled = true;
            btnStop.Enabled = false;
        }
        private void btnPulisci_Click(object sender, EventArgs e)
        {
            dgv.Rows.Clear();
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (btnStart.Enabled)
            {
                btnStop_Click(sender, e);
            }
        }

        private void StampaDatiRicevuti(ClsMessage msg)
        {
            BeginInvoke((MethodInvoker)delegate () 
            {
                dgv.Rows.Add(msg.ToArray());
            });
        }
    }
}
