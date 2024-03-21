#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

int main()
{
	Node* pHead;
	Node** ppHead = &pHead;
	int code=-1;
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
		case 0:								//退出系统
			break;
		case 1:								//初始化链表
			pHead = Create();
			printf("链表初始化成功\n");
			break;
		case 2:								//插入节点
			Insert(ppHead);
			printf("插入节点成功\n");
			break;
		case 3:								//翻转链表
			Reverse(ppHead);
			printf("链表反转成功\n");
			break;
		case 4:								//打印链表
			Print(pHead);
			break;
		case 5:								//寻找中间链表
			FindMiddleNode(pHead);
			break;
		case 6:								//判断是否是循环链表
			Judge_Loop(pHead);
			break;
		case 7:								//销毁链表
			Delete(ppHead);
			printf("销毁链表成功\n");
			break;
		case 8:								//奇偶反转
			ReverseEvenList(ppHead);
			printf("奇偶反转成功\n");
			break;
		case 9:								//查询链表
			Search(pHead);
			break;
		case 10:							//构造循环链表
			Looplinklist(pHead);
			printf("构造循环链表成功\n");
			break;
		default:
			printf("功能未开发！\n");
			break;
		}

	}

}
