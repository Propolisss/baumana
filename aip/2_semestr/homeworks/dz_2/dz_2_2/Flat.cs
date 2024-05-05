namespace dz_2_2;

public class Flat
{
    private int countRooms;
    private Room[] rooms;
    private double costPerMetr;

    public Flat(int count = 0, Room[] rooms_ = null, double cost = 0.0)
    {
        countRooms = count;
        rooms = rooms_;
        costPerMetr = cost;
    }

    public void PrintInfo()
    {
        Console.WriteLine($"Количество комнат: {countRooms}, стоимость на метр: {costPerMetr}, площадь квартиры: {CalculateSquare()}, стоимость квартиры: {CalculateCost()}");
    }

    public double CalculateSquare()
    {
        double square = 0.0;
        for (int i = 0; i < rooms.Length; i++)
        {
            square += rooms[i].CalculateSquare();
        }

        return square;
    }

    public double CalculateCost()
    {
        return costPerMetr * CalculateSquare();
    }
}