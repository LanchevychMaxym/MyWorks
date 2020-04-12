using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;


namespace Turing_Machine
{
    class Turing
    {
        struct pair //структура для зберігання пари з S і-того(елемента стрінга) та номеру стану в якому перебуваємо
        {
            public string s { get; set; }
            public int q { get; set; }


        }
        struct Command //структура для зручного зберігання команд, які будуть застосовуватися до стрінги, кожна команда містить пари З(тобто те, з чого замінятиму) та До(те,на що замінятиму), а також напрямок у якому рухатиметься головка після застосування змін до стрінги
        {
            public pair from;
            public pair to;
            public string newForward;
            public Command(string s,int q, string newS, int newQ,string newF)
            {
                from = new pair();
                from.q = q;
                from.s = s;
                to = new pair();
                to.q = newQ;
                to.s = newS;
                newForward = newF;
            }
        }

        private static void CheckComm(ref string str,Command c,ref int i,ref int state)//в даній ф-ї я застосовую команду до стрінги, тобто заміняю той символ на якому перебуває головка згідно правила
        {
            if (str.IndexOf('_') != 0)// в цьому іф-елсі передбачаю те, що після деяких замін стрінг буде без пустого символу, який позначив як '_'
            {
                str = "_" + str;
                i++;
            }
            else if (str.LastIndexOf('_') != str.Length - 1)
                str += "_";
            Console.Write($"i:{i} -- {str} -> ");//виводжу і(щоб наглядно було видно напрям в якому рухаємося) та стрічку до змін
            str = str.Remove(i,1);
            str = str.Insert(i, c.to.s);
            state = c.to.q;

            if (c.newForward == "R") //тут змінюю ітерацію відносно того в якому напрямку рухається головка
                i += 1;
            else if (c.newForward == "L")
                i -= 1;
            if (state == -1)//якщо стан -1, то головка припине рухатись, тобто це заключний стан
                i = -1;
            Console.WriteLine($"{str}");//стрічка після змін
        }

