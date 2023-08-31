using AppCassa.Classi;
using CarShopLibrary;
using Ex02_Socket_Tris.Classi;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppCassa
{
    public partial class OrdiniForm : Form
    {
        public OrdiniForm()
        {
            InitializeComponent();
        }

        private void OrdiniForm_Load(object sender, EventArgs e)
        {
            Form1.dbTools.CaricaOrdini();
            lstbOrdini.DataSource = Form1.dbTools.listaOrdini;
        }
        private void btnScontrino_Click(object sender, EventArgs e)
        {
            Ordine o = (Ordine)lstbOrdini.SelectedItem;
            string[] piatti = o.IdPiatti.Split(',');
            int importo = 0;

            for (int i = 0; i < piatti.Length; i++)
            {
                foreach (var piatto in Form1.dbTools.listaPiatti)
                {
                    if (piatto.IdPiatto == Convert.ToInt32(piatti[i]))
                    {
                        importo += piatto.Importo;
                    }
                }
            }

            Form1.dbTools.CreaScontrino(o, importo);
        }
    }
}
