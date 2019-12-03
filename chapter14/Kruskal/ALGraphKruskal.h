#ifndef __AL_GRAPH_KRUSKAL__H__
#define __AL_GRAPH_KRUSKAL__H__

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum {A, B, C, D, E, F, G, H, I, J};

class ALGraph {
    public:
        int numV;
        int numE;
        List * adjList;
        int * visitInfo;
        PQueue pqueue;

        void Init(int nv);
        void Destroy();
        void AddEdge(int fromV, int toV, int weight);
        void ShowGraphEdgeInfo();
        int VisitVertex(int visitV);
        void DFSShowGraphVertex(int startV);
        void ConKruskalMST();
        void ShowGraphEdgeWeightInfo();
};

#endif