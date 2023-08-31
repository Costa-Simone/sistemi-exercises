using AppMobile.Classi;
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
    public partial class Form1 : Form
    {
        InfoForm formInfo = new InfoForm();
        PiattiForm formPiatti = new PiattiForm();

        static public Tools tls = new Tools();

        static public string ip = "";
        static public string port = "";
        static public string reparto = "1";

        public Form1()
        {
            InitializeComponent();
        }

        private void infoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            formInfo.Show();
            formPiatti.Hide();
        }
        private void piattiToolStripMenuItem_Click(object sender, EventArgs e)
        {
            formInfo.Hide();
            formPiatti.Show();
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

            formInfo.Show();
        }
    }
}
