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
using UDP_IndovinaParolaClient.Classi;

namespace UDP_IndovinaParolaClient
{
    public partial class FrmMain : Form
    {
        ClsServerUDP clsServer;
        ClsClientUDP clsInvia;
        ClsMessage clsMsg;
        int diff; 

        public FrmMain()
        {
            InitializeComponent();
            ClsAddress.findIP();
            cmbIP.DataSource = ClsAddress.ipList;
            cmbIP.SelectedIndex = 1;
        }

        private void FrmMain_FormClosing(object sender, FormClosingEventArgs e)x
        {
            if (clsServer != null)
                clsServer.chiudi();
        }

        private void btnAvviaPartita_Click(object sender, EventArgs e)
        {
            if (txtUsername.Text != "")
            {
                clsServer = new ClsServerUDP((IPAddress)cmbIP.SelectedItem,
                                    8888);
                // Attivo l'evento datiRicevuti 
                clsServer.datiRicevutiEvent += gestisciRisposta;
                clsServer.avvia();

                if (rdb4.Checked)
                    diff = 4;
                else if (rdb6.Checked)
                    diff = 6;
                else diff = 8;

                txtParola.MaxLength = diff;


                clsInvia = new ClsClientUDP(IPAddress.Parse(txtServerIP.Text), 5555);
                clsMsg = new ClsMessage();
                clsMsg.Messaggio = txtUsername.Text + "-0-" + diff.ToString();
                
                clsInvia.invia(clsMsg);

                lblTentativi.Text = "";
                btnAvviaPartita.Enabled = false;
            }
            else
                MessageBox.Show("Inserire Username"); 
        }

        private void gestisciRisposta(ClsMessage rispostaServer)
        {
            BeginInvoke((MethodInvoker)delegate () {
                Console.WriteLine(rispostaServer.Ip + " " + rispostaServer.Port + " " + rispostaServer.Messaggio);
                // formato risposta: 0-00000000
                string[] spl = rispostaServer.Messaggio.Split('-');
                string result = txtParola.Text + ": "; 
                if (Convert.ToInt16(spl[0]) == 1)
                {
                    for(int i=0; i < diff; i++)
                    {
                        Console.WriteLine(spl[1][i].ToString().Length); 
                        if (spl[1][i] == '1')
                        {
                            result += "Sì ";
                            Console.WriteLine("Sì");
                        }
                        else
                        {
                            result += "No ";
                            Console.WriteLine("No");
                        }
                    }
                    lblTentativi.Text =  Environment.NewLine + result + lblTentativi.Text;
                }
            });
        }

        private void btnInvia_Click(object sender, EventArgs e)
        {
            if (txtParola.Text != "")
            {
                clsInvia = new ClsClientUDP(IPAddress.Parse(txtServerIP.Text), 5555);
                clsMsg = new ClsMessage();
                clsMsg.Messaggio = txtUsername.Text + "-1-" + txtParola.Text;

                clsInvia.invia(clsMsg);
            }
            else
                MessageBox.Show("Inserisci parola"); 
        }
    }
}
