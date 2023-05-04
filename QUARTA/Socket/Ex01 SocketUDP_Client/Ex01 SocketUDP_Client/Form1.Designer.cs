namespace Ex01_SocketUDP_Client
{
    partial class Form1
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
            this.txtServerIP = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.nudServerPost = new System.Windows.Forms.NumericUpDown();
            this.txtMsg = new System.Windows.Forms.TextBox();
            this.btnInvia = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.nudServerPost)).BeginInit();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.txtServerIP);
            this.groupBox1.Location = new System.Drawing.Point(12, 23);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(258, 100);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "SERVER IP";
            // 
            // txtServerIP
            // 
            this.txtServerIP.Location = new System.Drawing.Point(6, 41);
            this.txtServerIP.Name = "txtServerIP";
            this.txtServerIP.Size = new System.Drawing.Size(246, 31);
            this.txtServerIP.TabIndex = 0;
            this.txtServerIP.Text = "127.0.0.1";
            this.txtServerIP.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.nudServerPost);
            this.groupBox2.Location = new System.Drawing.Point(308, 23);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(200, 100);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "SERVER POST";
            // 
            // nudServerPost
            // 
            this.nudServerPost.Location = new System.Drawing.Point(18, 41);
            this.nudServerPost.Maximum = new decimal(new int[] {
            42151,
            0,
            0,
            0});
            this.nudServerPost.Minimum = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            this.nudServerPost.Name = "nudServerPost";
            this.nudServerPost.Size = new System.Drawing.Size(155, 31);
            this.nudServerPost.TabIndex = 0;
            this.nudServerPost.Value = new decimal(new int[] {
            1024,
            0,
            0,
            0});
            // 
            // txtMsg
            // 
            this.txtMsg.Location = new System.Drawing.Point(6, 30);
            this.txtMsg.Multiline = true;
            this.txtMsg.Name = "txtMsg";
            this.txtMsg.Size = new System.Drawing.Size(467, 212);
            this.txtMsg.TabIndex = 2;
            // 
            // btnInvia
            // 
            this.btnInvia.Location = new System.Drawing.Point(168, 446);
            this.btnInvia.Name = "btnInvia";
            this.btnInvia.Size = new System.Drawing.Size(181, 63);
            this.btnInvia.TabIndex = 4;
            this.btnInvia.Text = "Invia";
            this.btnInvia.UseVisualStyleBackColor = true;
            this.btnInvia.Click += new System.EventHandler(this.btnInvia_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.txtMsg);
            this.groupBox3.Location = new System.Drawing.Point(18, 144);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(490, 248);
            this.groupBox3.TabIndex = 5;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Messaggio";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(12F, 25F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(537, 542);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.btnInvia);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.nudServerPost)).EndInit();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox txtServerIP;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.NumericUpDown nudServerPost;
        private System.Windows.Forms.TextBox txtMsg;
        private System.Windows.Forms.Button btnInvia;
        private System.Windows.Forms.GroupBox groupBox3;
    }
}

