namespace AppCassa
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
            this.lstbAntipasti = new System.Windows.Forms.ListBox();
            this.lstbPrimi = new System.Windows.Forms.ListBox();
            this.lstbSecondi = new System.Windows.Forms.ListBox();
            this.lstbDolci = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // lstbAntipasti
            // 
            this.lstbAntipasti.FormattingEnabled = true;
            this.lstbAntipasti.Location = new System.Drawing.Point(12, 43);
            this.lstbAntipasti.Name = "lstbAntipasti";
            this.lstbAntipasti.SelectionMode = System.Windows.Forms.SelectionMode.None;
            this.lstbAntipasti.Size = new System.Drawing.Size(162, 433);
            this.lstbAntipasti.TabIndex = 1;
            // 
            // lstbPrimi
            // 
            this.lstbPrimi.FormattingEnabled = true;
            this.lstbPrimi.Location = new System.Drawing.Point(229, 43);
            this.lstbPrimi.Name = "lstbPrimi";
            this.lstbPrimi.SelectionMode = System.Windows.Forms.SelectionMode.None;
            this.lstbPrimi.Size = new System.Drawing.Size(162, 433);
            this.lstbPrimi.TabIndex = 2;
            // 
            // lstbSecondi
            // 
            this.lstbSecondi.FormattingEnabled = true;
            this.lstbSecondi.Location = new System.Drawing.Point(446, 43);
            this.lstbSecondi.Name = "lstbSecondi";
            this.lstbSecondi.SelectionMode = System.Windows.Forms.SelectionMode.None;
            this.lstbSecondi.Size = new System.Drawing.Size(162, 433);
            this.lstbSecondi.TabIndex = 3;
            // 
            // lstbDolci
            // 
            this.lstbDolci.FormattingEnabled = true;
            this.lstbDolci.Location = new System.Drawing.Point(672, 43);
            this.lstbDolci.Name = "lstbDolci";
            this.lstbDolci.SelectionMode = System.Windows.Forms.SelectionMode.None;
            this.lstbDolci.Size = new System.Drawing.Size(162, 433);
            this.lstbDolci.TabIndex = 4;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 18);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(50, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Antipasti:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(226, 18);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(32, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Primi:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(443, 18);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 13);
            this.label3.TabIndex = 7;
            this.label3.Text = "Secondi:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(669, 18);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(34, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "Dolci:";
            // 
            // PiattiForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1035, 572);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lstbDolci);
            this.Controls.Add(this.lstbSecondi);
            this.Controls.Add(this.lstbPrimi);
            this.Controls.Add(this.lstbAntipasti);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "PiattiForm";
            this.Text = "Piatti";
            this.Load += new System.EventHandler(this.PiattiForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox lstbAntipasti;
        private System.Windows.Forms.ListBox lstbPrimi;
        private System.Windows.Forms.ListBox lstbSecondi;
        private System.Windows.Forms.ListBox lstbDolci;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
    }
}