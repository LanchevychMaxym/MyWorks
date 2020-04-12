using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Solution
{
    public static class SimpleAssembler
    {
        public static Dictionary<string, int> Interpret(string[] program)
        {
            Dictionary<string, int> res = new Dictionary<string, int>();
            int count = program.Length;
            
            for (int i = 0; i < count; i++)
            {
                string[] command = program[i].Split(' ');
                if (command[0] == "mov")
                {
                    if (!res.ContainsKey(command[1]))
                        res[command[1]]=Int32.TryParse(command[2], out int a) ? Convert.ToInt32(command[2]) : res[command[2]];
                }
                else if (command[0] == "inc")
                    res[command[1]]++;
                else if (command[0] == "dec")
                    res[command[1]]--;
                else if (command[0] == "jnz")
                {
                    if (int.TryParse(command[1], out int a) && a != 0 || res.ContainsKey(command[1]) && res[command[1]] != 0)
                    {
                        i += Convert.ToInt32(command[2]) - 1;
                          
                    }
                  
                }

            }
            return res;
        }
    }
  
}
