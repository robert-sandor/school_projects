// 4. Determina numerele prime p1 si p2 gemene imediat superioare numarului natural nenul n dat. Doua numere prime p si q sunt gemene  daca q-p = 2.

using System;

namespace Lab1
{
	internal class Program
	{
		private static void Main(string[] args)
		{
			var app = new App();
			app.run(args);
		}
	}

	internal class App
	{
		/// <summary>
		///   Runs the program
		/// </summary>
		/// <param name="args">Arguments passed through the console</param>
		public void run(string[] args)
		{
			Console.Write("Enter a number : ");
			var input = Console.ReadLine();

			int n;
			try
			{
				n = int.Parse(input);
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
					if (second - first == 2 && isPrime(first))
					{
						Console.WriteLine(first + " " + second);
						return;
					}
					first = second;
				}
			}
		}

		/// <summary>
		///   Check is an integer is prime
		/// </summary>
		/// <param name="x">The integer to be checked</param>
		/// <returns>true - if the number is prime, false otherwise</returns>
		public bool isPrime(int x)
		{
			if (x <= 1)
			{
				return false;
			}
			if (x%2 == 0)
			{
				return false;
			}
			for (var div = 3; div <= Math.Sqrt(x); div += 2)
			{
				if (x%div == 0)
				{
					return false;
				}
			}
			return true;
		}
	}
}