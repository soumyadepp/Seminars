from collections import defaultdict
from typing import Dict, List


class Graph:
    def __init__(self, vertices: int):
        self.V = vertices
        self.graph = defaultdict(list)
        self.rev_graph = defaultdict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.rev_graph[v].append(u)

    def dfs(self, v: int, visited: Dict[int, bool], stack: List[int]):
        visited[v] = True
        for neighbour in self.graph[v]:
            if not visited[v]:
                self.dfs(self, neighbour, visited, stack)

        stack.append(v)

    def dfs_reverse(self, v: int, visited: Dict[int, bool], component: List[int]):
        visited[v] = True
        component.append(v)
        for neighbour in self.rev_graph[v]:
            if not visited[neighbour]:
                self.dfs_reverse(neighbour, visited, component)

    def kosaraju_algorithm(self):
        stack = []
        visited = [False] * (self.V + 1)

        for i in range(1, self.V + 1):
            if not visited[i]:
                self.dfs(i, visited, stack)

        visited = [False] * (self.V + 1)
        sccs = []

        while stack:
            v = stack.pop()
            component = []
            if not visited[v]:
                self.dfs_reverse(v, visited, component)
                sccs.append(component)
        return sccs


graph = Graph(7)
graph.add_edge(1, 2)
graph.add_edge(2, 3)
graph.add_edge(3, 1)
graph.add_edge(4, 5)
graph.add_edge(5, 6)
graph.add_edge(6, 7)
graph.add_edge(7, 4)

sccs = graph.kosaraju_algorithm()

print("Strongly connected components:", sccs)
