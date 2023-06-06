using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace UDP_IndovinaParolaClient.Classi
{
    public class ClsAddress
    {
        public static List<IPAddress> ipList;
        static ClsAddress()
        {
            ipList = new List<IPAddress>();
        }
        public static void findIP()
        {
            IPHostEntry hostInfo = Dns.GetHostEntry(Dns.GetHostName());
            // Aggiungo staticamente LOCALHOST 
            ipList.Add(IPAddress.Parse("127.0.0.1"));

            foreach (IPAddress ip in hostInfo.AddressList)
            {
                if (ip.AddressFamily ==
                        System.Net.Sockets.AddressFamily.InterNetwork)
                    ipList.Add(ip);
            }
        }
    }
}
