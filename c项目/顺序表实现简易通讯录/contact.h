#ifndef __CONTACT_H__
#define __CONTACT_H__

#define NAME_MAX 20
#define GENDER_MAX 10
#define TEL_MAX 20
#define ADDR_MAX 100

//定义联系人的数据结构
typedef struct PersonInfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoInfo;

typedef struct SeqList Contact;

//初始化通讯录
void InitContact(Contact* con);

//添加通讯录数据
void AddContact(Contact* con);
//删除通讯录数据
void DelContact(Contact* con);
//展⽰通讯录数据
void ShowContact(Contact* con);
//查找通讯录数据
void FindContact(Contact* con);
//修改通讯录数据
void ModifyContact(Contact* con);
//销毁通讯录数据
void DestroyContact(Contact* con);

#endif // __CONTACT_H__;

