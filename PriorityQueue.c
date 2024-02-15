#include "PriorityQueue.h"
#include "UsefulHeap.h"

void PQueueInit(PQueue* ppq, PriorityComp pc) //�켱���� ť �ʱ�ȭ
{
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue* ppq) //�켱���� ť ������� ���� ��ȯ
{
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue* ppq, PQData data) //�켱���� ť�� ������ ����
{
	HInsert(ppq, data);
}

PQData PDequeue(PQueue* ppq) //�켱���� ť���� ������ �����ϰ� ��ȯ
{
	return HDelete(ppq);
}