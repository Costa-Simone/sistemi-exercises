using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace UDP_IndovinaParolaServer.Classi
{
    public delegate void datiRicevutiEventHandler(ClsMessage messaggio); 
    public class ClsServerUDP
    {
        private const int MAX_BYTE = 1024; 
        private Socket socketID; // Socket principale del server
        private EndPoint endPointServer; // socket associato al nostro server
        private EndPoint endPointClient; // socket associato al client 
        private Thread threadAscolto;
        private volatile bool threadRun = true; // Per fermare il thread 

        public event datiRicevutiEventHandler datiRicevutiEvent; 
        public ClsServerUDP(IPAddress ip, int port)
        {
            socketID = new Socket(AddressFamily.InterNetwork, SocketType.Dgram,
                                                            ProtocolType.Udp);
            endPointServer = new IPEndPoint(ip, port);
            socketID.Bind(endPointServer);
        }
        public void avvia()
        {
            if (threadAscolto == null)
            {
                threadAscolto = new Thread(new ThreadStart(ricevi));
                threadAscolto.Start();
                while (!threadAscolto.IsAlive) ;
            }
        }
        private void ricevi()
        { // Eseguito dal thread 
            ClsMessage clsMes;
            byte[] bufferRx;
            int nBytesRicevuti;
            string msgRx; 

            bufferRx = new byte[MAX_BYTE];
            endPointClient = new IPEndPoint(IPAddress.Parse("127.0.0.1"), 5555);

            while(threadRun)
            {
                bufferRx = new byte[MAX_BYTE];
                try
                {
                    nBytesRicevuti = socketID.ReceiveFrom(bufferRx, 
                                                    MAX_BYTE,
                                                    SocketFlags.None,
                                                    ref endPointClient);
                    msgRx = Encoding.ASCII.GetString(bufferRx);
                    clsMes = new ClsMessage(msgRx, ';');
                    clsMes.Ip = (endPointClient as IPEndPoint).Address.ToString();
                    clsMes.Port = (endPointClient as IPEndPoint).Port.ToString();

                    datiRicevutiEvent(clsMes); 
                }
                catch(SocketException err)
                {
                    if (err.ErrorCode != 10004)
                        System.Windows.Forms.MessageBox.Show(err.Message); 
                }
            }
        }
        public void chiudi()
        {
            threadRun = false;
            socketID.Close(); 
        }
    }
}
