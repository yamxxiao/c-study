namespace 可空类型与编程规范
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string? input = Console.ReadLine();
            if(input!=null)
            {
                Console.WriteLine("你好" + input);
            }
            //null不等于0

        }
    }
}
