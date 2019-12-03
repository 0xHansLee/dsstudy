#include <iostream>
#include <cstring>
#include "ALGraphDFS.h"
#include "../DLinkedList.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

void ALGraphDFS::Init(int nv)
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

void ALGraphDFS::Destroy()
{
    if(this->adjList != NULL)
        delete[] this->adjList;

    if(this->visitInfo != NULL)
        delete[] this->visitInfo;
}

void ALGraphDFS::AddEdge(int fromV, int toV)
{
    this->adjList[fromV].LInsert(toV);
    this->adjList[toV].LInsert(fromV);
    this->numE += 1;
}

void ALGraphDFS::ShowGraphEdgeInfo()
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

int ALGraphDFS::VisitVertex(int visitV)
{
    if(this->visitInfo[visitV] == 0)
    {
        this->visitInfo[visitV] = 1;
        std::cout << char(visitV+65) << " ";
        return TRUE;
    }
    return FALSE;
}

void ALGraphDFS::DFSShowGraphVertex(int startV)
{
    ArrayStack stack;
    int vx;
    int trV;

    stack.StackInit();
    trV = startV;
    // this->VisitVertex(this->adjList[trV].LFirst(&vx));
    stack.SPush(trV);
    this->VisitVertex(trV);
    
    while(this->adjList[trV].LFirst(&vx))    // traverse linked list of adjList[trV]
    {
        int visitFlag = FALSE;

        if(this->VisitVertex(vx))           // find unvisited node
        {
            stack.SPush(trV);                
            trV = vx;
            visitFlag = TRUE;
            // this->adjList[trV].LFirst(&vx);
        }
        else
        {
            while(this->adjList[trV].LNext(&vx))
            {
                if(this->VisitVertex(vx))
                {
                    stack.SPush(trV);
                    trV = vx;
                    // this->adjList[trV].LFirst(&vx);
                    visitFlag = TRUE;
                    break;
                }
            }
            if(visitFlag == FALSE)
            {
                if(stack.SIsEmpty())
                    break;
                else
                    trV = stack.SPop();
            }
        }
    }
    
    for(int i=0; i<this->numV; i++)
    {
        this->visitInfo[i] = 0;
    }  
}