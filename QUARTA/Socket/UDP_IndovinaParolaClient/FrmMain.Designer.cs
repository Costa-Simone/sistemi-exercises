namespace UDP_IndovinaParolaClient
{
    partial class FrmMain
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
            this.txtServerIP = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.rdb8 = new System.Windows.Forms.RadioButton();
            this.rdb6 = new System.Windows.Forms.RadioButton();
            this.rdb4 = new System.Windows.Forms.RadioButton();
            this.btnAvviaPartita = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.txtUsername = new System.Windows.Forms.TextBox();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.btnInvia = new System.Windows.Forms.Button();
            this.lblTentativi = new System.Windows.Forms.Label();
            this.txtParola = new System.Windows.Forms.TextBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.cmbIP = new System.Windows.Forms.ComboBox();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txtServerIP);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.groupBox1.Location = new System.Drawing.Point(12, 113);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(210, 65);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "IP SERVER";
            // 
            // txtServerIP
            // 
            this.txtServerIP.Location = new System.Drawing.Point(6, 25);
            this.txtServerIP.Name = "txtServerIP";
            this.txtServerIP.Size = new System.Drawing.Size(189, 44);
            this.txtServerIP.TabIndex = 0;
            this.txtServerIP.Text = "#.#.#.#";
            this.txtServerIP.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.rdb8);
            this.groupBox3.Controls.Add(this.rdb6);
            this.groupBox3.Controls.Add(this.rdb4);
            this.groupBox3.Location = new System.Drawing.Point(228, 184);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(353, 191);
            this.groupBox3.TabIndex = 4;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "DIFFICOLTA\': Numero di caratteri";
            // 
            // rdb8
            // 
            this.rdb8.AutoSize = true;
            this.rdb8.Cursor = System.Windows.Forms.Cursors.Hand;
            this.rdb8.Location = new System.Drawing.Point(16, 134);
            this.rdb8.Name = "rdb8";
            this.rdb8.Size = new System.Drawing.Size(63, 36);
            this.rdb8.TabIndex = 2;
            this.rdb8.Text = "8";
            this.rdb8.UseVisualStyleBackColor = true;
            // 
            // rdb6
            // 
            this.rdb6.AutoSize = true;
            this.rdb6.Cursor = System.Windows.Forms.Cursors.Hand;
            this.rdb6.Location = new System.Drawing.Point(16, 92);
            this.rdb6.Name = "rdb6";
            this.rdb6.Size = new System.Drawing.Size(63, 36);
            this.rdb6.TabIndex = 1;
            this.rdb6.Text = "6";
            this.rdb6.UseVisualStyleBackColor = true;
            // 
            // rdb4
            // 
            this.rdb4.AutoSize = true;
            this.rdb4.Checked = true;
            this.rdb4.Cursor = System.Windows.Forms.Cursors.Hand;
            this.rdb4.Location = new System.Drawing.Point(22, 66);
            this.rdb4.Name = "rdb4";
            this.rdb4.Size = new System.Drawing.Size(63, 36);
            this.rdb4.TabIndex = 0;
            this.rdb4.TabStop = true;
            this.rdb4.Text = "4";
            this.rdb4.UseVisualStyleBackColor = true;
            // 
            // btnAvviaPartita
            // 
            this.btnAvviaPartita.Location = new System.Drawing.Point(12, 296);
            this.btnAvviaPartita.Name = "btnAvviaPartita";
            this.btnAvviaPartita.Size = new System.Drawing.Size(121, 44);
            this.btnAvviaPartita.TabIndex = 5;
            this.btnAvviaPartita.Text = "Avvia Partita";
            this.btnAvviaPartita.UseVisualStyleBackColor = true;
            this.btnAvviaPartita.Click += new System.EventHandler(this.btnAvviaPartita_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.txtUsername);
            this.groupBox4.Location = new System.Drawing.Point(12, 184);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(210, 106);
            this.groupBox4.TabIndex = 6;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "USERNAME";
            // 
            // txtUsername
            // 
            this.txtUsername.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtUsername.Location = new System.Drawing.Point(6, 38);
            this.txtUsername.Name = "txtUsername";
            this.txtUsername.Size = new System.Drawing.Size(189, 39);
            this.txtUsername.TabIndex = 0;
            this.txtUsername.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.btnInvia);
            this.groupBox5.Controls.Add(this.lblTentativi);
            this.groupBox5.Controls.Add(this.txtParola);
            this.groupBox5.Location = new System.Drawing.Point(228, 429);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(467, 229);
            this.groupBox5.TabIndex = 7;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Inserisci Parola";
            // 
            // btnInvia
            // 
            this.btnInvia.Location = new System.Drawing.Point(236, 49);
            this.btnInvia.Name = "btnInvia";
            this.btnInvia.Size = new System.Drawing.Size(143, 68);
            this.btnInvia.TabIndex = 9;
            this.btnInvia.Text = "Invia";
            this.btnInvia.UseVisualStyleBackColor = true;
            this.btnInvia.Click += new System.EventHandler(this.btnInvia_Click);
            // 
            // lblTentativi
            // 
            this.lblTentativi.AutoSize = true;
            this.lblTentativi.Location = new System.Drawing.Point(16, 85);
            this.lblTentativi.Name = "lblTentativi";
            this.lblTentativi.Size = new System.Drawing.Size(178, 32);
            this.lblTentativi.TabIndex = 8;
            this.lblTentativi.Text = "[lblTentativi]";
            // 
            // txtParola
            // 
            this.txtParola.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtParola.Location = new System.Drawing.Point(16, 49);
            this.txtParola.Name = "txtParola";
            this.txtParola.Size = new System.Drawing.Size(189, 39);
            this.txtParola.TabIndex = 1;
            this.txtParola.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.cmbIP);
            this.groupBox6.Location = new System.Drawing.Point(12, 13);
            this.groupBox6.Margin = new System.Windows.Forms.Padding(4);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Padding = new System.Windows.Forms.Padding(4);
            this.groupBox6.Size = new System.Drawing.Size(370, 90);
            this.groupBox6.TabIndex = 8;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "IP DISPONIBILI";
            // 
            // cmbIP
            // 
            this.cmbIP.Cursor = System.Windows.Forms.Cursors.Hand;
            this.cmbIP.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbIP.FormattingEnabled = true;
            this.cmbIP.Location = new System.Drawing.Point(8, 34);
            this.cmbIP.Margin = new System.Windows.Forms.Padding(4);
            this.cmbIP.Name = "cmbIP";
            this.cmbIP.Size = new System.Drawing.Size(281, 40);
            this.cmbIP.TabIndex = 0;
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(16F, 32F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(830, 768);
            this.Controls.Add(this.groupBox6);
            this.Controls.Add(this.groupBox5);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.btnAvviaPartita);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox1);
            this.Font = new System.Drawing.Font("Verdana", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.Margin = new System.Windows.Forms.Padding(4);
            this.MaximizeBox = false;
            this.Name = "FrmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Client UDP: Indovina la Parola";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FrmMain_FormClosing);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtServerIP;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.RadioButton rdb8;
        private System.Windows.Forms.RadioButton rdb6;
        private System.Windows.Forms.RadioButton rdb4;
        private System.Windows.Forms.Button btnAvviaPartita;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.TextBox txtUsername;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.TextBox txtParola;
        private System.Windows.Forms.Label lblTentativi;
        private System.Windows.Forms.Button btnInvia;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.ComboBox cmbIP;
    }
}

