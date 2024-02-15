#include "SimpleHeap.h"

void HeapInit(Heap* ph) //힙 초기화
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) //힙 비었는지 확인
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) //부모 노드 인덱스 값 반환
{
	return idx / 2;
}

int GetLChildIDX(int idx) //왼쪽 자식 노드 인덱스 값 반환
{
	return idx * 2;
}

int GetRChildIDX(int idx) //오른쪽 자식 노드 인덱스 값 반환
{
	return GetLChildIDX(idx) + 1;
}

//두 개의 자식 노드 중 우선순위 높은 자식의 노드 인덱스 값 반환
int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)    // 자식 노드 x
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)    // 자식 노드가 왼쪽 자식 하나만 존재
		return GetLChildIDX(idx);

	else   // 왼쪽 자식 노드와 오른쪽 자식 노드의 우선순위를 비교 ( 둘 다 존재)
	{
		if (ph->heapArr[GetLChildIDX(idx)].pr //오른쪽 자식 우선순위 높으면
						> ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx); //오른쪽 자식 인덱스반환
		else
			return GetLChildIDX(idx); //왼쪽 자식 우선순위 높으면 왼쪽 반환
	}
}

//힙에 데이터 저장
void HInsert(Heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1; //새 노드가 저장될 인덱스 값 idx에 저장
	HeapElem nelem = { pr, data };  //새 노드 생성,초기화

	while (idx != 1) //새 노드가 저장될 위치가 루트노드위치 아니면 반복
	{
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; //부모 노드 한 레벨 내림 실제로 내림
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

//힙에서 데이터 삭제
HData HDelete(Heap* ph)
{
	HData retData = (ph->heapArr[1]).data;    // 반환 위해 삭제할 데이터 임시 저장
	HeapElem lastElem = ph->heapArr[ph->numOfData]; //힙의 마지막 노드 저장
	//parentIdx에는 마지막 노드가 저장될 위치정보
	int parentIdx = 1;    // 루트 노드가 위치해야할 인덱스 값 저장
	int childIdx;
	//루트노드의 우선순위가 높은 자식 노드를 시작으로 반복시작
	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr) //마지막 노드와 우선순위 비교
			break; //마지막 노드 우선수뉘 높으면 반복문 탈출

		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; //마지막 노드보다 우선순위 높으니 비교대사 노드 레벨업
		parentIdx = childIdx; //마지막 노드가 저자될 위치정보 레벨 다운

	}

	ph->heapArr[parentIdx] = lastElem; //마지막 노드 최종 저장
	ph->numOfData -= 1;
	return retData;
}