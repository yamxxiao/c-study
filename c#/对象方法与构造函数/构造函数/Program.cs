namespace 构造函数
{
    internal class Program
    {
        class Character
        {
            public string name;
            public int hp;
            public int attack;
            public int def;

            public int Hp;//属性
            //public int Hp
            //{
            //    get {
            //        Console.WriteLine($"读取到HP" + hp);
            //        return hp; }
            //    set {
            //        Console.WriteLine($"获取到HP:" + value);
            //        if(hp<0)
            //        {
            //            value = 0;
            //            return;
            //        }
            //        hp = value; }
            //}
            public int Attack(Character theothers)
            {
                int damage = attack - theothers.def;
                theothers.hp -= damage;
                return damage;
            }
        }

        static void 基础对战()
        {
            Character character1 = new Character();
            character1.name = "皮卡丘";
            character1.hp = 100;
            character1.attack = 10;
            character1.def = 10;
            Console.WriteLine($"皮卡丘的生命值：{character1.hp}");

            character1.Hp = 80;
            Console.WriteLine($"皮卡丘的生命值：{character1.hp}");
            Character character2 = new Character();
            character2.name = "杰尼龟";
            character2.hp = 120;
            character2.attack = 100;
            character2.def = 5;

            PrintChar(character1);
            PrintChar(character2);

            Character vectory;
            while (true)
            {
                Console.WriteLine($"{character1.name}发起攻击");
                int demage1=character1.Attack(character2);
                int count1 = 0;
                PrintChar(character2);
                Console.WriteLine($"{character1.name}攻击后，造成{demage1}点伤害");
                if (character2.hp <= 0)
                {
                    vectory = character1;
                    count1 += demage1;
                    Console.WriteLine($"胜利者为：{vectory.name}");
                    break;
                }
                Console.WriteLine($"{character2.name}攻击");
                int count2 = 0;
                int demage2 = character2.Attack(character2);
                PrintChar(character1);
                Console.WriteLine($"{character2.name}攻击后，造成{demage2}点伤害");

                if (character1.hp <= 0)
                {
                    vectory = character2;
                    count2 += demage2;
                    Console.WriteLine($"胜利者为：{vectory.name}");
                    break;
                }
            }
        }
        static void Main(string[] args)
        {
            基础对战();
        }
       static void PrintChar(Character character)
        {
            Console.WriteLine($"------------{character.name}-----------");
            Console.WriteLine($"HP:{character.hp}     Attack:{character.attack}  Def:{character.def}");
        }
    }
}
