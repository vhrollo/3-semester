# Dynamic programming 


## Shortest Path - Bell-Ford Algorithm
- In: Digraph G = (V,E), $w: w \rightarrow \mathbb{Z}, s\in V$ 
- Out: dist_G(s,v) fora all $v\in V$ ( or some negative cycle)


Why will not Dijstra not work with negative weights
- once we pop a vertex we know its correct in Dijstra

This could be solved by shifting all the value so none are negative
- This only works with MST as it is always n-1 edge
- longer paths with smaller values will be punished for when shifting it
- as this will shift k values up, where k is how many edges


Lemma: IF G has no negative cycles, then there is a shortest s-v path that is simple and has $\leq$ n - 1 edges

Proof: Consider all shortest s-v paths and pick one with fewest number of edges P. Suppose for a contradiction that P contains a cycle C. The cost W(X) $\geq$ 0 by assumption. Let P' be P-C_1 the w(p') and not fewer edges 

Pseudo algorithm: 

DP(i, v) = cost of shortest s-v-path using at most i edges

Base case:
- DP(0,v) = {0 if v = s,  $\infty$ o.w}

Recursive Step:
- DP(i,v) = mm {
	- D(i-1,v) in cases that is a shortest s-path using $\leq$ i-1 edges
	- $\min_{u\in `(v)} DP[i-1, u] + w(uv)$

In code: 
```python
DP = deafultdict(\lambda * inf)
DP[0, s] = 0
for i in l...n
	for v in V:
		DP[i,v] = DP[i-1, v]
		for u in N^(v):
			cost = DP[i-1,u] + w(u,v)
			if cost < DP[i,v]
				DP[i,v] = cost
```

Pre(v) = u so that we can backtrack

Per cell will compute deg(v) time
There is n^2 cells
This will end with O(n^2*m)

**negative cycles observation**
I any value for any vertex v change from $DP[n-1, v] to DP[n,v]$ then there exist a negative cycle
Then the pre values will be overwritten an a cycle will appear
sufficient proof!


# Independent Set
In: Graph(V,E)
Out: find a largest set $S \in V$ that is pairwise non adjacent

requirements:
*no cycles in the graph*

*We don't know any polynomial time algorithm to this problem*

Same problem:
- Alarm problem, just on paths
- Interval scheduling

Let r be the root of T
let $T_v$ be the subset of the subtree rooted in v

DP($T_v$) "Two values: optimal solution in v if v is in the solution and v is out of the sol"


Basecase:
- $DP[t_\gamma]$ = weight$[\gamma]$ where $\gamma$ is a leaf if we pick it
-  $DP[t_\gamma]$ = 0 if we don't pick it

Recursive:
- $DP[T_v]$ = in = weight(v) + $DP[T_u].out$ + $DP[T_v].out$ 
- out = 0 + max($DP[T_{u_1}].out, DP[T_{u_1}].in$) +  max($DP[T_{u_2}].out, DP[T_{u_2}].in$)

Optimal sol: is max($DP[T].out, DP[T].in$)

```python
#postorder
def po(u)
	for u in children(v)
		po(u)
	yield(v)
```



# Compulsory Assignment Walkthrough 

## 2. Graphs

- u and v are in the same SCC iff $dist(u,v) < \infty$  and $dist(u,v) < \infty$
- Let G/scc be the condensation of G and suppose G/scc has a cycle C
- Let $V_1, V_2,..., V_k, V_1$
- 
## 5. Dynamic Programming 

Base case: 
- $OPT[0,s] = 0 if s = 0, \text{else } \infty$
- $OPT[i,s] = min \begin{cases} 1 + OPT[i-1, s-v_i]\\OPT[i-1,s]\end{cases}$ 