        private static void Calculate(ref string str,List<Command> commands) //дана ф-я застосовує наші правила до стрінги, це по суті наша головка, яка проходиться по стрічці
        {
            str = "_" + str + "_";//добавляю пусті символи до стрічки
            int i = 1;
            int state = 0;
            while (i >= 0)
            {
                for (int j = 0; j < commands.Count; j++)
                {
                    if (commands[j].from.s == str[i].ToString() && commands[j].from.q == state) // головка рухається по стрічці і для кожного символа на якому вона стоїть ми шукаємо в циклі відповідну команду(відповідно до того на якому символі стоїть головка та її стану)
                    {
                        CheckComm(ref str, commands[j], ref i, ref state); // і якщо ці умови задовільняться то я викликаю дня стрічки і даної команди дану ф-ю
                        break;
                    }
                }


            }
        }
        public static string AddInUnary(string str) //для кожного завдання написав ф-ю у якій вже готовий набір правил і я просто викликаю вище зазначену ф-ю для введеної стрічки(проходжусь по ній згідно команд)
        {                                          // це ф-я додавання в унарній системі числення, причому є закоментована система команд, яка коротша, але залишив другу, так як вона виконує всі дії згідно того алгоритму, який подано в книзі
            //List<Command> commands = new List<Command>() { new Command("1",0,"1",0,"R"),new Command("*",0,"1",1,"R"), new Command("1", 1, "1", 1, "R"), new Command("_",1,"_",2,"L"), new Command("1", 2, "_", -1, "N") };//-1 - заключний стан, N - на місці
            List<Command> commands = new List<Command>() { new Command("1", 0, "_", 1, "R"),
                                                           new Command("1", 1, "1", 1, "R"),
                                                           new Command("*", 1, "*", 1, "R"),
                                                           new Command("_", 1, "1", 2, "L"),
                                                           new Command("1", 2, "1", 2, "L"),
                                                           new Command("*", 2, "*", 2, "L"),
                                                           new Command("_", 2, "_", 0, "R"),
                                                           new Command("*", 0, "_", -1, "N")};//-1 - заключний стан, N - на місці
            Calculate(ref str, commands);
            return str;
        }
        public static string SubstractInUnary(string str)    //віднімання в унарній системі
                                                             //віднімаю праву частину від лівої
        {
            List<Command> commands = new List<Command>() { new Command("1", 0, "1", 0, "R"),
                                                           new Command("*", 0, "*", 0, "R"),
                                                           new Command("_", 0, "_", 1, "L"),
                                                           new Command("1", 1, "_", 2, "L"),
                                                           new Command("1", 2, "1", 2, "L"),
                                                           new Command("*", 2, "*", 2, "L"),
                                                           new Command("_", 2, "_", 3, "R"),
                                                           new Command("1", 3, "_", 0, "R"),
                                                           new Command("*", 1, "_", -1, "N")};
            Calculate(ref str, commands);
            return str;
        }
        public static string MultiplyInUnary(string str)//множення в унарній
        {
            List<Command> commands = new List<Command>() {new Command("1", 0, "1", 0, "R"), new Command("*", 0, "*", 0, "R"),new Command("_", 0, "=", 1, "L"),new Command("1", 1, "1", 1, "L"),
                        new Command("*", 1, "*", 1, "L"),new Command("_", 1, "_", 2, "R"),new Command("1", 2, "_", 3, "R"),new Command("1", 3, "1", 3, "R"),
                        new Command("*", 3, "*", 3, "R"),new Command("=", 3, "=", 4, "L"),new  Command("0", 4, "0", 4, "L"),new Command("1", 4, "0", 5, "R"),new  Command("0", 5, "0", 5, "R"),
                        new Command("=", 5, "=", 5, "R"),new Command("1", 5, "1", 5, "R"),new Command("_", 5, "1", 6, "L"),new Command("1", 6, "1", 6, "L"),new  Command("=", 6, "=", 4, "L"),
                        new Command("*", 4, "*", 7, "R"),new Command("0", 7, "1", 7, "R"),new Command("=", 7, "=", 1, "L"),new Command("*", 2, "_", 8, "R"),new Command("1", 8, "1", 8, "R"),
                        new Command("*", 8, "*", 8, "R"),new Command("=", 8, "_", 9, "L"),new Command("1", 9, "_", 9, "L"),new Command("*", 9, "_", 9, "L"),new Command("0", 9, "_", 9, "L"),
                        new Command("_", 9, "_", 9, "L")};
            Calculate(ref str, commands);
            return str;
        }

        public static string AddInBinary(string str)//додавання в бінарній
        {
            List<Command> commands = new List<Command>() {new Command("0", 0, "0", 0, "R"),new Command("1", 0, "1", 0, "R"),new Command("*", 0, "*", 0, "R"),new Command("_", 0, "_", 1, "L"),
                         new Command("0", 1, "1", 1, "L"),new Command("1", 1, "0", 2, "L"),new Command("*", 1, "_", 5, "R"),new Command("0", 2, "0", 2, "L"),
                        new Command("1", 2, "1", 2, "L"),new Command("*", 2, "*", 3, "L"),new Command("0", 2, "0", 2, "L"),new Command("0", 3, "1", 4, "R"),
                         new Command("1", 3, "0", 3, "L"),new Command("_", 3, "1", 4, "R"),new  Command("0", 4, "0", 4, "R"),new Command("1", 4, "1", 4, "R"),
                         new Command("*", 4, "*", 4, "R"),new Command("_", 4, "_", 1, "L"), new Command("1", 5, "_", 5, "R"),new Command("_", 5, "_", -1, "N")};//-1 - заключний стан, N - на місці
            Calculate(ref str, commands);
            return str;
        }

