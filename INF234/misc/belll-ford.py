import random

'''
Bellfordman algorithm
input: graph G = (V, E), source vertex s
output: shortest path from s to all vertices reachable from s
'''

def shortest_path(G, s):
    n = len(G)
    # Step 1: Initialize distances from the source to all vertices as infinite
    d = [float('inf')] * n
    d[s] = 0  # Distance to the source is always 0

    # Step 2: Relax edges (n-1) times
    for i in range(n-1):
        for u in range(n):
            for v in G[u]:
                # Relaxation step: If a shorter path is found, update the distance
                if d[v] > d[u] + G[u][v]:
                    d[v] = d[u] + G[u][v]
        print(f"After iteration {i+1}: {d}")

    # Step 3 (Optional): Check for negative weight cycles
    for u in range(n):
        for v in G[u]:
            if d[v] > d[u] + G[u][v]:
                print("Graph contains a negative weight cycle")
                return None

    return d  # Return the list of shortest distances


# Example graph (using vertex indices)
def generate_random_graph(n, max_weight=10):
    G = []
    for i in range(n):
        edges = {}
        for j in range(n):
            if i != j and random.random() < 0.5:  # Randomly decide if there's an edge
                edges[j] = random.randint(-max_weight, max_weight)
        G.append(edges)
    return G

# Generate a random graph with 6 vertices
G = generate_random_graph(4, 5)

# Print the generated graph for reference
for i, edges in enumerate(G):
    print(f"Vertex {i} connects to: {edges}")

# Call the function with source vertex 0
print("Final shortest distances:", shortest_path(G, 0))
