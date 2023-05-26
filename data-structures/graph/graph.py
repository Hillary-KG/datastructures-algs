"""
A graph is a non-linear data structure that consists of a set of vertices (also called nodes) and a set of edges connecting these vertices.
The edges can be directed (arrows) or undirected, and the vertices may be labeled.
Graphs are often used to represent networks, such as social networks or communication networks.

There are several ways to implement a graph in Python. 
One way is to use an adjacency matrix, which is a two-dimensional matrix that indicates which vertices are adjacent (connected) to which other vertices. 
Here is an example of a graph implementation using an adjacency matrix:
"""

class Graph:
    def __init__(self, num_vertices):
        # initialize the adjacency matrix with 0s
        self.adj_matrix = [[0 for _ in range(num_vertices)] for _ in range(num_vertices)]
        # store the number of vertices
        self.num_vertices = num_vertices

    def add_edge(self, v1, v2):
        # set the value at the v1 row and v2 column to 1 to indicate that v1 and v2 are connected
        self.adj_matrix[v1][v2] = 1
        # if the graph is undirected, set the value at the v2 row and v1 column to 1 as well
        self.adj_matrix[v2][v1] = 1

    def remove_edge(self, v1, v2):
        # set the value at the v1 row and v2 column to 0 to indicate that v1 and v2 are not connected
        self.adj_matrix[v1][v2] = 0
        # if the graph is undirected, set the value at the v2 row and v1 column to 0 as well
        self.adj_matrix[v2][v1] = 0

    def is_connected(self, v1, v2):
        # return True if the value at the v1 row and v2 column is 1, False otherwise
        return self.adj_matrix[v1][v2] == 1

# usage
graph = Graph(4)
graph.add_edge(0, 1)
graph.add_edge(1, 2)
graph.add_edge(2, 3)
print(graph.is_connected(0, 1))  # True
print(graph.is_connected(1, 3))  # False
graph.remove_edge(1, 2)
print(graph.is_connected(1, 2))  # False
