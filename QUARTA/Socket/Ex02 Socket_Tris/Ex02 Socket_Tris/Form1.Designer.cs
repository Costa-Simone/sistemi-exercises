namespace Ex02_Socket_Tris
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnStop = new System.Windows.Forms.Button();
            this.btnStart = new System.Windows.Forms.Button();
            this.nudPorta = new System.Windows.Forms.NumericUpDown();
            this.cmbIndirizziIp = new System.Windows.Forms.ComboBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.nudPortaAvversario = new System.Windows.Forms.NumericUpDown();
            this.txtIndirizzoAvversario = new System.Windows.Forms.TextBox();
            this.btn00 = new System.Windows.Forms.Button();
            this.btn01 = new System.Windows.Forms.Button();
            this.btn02 = new System.Windows.Forms.Button();
            this.btn10 = new System.Windows.Forms.Button();
            this.btn11 = new System.Windows.Forms.Button();
            this.btn12 = new System.Windows.Forms.Button();
            this.btn20 = new System.Windows.Forms.Button();
            this.btn21 = new System.Windows.Forms.Button();
            this.btn22 = new System.Windows.Forms.Button();
            this.txtNomeAvversario = new System.Windows.Forms.TextBox();
            this.txtNomeLocale = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPorta)).BeginInit();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPortaAvversario)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txtNomeLocale);
            this.groupBox1.Controls.Add(this.btnStop);
            this.groupBox1.Controls.Add(this.btnStart);
            this.groupBox1.Controls.Add(this.nudPorta);
            this.groupBox1.Controls.Add(this.cmbIndirizziIp);
            this.groupBox1.Location = new System.Drawing.Point(62, 23);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.groupBox1.Size = new System.Drawing.Size(706, 154);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Giocatore Locale";
            // 
            // btnStop
            // 
            this.btnStop.BackColor = System.Drawing.Color.Crimson;
            this.btnStop.Location = new System.Drawing.Point(548, 37);
            this.btnStop.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(130, 92);
            this.btnStop.TabIndex = 2;
            this.btnStop.Text = "STOP";
            this.btnStop.UseVisualStyleBackColor = false;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // btnStart
            // 
            this.btnStart.BackColor = System.Drawing.Color.Lime;
            this.btnStart.Location = new System.Drawing.Point(406, 37);
            this.btnStart.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(130, 92);
            this.btnStart.TabIndex = 1;
            this.btnStart.Text = "START";
            this.btnStart.UseVisualStyleBackColor = false;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // nudPorta
            // 
            this.nudPorta.Location = new System.Drawing.Point(266, 37);
            this.nudPorta.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
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
            this.nudPorta.Size = new System.Drawing.Size(128, 31);
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
            this.cmbIndirizziIp.Location = new System.Drawing.Point(12, 37);
            this.cmbIndirizziIp.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.cmbIndirizziIp.Name = "cmbIndirizziIp";
            this.cmbIndirizziIp.Size = new System.Drawing.Size(238, 33);
            this.cmbIndirizziIp.TabIndex = 0;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.txtNomeAvversario);
            this.groupBox2.Controls.Add(this.nudPortaAvversario);
            this.groupBox2.Controls.Add(this.txtIndirizzoAvversario);
            this.groupBox2.Location = new System.Drawing.Point(62, 188);
            this.groupBox2.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Padding = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.groupBox2.Size = new System.Drawing.Size(706, 107);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Avversario";
            // 
            // nudPortaAvversario
            // 
            this.nudPortaAvversario.Location = new System.Drawing.Point(266, 37);
            this.nudPortaAvversario.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.nudPortaAvversario.Maximum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudPortaAvversario.Minimum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudPortaAvversario.Name = "nudPortaAvversario";
            this.nudPortaAvversario.Size = new System.Drawing.Size(128, 31);
            this.nudPortaAvversario.TabIndex = 2;
            this.nudPortaAvversario.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // txtIndirizzoAvversario
            // 
            this.txtIndirizzoAvversario.Location = new System.Drawing.Point(12, 37);
            this.txtIndirizzoAvversario.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.txtIndirizzoAvversario.Name = "txtIndirizzoAvversario";
            this.txtIndirizzoAvversario.Size = new System.Drawing.Size(238, 31);
            this.txtIndirizzoAvversario.TabIndex = 0;
            this.txtIndirizzoAvversario.Text = "127.0.0.1";
            // 
            // btn00
            // 
            this.btn00.Location = new System.Drawing.Point(166, 329);
            this.btn00.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn00.Name = "btn00";
            this.btn00.Size = new System.Drawing.Size(150, 113);
            this.btn00.TabIndex = 2;
            this.btn00.Tag = "1";
            this.btn00.UseVisualStyleBackColor = true;
            this.btn00.Click += new System.EventHandler(this.btn_Click);
            // 
            // btn01
            // 
            this.btn01.Location = new System.Drawing.Point(328, 329);
            this.btn01.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn01.Name = "btn01";
            this.btn01.Size = new System.Drawing.Size(150, 113);
            this.btn01.TabIndex = 3;
            this.btn01.Tag = "2";
            this.btn01.UseVisualStyleBackColor = true;
            this.btn01.Click += new System.EventHandler(this.btn_Click);
            // 
            // btn02
            // 
            this.btn02.Location = new System.Drawing.Point(490, 329);
            this.btn02.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn02.Name = "btn02";
            this.btn02.Size = new System.Drawing.Size(150, 113);
            this.btn02.TabIndex = 4;
            this.btn02.Tag = "3";
            this.btn02.UseVisualStyleBackColor = true;
            this.btn02.Click += new System.EventHandler(this.btn_Click);
            // 
            // btn10
            // 
            this.btn10.Location = new System.Drawing.Point(166, 454);
            this.btn10.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn10.Name = "btn10";
            this.btn10.Size = new System.Drawing.Size(150, 113);
            this.btn10.TabIndex = 5;
            this.btn10.Tag = "4";
            this.btn10.UseVisualStyleBackColor = true;
            this.btn10.Click += new System.EventHandler(this.btn_Click);
            // 
            // btn11
            // 
            this.btn11.Location = new System.Drawing.Point(328, 454);
            this.btn11.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn11.Name = "btn11";
            this.btn11.Size = new System.Drawing.Size(150, 113);
            this.btn11.TabIndex = 6;
            this.btn11.Tag = "5";
            this.btn11.UseVisualStyleBackColor = true;
            this.btn11.Click += new System.EventHandler(this.btn_Click);
            // 
            // btn12
            // 
            this.btn12.Location = new System.Drawing.Point(490, 454);
            this.btn12.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn12.Name = "btn12";
            this.btn12.Size = new System.Drawing.Size(150, 113);
            this.btn12.TabIndex = 7;
            this.btn12.Tag = "6";
            this.btn12.UseVisualStyleBackColor = true;
            this.btn12.Click += new System.EventHandler(this.btn_Click);
            // 
            // btn20
            // 
            this.btn20.Location = new System.Drawing.Point(166, 579);
            this.btn20.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn20.Name = "btn20";
            this.btn20.Size = new System.Drawing.Size(150, 113);
            this.btn20.TabIndex = 8;
            this.btn20.Tag = "7";
            this.btn20.UseVisualStyleBackColor = true;
            this.btn20.Click += new System.EventHandler(this.btn_Click);
            // 
            // btn21
            // 
            this.btn21.Location = new System.Drawing.Point(328, 579);
            this.btn21.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn21.Name = "btn21";
            this.btn21.Size = new System.Drawing.Size(150, 113);
            this.btn21.TabIndex = 9;
            this.btn21.Tag = "8";
            this.btn21.UseVisualStyleBackColor = true;
            this.btn21.Click += new System.EventHandler(this.btn_Click);
            // 
            // btn22
            // 
            this.btn22.Location = new System.Drawing.Point(490, 579);
            this.btn22.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.btn22.Name = "btn22";
            this.btn22.Size = new System.Drawing.Size(150, 113);
            this.btn22.TabIndex = 10;
            this.btn22.Tag = "9";
            this.btn22.UseVisualStyleBackColor = true;
            this.btn22.Click += new System.EventHandler(this.btn_Click);
            // 
            // txtNomeAvversario
            // 
            this.txtNomeAvversario.Location = new System.Drawing.Point(435, 37);
            this.txtNomeAvversario.Name = "txtNomeAvversario";
            this.txtNomeAvversario.Size = new System.Drawing.Size(243, 31);
            this.txtNomeAvversario.TabIndex = 3;
            // 
            // txtNomeLocale
            // 
            this.txtNomeLocale.Location = new System.Drawing.Point(12, 79);
            this.txtNomeLocale.Name = "txtNomeLocale";
            this.txtNomeLocale.Size = new System.Drawing.Size(238, 31);
            this.txtNomeLocale.TabIndex = 4;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(808, 717);
            this.Controls.Add(this.btn22);
            this.Controls.Add(this.btn21);
            this.Controls.Add(this.btn20);
            this.Controls.Add(this.btn12);
            this.Controls.Add(this.btn11);
            this.Controls.Add(this.btn10);
            this.Controls.Add(this.btn02);
            this.Controls.Add(this.btn01);
            this.Controls.Add(this.btn00);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Margin = new System.Windows.Forms.Padding(6, 6, 6, 6);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPorta)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudPortaAvversario)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.NumericUpDown nudPorta;
        private System.Windows.Forms.ComboBox cmbIndirizziIp;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown nudPortaAvversario;
        private System.Windows.Forms.TextBox txtIndirizzoAvversario;
        private System.Windows.Forms.Button btn00;
        private System.Windows.Forms.Button btn01;
        private System.Windows.Forms.Button btn02;
        private System.Windows.Forms.Button btn10;
        private System.Windows.Forms.Button btn11;
        private System.Windows.Forms.Button btn12;
        private System.Windows.Forms.Button btn20;
        private System.Windows.Forms.Button btn21;
        private System.Windows.Forms.Button btn22;
        private System.Windows.Forms.TextBox txtNomeLocale;
        private System.Windows.Forms.TextBox txtNomeAvversario;
    }
}

