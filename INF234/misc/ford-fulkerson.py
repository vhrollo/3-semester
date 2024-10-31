import random as r

'''
Ford-Fulkerson algorithm
input: graph G = (V, E), source vertex s, sink vertex t
output: maximum flow from s to t
'''

def ford_fulkerson(graph, source, sink):
    n = len(graph)
    flow = 0
    parent = [-1] * n
    while True:
        visited = [False] * n
        
    


    pass


# Example graph (using vertex indices)
G = [{1: 3, 2: 2}, {2: 2, 3:2}, {3:3}, {}]