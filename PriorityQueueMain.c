#include <stdio.h>
#include "PriorityQueue.h"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main(void)
{
	PQueue pq; //우선순위 큐 선언
	PQueueInit(&pq, DataPriorityComp); //초기화

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq)); //가장 높은 우선순위 데이터 출력

	PEnqueue(&pq, 'A');
	PEnqueue(&pq, 'B');
	PEnqueue(&pq, 'C');
	printf("%c \n", PDequeue(&pq));

	while (!PQIsEmpty(&pq)) // 우선순위 큐 비어있지 않는 동안 모든 데이터 출력
		printf("%c \n", PDequeue(&pq));

	return 0;
}
