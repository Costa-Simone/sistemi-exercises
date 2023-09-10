using Ex02_Socket_Tris.Classi;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppCucina.Classi
{
    public class Tools
    {
        public ClsUDPServer clsServer;
        public ClsMessagge clsMsg;
        public ClasUDPClient clientCucina, clientCassa;

        public Dictionary<int, string> dicOrdini = new Dictionary<int, string>();
    }
}
