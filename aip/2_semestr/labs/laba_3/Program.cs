namespace laba_3;

class Program
{
    static void Main(string[] args)
    {
        bool isBreak = false;
        while (!isBreak)
        {
            double a, b, c;
            bool flagA, flagB, flagC;
            Console.Write("Введите через пробел 3 числа: ");
            string st = Console.ReadLine();

            try
            {
                if (st.Split(' ').Length != 3)
                {
                    var err = new Exception("Вы ввели не 3 числа. Попробуйте заново.");
                    throw err;
                }

                flagA = double.TryParse(st.Split(' ')[0], out a);
                flagB = double.TryParse(st.Split(' ')[1], out b);
                flagC = double.TryParse(st.Split(' ')[2], out c);
                if (!flagA || !flagB || !flagC)
                {
                    var err = new Exception("Вы ввели не числа. Попробуйте заново");
                    throw err;
                }

                if (Math.Abs(a) < double.Epsilon)
                {
                    if (Math.Abs(b) < double.Epsilon)
                    {
                        if (Math.Abs(c) < double.Epsilon)
                        {
                            Console.WriteLine("Уравнение имеет бесконечное количество решений.");
                        }
                        else
                        {
                            Console.WriteLine("Уравнение не имеет корней.");
                        }
                    }
                    else
                    {
                        Console.WriteLine($"корень уравнения: {-c / b}");
                    }
                }
                else
                {
                    double discriminant = b * b - 4 * a * c;

                    if (discriminant < 0)
                    {
                        Console.WriteLine("Уравнение не имеет корней.");
                    }
                    else if (Math.Abs(discriminant) < double.Epsilon)
                    {
                        Console.WriteLine($"Уравнение имеет один корень: {-b / (2 * a)}");
                    }
                    else
                    {
                        double x1 = (-b - Math.Sqrt(discriminant)) / (2 * a);
                        double x2 = (-b + Math.Sqrt(discriminant)) / (2 * a);
                        Console.WriteLine($"Первый корень уравнения: {x1}, второй корень уравнения: {x2}");
                    }
                }

                Console.WriteLine("Желаете ли вы закончить? да/нет");
                string response = Console.ReadLine();
                if (response.ToLower() == "да")
                {
                    isBreak = true;
                }

                Console.Clear();
            }
            catch (Exception err)
            {
                Console.WriteLine(err.Message);
            }
        }
    }
}