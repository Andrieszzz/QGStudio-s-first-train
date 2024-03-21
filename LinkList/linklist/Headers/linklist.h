#pragma once
typedef struct Node
{
	int data;
	struct Node* pNext;
}Node;

int iCount;

struct Node* Create(void);				//��ʼ������
void Print(struct Node* pHead);			//��ӡ����
void Insert(struct Node** ppHead);		//����ڵ�
void Delete(struct Node** ppHead);		//ɾ���ڵ�
void Destroy(struct Node* pHead);		//��������
void Reverse(struct Node** ppHead);		//��ת����
void Looplinklist(struct Node* pHead); 	//���ӻ�������
void Judge_Loop(struct Node* pHead);	//�ж������Ƿ�ɻ�
void FindMiddleNode(struct Node* pHead);//�ҵ��м�ڵ�
void ReverseEvenList(struct Node** ppHead);//��ż��ת
void Search(struct Node* pHead);		//��ѯ����
