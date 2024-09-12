
Interval partitioning
- input: {$I_1, I_2, ..., I_n$}
- output: A partition of I into fewest possible partitions of pairwise non-overlapping intervals
$\mathcal{I}$

depth($\mathcal{I}$) = max$_t$ | {$I \in \mathcal{I} : s(I) \leq t \leq f(I)$}

$\underline{WLOG}$. Assume all timesteps are unique
Compute depth depth(I) = 3
stack of colors
list of the steps sorted
For each timestep t:
	if I starts at t: (works ish)
		c = pop color -> I
	if I ends at t
		push back its color

Corollary:
- For interval graphs the size o fthe maximum clique is equal to its chrolic(?) number
- Corollary C_5 is 2

Lemma. The algorithm colors every interval using depth(I) many colors
	- Proof: Observation: The number of t available colors at time t is depth(I) -  | {$I \in \mathcal{I} : s(I) \leq t \leq f(I)$}|
	- Because we have popped each color ending before and pushed before ending too

Claim:
- There is avaible color at time t = s(I) (before we give it to (I)
- Proof of claim: Suppose k intervals started and did not finish before s(I)
 Then at t'= S(I) we have k+1 overlapping intervals. So k+1$\leq$ d, and d-k \leq 1,

Scheduling to minimize lateness
- Each request has a timespan and a deadline

A request i has $t_i$ and $d_i$.
- e.g if $t_1$ = 3 hrs, $d_1$ =13.00
- f(i) = s(i) + t(i)

The lateness of i is how delayed i is:
- $l_i  = max(O, f(i) - d(i))$

Latenes scheduling
- input: $\mathcal{I}=I_1, I_2, ..., I_n$
- task. assign start time to each request so that no two requests overlap with L max_i $\mathcal{L}_i$ minimized

- Earliest deadline first
	- Sort requests according to deadlines
	- i.e $d_1 \leq d_{...} \leq d_n$
	- let now s_1 = 0
	- for i = 1..n
		- assign request i to \[now, now\]
		- now <- now + t_i

Theorem. Earliest deadline first yields optimal maximum lateness
- Proof: Suppose requests are sorted by deadline

- Definition
	- Given a schedule S, an inversion is a pair of requests i < j (ie d_i <= d_j), but j comes before i
- Observation
	- unique idle free

Claim: If an idle-free schedule has an inversion it has a back to back inversion
- no element between the closest invrsion, as this will make an contra

Lemma. (exchange argument)
- Exchanging two adjecent inverted requests reduces the number of inversions without increasing maximum lateness

# Weighted greedy algorithms
### Dijkstra's algorithm
- This algorithm doesn't work with negative weights
- G = (V, E), l : E-> N
- $dist_G(u, v)$ length in normal graph
- $l(P)$ = sum(e), $e \in P$

##### Single source shortest path
- in: G = (V, E): l: E - N, $S\in V$
- out: $dist_G(s, t)$ for all $t \in V$
- idea: we maintain a set $S\in z$ where we knowe the correct to every $v\in S$
- d(v)= $dist_G(u,v)$ u - v vertex
- d'(v)= tentative distance from s to v

**Algorithm**:
- $d'(v) = inf \forall v \in V$ 
- $d'(s)= 0$ 
- while $S \not = V$:        *n vertexes*
	- pick $v \in V - S$         *priority queue*
	- S <- $v$ 
	- $d(v) = d'(v)
	- for each $u \in N(v)$ \S     *look around at their neighbors*
		- if d(v) + l(vu) < $d'(u)$
			- $d'(u) = d(v) + l(vu)  *updates priority queue*
			- pre(u) = v  *(array of pointers)*
- return d and pre

**Complexity**
- O(n) to iterate through vertexes
- O(logn) to take out smalles from priority queue

- O(m) looking at neighbors takes ish this time
- O(logn) updating the priority 



**Heap list / priority queue**
- Push:
	- place the value at the bottom and "bubble up"
	- log(n)
- pull
	- place the last one at the top, and "bubble down"
	- log(n)
- if you change a value you can bubble down / up


**Proof**: Theorem Dijkstra algorithm correctly computes all distances from S
- $v \in S, d(v) = dist_G(s,v)$
- **Base case**: k = 1 |S| Since s is the first vertex to be added to S with d(s) = 0
- **Induction hypothesis**: Suppose $d(v) = dist_G(s,v)$
	- for all $v \in S$ where $|S| = k-1$
- **Induction step**: In step k of the algorithm, initially |S| = k -1
	- Let v be the vertex chosen with the smallest d'
	- Consider a path $P_{n \cdot v}$
	- Claim that $P_{n \cdot v}$ is the shortest s-v-path
	- Suppose that there exists a shorter s-v-path
		- But $d'(v) \leq d'(y)$
			- This means that $P_{u \cdot v}$
				- is already at least as long as $P_{u \cdot v}$ 
			- which contradicts $P_{x \cdot y \cdot ... v}$ being shorter
		- Hence $P_{u \cdot v}$ = $P_v$ is a shorter s-v-path
		- And the claim holds for $S \union \{v\}$ and S u {v} has length k


### Minimum Spanning Trees

Let G = (V, E), l : E -> N be a weighted graph
Let T=(T, E') be a subgraph

Then TFAE:
	- T is a spanning tree of G
	- T is a acyclic of connected
	- T is ascyclic & |E'| = |V| - 1
	- T is minimally connected
	- T is maximally acyclic

**Problem**
- input: $G=(v,e), l=E->N$
- output: A spanning tree T=(V,E) with l(E') smallest possible


**Prims's algorithm**
- Let S = Ø
- c(v) = inf for all v
- c(s) = 0  for some $s \in V$
- while $S \not = V$
	- pick $v \in V \ S$
	- S<-S u {v}
	- for $u \in N(v) \ S$
		- if l(uv) < c(u)
			- c(u) = l(vu)
			- pre(u) = v


**Prims algorithm invariant**
- We maintain a MST S and always add a cheapest edge leaving S.

**Kruskal's algorithm**
- Starts with an empty tree
- Sort edges by l
- let T = (V, ø)
- for each $\in E$ 
	- if T + e is still a forest:
		- add e to T
