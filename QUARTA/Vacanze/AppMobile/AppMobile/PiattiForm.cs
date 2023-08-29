using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppMobile
{
    public partial class PiattiForm : Form
    {
        public PiattiForm()
        {
            InitializeComponent();
        }

        private void PiattiForm_Load(object sender, EventArgs e)
        {
            lstTavoli.DataSource = Form1.tls.listaTavoli;

            int x = 0; int y = 0;

            foreach (var piatto in Form1.tls.listaPiatti)
            {
                Button btn = new Button();

                btn.Text = piatto.ToString();
                btn.Name = $"btn{piatto}";
                btn.Top = y + 20;
                btn.Left = x + 20;
                btn.Width = 75;
                btn.Click += PiattoOnClick;

                x += 80;

                if (x == 320)
                {
                    y += 70;
                    x = 0;
                }

                grpbPiatti.Controls.Add(btn);
            }
        }

        private void PiattoOnClick(object sender, EventArgs e)
        {
            int tavolo = Convert.ToInt32(lstTavoli.SelectedItem);

            Form1.tls.dicOrdini[tavolo] += ((Button)sender).Text;
            lstOrdine.DataSource = Form1.tls.dicOrdini[tavolo].ToString();
        }
    }
}
