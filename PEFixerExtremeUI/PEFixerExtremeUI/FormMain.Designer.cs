
namespace PEFixerExtremeUI
{
    partial class FormMain
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.bunifuElipse1 = new Bunifu.Framework.UI.BunifuElipse(this.components);
            this.panel1 = new System.Windows.Forms.Panel();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.panel2 = new System.Windows.Forms.Panel();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.btnAbout = new Bunifu.Framework.UI.BunifuFlatButton();
            this.btnSair = new Bunifu.Framework.UI.BunifuFlatButton();
            this.btnHome = new Bunifu.Framework.UI.BunifuFlatButton();
            this.detalhes = new System.Windows.Forms.Panel();
            this.panel4 = new System.Windows.Forms.Panel();
            this.bunifuFlatButton1 = new Bunifu.Framework.UI.BunifuFlatButton();
            this.label3 = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.bunifuTileButton1 = new Bunifu.Framework.UI.BunifuTileButton();
            this.btnSelectFile = new Bunifu.Framework.UI.BunifuFlatButton();
            this.opCarrigirAsCaracteristicas = new System.Windows.Forms.CheckBox();
            this.opCorrigirAlinhamentosRaw = new System.Windows.Forms.CheckBox();
            this.opCorrigirTamanhoDaImagem = new System.Windows.Forms.CheckBox();
            this.opCorrigirOptionalHeader = new System.Windows.Forms.CheckBox();
            this.opCorrigiroTamanhoInitDATA = new System.Windows.Forms.CheckBox();
            this.opCorrigirInformacoesVersao = new System.Windows.Forms.CheckBox();
            this.opCorrigirTamanhoDoHeapDaStack = new System.Windows.Forms.CheckBox();
            this.opCorrigirDiretorioData = new System.Windows.Forms.CheckBox();
            this.bunifuFlatButton5 = new Bunifu.Framework.UI.BunifuFlatButton();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            this.panel4.SuspendLayout();
            this.SuspendLayout();
            // 
            // bunifuElipse1
            // 
            this.bunifuElipse1.ElipseRadius = 5;
            this.bunifuElipse1.TargetControl = this;
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(919, 55);
            this.panel1.TabIndex = 0;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.panel1_MouseDown);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(730, 14);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(186, 32);
            this.label2.TabIndex = 4;
            this.label2.Text = "Você esta utilizando o modulo:\r\nArquivos PE Nativos";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.label1.Location = new System.Drawing.Point(63, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(234, 32);
            this.label1.TabIndex = 3;
            this.label1.Text = "PEFixer Extreme";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(7, 6);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(50, 46);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            // 
            // panel2
            // 
            this.panel2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.panel2.Controls.Add(this.pictureBox2);
            this.panel2.Controls.Add(this.btnAbout);
            this.panel2.Controls.Add(this.btnSair);
            this.panel2.Controls.Add(this.btnHome);
            this.panel2.Controls.Add(this.detalhes);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel2.Location = new System.Drawing.Point(0, 55);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(180, 472);
            this.panel2.TabIndex = 1;
            // 
            // pictureBox2
            // 
            this.pictureBox2.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox2.Image")));
            this.pictureBox2.Location = new System.Drawing.Point(7, 442);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(35, 27);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox2.TabIndex = 5;
            this.pictureBox2.TabStop = false;
            this.pictureBox2.Click += new System.EventHandler(this.pictureBox2_Click);
            // 
            // btnAbout
            // 
            this.btnAbout.Activecolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnAbout.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnAbout.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.btnAbout.BorderRadius = 0;
            this.btnAbout.ButtonText = "Sobre o Projeto";
            this.btnAbout.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnAbout.DisabledColor = System.Drawing.Color.Gray;
            this.btnAbout.Iconcolor = System.Drawing.Color.Transparent;
            this.btnAbout.Iconimage = null;
            this.btnAbout.Iconimage_right = null;
            this.btnAbout.Iconimage_right_Selected = null;
            this.btnAbout.Iconimage_Selected = null;
            this.btnAbout.IconMarginLeft = 0;
            this.btnAbout.IconMarginRight = 0;
            this.btnAbout.IconRightVisible = true;
            this.btnAbout.IconRightZoom = 0D;
            this.btnAbout.IconVisible = true;
            this.btnAbout.IconZoom = 90D;
            this.btnAbout.IsTab = false;
            this.btnAbout.Location = new System.Drawing.Point(22, 100);
            this.btnAbout.Margin = new System.Windows.Forms.Padding(3, 6, 3, 6);
            this.btnAbout.Name = "btnAbout";
            this.btnAbout.Normalcolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnAbout.OnHovercolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnAbout.OnHoverTextColor = System.Drawing.Color.White;
            this.btnAbout.selected = false;
            this.btnAbout.Size = new System.Drawing.Size(142, 42);
            this.btnAbout.TabIndex = 4;
            this.btnAbout.Text = "Sobre o Projeto";
            this.btnAbout.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.btnAbout.Textcolor = System.Drawing.Color.White;
            this.btnAbout.TextFont = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAbout.Click += new System.EventHandler(this.btnHelp_Click);
            // 
            // btnSair
            // 
            this.btnSair.Activecolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnSair.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnSair.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.btnSair.BorderRadius = 0;
            this.btnSair.ButtonText = "Sair";
            this.btnSair.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnSair.DisabledColor = System.Drawing.Color.Gray;
            this.btnSair.Iconcolor = System.Drawing.Color.Transparent;
            this.btnSair.Iconimage = null;
            this.btnSair.Iconimage_right = null;
            this.btnSair.Iconimage_right_Selected = null;
            this.btnSair.Iconimage_Selected = null;
            this.btnSair.IconMarginLeft = 0;
            this.btnSair.IconMarginRight = 0;
            this.btnSair.IconRightVisible = true;
            this.btnSair.IconRightZoom = 0D;
            this.btnSair.IconVisible = true;
            this.btnSair.IconZoom = 90D;
            this.btnSair.IsTab = false;
            this.btnSair.Location = new System.Drawing.Point(22, 153);
            this.btnSair.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
            this.btnSair.Name = "btnSair";
            this.btnSair.Normalcolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnSair.OnHovercolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnSair.OnHoverTextColor = System.Drawing.Color.White;
            this.btnSair.selected = false;
            this.btnSair.Size = new System.Drawing.Size(142, 32);
            this.btnSair.TabIndex = 3;
            this.btnSair.Text = "Sair";
            this.btnSair.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.btnSair.Textcolor = System.Drawing.Color.White;
            this.btnSair.TextFont = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSair.Click += new System.EventHandler(this.btnSair_Click);
            // 
            // btnHome
            // 
            this.btnHome.Activecolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnHome.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnHome.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.btnHome.BorderRadius = 0;
            this.btnHome.ButtonText = "Home";
            this.btnHome.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnHome.DisabledColor = System.Drawing.Color.Gray;
            this.btnHome.Iconcolor = System.Drawing.Color.Transparent;
            this.btnHome.Iconimage = null;
            this.btnHome.Iconimage_right = null;
            this.btnHome.Iconimage_right_Selected = null;
            this.btnHome.Iconimage_Selected = null;
            this.btnHome.IconMarginLeft = 0;
            this.btnHome.IconMarginRight = 0;
            this.btnHome.IconRightVisible = true;
            this.btnHome.IconRightZoom = 0D;
            this.btnHome.IconVisible = true;
            this.btnHome.IconZoom = 90D;
            this.btnHome.IsTab = false;
            this.btnHome.Location = new System.Drawing.Point(22, 59);
            this.btnHome.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnHome.Name = "btnHome";
            this.btnHome.Normalcolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnHome.OnHovercolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.btnHome.OnHoverTextColor = System.Drawing.Color.White;
            this.btnHome.selected = false;
            this.btnHome.Size = new System.Drawing.Size(142, 32);
            this.btnHome.TabIndex = 2;
            this.btnHome.Text = "Home";
            this.btnHome.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.btnHome.Textcolor = System.Drawing.Color.White;
            this.btnHome.TextFont = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnHome.Click += new System.EventHandler(this.btnHome_Click);
            // 
            // detalhes
            // 
            this.detalhes.BackColor = System.Drawing.Color.DarkSlateBlue;
            this.detalhes.Location = new System.Drawing.Point(1, 59);
            this.detalhes.Name = "detalhes";
            this.detalhes.Size = new System.Drawing.Size(6, 32);
            this.detalhes.TabIndex = 2;
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.panel4.Controls.Add(this.bunifuFlatButton1);
            this.panel4.Controls.Add(this.label3);
            this.panel4.Controls.Add(this.richTextBox1);
            this.panel4.Controls.Add(this.bunifuTileButton1);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel4.Location = new System.Drawing.Point(766, 55);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(153, 472);
            this.panel4.TabIndex = 2;
            // 
            // bunifuFlatButton1
            // 
            this.bunifuFlatButton1.Activecolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.bunifuFlatButton1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.bunifuFlatButton1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.bunifuFlatButton1.BorderRadius = 0;
            this.bunifuFlatButton1.ButtonText = "Limpar Log";
            this.bunifuFlatButton1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bunifuFlatButton1.DisabledColor = System.Drawing.Color.Gray;
            this.bunifuFlatButton1.Iconcolor = System.Drawing.Color.Transparent;
            this.bunifuFlatButton1.Iconimage = null;
            this.bunifuFlatButton1.Iconimage_right = null;
            this.bunifuFlatButton1.Iconimage_right_Selected = null;
            this.bunifuFlatButton1.Iconimage_Selected = null;
            this.bunifuFlatButton1.IconMarginLeft = 0;
            this.bunifuFlatButton1.IconMarginRight = 0;
            this.bunifuFlatButton1.IconRightVisible = true;
            this.bunifuFlatButton1.IconRightZoom = 0D;
            this.bunifuFlatButton1.IconVisible = true;
            this.bunifuFlatButton1.IconZoom = 90D;
            this.bunifuFlatButton1.IsTab = false;
            this.bunifuFlatButton1.Location = new System.Drawing.Point(32, 422);
            this.bunifuFlatButton1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.bunifuFlatButton1.Name = "bunifuFlatButton1";
            this.bunifuFlatButton1.Normalcolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.bunifuFlatButton1.OnHovercolor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.bunifuFlatButton1.OnHoverTextColor = System.Drawing.Color.White;
            this.bunifuFlatButton1.selected = false;
            this.bunifuFlatButton1.Size = new System.Drawing.Size(106, 46);
            this.bunifuFlatButton1.TabIndex = 14;
            this.bunifuFlatButton1.Text = "Limpar Log";
            this.bunifuFlatButton1.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.bunifuFlatButton1.Textcolor = System.Drawing.Color.White;
            this.bunifuFlatButton1.TextFont = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bunifuFlatButton1.Click += new System.EventHandler(this.bunifuFlatButton1_Click_1);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(3, 181);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(111, 16);
            this.label3.TabIndex = 2;
            this.label3.Text = "Log de Operação:";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(3, 200);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(147, 215);
            this.richTextBox1.TabIndex = 1;
            this.richTextBox1.Text = "";
            // 
            // bunifuTileButton1
            // 
            this.bunifuTileButton1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.bunifuTileButton1.color = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.bunifuTileButton1.colorActive = System.Drawing.Color.FromArgb(((int)(((byte)(50)))), ((int)(((byte)(49)))), ((int)(((byte)(69)))));
            this.bunifuTileButton1.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bunifuTileButton1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F);
            this.bunifuTileButton1.ForeColor = System.Drawing.Color.White;
            this.bunifuTileButton1.Image = ((System.Drawing.Image)(resources.GetObject("bunifuTileButton1.Image")));
            this.bunifuTileButton1.ImagePosition = 20;
            this.bunifuTileButton1.ImageZoom = 50;
            this.bunifuTileButton1.LabelPosition = 41;
            this.bunifuTileButton1.LabelText = "Native PE";
            this.bunifuTileButton1.Location = new System.Drawing.Point(0, 0);
            this.bunifuTileButton1.Margin = new System.Windows.Forms.Padding(6);
            this.bunifuTileButton1.Name = "bunifuTileButton1";
            this.bunifuTileButton1.Size = new System.Drawing.Size(153, 135);
            this.bunifuTileButton1.TabIndex = 0;
            // 
            // btnSelectFile
            // 
            this.btnSelectFile.Activecolor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.btnSelectFile.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.btnSelectFile.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.btnSelectFile.BorderRadius = 0;
            this.btnSelectFile.ButtonText = "Clique para selecionar um Arquivo";
            this.btnSelectFile.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnSelectFile.DisabledColor = System.Drawing.Color.Gray;
            this.btnSelectFile.Iconcolor = System.Drawing.Color.Transparent;
            this.btnSelectFile.Iconimage = ((System.Drawing.Image)(resources.GetObject("btnSelectFile.Iconimage")));
            this.btnSelectFile.Iconimage_right = null;
            this.btnSelectFile.Iconimage_right_Selected = null;
            this.btnSelectFile.Iconimage_Selected = null;
            this.btnSelectFile.IconMarginLeft = 0;
            this.btnSelectFile.IconMarginRight = 0;
            this.btnSelectFile.IconRightVisible = true;
            this.btnSelectFile.IconRightZoom = 0D;
            this.btnSelectFile.IconVisible = true;
            this.btnSelectFile.IconZoom = 90D;
            this.btnSelectFile.IsTab = false;
            this.btnSelectFile.Location = new System.Drawing.Point(317, 127);
            this.btnSelectFile.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnSelectFile.Name = "btnSelectFile";
            this.btnSelectFile.Normalcolor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.btnSelectFile.OnHovercolor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.btnSelectFile.OnHoverTextColor = System.Drawing.Color.White;
            this.btnSelectFile.selected = false;
            this.btnSelectFile.Size = new System.Drawing.Size(317, 70);
            this.btnSelectFile.TabIndex = 4;
            this.btnSelectFile.Text = "Clique para selecionar um Arquivo";
            this.btnSelectFile.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnSelectFile.Textcolor = System.Drawing.Color.White;
            this.btnSelectFile.TextFont = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSelectFile.Click += new System.EventHandler(this.btnSelectFile_Click);
            // 
            // opCarrigirAsCaracteristicas
            // 
            this.opCarrigirAsCaracteristicas.AutoSize = true;
            this.opCarrigirAsCaracteristicas.ForeColor = System.Drawing.Color.White;
            this.opCarrigirAsCaracteristicas.Location = new System.Drawing.Point(504, 255);
            this.opCarrigirAsCaracteristicas.Name = "opCarrigirAsCaracteristicas";
            this.opCarrigirAsCaracteristicas.Size = new System.Drawing.Size(256, 20);
            this.opCarrigirAsCaracteristicas.TabIndex = 5;
            this.opCarrigirAsCaracteristicas.Text = "Corrigir as características do cabeçalho";
            this.opCarrigirAsCaracteristicas.UseVisualStyleBackColor = true;
            // 
            // opCorrigirAlinhamentosRaw
            // 
            this.opCorrigirAlinhamentosRaw.AutoSize = true;
            this.opCorrigirAlinhamentosRaw.ForeColor = System.Drawing.Color.White;
            this.opCorrigirAlinhamentosRaw.Location = new System.Drawing.Point(196, 255);
            this.opCorrigirAlinhamentosRaw.Name = "opCorrigirAlinhamentosRaw";
            this.opCorrigirAlinhamentosRaw.Size = new System.Drawing.Size(269, 20);
            this.opCorrigirAlinhamentosRaw.TabIndex = 6;
            this.opCorrigirAlinhamentosRaw.Text = "Corrigir o alinhamento do cabeçalho RAW";
            this.opCorrigirAlinhamentosRaw.UseVisualStyleBackColor = true;
            // 
            // opCorrigirTamanhoDaImagem
            // 
            this.opCorrigirTamanhoDaImagem.AutoSize = true;
            this.opCorrigirTamanhoDaImagem.ForeColor = System.Drawing.Color.White;
            this.opCorrigirTamanhoDaImagem.Location = new System.Drawing.Point(196, 281);
            this.opCorrigirTamanhoDaImagem.Name = "opCorrigirTamanhoDaImagem";
            this.opCorrigirTamanhoDaImagem.Size = new System.Drawing.Size(201, 20);
            this.opCorrigirTamanhoDaImagem.TabIndex = 7;
            this.opCorrigirTamanhoDaImagem.Text = "Corrigir o tamanho da imagem";
            this.opCorrigirTamanhoDaImagem.UseVisualStyleBackColor = true;
            // 
            // opCorrigirOptionalHeader
            // 
            this.opCorrigirOptionalHeader.AutoSize = true;
            this.opCorrigirOptionalHeader.ForeColor = System.Drawing.Color.White;
            this.opCorrigirOptionalHeader.Location = new System.Drawing.Point(504, 281);
            this.opCorrigirOptionalHeader.Name = "opCorrigirOptionalHeader";
            this.opCorrigirOptionalHeader.Size = new System.Drawing.Size(176, 20);
            this.opCorrigirOptionalHeader.TabIndex = 8;
            this.opCorrigirOptionalHeader.Text = "Corrigir o Optional Header";
            this.opCorrigirOptionalHeader.UseVisualStyleBackColor = true;
            // 
            // opCorrigiroTamanhoInitDATA
            // 
            this.opCorrigiroTamanhoInitDATA.AutoSize = true;
            this.opCorrigiroTamanhoInitDATA.ForeColor = System.Drawing.Color.White;
            this.opCorrigiroTamanhoInitDATA.Location = new System.Drawing.Point(196, 307);
            this.opCorrigiroTamanhoInitDATA.Name = "opCorrigiroTamanhoInitDATA";
            this.opCorrigiroTamanhoInitDATA.Size = new System.Drawing.Size(192, 20);
            this.opCorrigiroTamanhoInitDATA.TabIndex = 9;
            this.opCorrigiroTamanhoInitDATA.Text = "Corrigir tamanho da Init Data";
            this.opCorrigiroTamanhoInitDATA.UseVisualStyleBackColor = true;
            // 
            // opCorrigirInformacoesVersao
            // 
            this.opCorrigirInformacoesVersao.AutoSize = true;
            this.opCorrigirInformacoesVersao.ForeColor = System.Drawing.Color.White;
            this.opCorrigirInformacoesVersao.Location = new System.Drawing.Point(504, 307);
            this.opCorrigirInformacoesVersao.Name = "opCorrigirInformacoesVersao";
            this.opCorrigirInformacoesVersao.Size = new System.Drawing.Size(201, 20);
            this.opCorrigirInformacoesVersao.TabIndex = 10;
            this.opCorrigirInformacoesVersao.Text = "Corrigir informações da versão";
            this.opCorrigirInformacoesVersao.UseVisualStyleBackColor = true;
            // 
            // opCorrigirTamanhoDoHeapDaStack
            // 
            this.opCorrigirTamanhoDoHeapDaStack.AutoSize = true;
            this.opCorrigirTamanhoDoHeapDaStack.ForeColor = System.Drawing.Color.White;
            this.opCorrigirTamanhoDoHeapDaStack.Location = new System.Drawing.Point(196, 333);
            this.opCorrigirTamanhoDoHeapDaStack.Name = "opCorrigirTamanhoDoHeapDaStack";
            this.opCorrigirTamanhoDoHeapDaStack.Size = new System.Drawing.Size(237, 20);
            this.opCorrigirTamanhoDoHeapDaStack.TabIndex = 11;
            this.opCorrigirTamanhoDoHeapDaStack.Text = "Corrigir o tamanho do heap da stack";
            this.opCorrigirTamanhoDoHeapDaStack.UseVisualStyleBackColor = true;
            // 
            // opCorrigirDiretorioData
            // 
            this.opCorrigirDiretorioData.AutoSize = true;
            this.opCorrigirDiretorioData.ForeColor = System.Drawing.Color.White;
            this.opCorrigirDiretorioData.Location = new System.Drawing.Point(504, 333);
            this.opCorrigirDiretorioData.Name = "opCorrigirDiretorioData";
            this.opCorrigirDiretorioData.Size = new System.Drawing.Size(157, 20);
            this.opCorrigirDiretorioData.TabIndex = 12;
            this.opCorrigirDiretorioData.Text = "Corrigir o diretorio DAT";
            this.opCorrigirDiretorioData.UseVisualStyleBackColor = true;
            // 
            // bunifuFlatButton5
            // 
            this.bunifuFlatButton5.Activecolor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.bunifuFlatButton5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.bunifuFlatButton5.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.bunifuFlatButton5.BorderRadius = 0;
            this.bunifuFlatButton5.ButtonText = "Corrigir Arquivo";
            this.bunifuFlatButton5.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bunifuFlatButton5.DisabledColor = System.Drawing.Color.Gray;
            this.bunifuFlatButton5.Iconcolor = System.Drawing.Color.Transparent;
            this.bunifuFlatButton5.Iconimage = ((System.Drawing.Image)(resources.GetObject("bunifuFlatButton5.Iconimage")));
            this.bunifuFlatButton5.Iconimage_right = null;
            this.bunifuFlatButton5.Iconimage_right_Selected = null;
            this.bunifuFlatButton5.Iconimage_Selected = null;
            this.bunifuFlatButton5.IconMarginLeft = 0;
            this.bunifuFlatButton5.IconMarginRight = 0;
            this.bunifuFlatButton5.IconRightVisible = true;
            this.bunifuFlatButton5.IconRightZoom = 0D;
            this.bunifuFlatButton5.IconVisible = true;
            this.bunifuFlatButton5.IconZoom = 90D;
            this.bunifuFlatButton5.IsTab = false;
            this.bunifuFlatButton5.Location = new System.Drawing.Point(370, 406);
            this.bunifuFlatButton5.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.bunifuFlatButton5.Name = "bunifuFlatButton5";
            this.bunifuFlatButton5.Normalcolor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.bunifuFlatButton5.OnHovercolor = System.Drawing.Color.FromArgb(((int)(((byte)(76)))), ((int)(((byte)(75)))), ((int)(((byte)(105)))));
            this.bunifuFlatButton5.OnHoverTextColor = System.Drawing.Color.White;
            this.bunifuFlatButton5.selected = false;
            this.bunifuFlatButton5.Size = new System.Drawing.Size(196, 75);
            this.bunifuFlatButton5.TabIndex = 13;
            this.bunifuFlatButton5.Text = "Corrigir Arquivo";
            this.bunifuFlatButton5.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.bunifuFlatButton5.Textcolor = System.Drawing.Color.White;
            this.bunifuFlatButton5.TextFont = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bunifuFlatButton5.Click += new System.EventHandler(this.bunifuFlatButton5_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Arial", 6F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(317, 205);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(0, 10);
            this.label4.TabIndex = 14;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(187, 502);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(571, 16);
            this.label5.TabIndex = 15;
            this.label5.Text = "Importante: Tenha um backup do arquivo pois o mesmo será sobrescrito durante o pr" +
    "ocedimento !";
            // 
            // FormMain
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(44)))), ((int)(((byte)(43)))), ((int)(((byte)(60)))));
            this.ClientSize = new System.Drawing.Size(919, 527);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.bunifuFlatButton5);
            this.Controls.Add(this.opCorrigirDiretorioData);
            this.Controls.Add(this.opCorrigirTamanhoDoHeapDaStack);
            this.Controls.Add(this.opCorrigirInformacoesVersao);
            this.Controls.Add(this.opCorrigiroTamanhoInitDATA);
            this.Controls.Add(this.opCorrigirOptionalHeader);
            this.Controls.Add(this.opCorrigirTamanhoDaImagem);
            this.Controls.Add(this.opCorrigirAlinhamentosRaw);
            this.Controls.Add(this.opCarrigirAsCaracteristicas);
            this.Controls.Add(this.btnSelectFile);
            this.Controls.Add(this.panel4);
            this.Controls.Add(this.panel2);
            this.Controls.Add(this.panel1);
            this.Font = new System.Drawing.Font("Arial", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ForeColor = System.Drawing.Color.White;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "FormMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel2.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Bunifu.Framework.UI.BunifuElipse bunifuElipse1;
        private System.Windows.Forms.Panel panel2;
        private Bunifu.Framework.UI.BunifuFlatButton btnSair;
        private Bunifu.Framework.UI.BunifuFlatButton btnHome;
        private System.Windows.Forms.Panel detalhes;
        private System.Windows.Forms.Panel panel1;
        private Bunifu.Framework.UI.BunifuFlatButton btnAbout;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.CheckBox opCorrigirAlinhamentosRaw;
        private System.Windows.Forms.CheckBox opCarrigirAsCaracteristicas;
        private Bunifu.Framework.UI.BunifuFlatButton btnSelectFile;
        private System.Windows.Forms.CheckBox opCorrigirDiretorioData;
        private System.Windows.Forms.CheckBox opCorrigirTamanhoDoHeapDaStack;
        private System.Windows.Forms.CheckBox opCorrigirInformacoesVersao;
        private System.Windows.Forms.CheckBox opCorrigiroTamanhoInitDATA;
        private System.Windows.Forms.CheckBox opCorrigirOptionalHeader;
        private System.Windows.Forms.CheckBox opCorrigirTamanhoDaImagem;
        private Bunifu.Framework.UI.BunifuFlatButton bunifuFlatButton5;
        private System.Windows.Forms.Label label2;
        private Bunifu.Framework.UI.BunifuTileButton bunifuTileButton1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private Bunifu.Framework.UI.BunifuFlatButton bunifuFlatButton1;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
    }
}

