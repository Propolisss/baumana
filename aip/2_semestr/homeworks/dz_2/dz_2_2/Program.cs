namespace dz_2_2;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Введите количество комнат: ");
        int count = Convert.ToInt32(Console.ReadLine());
        Room[] rooms = new Room[count];
        for (int i = 0; i < count; i++)
        {
            Console.Write($"Введите длину и ширину {i + 1} комнаты через пробел: ");
            var temp = Console.ReadLine().Split(' ');
            rooms[i] = new Room(int.Parse(temp[0]), int.Parse(temp[1]));
        }
        Console.Write("Введите стоимость одного квадратного метра: ");
        var cost = double.Parse(Console.ReadLine());
        Flat flat = new Flat(count, rooms, cost);
        flat.PrintInfo();
    }
}