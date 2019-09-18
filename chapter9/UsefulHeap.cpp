#include "UsefulHeap.h"

void Heap::Init(PriorityComp pc)
{
    this->numOfData = 0;
    this->comp = pc;
}

int Heap::IsEmpty()
{
    if(this->numOfData == 0)
        return TRUE;

    else
        return FALSE;
}

int GetParentIDX(int idx)
{
    return idx/2;
}

int GetLChildIDX(int idx)
{
    return idx*2;
}

int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx)+1;
}

int Heap::GetHiPriChildIDX(int idx)             // compare priority of childs and return the index of the child (high priority)
{
    if(GetLChildIDX(idx) > this->numOfData)     // terminal node
        return 0;

    else if(GetLChildIDX(idx) == this->numOfData)   // Left child node is last node => return left child node
        return GetLChildIDX(idx);

    else
    {
        if(this->comp(this->heapArr[GetLChildIDX(idx)], this->heapArr[GetRChildIDX(idx)]) < 0)      // if -, right one has higher priority
            return GetRChildIDX(idx);

        else        // When both priorities are same, return left one
            return GetLChildIDX(idx);
    }
}

void Heap::Insert(HData data)
{
    int idx = this->numOfData+1;

    while(idx != 1)
    {
        if(this->comp(data, this->heapArr[GetParentIDX(idx)]) > 0)      // if left one has higher priority, change!
        {
            this->heapArr[idx] = this->heapArr[GetParentIDX(idx)];      // copy parent data to the child node
            idx = GetParentIDX(idx);                                    // update idx
        }
        else
        {
            break;
        }
    }
    this->heapArr[idx] = data;      // enter the data after updating node index
    this->numOfData++;
}

HData Heap::Delete()
{
    HData delData = this->heapArr[1];
    HData lastData = this->heapArr[this->numOfData];

    int parentIdx = 1;
    int childIdx;

    while(childIdx = GetHiPriChildIDX(parentIdx))
    {
        if(this->comp(lastData, this->heapArr[childIdx]) >= 0)
            break;

        this->heapArr[parentIdx] = this->heapArr[childIdx];
        parentIdx = childIdx;
    }

    this->heapArr[parentIdx] = lastData;
    this->numOfData--;
    return delData;
}

