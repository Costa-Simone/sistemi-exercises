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
        ClsMessagge clsMsg;
        ClasUDPClient client;

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

            clsMsg = new ClsMessagge();
            clsMsg.Messaggio = txtNomeLocale.Text;

            client = new ClasUDPClient(IPAddress.Parse(txtIndirizzoAvversario.Text), Convert.ToInt32(nudPortaAvversario.Value));
            client.Invia(clsMsg);

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
            Button btn = (Button)sender;

            int i, j;

            i = Convert.ToInt32(btn.Name.Substring(3, 1));
            j = Convert.ToInt32(btn.Name.Substring(4));

            clsMsg = new ClsMessagge();
            clsMsg.Messaggio = i.ToString() + j.ToString();

            client = new ClasUDPClient(IPAddress.Parse(txtIndirizzoAvversario.Text), Convert.ToInt32(nudPortaAvversario.Value));
            client.Invia(clsMsg);

            btn.Text = "X";
            btn.ForeColor = Color.Blue;
        }

        private void StampaPosizioneRicevuta(ClsMessagge infoAvv)
        {
            BeginInvoke((MethodInvoker)delegate ()
            {
                int i, j;

                if (infoAvv.Messaggio.Length > 2)
                {
                    txtNomeAvversario.Text = infoAvv.Messaggio;
                }
                else
                {
                    i = Convert.ToInt32(infoAvv.Messaggio.Substring(0, 1));
                    j = Convert.ToInt32(infoAvv.Messaggio.Substring(1, 1));

                    Controls["btn" + i.ToString() + j.ToString()].Text = "O";
                    Controls["btn" + i.ToString() + j.ToString()].ForeColor = Color.Red;
                }
            });
        }
    }
}
