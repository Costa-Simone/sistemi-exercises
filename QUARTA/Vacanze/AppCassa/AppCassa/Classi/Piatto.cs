using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppCassa.Classi
{
    public class Piatto
    {
        public int IdPiatto { get; set; }
        public int IdCategoria { get; set; }
        public string Descr { get; set; }
        public int Importo { get; set; }

        public Piatto(int idPiatto, int idCategoria, string descr, int importo)
        {
            IdPiatto = idPiatto;
            IdCategoria = idCategoria;
            Descr = descr;
            Importo = importo;
        }

        public override string ToString()
        {
            return $"{Descr} di importo {Importo} euro";
        }
    }
}
