using System.Runtime.InteropServices.Marshalling;

namespace 类和对象
{
    class Student {
     public string name;
     public int score;
     public int age;
    };

    internal class Program
    {
        static void StudentPrint(Student Student)
        {
            Console.WriteLine($"学生姓名：{Student.name},学生年龄：{Student.age},学生成绩：{Student.score}");
        }
        static void Main(string[] args)
        {
            Student std1 = new Student();
            Student std2 = new Student();
            Student std3 = new Student();

            std1.name = "夜鹿";
            std1.score = 100;
            std1.age = 9;

            std2.name = "真夜中";
            std2.score = 90;
            std2.age = 8;

            std3.name = "夜游";
            std3.score = 80;
            std3.age = 8;

            Student[] student = new Student[3] { std1, std2, std3 };
            StudentPrint(std1);
            StudentPrint(std2);
            StudentPrint(std3);
        }
    }
}
