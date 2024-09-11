
# 4.2 Scheduling to minimize lateness: An Exchange Argument

Analyzing the algorithm
	- A' has an inversion if there is a deadline $d_j < d_i$ ,and i is scheduled before j 


# 4.4 Shortest Paths in a Graph


+ Consider the set S at any point in the algorithm’s execution. For each
u ∈ S, the path Pu is a shortest s-u path.

- $\mathcal{L}(P')\geq\mathcal{P_x}$
- Will always find the shortest path in a set of of lengths $\geq$ 0

##### Dijstra proof by induction
- all distances has to be 0 <= d < \infty
- Base case
	- the shortest distance from node s to s is 0, therefore it will choose this, and the algorithm is correct
- Inductive hypothesis
	- Assume that after k iterations of dij, the algorithm has correctly identified the shortest path from the source s to k nodes. Let S_k represent the setof these nodes and each node in S_k has its shortest distance from s correctly calculated
- Inductive step
	- k + 1 iteration will identify the next node with the shortest distance from s
		1. v is the node selected that is not in S_k, and has the smallest distance from s
		2. for the sake of contradiction, that there is another node u with smaller collective distance than v called u
			1. this contradicts our assumption, that in step 1 it chooses the one with the smallest collective distance
		3. it then  updates its neighbor if a shorter distance is found

# 4.5 Minimum Spanning tree