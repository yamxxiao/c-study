namespace 静态和属性
{
    internal class Program
    {
        //static void print(List<int> list)
        //{
        //    Console.WriteLine("------------------");
        //    for (int i = 0; i < list.Count; i++)
        //    {
        //        Console.WriteLine(list[i]);
        //    }
        //}
        static void Main(string[] args)
        {
            List<string> list = new List<string>() { "王者荣耀" ,"王国之心","山丘之王"};

                for(int i=list.Count-1;i>=0;i++)
            {
                string s = list[i];
                if (s[0]=='王')
                {
                    list.RemoveAt(i);
                }
                Console.WriteLine(list[i]);
            }
            

            //List<int> list = new List<int>();
            //list.Add(1);
            //list.Add(2);
            //list.Add(3);
            //Console.WriteLine(list[0]);
            //int n = list[1];

            //list[0] = 999;
            //Console.WriteLine(list[0]);
            //list.RemoveAt(0);

            //print(list);
            //List<int> list2 = new List<int>() { 11, 12, 12, 15, 64, 33, 13, 13, 53, 54 };
            //list2.Remove(12);
            //list2.Insert(0, 10);
            //print(list2);
            //int[] temp = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            //list2.AddRange(temp);
            //Console.WriteLine("----------------");
            //int inex=list2.IndexOf(54);
            //Console.WriteLine($"元素54的下标为：{inex}");
            //print(list2);
         
        }
    }
}
