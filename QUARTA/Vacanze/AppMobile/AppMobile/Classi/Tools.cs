using Ex02_Socket_Tris.Classi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppMobile.Classi
{
    public class Tools
    {
        public ClsUDPServer clsServer;
        public ClsMessagge clsMsg;
        public ClasUDPClient clientCucina, clientMobile;

        public string[] listaPiatti;
        public string[] listaTavoli;
        public Dictionary<int, string> dicOrdini = new Dictionary<int, string>();
    }
}
