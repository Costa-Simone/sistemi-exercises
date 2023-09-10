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
    public partial class OrdiniForm : Form
    {
        public OrdiniForm()
        {
            InitializeComponent();
        }

        private void OrdiniForm_Load(object sender, EventArgs e)
        {
            lstTavolo1.DataSource = Form1.tls.dicOrdini[1];
            lstTavolo2.DataSource = Form1.tls.dicOrdini[2];
            lstTavolo3.DataSource = Form1.tls.dicOrdini[3];
            lstTavolo4.DataSource = Form1.tls.dicOrdini[4];
        }
    }
}
