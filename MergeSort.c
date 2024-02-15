#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	//병합 한 결과 담을 배열 SortArr 동적할당
	int* sortArr = (int*)malloc(sizeof(int) * (right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		//병합 할 두 영역 데이터 비교 -> 정렬순으로 옮겨담기
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid) //배열 앞부분이 모두 옮겨졌다면
	{
		for (i = rIdx; i <= right; i++, sIdx++) //남은 데이터 그대로 옮기기
			sortArr[sIdx] = arr[i];
	}
	else //배열 뒷부분이 옮겨졌다면
	{
		for (i = fIdx; i <= mid; i++, sIdx++) //남은 앞부분 그대로 옮기기
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right) //left가 작다면 더 나눌 수 있음
	{
		// 중간 지점을 계산한다.
		mid = (left + right) / 2;

		// 둘로 나눠서 각각을 정렬한다.
		MergeSort(arr, left, mid); //left~mid에 위치한 데이터 정렬
		MergeSort(arr, mid + 1, right); //mid+1~right에 위치한 데이터 정렬

		// 정렬된 두 배열을 병합한다.
		MergeTwoArea(arr, left, mid, right);
	}
}

int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	int i;

	// 배열 arr의 전체 영역 정렬 
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < 7; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}