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

# Task 2
**Butterfly algorithm**
*classify a butterflies as of group A or B*
*They can judge pair (i, j) as different, same, or no judgement (ambiguous)*
- input: n butterflies
- truthvalue if the set is proper or not

```python ish
adj = make an adjeceny list from given information # ignore ambigous
#can end up in different gropus of nodes
color = [-1] * n 

for i in 0..n # if not color, then it isnt connected
	if color[i] == -1:
		queue = [i]
		color[i] = 0
		while queue:
			node_i = queue.pop()
			current_color = color[node_i]
			for neigh_i, rel in adj[node_i]:
				if color[neigh_i] == -1:
					if rel == same
						color[neigh_i] = current_color
					else:
						color[neigh_i] = 1 - current_color
					queue.append(neigh_i)
				else:
					if rel == same and color[node_i] != color[neigh_i]:
						not happening
					if rel == diff and color[node_i] == color[neigh_i]
						not happening

return True
```

Given that we can divide this into two groups, this can be seen as 2-colorable


# Task 3
A group of n nodes if connected to all others will always have a grade of n-1
so if we split the nodes in two groups, the total number grade will be n/2-1
If we then connect it the two groups each node would have at least n grade
i have assumed that it is rounded up (if rounded down, it will be false, but i wont cover it)

Proof by contradiction
- G is disconnected
	- therefore there exist at least 2 components which are not connected: $C_1, C_2$ 
		- more components would mean lower grades per component
	- if we split the c 5050
		- both groups has to have high enough grades
	- $|C_1| = \frac{n}{2}$ 
		- A complete group would have a grade of n - 1
	- Therefore each node in  $C_1$ has a grade of $\frac{n}{2} - 1$ 
	- which means G has to be connected

# Task 4

Given a base case with n=1 box, the most optimal solution would be to send one truck, the greedy algorithm algorithm will fit the one box with one truck

Inductive step:
- We assume that the n boxes was sent in optimal full trucks
- for the n+1 truck the algorithm will try to fit it in the current truck, if it doesn't fit, the truck is optimally full, there is no better way to do the boxes.
- That is what is meant by staying ahead
	- Maximum number of boxes is sent as early as possible
- An optimal solution is just a solution 
- Therefore the $T_{greedy} \leq T_O$
