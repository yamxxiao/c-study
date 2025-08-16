#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
#include"SeList.h"

void LoadContact(Contact* con) {
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL) {
		perror("fopen error!\n");
		return;
	}
	//循环读取⽂件数据
	peoInfo info;
	while (fread(&info, sizeof(peoInfo), 1, pf))
	{
		SLPushBack(con, info);
	}


	printf("历史数据导⼊通讯录成功！\n");
}

void InitContact(Contact* con)
{
	SLInit(con);
}

void DestroyContact(Contact* con)
{
	SLDestroy(con);
}

void AddContact(Contact* con)
{
	peoInfo info;
	printf("请输出要添加的姓名:\n");
	scanf("%s", info.name);

	printf("请输出要添加的性别:\n");
	scanf("%s", info.gender);

	printf("请输出要添加的年龄:\n");
	scanf("%d", &info.age);

	printf("请输出要添加的电话:\n");
	scanf("%s", info.tel);

	printf("请输出要添加的地址:\n");
	scanf("%s", info.addr);

	SLPushBack(con,info);
}

int FindName(Contact* con, char name[])
{
	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->arr[i].name, name) == 0)
		{
			//找到了
			return i;
		}
	}
	//没找到
	return -1;
}
void DelContact(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名:\n");
	scanf("%s", name);

	int find = FindName(con, name);

	if (find < 0)
	{
		printf("要删除的人不存在\n");
		return;
	}

	Erase(con, find);
	printf("删除成功\n");
}

void ShowContact(Contact* con)
{
	printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("%s %s %d %s %s\n", con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].tel,
			con->arr[i].addr
		);
	}
}

void ModifyContact(Contact* con)
{
	char name[NAME_MAX];

	printf("请输入要修改的联系人姓名\n");
	scanf("%s", name);

	int find= FindName(con, name);
	if (find < 0)
	{
		printf("要修改的人不存在\n");
		return;
	}
	//直接修改
	printf("请输入要修改的姓名：\n");
	scanf("%s", &con->arr[find].name);
	printf("请输入要修改的性别：\n");
	scanf("%s", &con->arr[find].gender);
	printf("请输入要修改的年龄：\n");
	scanf("%d", &con->arr[find].age);
	printf("请输入要修改的联系电话：\n");
	scanf("%s", &con->arr[find].tel);
	printf("请输入要修改的地址：\n");
	scanf("%s", &con->arr[find].addr);
	printf("修改成功！\n");

}

void FindContact(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要查找联系人的姓名\n");
	scanf("%s",name);

	int find = FindName(con, name);

	if (find < 0)
	{
		printf("要查找的人不存在\n");
		return;

		printf("%s %s %s %s %s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%s %s %d %s %s\n", con->arr[find].name,
			con->arr[find].gender,
			con->arr[find].age,
			con->arr[find].tel,
			con->arr[find].addr
		);
	}



}