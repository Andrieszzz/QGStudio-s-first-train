#pragma once
typedef struct Node
{
	struct Node* pFront;
	int data;
	struct Node* pNext;
}Node;

Node* Create(void);
void Print(struct Node* pHead);
void Insert(struct Node** ppHead);
void Delete(struct Node** ppHead);
void Reverse(struct Node** ppHead);
void FindMiddleNode(struct Node* pHead);
void ReverseEvenList(struct Node** pHead);
void Search(struct Node* pHead);
void Looplinklist(struct Node* pHead);
void Judge_Loop(struct Node* pHead);
void Destroy(struct Node* pHead);

