#include <iostream>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

void ALGraph::Init(int nv)
{
    int i;
    this->adjList = new List[nv];

    this->numV = nv;
    this->numE = 0;

    for(i = 0; i < nv; i++)
    {
        this->adjList[i].ListInit();
        this->adjList[i].SetSortRule(WhoIsPrecede);
    }
}

void ALGraph::Destroy()
{
    if(this->adjList != NULL)
        delete[] this->adjList;
}

void ALGraph::AddEdge(int fromV, int toV)
{
    this->adjList[fromV].LInsert(toV);
    this->adjList[toV].LInsert(fromV);
    this->numE += 1;
}

void ALGraph::ShowGraphEdgeInfo()
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
