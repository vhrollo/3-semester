# 3.4
bipartite graph
- two sets where every edge can start in set V and end in set W
- cannot have an odd cycle
- all nodes are connected

- stronly connected
	- path from u, to w, and opposite

# 3.6 DAG
- A very common structure in computer science, because many kinds of dependency networks of the type.
- precedence relations
- topological ordering
	- $\forall (v_i, v_j) \in E \Rightarrow i < j$
	- Directed Acyclic Graph
- To check if G is a DAG
```
To compute a topological ordering of G: 
Find a node v with no incoming edges and order it first 
Delete v from G Recursively compute a topological ordering of G−{v} and append this order after v	
```
