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
    public partial class ScontriniForm : Form
    {
        public ScontriniForm()
        {
            InitializeComponent();
        }

        private void ScontriniForm_Load(object sender, EventArgs e)
        {
            Form1.dbTools.CaricaScontrini();
            lstbScontrini.DataSource = Form1.dbTools.listaScontrini;
        }
    }
}
