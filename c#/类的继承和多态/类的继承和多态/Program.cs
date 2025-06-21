using System.Runtime.CompilerServices;

namespace 类的继承和多态
{
    class Order//基类
    {
       public string Name;
        public int Num;
      public float Price;

       public  Order(string name, int num, float price)
        {
            Name = name;
            Num = num;
            Price = price;
        }
    }

    class DiscountOrder : Order//派生类 
    {
        public float Discount=0.8f;
        public DiscountOrder(string name,int num,float price,float discount):base(name, num, price)//base()填入基类的字段
        {
            //派生类特有的初始化
            Discount = discount;
        }

    }

    class FullSubOrder : Order
    {
        public float Full;
        public float Sub;

        public FullSubOrder(string name, int num, float price, float full, float sub) : base(name, num, price)//base()填入基类的字段
        {
            //派生类特有的初始化
            Full = full;
            Sub = sub;
        }
        public float Totalprice
        {
            get
            {
                float p = Price * Num;
                if (p > Full)

                    p -= Sub;

                return p;
            }
        }
    }

        internal class Program
        {
            static void Main(string[] args)
            {
            Order o1 = new Order("西瓜",01,45);
            Order o2 = new Order("苹果", 02, 10);
            Order o3 = new Order("香蕉", 03, 12);

            Order tmp = o1=o2=o3;
                List<Order> orders = new List<Order>{o1,o2,o3};
            }
        }
}