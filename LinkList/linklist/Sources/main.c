#include<stdio.h>
#include<stdlib.h>
#include "linklist.h"

int main()
{
	Node* pHead;
	Node** ppHead = &pHead;
	int code=-1;
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
		case 0:								//�˳�ϵͳ
			break;
		case 1:								//��ʼ������
			pHead = Create();
			printf("�����ʼ���ɹ�\n");
			break;
		case 2:								//����ڵ�
			Insert(ppHead);
			printf("����ڵ�ɹ�\n");
			break;
		case 3:								//��ת����
			Reverse(ppHead);
			printf("����ת�ɹ�\n");
			break;
		case 4:								//��ӡ����
			Print(pHead);
			break;
		case 5:								//Ѱ���м�����
			FindMiddleNode(pHead);
			break;
		case 6:								//�ж��Ƿ���ѭ������
			Judge_Loop(pHead);
			break;
		case 7:								//��������
			Delete(ppHead);
			printf("��������ɹ�\n");
			break;
		case 8:								//��ż��ת
			ReverseEvenList(ppHead);
			printf("��ż��ת�ɹ�\n");
			break;
		case 9:								//��ѯ����
			Search(pHead);
			break;
		case 10:							//����ѭ������
			Looplinklist(pHead);
			printf("����ѭ������ɹ�\n");
			break;
		default:
			printf("����δ������\n");
			break;
		}

	}

}
