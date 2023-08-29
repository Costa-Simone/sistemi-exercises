namespace AppMobile
{
    partial class PiattiForm
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
            this.lstTavoli = new System.Windows.Forms.ListBox();
            this.lstOrdine = new System.Windows.Forms.ListBox();
            this.grpbPiatti = new System.Windows.Forms.GroupBox();
            this.SuspendLayout();
            // 
            // lstTavoli
            // 
            this.lstTavoli.FormattingEnabled = true;
            this.lstTavoli.Location = new System.Drawing.Point(12, 12);
            this.lstTavoli.Name = "lstTavoli";
            this.lstTavoli.Size = new System.Drawing.Size(262, 277);
            this.lstTavoli.TabIndex = 1;
            // 
            // lstOrdine
            // 
            this.lstOrdine.FormattingEnabled = true;
            this.lstOrdine.Location = new System.Drawing.Point(304, 12);
            this.lstOrdine.Name = "lstOrdine";
            this.lstOrdine.Size = new System.Drawing.Size(178, 277);
            this.lstOrdine.TabIndex = 2;
            // 
            // grpbPiatti
            // 
            this.grpbPiatti.Location = new System.Drawing.Point(529, 12);
            this.grpbPiatti.Name = "grpbPiatti";
            this.grpbPiatti.Size = new System.Drawing.Size(353, 277);
            this.grpbPiatti.TabIndex = 3;
            this.grpbPiatti.TabStop = false;
            this.grpbPiatti.Text = "Piatti";
            // 
            // PiattiForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(916, 309);
            this.Controls.Add(this.lstTavoli);
            this.Controls.Add(this.lstOrdine);
            this.Controls.Add(this.grpbPiatti);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "PiattiForm";
            this.Text = "PiattiForm";
            this.Load += new System.EventHandler(this.PiattiForm_Load);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.ListBox lstTavoli;
        private System.Windows.Forms.ListBox lstOrdine;
        private System.Windows.Forms.GroupBox grpbPiatti;
    }
}