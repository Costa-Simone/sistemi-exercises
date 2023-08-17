namespace AppCassa
{
    partial class ScontriniForm
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
            this.lstbScontrini = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // lstbScontrini
            // 
            this.lstbScontrini.FormattingEnabled = true;
            this.lstbScontrini.Location = new System.Drawing.Point(12, 12);
            this.lstbScontrini.Name = "lstbScontrini";
            this.lstbScontrini.Size = new System.Drawing.Size(776, 433);
            this.lstbScontrini.TabIndex = 0;
            // 
            // ScontriniForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.lstbScontrini);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "ScontriniForm";
            this.Text = "ScontriniForm";
            this.Load += new System.EventHandler(this.ScontriniForm_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox lstbScontrini;
    }
}