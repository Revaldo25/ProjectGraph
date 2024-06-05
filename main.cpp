#include "header.h"
#include <iostream>

using namespace std;

int main() {
    int V, E, src, dest;

    cout << "Masukkan jumlah vertex: ";
    cin >> V;

    Graph* graph = createGraph(V);

    cout << "Masukkan jumlah edge: ";
    cin >> E;

    for (int i = 0; i < E; ++i) {
        cout << "Masukkan edge (source destination): ";
        cin >> src >> dest;
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    char choice;
    do {
        CekEdge(graph);
        cout << "Ingin mengecek edge lain? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
