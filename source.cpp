#include "header.h"

using namespace std;

Node* newNode(int dest) {
    Node* node = new Node;
    node->dest = dest;
    node->next = nullptr;
    return node;
}

Graph* createGraph(int V) {
    Graph* graph = new Graph;
    graph->V = V;
    graph->head = new Node*[V]();
    for (int i = 0; i < V; ++i) {
        graph->head[i] = nullptr;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* node = newNode(dest);
    node->next = graph->head[src];
    graph->head[src] = node;

    // Since the graph is undirected, add an edge from dest to src also
    node = newNode(src);
    node->next = graph->head[dest];
    graph->head[dest] = node;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        Node* crawl = graph->head[v];
        cout << "\nAdjacency list dari vertex " << v << " head";
        while (crawl) {
            cout << "-> " << crawl->dest;
            crawl = crawl->next;
        }
        cout << endl;
    }
}

int hasEdge(Graph* graph, int src, int dest) {
    Node* crawl = graph->head[src];
    while (crawl) {
        if (crawl->dest == dest) {
            return 1;
        }
        crawl = crawl->next;
    }
    return 0;
}

void CekEdge(Graph* graph) {
    int src, dest;
    cout << "\nMasukkan vertex yang dicari: ";
    cin >> src;
    cout << "Masukkan vertex tujuan: ";
    cin >> dest;

    if (hasEdge(graph, src, dest)) {
        cout << "\nEdge dari " << src << " ke " << dest << " ada." << endl;
    } else {
        cout << "\nEdge dari " << src << " ke " << dest << " tidak ada." << endl;
    }
}
