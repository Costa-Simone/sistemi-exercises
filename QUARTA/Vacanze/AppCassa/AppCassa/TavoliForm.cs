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
        private void btnComunicaTavoli_Click(object sender, EventArgs e)
        {
            string tavoli = "";

            foreach (var tavolo in Form1.dbTools.listaTavoli)
            {
                tavoli += tavolo.IdTavolo + ",";
            }

            ClsMessagge msg = new ClsMessagge(Form1.ip, Form1.port, Form1.reparto, "1", tavoli);

            Form1.dbTools.clientMobile.Invia(msg);
        }
    }
}
