using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Ex02_Socket_Tris.Classi
{
    public delegate void datiRicevutiEventHandler(ClsMessagge msg);

    public class ClsUDPServer
    {
        private const int MAX_BYTE = 1024;

        private Socket socketID;
        private EndPoint endPointServer;
        private EndPoint endPointClient;
        private Thread threadAscolto;

        public event datiRicevutiEventHandler datiRicevutiEvent;

        private volatile bool threadRun = true; // gestione avvio/stop del thread
        public string ip;

        public ClsUDPServer(IPAddress ip, int port)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);
            endPointServer = new IPEndPoint(ip, port);

            // bind
            socketID.Bind(endPointServer);
        }

        public void Avvia()
        {
            if (threadAscolto == null)
            {
                threadAscolto = new Thread(new ThreadStart(Ricevi));

                threadAscolto.Start();

                while (!threadAscolto.IsAlive) ;
            }
        }
        private void Ricevi()
        {
            ClsMessagge clsMsg;

            int nByteRicevuti;
            string msg;
            byte[] bufferRx;

            endPointClient = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 1024);

            while (threadRun)
            {
                bufferRx = new byte[MAX_BYTE];

                try
                {
                    nByteRicevuti = socketID.ReceiveFrom(bufferRx, MAX_BYTE, SocketFlags.None, ref endPointClient);
                    msg = Encoding.ASCII.GetString(bufferRx);
                    clsMsg = new ClsMessagge(msg, ';');

                    clsMsg.Ip = (endPointClient as IPEndPoint).Address.ToString();
                    clsMsg.Port = (endPointClient as IPEndPoint).Port.ToString();

                    datiRicevutiEvent(clsMsg);
                }
                catch (SocketException ex)
                {

                }
            }
        }
        public void Chiudi()
        {
            threadRun = false;

            socketID.Close();
        }
    }
}
