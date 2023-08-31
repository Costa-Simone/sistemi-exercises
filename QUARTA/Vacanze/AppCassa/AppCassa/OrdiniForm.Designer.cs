namespace AppCassa
{
    partial class OrdiniForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.lstbOrdini = new System.Windows.Forms.ListBox();
            this.btnScontrino = new System.Windows.Forms.Button();
            this.dbToolsBindingSource = new System.Windows.Forms.BindingSource(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.dbToolsBindingSource)).BeginInit();
            this.SuspendLayout();
            // 
            // lstbOrdini
            // 
            this.lstbOrdini.FormattingEnabled = true;
            this.lstbOrdini.Location = new System.Drawing.Point(12, 12);
            this.lstbOrdini.Name = "lstbOrdini";
            this.lstbOrdini.Size = new System.Drawing.Size(776, 420);
            this.lstbOrdini.TabIndex = 0;
            // 
            // btnScontrino
            // 
            this.btnScontrino.Location = new System.Drawing.Point(794, 169);
            this.btnScontrino.Name = "btnScontrino";
            this.btnScontrino.Size = new System.Drawing.Size(282, 109);
            this.btnScontrino.TabIndex = 1;
            this.btnScontrino.Text = "Emetti scontrino dell\'ordine selezionato";
            this.btnScontrino.UseVisualStyleBackColor = true;
            this.btnScontrino.Click += new System.EventHandler(this.btnScontrino_Click);
            // 
            // dbToolsBindingSource
            // 
            this.dbToolsBindingSource.DataSource = typeof(CarShopLibrary.DbTools);
            // 
            // OrdiniForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1088, 450);
            this.Controls.Add(this.btnScontrino);
            this.Controls.Add(this.lstbOrdini);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "OrdiniForm";
            this.Text = "Ordini";
            this.Load += new System.EventHandler(this.OrdiniForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dbToolsBindingSource)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button btnScontrino;
        public System.Windows.Forms.ListBox lstbOrdini;
        private System.Windows.Forms.BindingSource dbToolsBindingSource;
    }
}