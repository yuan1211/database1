#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap); //초기화 함수 호출

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap)); //우선순위 가장 높은 요소 삭제

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap)) //힙이 비어있지 않은 동안 반복
		printf("%c \n", HDelete(&heap));

	return 0;
}
