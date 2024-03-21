#pragma once
typedef struct Node
{
	int data;
	struct Node* pNext;
}Node;

int iCount;

struct Node* Create(void);				//初始化链表
void Print(struct Node* pHead);			//打印链表
void Insert(struct Node** ppHead);		//插入节点
void Delete(struct Node** ppHead);		//删除节点
void Destroy(struct Node* pHead);		//销毁链表
void Reverse(struct Node** ppHead);		//反转链表
void Looplinklist(struct Node* pHead); 	//链接环形链表
void Judge_Loop(struct Node* pHead);	//判断链表是否成环
void FindMiddleNode(struct Node* pHead);//找到中间节点
void ReverseEvenList(struct Node** ppHead);//奇偶反转
void Search(struct Node* pHead);		//查询链表
