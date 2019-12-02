#include <iostream>
#include "ALGraphDFS.h"
#include "ALGraphDFS.cpp"
#include "../DLinkedList.cpp"
#include "ArrayBaseStack.cpp"

int main(void)
{
    ALGraphDFS graph;
    graph.Init(7);

    graph.AddEdge(A, B);
    graph.AddEdge(A, D);
    graph.AddEdge(B, C);
    graph.AddEdge(D, C);
    graph.AddEdge(D, E);
    graph.AddEdge(E, F);
    graph.AddEdge(E, G);

    graph.ShowGraphEdgeInfo();

    graph.DFSShowGraphVertex(A); std::cout << std::endl;
    // graph.DFSShowGraphVertex(C); std::cout << std::endl;
    // graph.DFSShowGraphVertex(E); std::cout << std::endl;
    // graph.DFSShowGraphVertex(G); std::cout << std::endl;

    graph.Destroy();
    return 0;
}