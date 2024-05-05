namespace dz_2_2;

public class Room
{
    private double length;
    private double width;

    public Room(double length_ = 0.0, double width_ = 0.0)
    {
        length = length_;
        width = width_;
    }

    public void PrintInfo()
    {
        Console.WriteLine($"Длина комнаты: {length}, ширина комнаты: {width}");
    }

    public double CalculateSquare()
    {
        return width * length;
    }
}