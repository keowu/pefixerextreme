using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PEFixerExtremeUI
{
    public partial class FormMain : Form
    {

        public const int WM_NCLBUTTONDOWN = 0xA1;
        public const int HT_CAPTION = 0x2;
        private String selectedFilePath = "";
        private String logPath = System.IO.Path.GetDirectoryName(Application.ExecutablePath) + "/log.txt";
        System.Media.SoundPlayer mediaPlayer;

        [DllImportAttribute("user32.dll")]
        public static extern int SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);
        [DllImportAttribute("user32.dll")]
        public static extern bool ReleaseCapture();


        [DllImport("PEFixerNativeBridge.dll", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.Cdecl)]
        public static extern void corrigirArquivoPENativo(string filePath, string logPath, bool opCarrigirAsCaracteristicas,
        bool opCorrigirAlinhamentosRaw, bool opCorrigirTamanhoDaImagem, bool opCorrigirOptionalHeader,
        bool opCorrigiroTamanhoInitDATA, bool opCorrigirInformacoesVersao, bool opCorrigirTamanhoDoHeapDaStack,
        bool opCorrigirDiretorioData, bool opisDLL);

        public FormMain()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.bunifuElipse1.ApplyElipse(panel1, 40);
            this.bunifuElipse1.ApplyElipse(panel2, 40);
            this.bunifuElipse1.ApplyElipse(panel4, 40);
            System.IO.Stream path = Properties.Resources.Editing;
            this.mediaPlayer = new System.Media.SoundPlayer(path);
            this.mediaPlayer.Play();
        }

        private void moverDetalhePanel(Control c)
        {
            detalhes.Height = c.Height;
            detalhes.Top = c.Top;
        }

        private void btnHome_Click(object sender, EventArgs e)
        {
            moverDetalhePanel(btnHome);
        }

        private void btnHelp_Click(object sender, EventArgs e)
        {
            moverDetalhePanel(btnAbout);
            MessageBox.Show("Dev by Keowu go to -> www.github.com/keowu");
            Process navegador = new Process();
            try
            {
                navegador.StartInfo.UseShellExecute = true;
                navegador.StartInfo.FileName = "http://www.github.com/keowu";
                navegador.Start();
            }
            catch (Exception) { }
        }

        private void btnSair_Click(object sender, EventArgs e)
        {
            moverDetalhePanel(btnSair);
            System.Windows.Forms.Application.Exit();
        }

        private void panel1_MouseDown(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                ReleaseCapture();
                SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
            }
        }

        private void btnSelectFile_Click(object sender, EventArgs e)
        {
            OpenFileDialog arquivoFile = new OpenFileDialog();
            arquivoFile.Filter = "EXE, DLL, COM, SYS, entre outros. (*.*)|*.*";
            arquivoFile.FilterIndex = 1;
            arquivoFile.Multiselect = false;

            if (arquivoFile.ShowDialog() == DialogResult.OK)
            {
                this.selectedFilePath = arquivoFile.FileName;
                label4.Text = "Selecionado: " + this.selectedFilePath;
            }
        }

        private void bunifuFlatButton5_Click(object sender, EventArgs e)
        {
            if (!this.selectedFilePath.Equals("")) {
                File.Delete(logPath);
                corrigirArquivoPENativo(
                    this.selectedFilePath,
                    this.logPath,
                    opCarrigirAsCaracteristicas.Checked, opCorrigirAlinhamentosRaw.Checked,
                    opCorrigirTamanhoDaImagem.Checked, opCorrigirOptionalHeader.Checked,
                    opCorrigiroTamanhoInitDATA.Checked, opCorrigirInformacoesVersao.Checked,
                    opCorrigirTamanhoDoHeapDaStack.Checked, opCorrigirDiretorioData.Checked,
                    this.selectedFilePath.Contains(".dll")
                    );
                richTextBox1.Text = File.ReadAllText(this.logPath, Encoding.GetEncoding("iso-8859-1"));
            }
            else
            {
                MessageBox.Show("Você selecionou o arquivo ? eu não estou vendo, então vai lá e seleciona um arquivo !!");
            }
        }

        private void bunifuFlatButton1_Click_1(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            File.Delete(logPath);
        }

        private void pictureBox2_Click(object sender, EventArgs e)
        {
            mediaPlayer.Stop();
        }
    }
}
