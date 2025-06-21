using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 类的组合
{
    internal class Address
    {
        public string ? Street { get; set; }
        public string ? City { get; set; }
        public string ? Country { get; set; }

        public string Info()
        {
            return $"{Country}-{City}-{Street}";
        }
    }

    class Person
    {
        public string ? Name { get; set; }
        public Address ? addr { get; set; }

        public int age { get; set; }
        public string ? Gendar { get; set; }

        public  void Print()
        {
            Console.WriteLine($"-----{Name}-----");
            Console.WriteLine($"地址：{addr.Info()} {age}岁 性别：{Gendar}");
        }

    }

}
