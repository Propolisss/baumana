namespace dz_2;

class Program
{
    static void Main(string[] args)
    {
        string mark;
        double speed, fuel;
        double[,] races = new double[3, 2];
        Console.Write("Введите марку автомобиля: ");
        mark = Console.ReadLine();

        Console.Write("Введите максимальную скорость автомобиля: ");
        speed = Convert.ToDouble(Console.ReadLine());

        Console.Write("Введите расход топлива на километр автомобиля: ");
        fuel = Convert.ToDouble(Console.ReadLine()); 

        Console.Write("Введите время первого заезда и длину трассы через пробел: ");
        var temp = Console.ReadLine().Split(' ');
        races[0, 0] = Convert.ToDouble(temp[0]);
        races[0, 1] = Convert.ToDouble(temp[1]);

        Console.Write("Введите время второго заезда и длину трассы через пробел: ");
        temp = Console.ReadLine().Split(' ');
        races[1, 0] = Convert.ToDouble(temp[0]);
        races[1, 1] = Convert.ToDouble(temp[1]);

        Console.Write("Введите время третьего заезда и длину трассы через пробел: ");
        temp = Console.ReadLine().Split(' ');
        races[2, 0] = Convert.ToDouble(temp[0]);
        races[2, 1] = Convert.ToDouble(temp[1]);
        RaceCar car = new RaceCar(mark, speed, fuel, races);
        car.PrintInfo();
        double kilo;
        Console.Write("Введите километраж трассы: ");
        kilo = Convert.ToDouble(Console.ReadLine());
        Console.WriteLine($"Столько литров топлива понадобится для этой трассы: {car.CalculateVolume(kilo)}");
        if (car.IsReachMaxSpeed())
        {
            Console.WriteLine("Машина достигала своей максимальной скорости на последних трех заездах");
        }
        else
        {
            Console.WriteLine("Машина не достигала своей максимальной скорости на последних трех заездах");
        }
    }
}