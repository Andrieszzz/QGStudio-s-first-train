#include<stdio.h>
#include<stdlib.h>
#include"dulinklist.h"
//创建链表
Node* Create(void)
{
	int number,i;
	Node* pHead, * pEnd, * pNew;
	pHead = NULL;
	pEnd = NULL;
	printf("请输入您想要创建的节点个数：");
	scanf_s("%d", &number);
	for (i = 0; i < number; i++)
	{
		pNew = (Node*)malloc( sizeof(Node) );
		printf("请输入第%d个节点的数据:\n",i+1);
		scanf_s("%d", &pNew->data);
		if (i == 0)
		{
			pNew->pNext = NULL;
			pNew->pFront = NULL;
			pHead = pNew;
			pEnd = pNew;
		}
		else
		{
			pEnd->pNext = pNew;
			pNew->pNext = NULL;
			pNew->pFront = pEnd;
			pEnd = pNew;
		}
	}
	printf("链表初始化完成！\n");
	return pHead;
}
//打印链表
void Print(struct Node* pHead)
{
	if (pHead == NULL)
	{
		printf("链表不存在\n");
	}
	else
	{
		struct Node* pTemp;							//定义临时指针 
		pTemp = pHead;								//将头节点的地址给临时指针 
		printf("链表为：\n");
		while (pTemp != NULL)						//当临时指针不为NULL时，执行循环里的操作 
		{
			printf("%d", pTemp->data);				//输出临时指针的节点元素 
			if (pTemp->pNext != NULL)				//装饰用// 
				printf("->");						//      // 
			pTemp = pTemp->pNext;					//临时指针指向下一节点// 
		}
		printf("\n");
	}
}
//插入操作
void Insert(struct Node** ppHead)
{
	struct Node* pTemp;
	struct Node* pBefore = NULL;
	struct Node* pNew;
	pNew = (struct Node*)malloc(sizeof(struct Node));	//给新节点分配内存 
	pTemp = *ppHead;										//获取头节点地址 
	int location;										//记录节点位置 
	int cnt = 0;										//计数// 
	printf("输入插入数据的前一个数据的位置：");			//提示语句//
	scanf_s("%d", &location); 							//		  //
	printf("请输入插入的数据：");							//        // 
	scanf_s("%d", &pNew->data);							//提示语句// 
	printf("\n");
	if (location == 0)
	{
		(*ppHead)->pFront = pNew;
		pNew->pNext = *ppHead;
		pNew->pFront = NULL;

		*ppHead = pNew;
	}
	else
	{
		while (pTemp != NULL)								//循环//  
		{
			cnt++;											//计数自增// 
			//	printf("第%d个数据为：%d\n",cnt,pTemp->data);	//调试语句// 
			pBefore = pTemp;								//将该节点的指针记录下来// 
			pTemp = pTemp->pNext;							//调到下一节点// 
			if (cnt == location)							//如果cnt等于位置，跳出循环// 
				break;
		}
		pBefore->pNext = pNew;							//调整pNew和pBefore之间的链接// 
		pNew->pFront = pBefore;
		pNew->pNext = pTemp;							//调整pNew和pTemp之间的链接
		pTemp->pFront = pNew;
	}											 
}
//删除节点操作			//free函数没有解决问题，删除节点会释放不了内存
void Delete(struct Node** ppHead)
{
	struct Node* pTemp;
	pTemp = *ppHead;
	struct Node* pBefore = (*ppHead)->pFront;
	struct Node* pBehind = (*ppHead)->pNext;
	int location;
	printf("请输入删除数据的位置：");
	scanf_s("%d", &location);
	printf("\n");
	int cnt = 0;
	if (location == 1)
	{
		*ppHead = (*ppHead)->pNext;
		(*ppHead)->pFront = NULL;
		free(pTemp);
	}
	else
	{
		for (cnt = 1; cnt < location; cnt++)			//location输入3，pBefore为第二个数据，pTemp为第三个数据 
		{												//移动到目标节点
			pBefore = pTemp;
			pTemp = pTemp->pNext;
			pBehind = pTemp->pNext;
		}								//此时pTemp是目标节点，pBefore是目标节点的前一节点
		pBefore->pNext = pBehind;		//调整链接
		pBehind->pFront = pBefore;
		free(pTemp);
	}
}
//反转操作
void Reverse(struct Node** ppHead)			//这里要传入一个二级指针，因为此函数要改变pHead的指向
{
	struct Node* pTemp, * pNext;
	pTemp = *ppHead;
	pNext = pTemp->pNext;
	while (pNext != NULL)
	{
		pTemp->pNext = pNext->pNext;
		pTemp->pFront = pNext;
		pNext->pNext = *ppHead;
		pNext->pFront = NULL;
		*ppHead = pNext;
		pNext = pTemp->pNext;
	}
}
//找到中间节点
void FindMiddleNode(struct Node* pHead)
{
	struct Node* pTemp;
	struct Node* pSlow, * pFast;			//pSlow是慢指针，一次走一个节点,pFast是快指针，一次走两个节点，当pFast走到头时，pSlow就是中间节点
	pTemp = pHead;							//初始化指针
	pSlow = pHead;
	pFast = pHead;
	while (1)
	{
		if (pFast == NULL || pFast->pNext == NULL)//当pFast或pFast->pNext为NULL时，退出循环
			break;
		pSlow = pSlow->pNext;
		pFast = pFast->pNext->pNext;
	}
	printf("中间节点为：%d\n", pSlow->data);
}
//奇偶反转
void ReverseEvenList(struct Node** ppHead)
{
	struct Node* p1, * p2, * pTemp;
	p1 = *ppHead;					//初始化p1为头节点
	p2 = (*ppHead)->pNext;			//初始化p2为头节点的下一个节点

	p1->pNext = p2->pNext;			//在开头时，单独变换一次
	p2->pNext = p1;
	(*ppHead) = p2;
	(*ppHead)->pFront = NULL;
	p1->pFront = *ppHead;
	p1 = p1->pNext;
	p1->pFront = (*ppHead)->pNext;
	p2 = p1->pNext;
	while (p1 != NULL && p2 != NULL && p2->pNext!=NULL)
	{
		pTemp = p1->pFront;
		pTemp->pNext = p2;
		p1->pNext = p2->pNext;
		p2->pNext = p1;
		p2->pFront = p1->pFront;
		p1->pFront = p2;
		p1 = p1->pNext;
		p1->pFront = p2->pNext;
		p2 = p1->pNext;
	}
	if (p2->pNext == NULL)
	{
		pTemp = p1->pFront;
		pTemp->pNext = p2;
		p2->pNext = p1;
		p2->pFront = pTemp;
		p1->pNext = NULL;
		p1->pFront = p2;
	}
}
//查询链表
void Search(struct Node* pHead)
{
	struct Node* pTemp;
	pTemp = pHead;
	int data;
	printf("请输入你要查询的数据:");
	scanf_s("%d", &data);
	while (pTemp != NULL)
	{
		if (pTemp->data == data)
		{
			printf("该数据存在！\n");
			break;
		}
		else
		{
			printf("该数据不存在！\n");
			break;
		}
		pTemp = pTemp->pNext;
	}
}
//链接环形链表
void Looplinklist(struct Node* pHead)
{
	struct Node* pTemp = pHead;
	while (pTemp->pNext != NULL)
	{
		pTemp = pTemp->pNext;			//移动
	}
	pTemp->pNext = pHead;				//将链表最后一个节点的Next域指向头节点
	pHead->pFront = pTemp;				//将头结点的Front域指向最后一个节点
}
//判断是否成环
void Judge_Loop(struct Node* pHead)
{
	struct Node* pTemp;
	pTemp = pHead;
	pTemp = pHead->pNext;				//pTemp初始化为头节点的下一个节点
	while (pTemp != NULL)		//遍历链表
	{
		if (pTemp->pNext == pHead)
		{
			printf("链表已成环\n");
			break;
		}
		pTemp = pTemp->pNext;		//在遍历过程中，如果能找到一个节点的Next域指向头节点，就可以说明这个链表成环，否则不成环
	}
	if (pTemp == NULL)
	{
		printf("链表未成环\n");
	}
}
//销毁操作			
void Destroy(struct Node* pHead)
{
	struct Node* pTemp, * pLast;			//pTemp临时指针，pLast存放临时指针上一个节点
	pTemp = pHead;						//初始化pTemp
	while (pTemp != NULL)				//遍历链表
	{
		pLast = pTemp;					//记录pTemp上一个节点
		pTemp = pTemp->pNext;			//移动
		free(pLast);					//清除pTemp上一个节点
	}
	if (pTemp == NULL)					//如果全部清除，打印提示语句
	{
		printf("链表销毁成功\n");
		pHead->pNext = NULL;
	}
}
