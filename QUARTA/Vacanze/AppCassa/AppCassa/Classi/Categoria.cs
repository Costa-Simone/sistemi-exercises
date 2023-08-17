using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AppCassa.Classi
{
    public class Categoria
    {
        public int IdCategoria { get; set; }
        public string Descr { get; set; }

        public Categoria(int idCategoria, string descr)
        {
            IdCategoria = idCategoria;
            Descr = descr;
        }
    }
}
