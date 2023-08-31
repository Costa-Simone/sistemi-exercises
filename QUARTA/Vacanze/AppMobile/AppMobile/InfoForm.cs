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

namespace AppMobile
{
    public partial class InfoForm : Form
    {
        public InfoForm()
        {
            InitializeComponent();

            ClsAddress.CercaIP();

            cmbIndirizziIp.DataSource = ClsAddress.ipList;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            Form1.tls.clsServer = new ClsUDPServer((IPAddress)cmbIndirizziIp.SelectedItem, Convert.ToInt32(nudPorta.Value));
            Form1.tls.clsServer.Avvia();
            Form1.tls.clsServer.datiRicevutiEvent += GestisciRicezione;

            Form1.ip = cmbIndirizziIp.SelectedItem.ToString();
            Form1.port = nudPorta.Value.ToString();

            Form1.tls.clientCucina = new ClasUDPClient(IPAddress.Parse(txtCucina.Text), Convert.ToInt32(nudCucina.Value));
            Form1.tls.clientCassa = new ClasUDPClient(IPAddress.Parse(txtCassa.Text), Convert.ToInt32(nudCassa.Value));

            txtCucina.Enabled = false; txtCassa.Enabled = false;

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

            txtCucina.Enabled = true; txtCassa.Enabled = true;

            btnStart.Enabled = true;
            btnStart.Text = "START";
            btnStop.Enabled = false;
            btnStop.Text = "STOP";
        }

        private void GestisciRicezione(ClsMessagge msg)
        {
            switch (msg.Reparto)
            {
                default:
                    break;

                case "0":
                    switch (msg.Categoria)
                    {
                        default:
                            break;

                        case "0":
                            int p = 0;
                            string[] piatti  = msg.Messaggio.Split(',');

                            Form1.tls.listaPiatti = new string[piatti.Length - 1];

                            for (int i = 0; i < piatti.Length - 1; i++)
                            {
                                Form1.tls.listaPiatti[i] = piatti[i].Trim();
                            }
                            break;

                        case "1":
                            int t = 0;

                            string[] tavoli = msg.Messaggio.Split(',');

                            Form1.tls.listaTavoli = new string[tavoli.Length - 1];

                            for (int i = 0; i < tavoli.Length - 1; i++)
                            {
                                Form1.tls.listaTavoli[i] = tavoli[i].Trim();
                                Form1.tls.dicOrdini[Convert.ToInt32(tavoli[i])] = new string[100];
                            }
                            break;
                    }
                    break;

                case "1":

                    break;
            }
        }
    }
}
