namespace AppCassa
{
    partial class Form1
    {
        /// <summary>
        /// Variabile di progettazione necessaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Pulire le risorse in uso.
        /// </summary>
        /// <param name="disposing">ha valore true se le risorse gestite devono essere eliminate, false in caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Codice generato da Progettazione Windows Form

        /// <summary>
        /// Metodo necessario per il supporto della finestra di progettazione. Non modificare
        /// il contenuto del metodo con l'editor di codice.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.infoCassaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.elencoPiattiToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.elencoOrdiniToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.elencoTavoliToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.elencoScontriniToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.infoCassaToolStripMenuItem,
            this.elencoPiattiToolStripMenuItem,
            this.elencoOrdiniToolStripMenuItem,
            this.elencoTavoliToolStripMenuItem,
            this.elencoScontriniToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1079, 24);
            this.menuStrip1.TabIndex = 3;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // infoCassaToolStripMenuItem
            // 
            this.infoCassaToolStripMenuItem.Name = "infoCassaToolStripMenuItem";
            this.infoCassaToolStripMenuItem.Size = new System.Drawing.Size(71, 20);
            this.infoCassaToolStripMenuItem.Text = "Info cassa";
            this.infoCassaToolStripMenuItem.Click += new System.EventHandler(this.infoCassaToolStripMenuItem_Click);
            // 
            // elencoPiattiToolStripMenuItem
            // 
            this.elencoPiattiToolStripMenuItem.Name = "elencoPiattiToolStripMenuItem";
            this.elencoPiattiToolStripMenuItem.Size = new System.Drawing.Size(84, 20);
            this.elencoPiattiToolStripMenuItem.Text = "Elenco piatti";
            this.elencoPiattiToolStripMenuItem.Click += new System.EventHandler(this.elencoPiattiToolStripMenuItem_Click);
            // 
            // elencoOrdiniToolStripMenuItem
            // 
            this.elencoOrdiniToolStripMenuItem.Name = "elencoOrdiniToolStripMenuItem";
            this.elencoOrdiniToolStripMenuItem.Size = new System.Drawing.Size(88, 20);
            this.elencoOrdiniToolStripMenuItem.Text = "Elenco ordini";
            this.elencoOrdiniToolStripMenuItem.Click += new System.EventHandler(this.elencoOrdiniToolStripMenuItem_Click);
            // 
            // elencoTavoliToolStripMenuItem
            // 
            this.elencoTavoliToolStripMenuItem.Name = "elencoTavoliToolStripMenuItem";
            this.elencoTavoliToolStripMenuItem.Size = new System.Drawing.Size(87, 20);
            this.elencoTavoliToolStripMenuItem.Text = "Elenco Tavoli";
            this.elencoTavoliToolStripMenuItem.Click += new System.EventHandler(this.elencoTavoliToolStripMenuItem_Click);
            // 
            // elencoScontriniToolStripMenuItem
            // 
            this.elencoScontriniToolStripMenuItem.Name = "elencoScontriniToolStripMenuItem";
            this.elencoScontriniToolStripMenuItem.Size = new System.Drawing.Size(104, 20);
            this.elencoScontriniToolStripMenuItem.Text = "Elenco Scontrini";
            this.elencoScontriniToolStripMenuItem.Click += new System.EventHandler(this.elencoScontriniToolStripMenuItem_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1079, 537);
            this.Controls.Add(this.menuStrip1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.IsMdiContainer = true;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Cassa";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem elencoPiattiToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem elencoOrdiniToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem elencoTavoliToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem infoCassaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem elencoScontriniToolStripMenuItem;
    }
}

