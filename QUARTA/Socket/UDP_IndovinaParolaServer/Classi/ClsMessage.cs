using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UDP_IndovinaParolaServer.Classi
{
    public class ClsMessage
    {
        private string ip, port, messaggio;

        public string Ip { get => ip; set => ip = value; }
        public string Port { get => port; set => port = value; }
        public string Messaggio { get => messaggio; set => messaggio = value; }

        public ClsMessage()
        {
            this.ip = "";
            this.port = "";
            this.messaggio = ""; 
        }
        public ClsMessage(string ip = "", string port = "", string msg ="")
        {
            this.ip = ip;
            this.port = port;
            this.messaggio = msg; 
        }
        public ClsMessage(string csv, char separatore)
        {
            fromCsv(csv, separatore);
        }
        private void fromCsv(string csv, char separatore)
        {
            string[] spl = csv.Split(separatore);
            // 10.0.0.34;10634;Ciao!

            this.ip = spl[0];
            this.port = spl[1];
            this.messaggio = spl[2]; 
        }
        public string toCsv(char separatore = ';')
        {
            return ip + separatore + port + separatore + messaggio; 
        }
        public string[] toArray()
        {
            return new string[] { ip, port, messaggio }; 
        }

    }
}