        public static string ConvertFromUnaryToBinary(string str)//переводить унарний запис числа в десятковий
        {
//          
            List<Command> commands = new List<Command>() {new Command("|", 0, "|", 0, "R"),new Command("1", 0, "1", 0, "R"),new Command("2", 0, "2", 0, "R"),new Command("3", 0, "3", 0, "R"),new Command("4", 0, "4", 0, "R"),
                                  new Command("5", 0, "5", 0, "R"),new Command("6", 0, "6", 0, "R"), new Command("7", 0, "7", 0, "R"),new Command("_", 0, "_", 1, "L"),
                                 new  Command("8", 0, "8", 0, "R"),new Command("9", 0, "9", 0, "R"),new Command("0", 0, "0", 0, "R") ,new Command("|", 1, "_", 2, "L"),new Command("1", 1, "1", -1, "N"),
                                  new Command("|", 2, "|", 2, "L"),new Command("1", 2, "2", 0, "R"),new Command("2", 2, "3", 0, "R"),new Command("3", 2, "4", 0, "R"),new Command("4", 2, "5", 0, "R"),
                                new   Command("5", 2, "6", 0, "R"),new Command("6", 2, "7", 0, "R"),new Command("7", 2, "8", 0, "R"),new Command("8", 2, "9", 0, "R"),
                                 new  Command("9", 2, "0", 2, "L"),new  Command("0", 2, "1", 0, "R"),new Command("_", 2, "_", 3, "R"),new Command("|", 3, "2", 0, "R"),
                                  new  Command("_", 3, "1", 0, "R"),new Command("0", 3, "0", 4, "L"),new Command("_", 4, "1", 0, "R"),new Command("1", 1, "1", -1, "N"),new Command("2", 1, "2", -1, "N"),
                                  new  Command("3", 1, "3", -1, "N"),new Command("4", 1, "4", -1, "N"),new Command("5", 1, "5", -1, "N"), new Command("6", 1, "6", -1, "N"),new Command("7", 1, "7", -1, "N"),
                                  new  Command("8", 1, "8", -1, "N"),new Command("9", 1, "9", -1, "N"),new Command("0", 1, "0", -1, "N")};
            Console.WriteLine(str.Length); //виводжу довжину стрінги до змін, для того щоб порівняти з результатом роботи машини
            Calculate(ref str, commands);
         
            return str;
        }

    }


    class Program
    {
        public static void ToCompare(int k)//ф-я для перевірки часу виконання останнього завдання
        {
            int g = 0;
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < k; j++)
                {
                    Console.Write(g);
                    if (j%2==0)
                    {
                        g++;
                    }
                }
            }
            Console.WriteLine();

        }
        static void Main(string[] args)
        {
            Console.WriteLine(Turing.AddInUnary("111*1111"));
            Console.WriteLine(Turing.AddInBinary("010*101"));
            Console.WriteLine(Turing.SubstractInUnary("11111*1111"));
            Console.WriteLine(Turing.MultiplyInUnary("11*111"));
            string bin = "|||||||||||||||||||||||";
            var watch = Stopwatch.StartNew();
            Console.WriteLine(Turing.ConvertFromUnaryToBinary(bin));
            watch.Stop();

            var watch2 = Stopwatch.StartNew();
            ToCompare(bin.Length);
            watch2.Stop();
            Console.WriteLine($"Execution time of ConvertFromUnaryToBinary - {watch.ElapsedMilliseconds} ms; Function ToCompare - {watch2.ElapsedMilliseconds} ms;\nRelation: {watch.ElapsedMilliseconds/watch2.ElapsedMilliseconds}"); //можна побачити відношення виконання останнього завдання до ф-ї зі складністю n^2
            Console.ReadLine();                                                                                                                                                                                                          //Отже загальна складність виконання переводу числа з унарної системи в десяткову з допомогою машини Тюрінга О(k*n^2), де k- к-сть команд, а n-довжина стрічки
        }
    }
}
