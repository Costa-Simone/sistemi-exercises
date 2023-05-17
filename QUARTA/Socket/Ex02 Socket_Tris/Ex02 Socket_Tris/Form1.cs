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

namespace Ex02_Socket_Tris
{
    public partial class Form1 : Form
    {
        ClsUDPServer clsServer;

        public int turno = 0;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ClsAddress.CercaIP();

            cmbIndirizziIp.DataSource = ClsAddress.ipList;
        }
        private void btnStart_Click(object sender, EventArgs e)
        {
            clsServer = new ClsUDPServer((IPAddress)cmbIndirizziIp.SelectedItem, Convert.ToInt32(nudPorta.Value));
            clsServer.datiRicevutiEvent += StampaPosizioneRicevuta;
            clsServer.Avvia();

            if (cmbIndirizziIp.SelectedItem.ToString() == "192.168.1.50")
            {
                turno = 0;
                clsServer.ip = "10.211.55.5";
                txtIndirizzoAvversario.Text = "10.211.55.5";
            }
            else
            {
                turno = 1;
                txtIndirizzoAvversario.Text = "192.168.1.50";
                clsServer.ip = "192.168.1.50";
            }

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
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (btnStart.Enabled)
            {
                btnStop_Click(sender, e);
            }
        }
        private void btn_Click(object sender, EventArgs e)
        {
            if (turno == 1)
            {
                ClasUDPClient clsUDPClient = new ClasUDPClient(IPAddress.Parse(txtIndirizzoAvversario.Text), Convert.ToInt32(nudPortaAvversario.Value));
                ClsMessagge clsMessage = new ClsMessagge();

                clsMessage.Messaggio = (sender as Button).Name;

                clsUDPClient.Invia(clsMessage);

                (sender as Button).Text = "X";
                (sender as Button).Enabled = false;
                turno = 0;
            }
        }

        private void StampaPosizioneRicevuta(ClsMessagge msg)
        {
            BeginInvoke((MethodInvoker)delegate ()
            {
                foreach (var item in Controls)
                {
                    if (item is Button)
                    {
                        string[] messaggio = msg.ToArray();
                        if ((item as Button).Name == messaggio[2])
                        {
                            (item as Button).Text = "O";
                            (item as Button).Enabled = false;
                            turno = 1;
                        }
                    }
                }
            });
        }
    }
}
