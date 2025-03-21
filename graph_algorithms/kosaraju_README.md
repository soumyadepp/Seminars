# Kosaraju's Algorithm

## Overview

**Kosaraju's Algorithm** is an efficient method to find Strongly Connected Components (SCCs) in a directed graph. A strongly connected component is a maximal set of vertices such that each vertex is reachable from every other vertex in the set.

Kosaraju's algorithm runs in _O(V + E)_ time, where:

_V_ is the number of vertices.
_E_ is the number of edges.

## Prerequisites

Before diving into Kosaraju's algorithm, you should be familiar with:

1. Graph Terminology (Directed Graphs, Components)
2. Depth-First Search (DFS)
3. Stack Data Structure
4. Graph Traversal

## Intuition

A **Strongly Connected Component (SCC)** is like a closed group of nodes, where you can travel between any two nodes inside the group but not necessarily outside of it.

Kosaraju's algorithm works by performing two DFS traversals, and it leverages the fact that reversing the graph helps in discovering SCCs efficiently.

## Algorithm Steps

1. Perform DFS and store vertices by finish time
   Start DFS traversal from any unvisited node.
   After visiting all reachable nodes from a vertex, push it onto a stack.
   The stack will hold nodes ordered by decreasing finish time.
2. Transpose the Graph (Reverse all edges)
   Create a new graph where every edge (u -> v) becomes (v -> u).
3. Perform DFS on the Transposed Graph
   Pop nodes one by one from the stack and perform DFS on the transposed graph.
   Each DFS traversal will give you a strongly connected component (SCC).
   Repeat until the stack is empty.

## Time Complexity

| Operation            | Complexity |
| -------------------- | ---------- |
| First DFS traversal  | O(V + E)   |
| Graph transposition  | O(V + E)   |
| Second DFS traversal | O(V + E)   |

#### Total Time Complexity: O(V + E)

## Applications

- **Web Crawlers** (to find groups of web pages with mutual links).
- **Social Networks** (to detect communities).
- **Compilers** (to find strongly connected components in dependency graphs).
- **Electric Circuits** (for strongly connected components in circuit design)

## Visualization

Here’s a simple way to think of it:

1. DFS 1: Explore everything and note finish times.
   Transpose: Flip the graph.
2. DFS 2: Explore again using the finish times, revealing SCCs.
