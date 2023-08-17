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
    public partial class TavoliForm : Form
    {
        public TavoliForm()
        {
            InitializeComponent();
        }

        private void TavoliForm_Load(object sender, EventArgs e)
        {
            Form1.dbTools.CaricaTavoli();
            listBox1.DataSource = Form1.dbTools.listaTavoli;
        }
    }
}
