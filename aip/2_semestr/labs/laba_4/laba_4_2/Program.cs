using System.Text;
using System.Text.RegularExpressions;

namespace laba_4_2;

class Program
{
    static void Main(string[] args)
    {
        StringBuilder st;
        bool isBreak = false;
        Regex reg = new Regex(@"#+((\w)+)#+", RegexOptions.IgnoreCase);
        while (!isBreak)
        {
            Console.WriteLine(
                "Введите строку, состоящую из слов, разделенных пробелами или пустую строчку для завершения: ");
            st = new StringBuilder(Console.ReadLine());
            foreach (Match match in reg.Matches(st.ToString()))
            {
                Console.Write($"Введите замену для '{match.Groups[1].Value}': ");
                string newWord = Console.ReadLine();
                st.Replace(match.Value, newWord);
            }

            Console.WriteLine($"Получившаяся строка: {st}");
            Console.WriteLine("Хотите ли вы продолжить? да/нет");
            string response = Console.ReadLine();
            while (response != "да" && response != "нет")
            {
                Console.WriteLine("Введите еще раз. Хотите ли вы продолжить? да/нет");
                response = Console.ReadLine();
            }

            if (response == "нет")
            {
                isBreak = true;
            }

            Console.Clear();
        }
    }
}