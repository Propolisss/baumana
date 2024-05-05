namespace dz_2;

public class Car
{
    protected string model;
    protected double speed;
    protected double fuelPerKil;
    
    public Car(string model_ = "", double speed_ = 0.0, double fuelPerKil_ = 0.0)
    {
        model = model_;
        speed = speed_;
        fuelPerKil = fuelPerKil_;
    }

    virtual public void PrintInfo()
    {
        Console.WriteLine($"Марка автомобиля: {model}, максимальная скорость: {speed}, расход топлива: {fuelPerKil}");
    }

    public double CalculateVolume(double kilometers)
    {
        return kilometers * fuelPerKil;
    }
}