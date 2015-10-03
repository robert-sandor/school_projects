using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab1
{
    class Program
    {
        static void Main(string[] args)
        {
            App app = new App();
            app.run(args);
        }
    }

    class App
    {
        public void run (string[] args)
        {
            Console.Write("Enter a number : ");
            string input = Console.ReadLine();

            int n;
            try
            {
                n = Int32.Parse(input);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
                return;
            }

            int first, second;
            first = second = n + 1;
            while (true)
            {
                second++;
                if (isPrime(second))
                {
                    if (second - first == 2 && isPrime (first))
                    {
                        Console.WriteLine(first + " " + second);
                        return;
                    }
                    else
                    {
                        first = second;
                    }
                }
            }
        }

        public bool isPrime(int x)
        {
            if (x % 2 == 0)
            {
                return false;
            }
            for (int div = 3; div <= Math.Sqrt(x); div += 2)
            {
                if (x % div == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }
}
