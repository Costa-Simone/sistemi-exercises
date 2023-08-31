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
        public string IdPiatti { get; set; }
        public int IdUtente { get; set; }

        public Ordine(int idOrdine, int idTavolo, string idPiatti, int idUtente)
        {
            IdOrdine = idOrdine;
            IdTavolo = idTavolo;
            IdPiatti = idPiatti;
            IdUtente = idUtente;
        }

        public override string ToString()
        {
            Form1.dbTools.CaricaPiatti();
            string[] aus = IdPiatti.Split(',');
            string piatti = "";

            for (int i = 0; i < aus.Length - 1; i++)
            {
                foreach (var piatto in Form1.dbTools.listaPiatti)
                {
                    if (piatto.IdPiatto == Convert.ToInt32(aus[i]))
                    {
                        piatti += piatto.Descr + ", ";
                    }
                }
            }

            piatti = piatti.Substring(0, piatti.Length - 2);

            return $"{piatti} ordinato dal tavolo {IdTavolo}";
        }
    }
}
