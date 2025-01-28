using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        string display = "0";
        double kotae = 0;
        private void button5_Click(object sender, EventArgs e)
        {
            //ボタン１をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "1";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }
        private void button6_Click(object sender, EventArgs e)
        {
            //ボタン２をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "2";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            //ボタン３をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "3";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            //ボタン４をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "4";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }

        private void button10_Click(object sender, EventArgs e)
        {
            //ボタン５をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "5";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }

        private void button11_Click(object sender, EventArgs e)
        {
            //ボタン６をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "6";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }

        private void button13_Click(object sender, EventArgs e)
        {
            //ボタン７をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "7";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }

        private void button14_Click(object sender, EventArgs e)
        {
            //ボタン８をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "8";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }

        private void button15_Click(object sender, EventArgs e)
        {
            //ボタン９をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "9";

            double a = double.Parse(display);
            String display2 = a.ToString();

            textBox1.Text = (display2);
        }

        private void button18_Click(object sender, EventArgs e)
        {
            //ボタン０をクリックした場合
            display = textBox1.Text.ToString();
            display = display += "0";
            textBox1.Text = (display);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //ボタンCをクリックした場合
            display = "0";
            textBox1.Text = (display);
            textBox2.Text = (" ");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //ボタンdeleteをクリックした場合
            //１文字ずつ消していく　"なくなった場合は0"
            display = textBox1.Text.ToString();
            int display_member = display.Length;
            if (display_member > 0)
            {
                string st = display;
                st = (st.Substring(0, st.Length - 1));
                display_member = st.Length;
                if (display_member > 0)
                {
                    textBox1.Text = st;
                }
                else
                {
                    textBox1.Text = ("0");
                }
            }
            else
            {
                textBox1.Text = ("0");
            }
        }

        private void button21_Click(object sender, EventArgs e)
        {
            //ボタン÷をクリックした場合
            string hantei = textBox2.Text.ToString();
            if (hantei == " ")
            {
                display = textBox1.Text.ToString();

                //数字をきれいにする
                double a = double.Parse(display);
                String display2 = a.ToString();
                double b = double.Parse(display2);
                textBox2.Text = (display2 + "÷");
                textBox1.Text = ("0");
            }
            else
            {
                //textbox1を数値として抜き取る
                string x1 = textBox1.Text.ToString();
                double xx1 = double.Parse(x1);

                //textbox2の数値だけを抜き取る
                string x2 = textBox2.Text.ToString();
                string a = x2;
                a = (a.Substring(0, a.Length - 1));
                double xx2 = double.Parse(a);

                //textbox2の計算記号を抽出
                char x3 = x2[x2.Length - 1];
                string s = x3.ToString();
                //答えの計算
                if (s == "×")
                {
                    kotae = xx2 * xx1;
                }
                else if (s == "÷")
                {
                    kotae = xx2 / xx1;
                }
                else if (s == "＋")
                {
                    kotae = xx2 + xx1;
                }
                else if (s == "－")
                {
                    kotae = xx2 - xx1;
                }

                //答えの表示
                String anser = kotae.ToString();
                textBox2.Text = (anser + "÷");
                textBox1.Text = ("0");
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            //ボタン×をクリックした場合
            string hantei = textBox2.Text.ToString();
            if (hantei == " ")
            {
                display = textBox1.Text.ToString();

                //数字をきれいにする
                double a = double.Parse(display);
                String display2 = a.ToString();
                double b = double.Parse(display2);
                textBox2.Text = (display2 + "×");
                textBox1.Text = ("0");
            }
            else
            {
                //textbox1を数値として抜き取る
                string x1 = textBox1.Text.ToString();
                double xx1 = double.Parse(x1);

                //textbox2の数値だけを抜き取る
                string x2 = textBox2.Text.ToString();
                string a = x2;
                a = (a.Substring(0, a.Length - 1));
                double xx2 = double.Parse(a);

                //textbox2の計算記号を抽出
                char x3 = x2[x2.Length - 1];
                string s = x3.ToString();
                //答えの計算
                if (s == "×")
                {
                    kotae = xx2 * xx1;
                }
                else if (s == "÷")
                {
                    kotae = xx2 / xx1;
                }
                else if (s == "＋")
                {
                    kotae = xx2 + xx1;
                }
                else if (s == "－")
                {
                    kotae = xx2 - xx1;
                }

                //答えの表示
                String anser = kotae.ToString();
                textBox2.Text = (anser + "×");
                textBox1.Text = ("0");
            }
        }

        private void button12_Click(object sender, EventArgs e)
        {
            //ボタン－をクリックした場合
            string hantei = textBox2.Text.ToString();
            if (hantei == " ")
            {
                display = textBox1.Text.ToString();

                //数字をきれいにする
                double a = double.Parse(display);
                String display2 = a.ToString();
                double b = double.Parse(display2);
                textBox2.Text = (display2 + "－");
                textBox1.Text = ("0");
            }
            else
            {
                //textbox1を数値として抜き取る
                string x1 = textBox1.Text.ToString();
                double xx1 = double.Parse(x1);

                //textbox2の数値だけを抜き取る
                string x2 = textBox2.Text.ToString();
                string a = x2;
                a = (a.Substring(0, a.Length - 1));
                double xx2 = double.Parse(a);

                //textbox2の計算記号を抽出
                char x3 = x2[x2.Length - 1];
                string s = x3.ToString();
                //答えの計算
                if (s == "×")
                {
                    kotae = xx2 * xx1;
                }
                else if (s == "÷")
                {
                    kotae = xx2 / xx1;
                }
                else if (s == "＋")
                {
                    kotae = xx2 + xx1;
                }
                else if (s == "－")
                {
                    kotae = xx2 - xx1;
                }

                //答えの表示
                String anser = kotae.ToString();
                textBox2.Text = (anser + "－");
                textBox1.Text = ("0");
            }
        }

        private void button16_Click(object sender, EventArgs e)
        {
            //ボタン＋をクリックした場合
            string hantei = textBox2.Text.ToString();
            if (hantei == " ")
            {
                display = textBox1.Text.ToString();

                //数字をきれいにする
                double a = double.Parse(display);
                String display2 = a.ToString();
                double b = double.Parse(display2);
                textBox2.Text = (display2 + "＋");
                textBox1.Text = ("0");
            }
            else
            {
                //textbox1を数値として抜き取る
                string x1 = textBox1.Text.ToString();
                double xx1 = double.Parse(x1);

                //textbox2の数値だけを抜き取る
                string x2 = textBox2.Text.ToString();
                string a = x2;
                a = (a.Substring(0, a.Length - 1));
                double xx2 = double.Parse(a);

                //textbox2の計算記号を抽出
                char x3 = x2[x2.Length - 1];
                string s = x3.ToString();
                //答えの計算
                if (s == "×")
                {
                    kotae = xx2 * xx1;
                }
                else if (s == "÷")
                {
                    kotae = xx2 / xx1;
                }
                else if (s == "＋")
                {
                    kotae = xx2 + xx1;
                }
                else if (s == "－")
                {
                    kotae = xx2 - xx1;
                }

                //答えの表示
                String anser = kotae.ToString();
                textBox2.Text = (anser + "＋");
                textBox1.Text = ("0");
            }
        }

        private void button20_Click(object sender, EventArgs e)
        {
            //ボタン＝をクリックした場合
            //textbox1を数値として抜き取る
            string x1 = textBox1.Text.ToString();
            double xx1 = double.Parse(x1);

            //textbox2の数値だけを抜き取る
            string x2 = textBox2.Text.ToString();
            string a = x2;
            a = (a.Substring(0, a.Length - 1));
            double xx2 = double.Parse(a);

            //textbox2の計算記号を抽出
            char x3 = x2[x2.Length - 1];
            string s = x3.ToString();
            //答えの計算
            if (s =="×"){
                kotae = xx2 * xx1;
            }
            else if(s == "÷")
            {
                kotae = xx2 / xx1;
            }
            else if (s == "＋")
            {
                kotae = xx2 + xx1;
            }
            else if (s == "－")
            {
                kotae = xx2 - xx1;
            }

            //答えの表示
            String anser = kotae.ToString();
            textBox2.Text = (anser);
            textBox1.Text = ("0");
        }

        private void button17_Click(object sender, EventArgs e)
        {
            //ボタン+/-をクリックした場合
            string display = textBox1.Text.ToString();
            double a = double.Parse(display);
            a = -a;
            display = a.ToString();
            textBox1.Text = (display);
        }

        private void button19_Click(object sender, EventArgs e)
        {
            //ボタン.をクリックした場合
            display = textBox1.Text.ToString();
            double a = double.Parse(display);
            if (a == (int)a)
            {
                display = display += ".";
                textBox1.Text = (display);
            }
        }
    }
}
