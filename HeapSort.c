#include <stdio.h>
#include "UsefulHeap.h"

int PriComp(int n1, int n2)
{
	return n2 - n1; //오름차순 정렬
	//	return n1-n2; = 내림차순 정렬
}

void HeapSort(int arr[], int n, PriorityComp pc) //힙 정렬 구현함수
{
	Heap heap;
	int i;

	HeapInit(&heap, pc);

	// 정렬 대상을 가지고 힙 구성
	//힙 정렬 1단계: 데이터 모두 힙에 넣음
	for (i = 0; i < n; i++)
		HInsert(&heap, arr[i]);

	// 순서대로 하나씩 꺼내서 정렬을 완성
	//힙 정렬 2단계 : 데이터 꺼내기
	for (i = 0; i < n; i++)
		arr[i] = HDelete(&heap);
}

int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };
	int i;

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;