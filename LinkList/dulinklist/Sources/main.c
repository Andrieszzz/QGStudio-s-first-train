#include<stdio.h>
#include<stdlib.h>
#include"dulinklist.h"
#define scanf scanf_s

int main()
{
	Node* pHead;
	Node** ppHead = &pHead;
	pHead = Create();		//初始化链表
	Print(pHead);			//打印链表
	FindMiddleNode(pHead);	//寻找中间节点
/*
	printf("下面进行反转链表的操作\n");
	Reverse(ppHead);		//反转链表
	Print(pHead);			
	printf("下面进行插入节点的操作\n");
	Insert(ppHead);			//插入节点
	Print(pHead);
	printf("下面进行删除节点的操作\n");
	Delete(ppHead);			//删除节点
	Print(pHead);
	printf("下面进行奇偶反转的操作\n");
	ReverseEvenList(ppHead);//奇偶反转
	Print(pHead);
	printf("下面进行查询链表的操作\n");
	Search(pHead);			//查询链表
	*/
	printf("下面判断链表是否成环\n");
	Judge_Loop(pHead);		//判断链表是否成环
	printf("下面让链表连成环\n");
	Looplinklist(pHead);	//构造循环链表
	printf("下面再次判断链表是否成环\n");
	Judge_Loop(pHead);		//判断链表是否成环
}


/*
int main()
{
	Node* pHead;
	Node** ppHead;
	ppHead = &pHead;
	int code = -1;
	printf("*************************************************\n");
	printf("*     1、初始化链表      *    2、插入新节点       *\n");
	printf("*     3、翻转链表        *    4、输出链表         *\n");
	printf("*     5、中间链表        *    6、判断链表是否成环  *\n");
	printf("*     7、删除节点        *    8、奇偶反转         *\n");
	printf("*     9、查询链表        *    10、构造循环链表    *\n");
	printf("*     0、退出系统        *                       *\n");
	while (1)
	{
		code = -1;
		printf("请输入对应数字：");
		scanf_s("%d", &code);
		switch (code)
		{
		case 0:
			break;
		case 1:
			pHead = Create();
			break;
		case 2:
			Insert(pHead);
			printf("插入节点成功\n");
			break;
		case 3:
			Reverse(ppHead);
			printf("链表反转成功\n");
			break;
		case 4:
			Print(pHead);
			break;
		case 5:
			FindMiddleNode(pHead);
			break;
		case 6:
			Judge_Loop(pHead);
			break;
		case 7:
			Delete(pHead);
			printf("销毁链表成功\n");
			break;
		case 8:
			ReverseEvenList(ppHead);
			printf("奇偶反转成功\n");
			break;
		case 9:
			Search(pHead);
			break;
		case 10:
			Looplinklist(pHead);
			printf("构造循环链表成功\n");
			break;
		default:
			printf("功能未开发！\n");
			break;
		}
	}
}
*/