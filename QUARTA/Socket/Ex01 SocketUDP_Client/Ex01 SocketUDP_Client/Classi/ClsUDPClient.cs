using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace Ex01_SocketUDP_Client.Classi
{
    public class ClsUDPClient
    {
        private Socket socketID;
        private EndPoint endPointServer;

        public ClsUDPClient(IPAddress ipServer, int portServer)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            endPointServer = new IPEndPoint(ipServer, portServer);
        }

        public void Invia(ClsMessage clsMsg)
        {
            string messaggio = clsMsg.ToCsv(';');
            byte[] bufferTx = Encoding.ASCII.GetBytes(messaggio);

            // invio pacchetto dati
            socketID.SendTo(bufferTx, bufferTx.Length, SocketFlags.None, endPointServer);
        }
    }
}
