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
using UDP_IndovinaParolaServer.Classi;

namespace UDP_IndovinaParolaServer
{
    public partial class FrmMain : Form
    {
        ClsServerUDP clsServer;
        static Random rnd = new Random();
        static string[] wFacile = {"CASA", "SALA", "COSA", "POSA", "NOTA", "CARA", "FARO" };
        static string[] wMedia = {"AGRUME", "ALAMMO", "ASPIRO", "ASSIRO", "BIECHI", "BILICO", "ZELOTI"};
        static string[] wDifficile = { "ZAPPANDO", "ZUPPIERE", "VEGETATO", "URTATORI", "TRASMESSO", "SUPPORTI" };

        string[] vUsername; string[] vParole; 
        public FrmMain()
        {
            InitializeComponent();
            ClsAddress.findIP();
            cmbIP.DataSource = ClsAddress.ipList;
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            clsServer = new ClsServerUDP((IPAddress)cmbIP.SelectedItem,
                                       Convert.ToInt32(5555));
            // Attivo l'evento datiRicevuti 
            clsServer.datiRicevutiEvent += gestisciRichiesta;
            clsServer.avvia();

            vUsername = new string[0];
            vParole = new string[0]; 

            btnStart.Enabled = false;
            btnStop.Enabled = true;
        }
        private void btnStop_Click(object sender, EventArgs e)
        {
            clsServer.chiudi();
            btnStart.Enabled = true;
            btnStop.Enabled = false;
        }

        private void FrmMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!btnStart.Enabled)
                btnStop_Click(sender, e);
        }
        private void gestisciRichiesta(ClsMessage clientMsg)
        {
            ClsClientUDP clsInvia;
            ClsMessage clsMsg;
            string[] spl;
            
            string response;
            int pos, posvUsr; 
            // FORMATO MESSAGGIO 
            // 1: username - 0 - difficolta => 4, 6, 8
            // 2: username - 1 - parola
            clsInvia = new ClsClientUDP(IPAddress.Parse(clientMsg.Ip), 8888);
            clsMsg = new ClsMessage();

            // A) ANALIZZO MESSAGGIO IN INGRESSO 
            spl = clientMsg.Messaggio.Split('-');
    
            if (Convert.ToInt16(spl[1]) == 0)
            { /// Salvo Nome e Associo Parola generata casualemnte in base alla difficoltà 
                // Verifico presenza username => -1 se assente 
                posvUsr = ricercaUtente(spl[0]);
                if(posvUsr == -1) 
                { // Creo nuova cella array per inserimento 
                    Array.Resize(ref vUsername, vUsername.Length + 1);
                    Array.Resize(ref vParole, vParole.Length + 1);
                    posvUsr = vUsername.Length - 1;
                }
                
                vUsername[posvUsr] = spl[0];
                switch (Convert.ToInt16(spl[2]))
                { // Assegno parola casuale in base alla difficoltà scelta 
                    case 4:
                        vParole[posvUsr] = wFacile[rnd.Next(0, wFacile.Length)];
                        break;
                    case 6:
                        vParole[posvUsr] = wMedia[rnd.Next(0, wMedia.Length)];
                        break;
                    case 8:
                        vParole[posvUsr] = wDifficile[rnd.Next(0, wDifficile.Length)];
                        break;
                }

                clsMsg.Messaggio = "0-00000000";
                
            }
            else
            { // Controllo parola e restituisco risultato 
                pos = 0;
                response = "";
                while (vUsername[pos] != spl[0])
                    pos++;

                for(int i=0; i < vParole[pos].Length; i++)
                {
                    if (vParole[pos][i] == spl[2][i])
                        response += "1";
                    else
                        response += "0"; 
                }
                clsMsg.Messaggio = "1-" + response; 
            }
            stampaVettori();
            clsInvia.invia(clsMsg);
        }

        private int ricercaUtente(string username)
        {
            int i = 0;
            while (i < vUsername.Length && vUsername[i] != username)
                i++;
            if (i == vUsername.Length)
                i = -1;
            return i;
        }
        
        private void stampaVettori()
        {
            BeginInvoke((MethodInvoker)delegate ()
            {
                string dataTxt = "";
                for (int i = 0; i < vParole.Length; i++)
                    dataTxt += vUsername[i] + ": " + vParole[i] + "\n";
                txtLog.Text = dataTxt;
            });
        }
    }
}
