using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppCassa.Classi
{
    public class Tavolo
    {
        public int IdTavolo { get; set; }
        public int Numero { get; set; }
        public int Occupato { get; set; }

        public Tavolo(int idTavolo, int numero, int occupato)
        {
            IdTavolo = idTavolo;
            Numero = numero;
            Occupato = occupato;
        }

        public override string ToString()
        {
            string aus = "";

            if (Occupato == 0)
            {
                aus = "libero";
            }
            else
            {
                aus = "occupato";
            }

            return $"Tavolo {IdTavolo} con {Numero} posti e' {aus}";
        }
    }
}
