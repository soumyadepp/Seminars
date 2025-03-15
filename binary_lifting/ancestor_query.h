#ifndef ANCESTOR_H
#define ANCESTOR_H

#include <vector>

/**
 * @brief Abstract base class for ancestor queries on a tree structure.
 *
 * This interface provides common operations such as finding the k-th ancestor
 * of a node or the lowest common manager (ancestor) between two nodes.
 * Concrete implementations can use algorithms like Binary Lifting or Euler Tour + RMQ.
 */
class AncestorQuery
{
public:
    /**
     * @brief Virtual destructor for safe polymorphic destruction.
     */
    virtual ~AncestorQuery() {}

    /**
     * @brief Preprocesses the tree to enable efficient ancestor and LCA queries.
     *
     * Should be called after constructing the tree with addEdge().
     *
     * @param root The root node of the tree (typically the CEO or top-level manager).
     */
    virtual void preprocess(int root) = 0;

    /**
     * @brief Finds the k-th ancestor (manager) of a given node (employee).
     *
     * @param node The employee whose ancestor is to be found.
     * @param k The number of levels to move up in the hierarchy.
     * @return int The k-th ancestor node ID, or -1 if it does not exist.
     */
    virtual int getKthAncestor(int node, int k) = 0;

    /**
     * @brief Finds the lowest common manager (ancestor) of two employees.
     *
     * @param u The first employee's node ID.
     * @param v The second employee's node ID.
     * @return int The node ID of the lowest common manager.
     */
    virtual int getLowestCommonManager(int u, int v) = 0;

    /**
     * @brief Adds a bidirectional edge between two nodes to build the hierarchy tree.
     *
     * Typically used to connect a manager with their direct report.
     *
     * @param u The first node (employee/manager).
     * @param v The second node (employee/manager).
     */
    virtual void addEdge(int u, int v) = 0;
};

#endif // ANCESTOR_H
