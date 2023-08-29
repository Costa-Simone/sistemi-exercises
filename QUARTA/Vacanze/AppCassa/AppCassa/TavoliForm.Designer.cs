namespace AppCassa
{
    partial class TavoliForm
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
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.btnComunicaTavoli = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // listBox1
            // 
            this.listBox1.FormattingEnabled = true;
            this.listBox1.Location = new System.Drawing.Point(12, 12);
            this.listBox1.Name = "listBox1";
            this.listBox1.SelectionMode = System.Windows.Forms.SelectionMode.None;
            this.listBox1.Size = new System.Drawing.Size(538, 420);
            this.listBox1.TabIndex = 0;
            // 
            // btnComunicaTavoli
            // 
            this.btnComunicaTavoli.Location = new System.Drawing.Point(581, 152);
            this.btnComunicaTavoli.Name = "btnComunicaTavoli";
            this.btnComunicaTavoli.Size = new System.Drawing.Size(180, 119);
            this.btnComunicaTavoli.TabIndex = 1;
            this.btnComunicaTavoli.Text = "Comunica tavoli";
            this.btnComunicaTavoli.UseVisualStyleBackColor = true;
            this.btnComunicaTavoli.Click += new System.EventHandler(this.btnComunicaTavoli_Click);
            // 
            // TavoliForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnComunicaTavoli);
            this.Controls.Add(this.listBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "TavoliForm";
            this.Text = "Tavoli";
            this.Load += new System.EventHandler(this.TavoliForm_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.Button btnComunicaTavoli;
    }
}