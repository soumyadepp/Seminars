#include "directed_graph.h"

/**
 * @brief Constructs a Graph object with the given number of vertices.
 *
 * Initializes the adjacency and reverse adjacency lists with the specified
 * number of vertices.
 *
 * @param vertices Initial number of vertices in the graph.
 */
Graph::Graph(int vertices) : V(0)
{
    adj.resize(vertices);
    revAdj.resize(vertices);
}

/**
 * @brief Gets the unique integer ID for a given node name.
 *
 * If the node name does not exist, assigns a new ID to it and updates
 * internal data structures accordingly.
 *
 * @param name The name of the node (website name).
 * @return The unique integer ID corresponding to the node name.
 */
int Graph::getId(const string &name)
{
    if (nameToId.find(name) == nameToId.end())
    {
        nameToId[name] = V++;
        idToName.push_back(name);
        adj.resize(V);
        revAdj.resize(V);
    }
    return nameToId[name];
}

/**
 * @brief Adds a directed edge from node uName to node vName.
 *
 * Internally resolves the unique IDs of the nodes and updates both
 * the adjacency and reverse adjacency lists.
 *
 * @param uName The name of the source node (website).
 * @param vName The name of the destination node (website).
 */
void Graph::addEdge(const string &uName, const string &vName)
{
    int u = getId(uName);
    int v = getId(vName);

    adj[u].push_back(v);
    revAdj[v].push_back(u);
}

/**
 * @brief Returns the number of vertices currently in the graph.
 *
 * @return The number of vertices.
 */
int Graph::getV() const
{
    return V;
}

/**
 * @brief Returns the adjacency list of the graph.
 *
 * @return A constant reference to the adjacency list.
 */
const vector<vector<int>> &Graph::getAdj() const
{
    return adj;
}

/**
 * @brief Returns the reverse adjacency list of the graph.
 *
 * @return A constant reference to the reverse adjacency list.
 */
const vector<vector<int>> &Graph::getRevAdj() const
{
    return revAdj;
}

/**
 * @brief Returns the name of the node corresponding to the given ID.
 *
 * @param id The unique integer ID of the node.
 * @return The name of the node.
 */
string Graph::getName(int id) const
{
    return idToName[id];
}

/**
 * @brief Displays the graph's adjacency list.
 *
 * Outputs each node and its corresponding adjacent nodes (outgoing edges)
 * by resolving their names from the internal ID mapping.
 */
void Graph::displayGraph() const
{
    for (int i = 0; i < V; ++i)
    {
        cout << getName(i) << " -> ";
        for (int v : adj[i])
        {
            cout << getName(v) << " ";
        }
        cout << endl;
    }
}
