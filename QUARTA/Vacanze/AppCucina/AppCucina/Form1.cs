using AppCucina.Classi;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AppCucina
{
    public partial class Form1 : Form
    {
        InfoForm formInfo = new InfoForm();
        OrdiniForm formOrdini = new OrdiniForm();

        static public Tools tls = new Tools();

        static public string ip = "";
        static public string port = "";
        static public string reparto = "2";

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            formInfo.MdiParent = this;
            formInfo.Width = this.Width;
            formInfo.Height = this.Height - menuStrip1.Height;
            formInfo.StartPosition = 0;

            formOrdini.MdiParent = this;
            formOrdini.Width = this.Width;
            formOrdini.Height = this.Height - menuStrip1.Height;
            formOrdini.StartPosition = 0;

            formInfo.Show();
        }
    }
}
