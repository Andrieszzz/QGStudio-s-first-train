#include<stdio.h>
#include<stdlib.h>
#include"dulinklist.h"
//��������
Node* Create(void)
{
	int number,i;
	Node* pHead, * pEnd, * pNew;
	pHead = NULL;
	pEnd = NULL;
	printf("����������Ҫ�����Ľڵ������");
	scanf_s("%d", &number);
	for (i = 0; i < number; i++)
	{
		pNew = (Node*)malloc( sizeof(Node) );
		printf("�������%d���ڵ������:\n",i+1);
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
	printf("�����ʼ����ɣ�\n");
	return pHead;
}
//��ӡ����
void Print(struct Node* pHead)
{
	if (pHead == NULL)
	{
		printf("��������\n");
	}
	else
	{
		struct Node* pTemp;							//������ʱָ�� 
		pTemp = pHead;								//��ͷ�ڵ�ĵ�ַ����ʱָ�� 
		printf("����Ϊ��\n");
		while (pTemp != NULL)						//����ʱָ�벻ΪNULLʱ��ִ��ѭ����Ĳ��� 
		{
			printf("%d", pTemp->data);				//�����ʱָ��Ľڵ�Ԫ�� 
			if (pTemp->pNext != NULL)				//װ����// 
				printf("->");						//      // 
			pTemp = pTemp->pNext;					//��ʱָ��ָ����һ�ڵ�// 
		}
		printf("\n");
	}
}
//�������
void Insert(struct Node** ppHead)
{
	struct Node* pTemp;
	struct Node* pBefore = NULL;
	struct Node* pNew;
	pNew = (struct Node*)malloc(sizeof(struct Node));	//���½ڵ�����ڴ� 
	pTemp = *ppHead;										//��ȡͷ�ڵ��ַ 
	int location;										//��¼�ڵ�λ�� 
	int cnt = 0;										//����// 
	printf("����������ݵ�ǰһ�����ݵ�λ�ã�");			//��ʾ���//
	scanf_s("%d", &location); 							//		  //
	printf("�������������ݣ�");							//        // 
	scanf_s("%d", &pNew->data);							//��ʾ���// 
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
		while (pTemp != NULL)								//ѭ��//  
		{
			cnt++;											//��������// 
			//	printf("��%d������Ϊ��%d\n",cnt,pTemp->data);	//�������// 
			pBefore = pTemp;								//���ýڵ��ָ���¼����// 
			pTemp = pTemp->pNext;							//������һ�ڵ�// 
			if (cnt == location)							//���cnt����λ�ã�����ѭ��// 
				break;
		}
		pBefore->pNext = pNew;							//����pNew��pBefore֮�������// 
		pNew->pFront = pBefore;
		pNew->pNext = pTemp;							//����pNew��pTemp֮�������
		pTemp->pFront = pNew;
	}											 
}
//ɾ���ڵ����			//free����û�н�����⣬ɾ���ڵ���ͷŲ����ڴ�
void Delete(struct Node** ppHead)
{
	struct Node* pTemp;
	pTemp = *ppHead;
	struct Node* pBefore = (*ppHead)->pFront;
	struct Node* pBehind = (*ppHead)->pNext;
	int location;
	printf("������ɾ�����ݵ�λ�ã�");
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
		for (cnt = 1; cnt < location; cnt++)			//location����3��pBeforeΪ�ڶ������ݣ�pTempΪ���������� 
		{												//�ƶ���Ŀ��ڵ�
			pBefore = pTemp;
			pTemp = pTemp->pNext;
			pBehind = pTemp->pNext;
		}								//��ʱpTemp��Ŀ��ڵ㣬pBefore��Ŀ��ڵ��ǰһ�ڵ�
		pBefore->pNext = pBehind;		//��������
		pBehind->pFront = pBefore;
		free(pTemp);
	}
}
//��ת����
void Reverse(struct Node** ppHead)			//����Ҫ����һ������ָ�룬��Ϊ�˺���Ҫ�ı�pHead��ָ��
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
//�ҵ��м�ڵ�
void FindMiddleNode(struct Node* pHead)
{
	struct Node* pTemp;
	struct Node* pSlow, * pFast;			//pSlow����ָ�룬һ����һ���ڵ�,pFast�ǿ�ָ�룬һ���������ڵ㣬��pFast�ߵ�ͷʱ��pSlow�����м�ڵ�
	pTemp = pHead;							//��ʼ��ָ��
	pSlow = pHead;
	pFast = pHead;
	while (1)
	{
		if (pFast == NULL || pFast->pNext == NULL)//��pFast��pFast->pNextΪNULLʱ���˳�ѭ��
			break;
		pSlow = pSlow->pNext;
		pFast = pFast->pNext->pNext;
	}
	printf("�м�ڵ�Ϊ��%d\n", pSlow->data);
}
//��ż��ת
void ReverseEvenList(struct Node** ppHead)
{
	struct Node* p1, * p2, * pTemp;
	p1 = *ppHead;					//��ʼ��p1Ϊͷ�ڵ�
	p2 = (*ppHead)->pNext;			//��ʼ��p2Ϊͷ�ڵ����һ���ڵ�

	p1->pNext = p2->pNext;			//�ڿ�ͷʱ�������任һ��
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
//��ѯ����
void Search(struct Node* pHead)
{
	struct Node* pTemp;
	pTemp = pHead;
	int data;
	printf("��������Ҫ��ѯ������:");
	scanf_s("%d", &data);
	while (pTemp != NULL)
	{
		if (pTemp->data == data)
		{
			printf("�����ݴ��ڣ�\n");
			break;
		}
		else
		{
			printf("�����ݲ����ڣ�\n");
			break;
		}
		pTemp = pTemp->pNext;
	}
}
//���ӻ�������
void Looplinklist(struct Node* pHead)
{
	struct Node* pTemp = pHead;
	while (pTemp->pNext != NULL)
	{
		pTemp = pTemp->pNext;			//�ƶ�
	}
	pTemp->pNext = pHead;				//���������һ���ڵ��Next��ָ��ͷ�ڵ�
	pHead->pFront = pTemp;				//��ͷ����Front��ָ�����һ���ڵ�
}
//�ж��Ƿ�ɻ�
void Judge_Loop(struct Node* pHead)
{
	struct Node* pTemp;
	pTemp = pHead;
	pTemp = pHead->pNext;				//pTemp��ʼ��Ϊͷ�ڵ����һ���ڵ�
	while (pTemp != NULL)		//��������
	{
		if (pTemp->pNext == pHead)
		{
			printf("�����ѳɻ�\n");
			break;
		}
		pTemp = pTemp->pNext;		//�ڱ��������У�������ҵ�һ���ڵ��Next��ָ��ͷ�ڵ㣬�Ϳ���˵���������ɻ������򲻳ɻ�
	}
	if (pTemp == NULL)
	{
		printf("����δ�ɻ�\n");
	}
}
//���ٲ���			
void Destroy(struct Node* pHead)
{
	struct Node* pTemp, * pLast;			//pTemp��ʱָ�룬pLast�����ʱָ����һ���ڵ�
	pTemp = pHead;						//��ʼ��pTemp
	while (pTemp != NULL)				//��������
	{
		pLast = pTemp;					//��¼pTemp��һ���ڵ�
		pTemp = pTemp->pNext;			//�ƶ�
		free(pLast);					//���pTemp��һ���ڵ�
	}
	if (pTemp == NULL)					//���ȫ���������ӡ��ʾ���
	{
		printf("�������ٳɹ�\n");
		pHead->pNext = NULL;
	}
}
