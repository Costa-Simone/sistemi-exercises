using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppCassa.Classi
{
    public class Scontrino
    {
        public int IdScontrino { get; set; }
        public int IdOrdine { get; set; }
        public int Importo { get; set; }
        public DateTime DataEmissione { get; set; }

        public Scontrino(int idScontrino, int idOrdine, int importo, DateTime dataEmissione)
        {
            IdScontrino = idScontrino;
            IdOrdine = idOrdine;
            Importo = importo;
            DataEmissione = dataEmissione;
        }

        public override string ToString()
        {
            return $"Scontrino dell'ordine {IdOrdine} di {Importo} euro emesso in data {DataEmissione.ToLocalTime()}";
        }
    }
}
