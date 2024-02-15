#include "SimpleHeap.h"

void HeapInit(Heap* ph) //�� �ʱ�ȭ
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph) //�� ������� Ȯ��
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIDX(int idx) //�θ� ��� �ε��� �� ��ȯ
{
	return idx / 2;
}

int GetLChildIDX(int idx) //���� �ڽ� ��� �ε��� �� ��ȯ
{
	return idx * 2;
}

int GetRChildIDX(int idx) //������ �ڽ� ��� �ε��� �� ��ȯ
{
	return GetLChildIDX(idx) + 1;
}

//�� ���� �ڽ� ��� �� �켱���� ���� �ڽ��� ��� �ε��� �� ��ȯ
int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)    // �ڽ� ��� x
		return 0;

	else if (GetLChildIDX(idx) == ph->numOfData)    // �ڽ� ��尡 ���� �ڽ� �ϳ��� ����
		return GetLChildIDX(idx);

	else   // ���� �ڽ� ���� ������ �ڽ� ����� �켱������ �� ( �� �� ����)
	{
		if (ph->heapArr[GetLChildIDX(idx)].pr //������ �ڽ� �켱���� ������
						> ph->heapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx); //������ �ڽ� �ε�����ȯ
		else
			return GetLChildIDX(idx); //���� �ڽ� �켱���� ������ ���� ��ȯ
	}
}

//���� ������ ����
void HInsert(Heap* ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1; //�� ��尡 ����� �ε��� �� idx�� ����
	HeapElem nelem = { pr, data };  //�� ��� ����,�ʱ�ȭ

	while (idx != 1) //�� ��尡 ����� ��ġ�� ��Ʈ�����ġ �ƴϸ� �ݺ�
	{
		if (pr < (ph->heapArr[GetParentIDX(idx)].pr))
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; //�θ� ��� �� ���� ���� ������ ����
			idx = GetParentIDX(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

//������ ������ ����
HData HDelete(Heap* ph)
{
	HData retData = (ph->heapArr[1]).data;    // ��ȯ ���� ������ ������ �ӽ� ����
	HeapElem lastElem = ph->heapArr[ph->numOfData]; //���� ������ ��� ����
	//parentIdx���� ������ ��尡 ����� ��ġ����
	int parentIdx = 1;    // ��Ʈ ��尡 ��ġ�ؾ��� �ε��� �� ����
	int childIdx;
	//��Ʈ����� �켱������ ���� �ڽ� ��带 �������� �ݺ�����
	while (childIdx = GetHiPriChildIDX(ph, parentIdx))
	{
		if (lastElem.pr <= ph->heapArr[childIdx].pr) //������ ���� �켱���� ��
			break; //������ ��� �켱���� ������ �ݺ��� Ż��

		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; //������ ��庸�� �켱���� ������ �񱳴�� ��� ������
		parentIdx = childIdx; //������ ��尡 ���ڵ� ��ġ���� ���� �ٿ�

	}

	ph->heapArr[parentIdx] = lastElem; //������ ��� ���� ����
	ph->numOfData -= 1;
	return retData;
}