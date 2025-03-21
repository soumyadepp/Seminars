#include "directed_graph.h"
#include "strongly_connected.h"
#include <iostream>

using namespace std;

/**
 * @brief Main function to demonstrate Kosaraju's algorithm
 *        for finding strongly connected components (SCCs) in a directed graph.
 *
 * The user is prompted to input the number of edges and then each edge in the graph.
 * Kosaraju's algo is executed and the SCCs are displayed as result
 *
 * @return int Exit status of the program.
 */
int main()
{
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g(0);

    cout << "Enter edges in format (source destination):\n";
    for (int i = 0; i < edges; ++i)
    {
        string u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "\nGraph Structure:\n";
    g.displayGraph();

    cout << "\n====== Running Kosaraju's Algorithm ======\n";
    KosarajuAlgorithm::run(g);

    return 0;
}
