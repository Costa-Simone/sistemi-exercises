using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Http.Headers;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;

namespace UDP_IndovinaParolaClient.Classi
{
    public class ClsClientUDP
    {
        private Socket socketID;
        private EndPoint endPointServer; 
        public ClsClientUDP(IPAddress ipServer, int portaServer)
        {
            socketID = new Socket(AddressFamily.InterNetwork, 
                                SocketType.Dgram, 
                                ProtocolType.Udp);
            endPointServer = new IPEndPoint(ipServer, portaServer); 
        }
        public void invia(ClsMessage clsMsg)
        {
            string message = clsMsg.toCsv(';');
            byte[] bufferTx;

            bufferTx = Encoding.ASCII.GetBytes(message);

            socketID.SendTo(bufferTx, bufferTx.Length,
                                    SocketFlags.None, endPointServer);
        }
    }
}
