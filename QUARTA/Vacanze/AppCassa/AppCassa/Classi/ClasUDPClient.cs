using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace Ex02_Socket_Tris.Classi
{
    public class ClasUDPClient
    {
        private Socket socketID;
        private EndPoint endPointServer;

        public ClasUDPClient(IPAddress ipServer, int portServer)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            endPointServer = new IPEndPoint(ipServer, portServer);
        }

        public void Invia(ClsMessagge clsMsg)
        {
            string messaggio = clsMsg.ToCsv(';');
            byte[] bufferTx = Encoding.ASCII.GetBytes(messaggio);

            socketID.SendTo(bufferTx, bufferTx.Length, SocketFlags.None, endPointServer);
        }
    }
}
