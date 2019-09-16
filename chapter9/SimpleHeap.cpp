#include <iostream>
#include "SimpleHeap.h"

void Heap::Init()
{
    this->numOfData = 0;
}

int Heap::IsEmpty()
{
    if(this->numOfData == 0)
        return TRUE;

    else
        return FALSE;
}

void Heap::Insert(HData data, Priority pr)
{
    HeapElem tmpElem;
    
    this->numOfData++;
    this->heapArr[numOfData].data = data;
    this->heapArr[numOfData].pr = pr;

    int idx = this->numOfData;

    while(this->heapArr[idx].pr <= this->heapArr[idx/2].pr)
    {
        if(idx/2 == 0)
            exit(-1);
        
        // tmpElem.data = this->heapArr[numOfData].data;
        // tmpElem.pr = this->heapArr[numOfData].pr;
        tmpElem = this->heapArr[idx];

        // this->heapArr[numOfData].data = this->heapArr[numOfData/2].data;
        // this->heapArr[numOfData].pr = this->heapArr[numOfData/2].pr;
        // this->heapArr[numOfData/2].data = 
        this->heapArr[idx] = this->heapArr[idx/2];
        this->heapArr[idx/2] = tmpElem;
        idx /= 2;
    }
}

HData Heap::Delete()
{
    HeapElem tmpElem;
    if(this->IsEmpty)
        std::cout << "Empty Heap!" << std::endl;

    this->heapArr[1] = this->heapArr[numOfData];
    int idx = 1;

    while( (this->heapArr[idx].pr >= this->heapArr[idx*2].pr) && (this->heapArr[idx].pr >= this->heapArr[idx*2+1].pr) )
    {
        if(this->heapArr[idx*2].pr > this->heapArr[idx*2+1].pr)
        {
            tmpElem = this->heapArr[idx];
            this->heapArr[idx] = this->heapArr[idx*2+1];
            this->heapArr[idx*2+1] = tmpElem;
        }
        else
        {
            tmpElem = this->heapArr[idx];
            this->heapArr[idx] = this->heapArr[idx*2];
            this->heapArr[idx*2] = tmpElem;
        }
        idx *= 2;
    }
}