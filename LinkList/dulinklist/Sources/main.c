#include<stdio.h>
#include<stdlib.h>
#include"dulinklist.h"
#define scanf scanf_s

int main()
{
	Node* pHead;
	Node** ppHead = &pHead;
	pHead = Create();		//��ʼ������
	Print(pHead);			//��ӡ����
	FindMiddleNode(pHead);	//Ѱ���м�ڵ�
/*
	printf("������з�ת����Ĳ���\n");
	Reverse(ppHead);		//��ת����
	Print(pHead);			
	printf("������в���ڵ�Ĳ���\n");
	Insert(ppHead);			//����ڵ�
	Print(pHead);
	printf("�������ɾ���ڵ�Ĳ���\n");
	Delete(ppHead);			//ɾ���ڵ�
	Print(pHead);
	printf("���������ż��ת�Ĳ���\n");
	ReverseEvenList(ppHead);//��ż��ת
	Print(pHead);
	printf("������в�ѯ����Ĳ���\n");
	Search(pHead);			//��ѯ����
	*/
	printf("�����ж������Ƿ�ɻ�\n");
	Judge_Loop(pHead);		//�ж������Ƿ�ɻ�
	printf("�������������ɻ�\n");
	Looplinklist(pHead);	//����ѭ������
	printf("�����ٴ��ж������Ƿ�ɻ�\n");
	Judge_Loop(pHead);		//�ж������Ƿ�ɻ�
}


/*
int main()
{
	Node* pHead;
	Node** ppHead;
	ppHead = &pHead;
	int code = -1;
	printf("*************************************************\n");
	printf("*     1����ʼ������      *    2�������½ڵ�       *\n");
	printf("*     3����ת����        *    4���������         *\n");
	printf("*     5���м�����        *    6���ж������Ƿ�ɻ�  *\n");
	printf("*     7��ɾ���ڵ�        *    8����ż��ת         *\n");
	printf("*     9����ѯ����        *    10������ѭ������    *\n");
	printf("*     0���˳�ϵͳ        *                       *\n");
	while (1)
	{
		code = -1;
		printf("�������Ӧ���֣�");
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
			printf("����ڵ�ɹ�\n");
			break;
		case 3:
			Reverse(ppHead);
			printf("����ת�ɹ�\n");
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
			printf("��������ɹ�\n");
			break;
		case 8:
			ReverseEvenList(ppHead);
			printf("��ż��ת�ɹ�\n");
			break;
		case 9:
			Search(pHead);
			break;
		case 10:
			Looplinklist(pHead);
			printf("����ѭ������ɹ�\n");
			break;
		default:
			printf("����δ������\n");
			break;
		}
	}
}
*/