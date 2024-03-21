#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"
#define scanf scanf_s

extern int iCount;

//��������
struct Node* Create(void)
{
	int number, i;								//number���ڴ洢�ڵ������i����ѭ�� 
	struct Node* pHead = NULL;					//��ʼ������ͷָ��Ϊ��
	struct Node* pEnd = NULL;					//�����ڵ㣬pNEW���½��ڵ㣬pEnd�Ǿ������β�ڵ� 
	struct Node* pNew;
	iCount = 0; 								//��ʼ�������� 
	printf("����������Ҫ�����Ľڵ������\n");	//��ʾ��� 
	scanf("%d", &number);
	//pEnd = (struct Node*)malloc(sizeof(struct Node));
	for (i = 0; i < number; i++)
	{
		pNew = (struct Node*)malloc(sizeof(struct Node));//���ڵ�����ڴ� 
		//	pEnd = (struct Node*)malloc(sizeof(struct Node));
		iCount++;										//������Ŀ��һ 
		printf("��%d���ڵ����ݣ�", iCount); 				//������� 
		scanf("%d", &pNew->data);						//�������� 
		printf("\n"); 									//���� 
		//�������� 
		if (iCount == 1)							//����ǵ�һ���ڵ㣬ִ��if��Ĳ��� 
		{
			pNew->pNext = NULL;
			pEnd = pNew;
			pHead = pNew;
		}
		else									//������ǵ�һ���ڵ㣬ִ��else��Ĳ��� 
		{
			pNew->pNext = NULL;
			pEnd->pNext = pNew;
			pEnd = pNew;
		}
		//printf("pNew->data=%d\n",pNew->data);		//���Դ���// 
		//printf("pNew->pNext=%d\n",pNew->pNext);		//���Դ���// 
		//printf("pNew=%d\n",pNew);					//���Դ���// 
	}
	//printf("iCount=%d\n",iCount);					//���Դ���// 
	return pHead;
}
//�������ĺ��� 
void Print(struct Node* pHead)
{
	if (pHead->pNext == NULL)
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
	scanf("%d", &location); 								//		  //
	printf("�������������ݣ�");						//        // 
	scanf("%d", &pNew->data);							//��ʾ���// 
	printf("\n");
	if (location == 0)
	{
		pNew->pNext = pTemp;
		*ppHead = pNew;
		pTemp = pNew;
	}
	else
	{
		while (pTemp != NULL)								//ѭ��// 
		{
			cnt++;											//��������// 
			//	printf("��%d������Ϊ��%d\n",cnt,pTemp->data);	//�������// 
			pBefore = pTemp;								//���ýڵ��ָ���¼����// 
			pTemp = pTemp->pNext;							//������һ�ڵ�// 
			if (cnt == location)								//���cnt����λ�ã�����ѭ��// 
				break;
		}
		pBefore->pNext = pNew;								//��������// 
		pNew->pNext = pTemp;
	}
	iCount++;											//����ڵ�����һ// 
}

//ɾ������ 
void Delete(struct Node** ppHead)
{
	struct Node* pTemp;
	struct Node* pBefore = NULL;
	pTemp = *ppHead;										//��ȡͷ�ڵ�// 
	int location;
	printf("������ɾ�����ݵ�λ�ã�");
	scanf("%d", &location);
	printf("\n");
	int cnt = 0;
	while (pTemp != NULL)			//location����3��pBeforeΪ�ڶ������ݣ�pTempΪ���������� 
	{
		cnt++;
		//	printf("��%d������Ϊ��%d\n",cnt,pTemp->data);
		pBefore = pTemp;
		pTemp = pTemp->pNext;
		if (cnt == location - 1)
			break;
	}
	pBefore->pNext = pTemp->pNext;
	free(pTemp);
}
//���ٲ���
void Destroy(struct Node* pHead)
{
	struct Node *pTemp,*pLast;			//pTemp��ʱָ�룬pLast�����ʱָ����һ���ڵ�
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
//��ת����
void Reverse(struct Node** ppHead)			//����Ҫ����һ������ָ�룬��Ϊ�˺���Ҫ�ı�pHead��ָ��
{
	struct Node* pBegin, * pEnd;
	pBegin = *ppHead;
	pEnd = (*ppHead)->pNext;
	while (pEnd != NULL)
	{
		pBegin->pNext = pEnd->pNext;
		pEnd->pNext = *ppHead;
		*ppHead = pEnd;
		pEnd = pBegin->pNext;
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
//�ҵ��м�ڵ�
void FindMiddleNode(struct Node* pHead)
{
	struct Node* pTemp;
	struct Node* pSlow, * pFast;			//pSlow����ָ�룬һ����һ���ڵ�,pFast�ǿ�ָ�룬һ���������ڵ㣬��pFast�ߵ�ͷʱ��pSlow�����м�ڵ�
	pTemp = pHead;							//��ʼ��ָ��
	pSlow = pHead;
	pFast = pHead;
	while ( 1 )
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
	struct Node* p1, * p2,*pTemp;
	p1 = *ppHead;					//��ʼ��p1Ϊͷ�ڵ�
	p2 = (*ppHead)->pNext;			//��ʼ��p2Ϊͷ�ڵ����һ���ڵ�
	p1->pNext = p2->pNext;			//�ڿ�ͷʱ�������任һ��
	p2->pNext = p1;
	*ppHead = p2;
	pTemp = p1;
	p1 = p1->pNext;
	p2 = p1->pNext;
	while (p1 != NULL && p2 != NULL)
	{
		p1->pNext = p2->pNext;
		p2->pNext = p1;
		pTemp->pNext = p2;
		pTemp = p1;
		p1 = p1->pNext;
		if (p1 == NULL)
			break;
		p2 = p1->pNext;
	}
}
//��ѯ����
void Search(struct Node* pHead)
{
	struct Node* pTemp;
	pTemp = pHead;
	int data;
	printf("��������Ҫ��ѯ������:");
	scanf("%d", &data);
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




