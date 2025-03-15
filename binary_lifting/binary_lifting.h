#ifndef BINARY_LIFTING_H
#define BINARY_LIFTING_H

#include "ancestor_query.h"
#include <vector>
#include <cmath>

/**
 * @class BinaryLifting
 * @brief Concrete implementation of the AncestorQuery interface using Binary Lifting technique.
 *
 * This class allows efficient computation of k-th ancestors and lowest common managers (LCM) in a tree
 * representing a company's organizational hierarchy. Binary lifting precomputes ancestors for each node
 * to answer queries in O(log N) time.
 */
class BinaryLifting : public AncestorQuery
{
private:
    /**
     * @brief up[node][i] stores the 2^i-th ancestor of node.
     */
    std::vector<std::vector<int>> up;

    /**
     * @brief depth[node] stores the depth of the node from the root.
     */
    std::vector<int> depth;

    /**
     * @brief adj[node] holds the list of immediate subordinates (children) of the node.
     */
    std::vector<std::vector<int>> adj;

    /**
     * @brief LOG is the maximum power of two required for binary lifting (log2(n)).
     */
    int LOG;

    /**
     * @brief n is the number of nodes (employees) in the company hierarchy.
     */
    int n;

    /**
     * @brief Performs a DFS traversal to compute depths and populate the 'up' table.
     *
     * @param node Current node being visited.
     * @param parent Parent of the current node.
     */
    void dfs(int node, int parent);

public:
    /**
     * @brief Constructs the BinaryLifting object for a given number of nodes.
     *
     * @param size The total number of nodes (employees) in the tree.
     */
    explicit BinaryLifting(int size);

    /**
     * @brief Adds a bidirectional edge between two nodes in the company hierarchy.
     *
     * @param u First employee.
     * @param v Second employee.
     */
    void addEdge(int u, int v) override;

    /**
     * @brief Preprocesses the tree for binary lifting starting from the given root node.
     *
     * This function prepares the data structures to efficiently answer ancestor and LCM queries.
     * It should be called once after constructing the tree with addEdge().
     *
     * @param root The root of the tree (usually the CEO or the top-most manager).
     */
    void preprocess(int root) override;

    /**
     * @brief Finds the k-th ancestor (manager) of the given node (employee).
     *
     * @param node The employee for whom the ancestor is to be found.
     * @param k The level of the ancestor (e.g., k=1 returns the direct manager).
     * @return The k-th ancestor of the given node, or -1 if it doesn't exist.
     */
    int getKthAncestor(int node, int k) override;

    /**
     * @brief Finds the lowest common manager (LCM) between two employees.
     *
     * This function returns the lowest common ancestor of two nodes in the tree,
     * representing their lowest shared manager in the corporate hierarchy.
     *
     * @param u The first employee.
     * @param v The second employee.
     * @return The lowest common manager of employees u and v.
     */
    int getLowestCommonManager(int u, int v) override;
};

#endif // BINARY_LIFTING_H
