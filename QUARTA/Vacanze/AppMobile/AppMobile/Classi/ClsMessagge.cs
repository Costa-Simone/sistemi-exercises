using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ex02_Socket_Tris.Classi
{
    public class ClsMessagge
    {
        private string ip, port, messaggio;

        public string Ip { get => ip; set => ip = value; }
        public string Port { get => port; set => port = value; }
        public string Reparto { get; set; }
        public string Categoria { get; set; }
        public string Messaggio { get => messaggio; set => messaggio = value; }

        public ClsMessagge(string _ip = "", string _port = "", string _reparto = "", string _categoria = "", string _msg = "")
        {
            this.Ip = _ip;
            this.Port = _port;
            Reparto = _reparto;
            Categoria = _categoria;
            this.Messaggio = _msg;
        }
        public ClsMessagge(string csv, char separatore) // ip;port;messaggio
        {
            this.Ip = csv.Split(separatore)[0];
            this.Port = csv.Split(separatore)[1];
            Reparto = csv.Split(separatore)[2];
            Categoria = csv.Split(separatore)[3];
            this.Messaggio = csv.Split(separatore)[4];
        }

        public string ToCsv(char separatore)
        {
            return $"{ip}{separatore}{port}{separatore}{Reparto}{separatore}{Categoria}{separatore}{Messaggio}";
        }
        public string[] ToArray()
        {
            return new string[] { this.Ip, this.Port, this.Messaggio };
        }
    }
}
