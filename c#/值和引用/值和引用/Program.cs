namespace 值和引用
{
    internal class Program
    {
        static void Arry(int[] arry)
        {
            for(int i=0;i<arry.Length;i++)
            {
                arry[i] *= 2;
            }
        }
        static void Main(string[] args)
        {
            int[] test = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };
                Arry(test);
            int[] test2 = test;
            for(int i=0; i<test2.Length;i++)
            {
                Console.Write($"{test[i]} ");
            }
            Console.WriteLine();
        }
    }
}
