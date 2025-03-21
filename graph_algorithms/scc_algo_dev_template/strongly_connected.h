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

#endif