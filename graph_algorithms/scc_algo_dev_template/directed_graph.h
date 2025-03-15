#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/**
 * @brief Represents a directed graph where nodes are identified by string names.
 *
 * The Graph class supports adding edges between nodes, retrieving adjacency lists,
 * and displaying the graph. Internally, node names are mapped to unique integer IDs
 * for efficient storage and lookup.
 */
class Graph
{
private:
    /**
     * @brief Number of vertices in the graph.
     */
    int V;

    /**
     * @brief Adjacency list representing edges from each node.
     */
    vector<vector<int>> adj;

    /**
     * @brief Reverse adjacency list representing incoming edges to each node.
     */
    vector<vector<int>> revAdj;

    /**
     * @brief Maps node names (strings) to unique integer IDs.
     */
    map<string, int> nameToId;

    /**
     * @brief Maps unique integer IDs back to node names.
     */
    vector<string> idToName;

public:
    /**
     * @brief Constructs a Graph with a specified number of vertices.
     *
     * @param vertices Initial number of vertices in the graph.
     */
    Graph(int vertices);

    /**
     * @brief Adds a directed edge from node u to node v.
     *
     * @param u The name of the source node.
     * @param v The name of the destination node.
     */
    void addEdge(const string &u, const string &v);

    /**
     * @brief Returns the number of vertices in the graph.
     *
     * @return The number of vertices.
     */
    int getV() const;

    /**
     * @brief Returns the adjacency list of the graph.
     *
     * @return A constant reference to the adjacency list.
     */
    const vector<vector<int>> &getAdj() const;

    /**
     * @brief Returns the reverse adjacency list of the graph.
     *
     * @return A constant reference to the reverse adjacency list.
     */
    const vector<vector<int>> &getRevAdj() const;

    /**
     * @brief Returns the name of the node corresponding to the given ID.
     *
     * @param id The unique integer ID of the node.
     * @return The name of the node.
     */
    string getName(int id) const;

    /**
     * @brief Returns the unique integer ID for a given node name.
     *
     * If the node name does not exist in the graph, a new ID is assigned.
     *
     * @param name The name of the node.
     * @return The unique integer ID of the node.
     */
    int getId(const string &name);

    /**
     * @brief Displays the graph's adjacency list.
     *
     * Outputs each node and its outgoing edges.
     */
    void displayGraph() const;
};

#endif // GRAPH_H
