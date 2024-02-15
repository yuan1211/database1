#include <stdio.h>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	HeapInit(&heap); //�ʱ�ȭ �Լ� ȣ��

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap)); //�켱���� ���� ���� ��� ����

	HInsert(&heap, 'A', 1);
	HInsert(&heap, 'B', 2);
	HInsert(&heap, 'C', 3);
	printf("%c \n", HDelete(&heap));

	while (!HIsEmpty(&heap)) //���� ������� ���� ���� �ݺ�
		printf("%c \n", HDelete(&heap));

	return 0;
}
