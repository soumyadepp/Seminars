#include "strongly_connected.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

// ---------- Kosaraju ----------

namespace
{
    // Global variables used for Kosaraju's Algorithm
    vector<bool> visited;
    stack<int> finishStack;
    int V;

    /**
     * @brief Performs DFS traversal to fill the finish stack based on finishing times.
     *
     * @param graph Adjacency list representation of the directed graph.
     * @param u Current vertex being visited.
     */
    void dfsFillOrder(const vector<vector<int>> &graph, int u)
    {
        visited[u] = true;
        for (int v : graph[u])
        {
            if (!visited[v])
            {
                dfsFillOrder(graph, v);
            }
        }
        finishStack.push(u);
    }

    /**
     * @brief Performs DFS traversal on the reversed graph and prints the nodes in the SCC.
     *
     * @param graph Adjacency list representation of the reversed graph.
     * @param u Current vertex being visited.
     * @param directed_graph Reference to the original Graph object (to map IDs to names).
     */
    void dfsOnReversedGraph(const vector<vector<int>> &graph, int u, Graph &directed_graph)
    {
        visited[u] = true;
        cout << directed_graph.getName(u) << " ";
        for (int v : graph[u])
        {
            if (!visited[v])
            {
                dfsOnReversedGraph(graph, v, directed_graph);
            }
        }
    }
}

/**
 * @brief Runs Kosaraju's Algorithm to find and print all strongly connected components (SCCs) in a directed graph.
 *
 * The algorithm works in two passes:
 * 1. Fills nodes in a stack according to their finishing times using DFS on the original graph.
 * 2. Performs DFS on the reversed graph in the order defined by the stack to identify SCCs.
 *
 * @param directed_graph Reference to the Graph object representing the directed graph.
 * @return int The number of strongly connected components found.
 */
int KosarajuAlgorithm::run(Graph &directed_graph)
{
    V = directed_graph.getV();
    visited.assign(V, false);

    const vector<vector<int>> &adj = directed_graph.getAdj();
    const vector<vector<int>> &revAdj = directed_graph.getRevAdj();

    // First pass: fill stack by finish time
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            dfsFillOrder(adj, i);
        }
    }

    visited.assign(V, false);
    int sccCount = 0;

    cout << "Strongly Connected Components (Kosaraju):\n";

    // Second pass: process nodes in reverse finish time order
    while (!finishStack.empty())
    {
        int u = finishStack.top();
        finishStack.pop();

        if (!visited[u])
        {
            cout << "SCC #" << sccCount + 1 << ": ";
            dfsOnReversedGraph(revAdj, u, directed_graph);
            cout << endl;
            ++sccCount;
        }
    }

    return sccCount;
}
