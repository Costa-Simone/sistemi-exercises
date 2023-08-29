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
    public partial class Form1 : Form
    {
        InfoForm formInfo = new InfoForm();
        PiattiForm formPiatti = new PiattiForm();
        TavoliForm formTavoli = new TavoliForm();
        OrdiniForm formOrdini = new OrdiniForm();
        ScontriniForm formScontrini = new ScontriniForm();

        static public DbTools dbTools = new DbTools();

        static public string ip = "";
        static public string port = "";
        static public string reparto = "0";

        public Form1()
        {
            InitializeComponent();
        }

        private void elencoOrdiniToolStripMenuItem_Click(object sender, EventArgs e)
        {
            formPiatti.Hide();
            formTavoli.Hide();
            formInfo.Hide();
            formOrdini.Show();
            formScontrini.Hide();
        }
        private void elencoPiattiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            formInfo.Hide();
            formPiatti.Hide();
            formOrdini.Hide();
            formPiatti.Show();
            formScontrini.Hide();
        }
        private void elencoTavoliToolStripMenuItem_Click(object sender, EventArgs e)
        {
            formInfo.Hide();
            formPiatti.Hide();
            formOrdini.Hide();
            formTavoli.Show();
            formScontrini.Hide();
        }
        private void infoCassaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            formPiatti.Hide();
            formTavoli.Hide();
            formOrdini.Hide();
            formScontrini.Hide();
            formInfo.Show();
        }
        private void elencoScontriniToolStripMenuItem_Click(object sender, EventArgs e)
        {
            formPiatti.Hide();
            formTavoli.Hide();
            formOrdini.Hide();
            formScontrini.Show();
            formInfo.Hide();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            formInfo.MdiParent = this;
            formInfo.Width = this.Width;
            formInfo.Height = this.Height - menuStrip1.Height;
            formInfo.StartPosition = 0;

            formPiatti.MdiParent = this;
            formPiatti.Width = this.Width;
            formPiatti.Height = this.Height - menuStrip1.Height;
            formPiatti.StartPosition = 0;

            formTavoli.MdiParent = this;
            formTavoli.Width = this.Width;
            formTavoli.Height = this.Height - menuStrip1.Height;
            formTavoli.StartPosition = 0;

            formOrdini.MdiParent = this;
            formOrdini.Width = this.Width;
            formOrdini.Height = this.Height - menuStrip1.Height;
            formOrdini.StartPosition = 0;

            formScontrini.MdiParent = this;
            formScontrini.Width = this.Width;
            formScontrini.Height = this.Height - menuStrip1.Height;
            formScontrini.StartPosition = 0;

            formInfo.Show();
        }
    }
}
