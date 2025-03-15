#include "binary_lifting.h"
#include <iostream>

/**
 * @brief Constructs the BinaryLifting object.
 * Initializes necessary data structures based on the number of nodes.
 *
 * @param size The total number of employees (nodes) in the corporate hierarchy.
 */
BinaryLifting::BinaryLifting(int size)
{
    n = size;
    LOG = std::ceil(std::log2(n));

    // Initialize 'up' table for storing 2^i ancestors
    up.assign(n, std::vector<int>(LOG + 1, -1));

    // Initialize depth array for each node
    depth.assign(n, 0);

    // Initialize adjacency list for each node
    adj.resize(n);
}

/**
 * @brief Adds a bidirectional connection (edge) between two employees in the hierarchy.
 *
 * @param u Employee u
 * @param v Employee v
 */
void BinaryLifting::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

/**
 * @brief Prepares the data structures for answering ancestor queries.
 * Should be called after all edges are added.
 *
 * @param root The starting node (e.g., CEO or top manager).
 */
void BinaryLifting::preprocess(int root)
{
    dfs(root, -1);
}

/**
 * @brief Depth-first traversal to populate ancestor table (`up`) and depth array.
 *
 * @param node Current node being processed.
 * @param parent The immediate parent (manager) of the current node.
 */
void BinaryLifting::dfs(int node, int parent)
{
    up[node][0] = parent;

    // Precompute 2^i-th ancestors for current node
    for (int i = 1; i <= LOG; ++i)
    {
        int prevAncestor = up[node][i - 1];
        if (prevAncestor != -1)
            up[node][i] = up[prevAncestor][i - 1];
        else
            up[node][i] = -1;
    }

    // Recursively process all subordinates (children)
    for (int neighbor : adj[node])
    {
        if (neighbor != parent)
        {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node);
        }
    }
}

/**
 * @brief Returns the k-th ancestor (manager) of a given employee.
 *
 * @param node The employee whose ancestor is queried.
 * @param k The number of levels up in the hierarchy.
 * @return int The k-th ancestor of the node, or -1 if it doesn't exist.
 */
int BinaryLifting::getKthAncestor(int node, int k)
{
    for (int i = 0; i <= LOG; ++i)
    {
        if (node == -1)
            break;

        // If the i-th bit in k is set, move up 2^i levels
        if (k & (1 << i))
        {
            node = up[node][i];
        }
    }
    return node;
}

/**
 * @brief Returns the lowest common manager (ancestor) of two employees in the hierarchy.
 *
 * @param u The first employee.
 * @param v The second employee.
 * @return int The lowest common manager of u and v.
 */
int BinaryLifting::getLowestCommonManager(int u, int v)
{
    // Ensure u is the deeper node
    if (depth[u] < depth[v])
        std::swap(u, v);

    // Bring u up to the same depth as v
    int diff = depth[u] - depth[v];
    u = getKthAncestor(u, diff);

    // If they meet at the same node, return it
    if (u == v)
        return u;

    // Move both u and v up until their ancestors match
    for (int i = LOG; i >= 0; --i)
    {
        if (up[u][i] != -1 && up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    // Return their lowest common ancestor (manager)
    return up[u][0];
}
