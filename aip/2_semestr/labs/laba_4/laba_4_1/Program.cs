namespace laba_4_1;

class Program
{
    static double Determinant(int m1, int m2, double[,] arr)
    {
        return (arr[0, m1] * arr[1, m2] - arr[1, m1] * arr[0, m2]);
    }

    static void Main(string[] args)
    {
        double[,] kramer = new double[2, 3];
        Console.Write("Введите коэффициенты a и b и c через пробел: ");
        string input = Console.ReadLine();
        string[] parts = input.Split(' ');
        while (!(parts.Length == 3 && double.TryParse(parts[0], out kramer[0, 0]) &&
                 double.TryParse(parts[1], out kramer[0, 1]) && double.TryParse(parts[2], out kramer[0, 2])))
        {
            Console.Write("Неккоректный ввод. Попробуйте еще раз: ");
            input = Console.ReadLine();
            parts = input.Split(' ');
        }

        Console.Write("Введите коэффициенты c и d через пробел: ");
        input = Console.ReadLine();
        parts = input.Split(' ');
        while (!(parts.Length == 3 && double.TryParse(parts[0], out kramer[1, 0]) &&
                 double.TryParse(parts[1], out kramer[1, 1]) && double.TryParse(parts[2], out kramer[1, 2])))
        {
            Console.Write("Неккоректный ввод. Попробуйте еще раз: ");
            input = Console.ReadLine();
            parts = input.Split(' ');
        }

        if (Determinant(0, 1, kramer) == 0)
        {
            Console.WriteLine("Решений нет или их бесконечное количество.");
        }
        else
        {
            Console.WriteLine($"x = {Determinant(2, 1, kramer) / Determinant(0, 1, kramer)}");
            Console.WriteLine($"y = {Determinant(0, 2, kramer) / Determinant(0, 1, kramer)}");
        }
    }
}
