#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main(void)
{
	PQueue pq; //�켱���� ť ����
	PQueueInit(&pq, DataPriorityComp); //�ʱ�ȭ

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq)); //���� ���� �켱���� ������ ���

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	while (!PQIsEmpty(&pq)) // �켱���� ť ������� �ʴ� ���� ��� ������ ���
		printf("%c \n", PDequeue(&pq));

	return 0;
}
