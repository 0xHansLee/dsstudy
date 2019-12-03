#include <iostream>
#include <cstring>
#include "ALGraphBFS.h"
#include "../DLinkedList.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

void ALGraphBFS::Init(int nv)
{
    int i;
    this->adjList = new List[nv];
    this->visitInfo = new int[nv];

    this->numV = nv;
    this->numE = 0;

    for(i = 0; i < nv; i++)
    {
        this->adjList[i].ListInit();
        this->adjList[i].SetSortRule(WhoIsPrecede);
        this->visitInfo[i] = 0;         // memset to 0
    }
}

void ALGraphBFS::Destroy()
{
    if(this->adjList != NULL)
        delete[] this->adjList;

    if(this->visitInfo != NULL)
        delete[] this->visitInfo;
}

void ALGraphBFS::AddEdge(int fromV, int toV)
{
    this->adjList[fromV].LInsert(toV);
    this->adjList[toV].LInsert(fromV);
    this->numE += 1;
}

void ALGraphBFS::ShowGraphEdgeInfo()
{
    int i;
    int vx;
    for(i = 0; i < this->numV; i++)
    {
        std::cout << char(i+65) << "와 연결된 정점: ";

        if(this->adjList[i].LFirst(&vx))
        {
            std::cout << char(vx+65) << " ";

            while(this->adjList[i].LNext(&vx))
                std::cout << char(vx+65) << " ";
        }
        std::cout << std::endl;
    }
}

int ALGraphBFS::VisitVertex(int visitV)
{
    if(this->visitInfo[visitV] == 0)
    {
        this->visitInfo[visitV] = 1;
        std::cout << char(visitV+65) << " ";
        return TRUE;
    }
    return FALSE;
}

void ALGraphBFS::BFSShowGraphVertex(int startV)
{
    CQueue queue;
    int trV = startV;
    int vx;
    
    queue.Init();
    this->VisitVertex(trV);

    while(this->adjList[trV].LFirst(&vx))
    {
        if(this->visitInfo[vx] == 0)
        {
            queue.Enqueue(vx);
            this->VisitVertex(vx);
        }
        while(this->adjList[trV].LNext(&vx))
        {
            if(this->visitInfo[vx] == 0)
            {
                queue.Enqueue(vx);
                this->VisitVertex(vx);
            }
        }
        // trV = queue.Dequeue();
        if(queue.IsEmpty())
            break;
        else
            trV = queue.Dequeue();
    }
    
    for(int i=0; i<this->numV; i++)
    {
        this->visitInfo[i] = 0;
    }  
}