# Task 1
```rar
To compute a topological ordering of G:
	while Active nodes
		if node with 0 incoming exissts:
			Find a node v with no incoming edges and order it first 
			Delete v from G
			add V to ordering
		else:
			delete topological ordering
			find a node v with lowest incoming edges
			use DFS until you find node v
				append node
			return ordering 
	return topological ordering
```
