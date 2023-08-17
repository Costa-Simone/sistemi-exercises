using CarShopLibrary;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppCassa.Classi
{
    public class Ordine
    {
        public int IdOrdine { get; set; }
        public int IdTavolo { get; set; }
        public int IdPiatto { get; set; }
        public int IdUtente { get; set; }

        public Ordine(int idOrdine, int idTavolo, int idPiatto, int idUtente)
        {
            IdOrdine = idOrdine;
            IdTavolo = idTavolo;
            IdPiatto = idPiatto;
            IdUtente = idUtente;
        }

        public override string ToString()
        {
            string aus = "";

            Form1.dbTools.CaricaPiatti();

            foreach (var piatto in Form1.dbTools.listaPiatti)
            {
                if (piatto.IdPiatto == IdPiatto)
                {
                    aus = piatto.Descr;
                }
            }

            return $"{aus} ordinato dal tavolo {IdTavolo}";
        }
    }
}
