#include <iostream>
#include <cstring>
#include "ALGraphKruskal.h"
#include "DLinkedList.h"
#include "ArrayBaseStack.h"
#include "PriorityQueue.h"
#include "UsefulHeap.h"
#include "ALEdge.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

int PQWeightComp(Edge d1, Edge d2)
{
    return d1.weight - d2.weight;
}

void ALGraph::Init(int nv)
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
    this->pqueue.Init(PQWeightComp);
}

void ALGraph::Destroy()
{
    if(this->adjList != NULL)
        delete[] this->adjList;

    if(this->visitInfo != NULL)
        delete[] this->visitInfo;
}

void ALGraph::AddEdge(int fromV, int toV, int weight)
{
    Edge edge = {fromV, toV, weight};

    this->adjList[fromV].LInsert(toV);
    this->adjList[toV].LInsert(fromV);
    this->numE += 1;

    pqueue.Enqueue(edge);
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

int ALGraph::VisitVertex(int visitV)
{
    if(this->visitInfo[visitV] == 0)
    {
        this->visitInfo[visitV] = 1;
        std::cout << char(visitV+65) << " ";
        return TRUE;
    }
    return FALSE;
}

void ALGraph::DFSShowGraphVertex(int startV)
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

int disConnected(CQueue pq, int v)
{
    while(!pq.IsEmpty())
    {
        Edge dEdge = pq.Dequeue();
        if(v == dEdge.v1 || v == dEdge.v2)
        {
            return 0;
        }
    }
    return 1;
}

void ALGraph::ConKruskalMST()   // MST만들기
{
    int numMSTEdge = this->pqueue.numOfData;
    PQueue tempPQ;
    PQueue tq = this->pqueue;
    CQueue copyQ;
    copyQ.Init();
    tempPQ.Init(PQWeightComp);

    while(!tq.IsEmpty())
        copyQ.Enqueue(tq.Dequeue());

    while(TRUE)
    {
        Edge rEdge = pqueue.Dequeue();
        copyQ.Dequeue();
        numMSTEdge -= 1;
        // std::cout << "1" << std::endl;
        if(disConnected(copyQ, rEdge.v1) || disConnected(copyQ, rEdge.v2))
        {
            // std::cout << "2" << std::endl;
            numMSTEdge += 1;
            tempPQ.Insert(rEdge);       // 뺐다 넣을거 임시로 넣어놓는 곳
            copyQ.Enqueue(rEdge);
        }
        if(numMSTEdge+1 == this->numV)
        {
            // std::cout<< "2.5" << std::endl;
            break;
        }
    }
    // std::cout << "3" << std::endl;
    while(!tempPQ.IsEmpty())
    {
        // std::cout << "4" << std::endl;
        pqueue.Enqueue(tempPQ.Dequeue());
    }
    // std::cout << "success" << std::endl;
}

void ALGraph::ShowGraphEdgeWeightInfo()     // MST 출력
{
    PQueue copyPQ = this->pqueue;
    Edge tEdge;
    while(!copyPQ.IsEmpty())
    {
        tEdge = copyPQ.Dequeue();
        std::cout << "(" << char(tEdge.v1+65) << ", " << char(tEdge.v2+65) << ") - " << tEdge.weight << std::endl;
    }
}
