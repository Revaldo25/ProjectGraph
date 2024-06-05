#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** head;
};

Node* newNode(int dest);
Graph* createGraph(int V);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
int hasEdge(Graph* graph, int src, int dest);
void CekEdge(Graph* graph);

#endif
