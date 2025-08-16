#include"LIstNode.h"

int main()
{
	//STLNode* Node1 = (STLNode*)malloc(sizeof(STLNode));
	//STLNode* Node2 = (STLNode*)malloc(sizeof(STLNode));
	//STLNode* Node3 = (STLNode*)malloc(sizeof(STLNode));
	//STLNode* Node4 = (STLNode*)malloc(sizeof(STLNode));

	//Node1->data = 1;
	//Node2->data = 2;
	//Node3->data = 3;
	//Node4->data = 4;

	//Node1->next = Node2;
	//Node2->next = Node3;
	//Node3->next = Node4;
	//Node4->next = NULL;

	/*STLNode* Node5=NULL;
	Push_Back(&Node5,5);
	Print(Node5);*/

	STLNode* node5=NULL;
	Push_Front(&node5, 1);
	Push_Front(&node5, 2);
	Push_Front(&node5, 3);
	Push_Front(&node5, 4);
	Push_Front(&node5, 5);
	Push_Front(&node5, 6);
	Pop_Back(&node5);
	Print(node5);
	Pop_Front(&node5);
	Print(node5);

	return 0;
}