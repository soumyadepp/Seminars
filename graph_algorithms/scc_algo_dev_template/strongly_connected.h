#ifndef STRONGLY_CONNECTED_H
#define STRONGLY_CONNECTED_H

#include "directed_graph.h"

/**
 * @brief Implements Kosaraju's algorithm to find strongly connected components in a directed graph.
 *
 * Kosaraju's algorithm works in two passes:
 * 1. Perform a DFS on the original graph and push nodes onto a stack based on their finish times.
 * 2. Perform DFS on the reversed graph in the order of the stack to find strongly connected components (SCCs).
 */
class KosarajuAlgorithm
{
public:
    /**
     * @brief Runs Kosaraju's algorithm on the given directed graph.
     *
     * This method finds and prints all strongly connected components (SCCs) in the graph.
     *
     * @param directed_graph The directed graph to process.
     * @return int The number of strongly connected components found.
     */
    static int run(Graph &directed_graph);
};

/**
 * @brief Implements Tarjan's algorithm to find strongly connected components in a directed graph.
 *
 * Tarjan's algorithm uses DFS and keeps track of low-link values to find SCCs in a single pass.
 * It is more efficient than Kosaraju's algorithm because it doesn't require reversing the graph or performing two passes.
 */
class TarjanAlgorithm
{
public:
    /**
     * @brief Runs Tarjan's algorithm on the given directed graph.
     *
     * This method finds and prints all strongly connected components (SCCs) in the graph.
     *
     * @param directed_graph The directed graph to process.
     * @return int The number of strongly connected components found.
     */
    static int run(Graph &directed_graph);
};

#endif