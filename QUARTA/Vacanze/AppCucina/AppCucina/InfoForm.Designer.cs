namespace AppCucina
{
    partial class InfoForm
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.nudCassa = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.txtCassa = new System.Windows.Forms.TextBox();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.nudPorta = new System.Windows.Forms.NumericUpDown();
            this.cmbIndirizziIp = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudCassa)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPorta)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.nudCassa);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.txtCassa);
            this.groupBox1.Controls.Add(this.btnStop);
            this.groupBox1.Controls.Add(this.btnStart);
            this.groupBox1.Controls.Add(this.nudPorta);
            this.groupBox1.Controls.Add(this.cmbIndirizziIp);
            this.groupBox1.Location = new System.Drawing.Point(12, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(421, 84);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Indirizzo cassa";
            // 
            // nudCassa
            // 
            this.nudCassa.Location = new System.Drawing.Point(203, 50);
            this.nudCassa.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudCassa.Minimum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudCassa.Name = "nudCassa";
            this.nudCassa.Size = new System.Drawing.Size(64, 20);
            this.nudCassa.TabIndex = 7;
            this.nudCassa.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 50);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(51, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Ip Cassa:";
            // 
            // txtCassa
            // 
            this.txtCassa.Location = new System.Drawing.Point(68, 47);
            this.txtCassa.Name = "txtCassa";
            this.txtCassa.Size = new System.Drawing.Size(129, 20);
            this.txtCassa.TabIndex = 3;
            // 
            // btnStop
            // 
            this.btnStop.BackColor = System.Drawing.Color.Crimson;
            this.btnStop.Location = new System.Drawing.Point(349, 19);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(65, 48);
            this.btnStop.TabIndex = 2;
            this.btnStop.Text = "STOP";
            this.btnStop.UseVisualStyleBackColor = false;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.Lime;
            this.btnStart.Location = new System.Drawing.Point(278, 19);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(65, 48);
            this.btnStart.TabIndex = 1;
            this.btnStart.Text = "START";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // nudPorta
            // 
            this.nudPorta.Location = new System.Drawing.Point(133, 19);
            this.nudPorta.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudPorta.Minimum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudPorta.Name = "nudPorta";
            this.nudPorta.Size = new System.Drawing.Size(64, 20);
            this.nudPorta.TabIndex = 1;
            this.nudPorta.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // cmbIndirizziIp
            // 
            this.cmbIndirizziIp.FormattingEnabled = true;
            this.cmbIndirizziIp.Location = new System.Drawing.Point(6, 19);
            this.cmbIndirizziIp.Name = "cmbIndirizziIp";
            this.cmbIndirizziIp.Size = new System.Drawing.Size(121, 21);
            this.cmbIndirizziIp.TabIndex = 0;
            // 
            // InfoForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "InfoForm";
            this.Text = "InfoForm";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudCassa)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.nudPorta)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        public System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.NumericUpDown nudCassa;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtCassa;
        private System.Windows.Forms.Button btnStop;
        public System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.NumericUpDown nudPorta;
        private System.Windows.Forms.ComboBox cmbIndirizziIp;
    }
}