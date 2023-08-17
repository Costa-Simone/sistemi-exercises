using AppCassa.Classi;
using CarShopLibrary;
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
    public partial class PiattiForm : Form
    {
        public PiattiForm()
        {
            InitializeComponent();
        }

        private void PiattiForm_Load(object sender, EventArgs e)
        {
            Form1.dbTools.CaricaPiatti();

            foreach (var piatto in Form1.dbTools.listaPiatti)
            {
                switch (piatto.IdCategoria)
                {
                    default:
                        break;

                    case 1:
                        lstbAntipasti.Items.Add(piatto.ToString());
                        break;

                    case 2:
                        lstbPrimi.Items.Add(piatto.ToString());
                        break;

                    case 3:
                        lstbSecondi.Items.Add(piatto.ToString());
                        break;

                    case 4:
                        lstbDolci.Items.Add(piatto.ToString());
                        break;
                }
            }
        }
    }
}
