### Theorem: TFAE for a  graph G
1.  G is bipartite
2. G is 2-colorable
3. G has no odd cycle
- Proof 1 <-> 2
- proof 1 -> 3 
	- $C = v_1, v_2, v_3, ..., v_k = v_1$
	- WLOG (without loss of generality)
	- $v_1, v_3, v_5 \in A$ , $v_2, v_4, v_6 \in B$
	- $v_1 = v_k \in C$
	- $|c| = k is even
- proof 3 -> 2
	- G is 2-colorable
	- Let G be a connected graph with no odd cycle
	- Let $r \in V$, color r red x(r)=red
	- Consider $dist_G(r,v)$ let x(v)
		- red if dist is even
		- blue if it is odd
	- Claim x is a proper 2-coloring
		- Suppose not there are two vertecies u, v with $uv \in E$
		- s.t x(u) = x(v)
		- $dist(r,u) \equiv_2 dist(r,u)$ 
		- Let C be the color found by the shortest bath w to u, uv, v to w. The length of C is 1 + dist(w,u) + dist(w,v)
		- length of C is
			- 1 + even + even = odd
			- 1 + odd + odd = odd
			- C is an odd cycle
		- Gives us algorithm for checking if bipartiete is 2 colorable
		- 3 coloring is NP-complete
#### Greedy algorithms

Interval Scheduling
- input I ={$I_1, I_2,..., I_n$}
- output: maximum set of pairwise non overlapping intervals

- solution
	- pick the one that ends earliest
		- and then prune all conflicting ones

Lemma:
- A is optional ie for any solution S,
	- $|A| \geq |S|$
- Proof: Will prove that "A stays ahead of S"
	- Base case: r = 1, i_1 is an interval with earliest possible finish time $f(i_1) \leq f(j_j)$
		- for some r>1, the claim holds for r-1
			- Prove that when $f(i_{r-1}) \leq f(j_{r-1}) \leq s(j_r)$
				- which means that $s(j_r)$ is a viable pairwise with $f(i_{r-1}$) , but still did not choose it, therefore $f(i_r) \leq f(j_r)$ 


**Interval Partitioning**
- input I ={$I_1, I_2,..., I_n$}
- output: partitioning I into fewest possible pairwise non-overlapping intervals