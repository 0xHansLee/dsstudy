#ifndef __AL_Graph__H__
#define __AL_Graph__H__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

class ALGraph {
    public:
        int numV;
        int numE;
        List * adjList;

        void Init(int nv);
        void Destroy();
        void AddEdge(int fromV, int toV);
        void ShowGraphEdgeInfo();
};

#endif