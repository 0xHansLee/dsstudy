#include <iostream>
#include "ALGraphBFS.h"
#include "CircularQueue.h"
#include "ALGraphBFS.cpp"
#include "CircularQueue.cpp"
#include "../DLinkedList.cpp"

int main(void)
{
    ALGraphBFS graph;
    graph.Init(7);

    graph.AddEdge(A, B);
    graph.AddEdge(A, D);
    graph.AddEdge(B, C);
    graph.AddEdge(D, C);
    graph.AddEdge(D, E);
    graph.AddEdge(E, F);
    graph.AddEdge(E, G);

    graph.ShowGraphEdgeInfo();
    graph.BFSShowGraphVertex(A); std::cout << std::endl;
    graph.BFSShowGraphVertex(C); std::cout << std::endl;
    graph.BFSShowGraphVertex(E); std::cout << std::endl;
    graph.BFSShowGraphVertex(G); std::cout << std::endl;

    graph.Destroy();
    return 0;
}