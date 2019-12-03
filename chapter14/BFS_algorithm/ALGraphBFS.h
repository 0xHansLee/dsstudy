#ifndef __AL_Graph_DFS__H__
#define __AL_Graph_DFS__H__

#include "../DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

class ALGraphBFS {
    public:
        int numV;
        int numE;
        List * adjList;
        int * visitInfo;

        void Init(int nv);
        void Destroy();
        void AddEdge(int fromV, int toV);
        void ShowGraphEdgeInfo();
        int VisitVertex(int visitV);
        void BFSShowGraphVertex(int startV);
};

#endif