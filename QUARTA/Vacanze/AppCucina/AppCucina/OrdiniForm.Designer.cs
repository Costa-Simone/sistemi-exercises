namespace AppCucina
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
            this.lstTavolo1 = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lstTavolo2 = new System.Windows.Forms.ListBox();
            this.label3 = new System.Windows.Forms.Label();
            this.lstTavolo3 = new System.Windows.Forms.ListBox();
            this.label4 = new System.Windows.Forms.Label();
            this.lstTavolo4 = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // lstTavolo1
            // 
            this.lstTavolo1.FormattingEnabled = true;
            this.lstTavolo1.Location = new System.Drawing.Point(12, 25);
            this.lstTavolo1.Name = "lstTavolo1";
            this.lstTavolo1.Size = new System.Drawing.Size(156, 186);
            this.lstTavolo1.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(63, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(49, 13);
            this.label1.TabIndex = 1;
            this.label1.Text = "Tavolo 1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(242, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "Tavolo 2";
            // 
            // lstTavolo2
            // 
            this.lstTavolo2.FormattingEnabled = true;
            this.lstTavolo2.Location = new System.Drawing.Point(191, 25);
            this.lstTavolo2.Name = "lstTavolo2";
            this.lstTavolo2.Size = new System.Drawing.Size(156, 186);
            this.lstTavolo2.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(424, 9);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Tavolo 3";
            // 
            // lstTavolo3
            // 
            this.lstTavolo3.FormattingEnabled = true;
            this.lstTavolo3.Location = new System.Drawing.Point(373, 25);
            this.lstTavolo3.Name = "lstTavolo3";
            this.lstTavolo3.Size = new System.Drawing.Size(156, 186);
            this.lstTavolo3.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(616, 9);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(49, 13);
            this.label4.TabIndex = 7;
            this.label4.Text = "Tavolo 4";
            // 
            // lstTavolo4
            // 
            this.lstTavolo4.FormattingEnabled = true;
            this.lstTavolo4.Location = new System.Drawing.Point(565, 25);
            this.lstTavolo4.Name = "lstTavolo4";
            this.lstTavolo4.Size = new System.Drawing.Size(156, 186);
            this.lstTavolo4.TabIndex = 6;
            // 
            // OrdiniForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.lstTavolo4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.lstTavolo3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.lstTavolo2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.lstTavolo1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "OrdiniForm";
            this.Text = "OrdiniForm";
            this.Load += new System.EventHandler(this.OrdiniForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox lstTavolo1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ListBox lstTavolo2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ListBox lstTavolo3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.ListBox lstTavolo4;
    }
}