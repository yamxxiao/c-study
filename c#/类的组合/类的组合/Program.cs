namespace 类的组合
{
    class Engine
    {
        private string model = "1.5L";

        public void Start()
        {
            Console.WriteLine($"{model}引擎启动");

        }
    }

    class Wheel
    {
        public float radius;

    }

    class Car
    {
        public Engine engine;
        public Wheel[] wheel;

        public Car()
        {
            engine = new Engine();
            wheel = new Wheel[4];
            for(int i=0;i<wheel.Length;i++)
            {
                wheel[i] = new Wheel();
                wheel[i].radius = 0.5f;
            }

        }

        public void StartCar()
        {
            engine.Start();
            Console.WriteLine("汽车启动");

        }
    }

    internal class Program
    {
        static void TestCar()
        {
            Car car = new Car();
            car.StartCar();
        }
        static void TestAddress()
        {
            Address addr = new Address
            {
                Street = "健康路",
                City="武汉",
                Country="中国",
            };
            Person uncleWang = new Person { Name="王大爷",addr=addr,age=76,Gendar="男" };
            uncleWang.Print();
        }
        static void Main(string[] args)
        {
            //TestCar();
            TestAddress();
        }
    }
}
