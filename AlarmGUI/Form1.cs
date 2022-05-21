using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;

namespace AlarmGUI
{
    public partial class Form1 : Form
    {
        int hour;
        int minute;
        String state;

        public Form1()
        {
            InitializeComponent();
            // this.BackColor = Color.LightPink;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            hour = Convert.ToInt32(textBox1.Text);
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            minute = Convert.ToInt32(textBox2.Text);
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            state = "AM";
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            state = "PM";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Trace.WriteLine("Hour: " + hour);
            System.Diagnostics.Trace.WriteLine("Minute: " + minute);
            System.Diagnostics.Trace.WriteLine("State: " + state);

            string path = @"C:\Users\ankur\Desktop\Alarm\AlarmCLI\info.txt";
            
            using (StreamWriter sw = File.CreateText(path)) {

                if (hour < 10) {
                    sw.Write("0" + hour);
                }
                else {
                    sw.Write(hour);
                }

                if (minute < 10) {
                    sw.Write("0" + minute);
                }
                else {
                    sw.Write(minute);
                }

                sw.Write(state);
            }

            Process proc = null;
            try {
                string batDir = string.Format(@"C:\Users\ankur\Desktop\Alarm\AlarmCLI");
                proc = new Process();
                proc.StartInfo.WorkingDirectory = batDir;
                proc.StartInfo.FileName = "run.bat";
                proc.StartInfo.CreateNoWindow = false;
                proc.Start();
                proc.WaitForExit();
            } catch (Exception ex) {
                Console.WriteLine(ex.StackTrace.ToString());
            }
        }
    }
}
