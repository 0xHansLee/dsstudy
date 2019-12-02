#include <iostream>
#include "ALGraph.h"
#include "DLinkedList.h"
// #include "ALGraph.cpp"
// #include "DLinkedList.cpp"

int main(void)
{
    ALGraph graph;
    graph.Init(5);

    graph.AddEdge(A, B);
    graph.AddEdge(A, D);
    graph.AddEdge(B, C);
    graph.AddEdge(C, D);
    graph.AddEdge(D, E);
    graph.AddEdge(E, A);

    graph.ShowGraphEdgeInfo();
    graph.Destroy();
    return 0;
}