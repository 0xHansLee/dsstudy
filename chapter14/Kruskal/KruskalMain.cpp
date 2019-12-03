#include <iostream>
#include "ALGraphKruskal.h"
#include "ALGraphKruskal.cpp"
#include "ArrayBaseStack.cpp"
#include "CircularQueue.cpp"
#include "DLinkedList.cpp"
#include "PriorityQueue.cpp"
#include "UsefulHeap.cpp"

int main(void)
{
    ALGraph graph;
    graph.Init(6);

    graph.AddEdge(A, B, 9);
    graph.AddEdge(B, C, 2);
    graph.AddEdge(A, C, 12);
    graph.AddEdge(A, D, 8);
    graph.AddEdge(D, C, 6);
    graph.AddEdge(A, F, 11);
    graph.AddEdge(F, D, 4);
    graph.AddEdge(D, E, 3);
    graph.AddEdge(E, C, 7);
    graph.AddEdge(F, E, 13);

    graph.ShowGraphEdgeInfo();
    graph.ConKruskalMST();
    graph.ShowGraphEdgeWeightInfo();

    graph.Destroy();
    return 0;
}