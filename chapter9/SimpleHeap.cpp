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
            // exit(-1);
            break;
            
        
        // tmpElem.data = this->heapArr[numOfData].data;
        // tmpElem.pr = this->heapArr[numOfData].pr;
        tmpElem = this->heapArr[idx];       // class = operator working!

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
    if(this->IsEmpty())
        std::cout << "Empty Heap!" << std::endl;

    HData retData = this->heapArr[1].data;
    this->heapArr[1] = this->heapArr[numOfData];            // Move last node to first node
    this->heapArr[numOfData].data = 'D';                   // Delete last node (임의의 값으로 채움. array nulling 어떻게?))
    this->heapArr[numOfData].pr = 9999;                     
    int idx = 1;

    // 자식 노드가 없을 때 혹은 한 개만 있을 때는 고려 x. 그래도 작동하는 이유는 garbage node에 priority가 큰 값이 들어가 있기 때문
    while( (this->heapArr[idx].pr >= this->heapArr[idx*2].pr) && (this->heapArr[idx].pr >= this->heapArr[idx*2+1].pr) )     // Until the priority of parent is lowerer than those of childs
    {
        if(this->heapArr[idx*2].pr > this->heapArr[idx*2+1].pr)         // when the priority of right node is higher than left one
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
    this->numOfData--;                      // 빼먹었음..  
    return retData;                         // 빼먹었음..
}