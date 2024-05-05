namespace rk_2;

class X
{
    protected string C;

    public X()
    {
    }

    public X(string C)
    {
        this.C = C;
    }

    virtual public void Out()
    {
        Console.WriteLine(C);
    }
}

class Y : X
{
    protected int A, B;

    public Y()
    {
    }

    public Y(string C, int A = 0, int B = 0) : base(C)
    {
        this.A = A;
        this.B = B;
    }

    public override void Out()
    {
        Console.WriteLine(C[A + B - 1]);
    }
}

class Z : Y
{
    public Z()
    {
    }

    public Z(string C, int A = 0, int B = 0) : base(C, A, B)
    {
    }

    public override void Out()
    {
        Console.WriteLine(C[9..]);
        Console.WriteLine(C[9..]);
        Console.WriteLine(C[9..]);
        Console.WriteLine(C[9..]);
        Console.WriteLine(C[9..]);
    }
}

internal class Program
{
    static void Main(string[] args)
    {
        X x = new X("Петров Иван Иванович как дела");
        Y y = new Y("Петров Иван Иванович как дела", 2, 3);
        Z z = new Z("Петров Иван Иванович как дела");
        Test(x);
        Test(y);
        Test(z);
    }

    static void Test(X x)
    {
        Console.WriteLine("==========================");
        x.Out();
        Console.WriteLine("==========================");
        Console.WriteLine();
        Console.WriteLine();
    }
}