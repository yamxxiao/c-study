#include"SeList.h"
#include"contact.h"

//void contact()
//{
//	Contact con;
//	InitContact(&con);
//	AddContact(&con);
//	AddContact(&con);
//	ModifyContact(&con);
//	ShowContact(&con);
//	DelContact(&con);
//	DestroyContact(&con);
//
//}

void menu()
{
	//通讯录初始化
	Contact con;
	InitContact(&con);
	int op = -1;
	
	do {
		printf("********************************\n");
		printf("*****1、添加用户 2、删除用户*****\n");
		printf("*****3、查找用户 4、修改用户*****\n");
		printf("*****5、展示用户 0、退出 *****\n");
		printf("********************************\n");
		printf("请选择您的操作：\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			FindContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		default:
			printf("通讯录退出成功\n");
			break;
		}
	} while (op != 0);
	//销毁通讯录
	DestroyContact(&con);
}

int main()
{
	/*contact();*/
	menu();

	return 0;
}