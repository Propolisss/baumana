namespace dz_2;

public class RaceCar : Car
{
   private double[,] races;

   public RaceCar(string model_ = "", double speed_ = 0.0, double fuelPerKil_ = 0.0, double[,] races_ = null) : base(model_,
      speed_, fuelPerKil_)
   {
      races = races_;
   }

   public override void PrintInfo()
   {
        Console.Write($"Марка автомобиля: {model}, максимальная скорость: {speed}, расход топлива: {fuelPerKil}, ");
        Console.WriteLine($"1) {races[0, 0]} : {races[0, 1]}, 2) {races[1, 0]} : {races[1, 1]}, 3) {races[2, 0]} : {races[2, 1]}");
   }

   public bool IsReachMaxSpeed()
   {
      bool flag = false;
      for (int i = 0; i < 3; i++)
      {
         if (races[i, 1] / speed <= races[i, 0])
         {
            flag = true;
         }
      }

      return flag;
   }
}