
# Network flow
*Directed graphs*, $G=(V_i, E), c : E\rightarrow \mathbb{N}, s,t \in V$ 
S is the source, and t is a sink

Exercise 5
p is a path from s to t
$B =$ set of all p
when all p does not have a bottleneck value of 0
	d = max(bottleneck(p_i) \in B)
	f_j = f_j + bottleneck(d) \in D

Exercise 6.b
	given a vertices capaciety, split vetex into vetex_in vertex_out with cap edge between
	inf around this edge to only gut vertexes

Exercise 7
$\sum_{cut(A)}c(e)$ 
Exercise 8 
- there are no s-t paths
- $\geq$ 2 (strongly) connected components ( might be a t-s path in digraphs)
Exercise 
- If C is an s-t-cut, then for every s-t-path $\geq$ 1 of the edges in the path in C

**Min Cut**
In: G, s, t, c
Out: A s-t cut(A) is cap minimum, $C\subseteq$ s-t c is an s-t-cut 
- "f(A)" = $\sum_{e\in cut(A)}f(e) \leq \sum_{e\in cut(A)}c(e) = cap(A)$ 