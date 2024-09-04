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


# Greedy Algorithms
Always gives an optimal solution

### 4.1 Interval Scheduling: The greedy algorithm stays ahead
- Designing a rule set for the greedy algorithm to operate about
- solution: We request i for which f(i) is as small as possible 
```IntervalAlgorithm
Initially let R be the set of all requests, and let A be empty
While R is not yet empty
	Choose a request i ∈ R that has the smallest finishing time
	Add request i to A
	Delete all requests from R that are not compatible with request i
EndWhile
Return the set A as the set of accepted requests
```

##### Analyzing the Algorithm
- Given that A is our solution, $|A| = |O|$, or $A\in O$ , depending if O is one of the optimal solutions or a set of the optimal solutions
- Inductive proof that our greedy algorithm stays ahead
	- Base case: Our greedy algorithm guarantees us that $f(i_1)\leq f(j_1)$, where i is the first segment in our greedy algo, and j is another segment in the optimal solution set
	- Inductive step: $r\geq 1$, we will assume that it is true for $r-1$.
		- $f(i_{i-1}) \leq f(j_{r-1})$ then $f(i_{i-1}) \leq s(j_{r})$, we know that $j_r$ is one of the potential candidates for $i_{i-1}$, and it did not choose it, therefore $f(i_{i}) \leq f(j_{r})$ must be true
- The greedy algo returns an optimal set A
	- Given that Greedy is always ahead for every step given the induction above, if a sol in O has one extra, A should also take it since it is always ahead, and will therefore always be able to take a new one
- Interval partitioning
	- The number of resources needed is at least the depth of the set of intervals
	- 