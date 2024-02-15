#include <stdio.h>

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}


int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];    // 피벗의 위치는 가장 왼쪽
	int low = left + 1;
	int high = right;

	while (low <= high)    // 교차되지 않을 때까지 반복 , 항상 참
	{
		//피벗보다 큰 값 찾는 과정
		while (pivot > arr[low]) //문제 발생 지점
			low++; //low오른쪽으로 이동

		//피벗보다 작은 값 찾는 과정
		while (pivot < arr[high]) //문제 발생 지점
			high--;//high 왼쪽으로 이동

		//코드 버그로 인해 partition 함수 못빠져나옴
		//-> 다음과 같이 코드 바꿔야 함
		/*
		while(pivot >= arr[low] && low <= right)
			low++;

		while(pivot <= arr[high] && high >= (left+1))
			high--;
		*/

		if (low <= high)    // 교차되지 않은 상태라면 Swap 실행
			Swap(arr, low, high);    // low와 high가 가리키는 대상 교환
	}

	Swap(arr, left, high);    // 피벗과 high가 가리키는 대상 교환
	return high;    // 옮겨진 피벗의 위치 정보 반환
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);    // 둘로 나눠서 
		QuickSort(arr, left, pivot - 1);    // 왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right);    // 오른쪽 영역을 정렬
	}
}

int main(void)
{
	//	int arr[7] = {3, 2, 4, 1, 7, 6, 5};
	int arr[3] = { 3, 3, 3 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}