#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue* ppq, PriorityComp pc) //우선순위 큐 초기화
{
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue* ppq) //우선순위 큐 비었는지 여부 반환
{
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue* ppq, PQData data) //우선순위 큐에 데이터 삽입
{
	HInsert(ppq, data);
}

PQData PDequeue(PQueue* ppq) //우선순위 큐에서 데이터 삭제하고 반환
{
	return HDelete(ppq);
}