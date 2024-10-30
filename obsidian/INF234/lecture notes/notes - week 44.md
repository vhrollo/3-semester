# Max Flow Algorithms

augmenting path:
	- the P

### Theorem: ( Max flow - Min Cut )


### Residual Graph

You add the opposite directed edge on each edge on the graph, and then search using those too, but if this is included you take the negative value on the residual edges used

when using a residual edge its capacity is how much flow is currently in use, not max capacity

basically add an if statement which will check if the edge is backwards, if so then reduce 
**Definition**
Given a flow network G, s, t, c and a flow f

The residual graph is the graph with the same vertex set, and for each edge $uv \in E(G)$, we create:
- uv with with capacity c(uv) - f(uv)
- vu with capacity f(uv)


### Algorithm - greedy
```
while P:= s-t-path with positive bottleneck
	then for e in P
		f(e) += b
		
return f
```

Problem here is that some edges can be saturated too early


### Ford - Fulkerson '55

$Let f_e \leftarrow O  \forall.e\in E(G)$ 
Do:
	Find an s-t path P  in $G_f$
	Let b $\leftarrow$ bottleneck of P
	For each edge e = (u,v) $\in$ P
		if e is a found edge:
			$f_e+=b$
		else backwards
			let $e`$ = vu	
			$f_{e`}$-=b

If we want to optimize this we would make an adjacency matrix instead of computing the residual graph every iteration 

**Observation (regarding F.F)**
1. f is always a valid flow
2. f is increased wherever we find an s-t path in $G_f$
3. it increases with an integer vaues if the capacities are integers

when F.F terminates, which it does after finitely many iterations it returns a valid flow

**Claim**: if $G_f$ ahs no s-t-path then f is max flow in G

**Corollary of claim**
- If claim then F.F is correct

**Runtime**
$G_j:$ O(m) time copy all edges

Let $F* = cap({s})$
$\rightarrow$ we have $\leq F*$ many iterations
$O(mF*)$  this is psudo - polinomial 
actually $O(mF)$ where F is the max flow

"for all s-t cut(A,B), and a flow f"
$v(f)= \sum_{u\in A, v\in B} f(uv)$ - $\sum_{u\in A, v\in B} f(vu)$

Lemma (flow value) let f be a flow and cut(A, B) be any s-t-cut
- Then $v(f)= \sum_{u\in A, v\in B} f(uv)$ - $\sum_{u\in A, v\in B} f(vu)$

**Proof. By induction on |A|**
- Base case. $|A|=1$, then $A=\{s\}$
	- $v(f) = \sum_{u\in n^+ (s)} -\sum_{u\in n^- (s)}$
	- But s has no n-neighboors
	- $\sum_{u\in n^- (s)} = v(f)$

- Induction hypothesis:
	- This is true for all sizes of A < k.
	- $v(f) = \sum_{\text{e out of A}}f(e) -\sum_{\text{e into a}}f(e)$
	- The flow for A\`
	- $v(f) = \sum_{\text{e out of A`}}f(e) -\sum_{\text{e into A`}}f(e)$
- Induction step:
	- $A` = A U \{v\}, v\not \in A, v\not \in t$ 
	- = $\sum_{\text{e out of A}}f(e) -\sum_{\text{e into a}}f(e) + \sum_{a \rightarrow v}f(e) -\sum_{v\rightarrow a}f(e) - \sum_{b \rightarrow v}f(e)+ \sum_{v \rightarrow b}f(e)$ 
	- = $\sum_{\text{e out of A}}f(e) -\sum_{\text{e into a}}f(e) + \sum_{\text{e out of v}}f(e) -\sum_{\text{e into v}}f(e)$

	- Lemma (weak duality)
		- Let f be any flow 
		- Then for any s-t-cut cut(A,B)
			- $v(f) \leq cap(A)$
		- Proof:
			- $\sum_{\text{e out of A}}f(e) -\sum_{\text{e into a}}f(e)$
			- $\leq \sum_{\text{e out of A}}f(e)$
			- By capacity condition:
			- $\leq \sum_{\text{e out of A}}f(e) = cap(A)$




### Theorem. TFAE
- f is a max-flow in G
- $\exists$ s-t-cut with cap(A) = v(f)
- There is no s-t-path in $G_f$ 



**Definition - Residual graph**
Given $G=(V, E)$, t, c and a flow f. $G_f$ is dfined as having vertex set V and for each edge $uv\in E$:
- let uv be an edge in G, with C(uv) = C(uv) - f(uv) = r(uv)
- let vu be an edge in $G_f$ with c(vu) = f(uv)

Proof.  $ii \rightarrow i$:
- If any flow f\`
	- v(f\`) $\leq$ cap(A) - *weak duality*
	- since v(f) = cap(A)
		- f must be maximym

Proof. $i \rightarrow iii$
- $\neg iii \rightarrow \neg i$ (contra-positive)
- Suppose there is an s-t-path
- Run one iteration of ford-Folkerson
	- In $G_f$. run one iteration of Fold fulkerson. The flow produced
	- $f` \text{ has } v(f`) \le v(f)$
	- Hence f is not maximum which is $\neg i$


Proof. $iii \rightarrow ii$ There is no s-t-path is $G_f$. (have to do. Find a with cap(A)=f(f))
- Run BFS from s in $G_f$
- Let $A=\{v\in V : \exists \text{ s-v-path in } G_f\}$ 
- Let B = V - A
- Will prove that any edge in $G_f$ from A to B
- Let $uv\in E$ with $u \in A, v\in B$ since$u\in A, v\in D$ then $f(uv)= c(uv)$
- Let $ub\in E$ with $u\in A, v\in B$. Since $u\in A$,


- Every edge in G from A to B is saturated, i.e f(e)=c(e)
	- all is saturated
	- this means that residual graph will have 0 in flow backwards
- Every edge in G from B to A has f(e) = 0


- Recall v(f) = $\sum_{\text{uv out of A}}f(uv) -\sum_{\text{uv into a}}f(uv) = \sum_{\text{uv into A}}c(uv) = cap(A)$


Corollary. Ford-Fulkerson is correct.
- We also get an algorithm for MinCut


## Minimum seperator
- $G, s, t, c: V \rightarrow \mathbb{N}$
- Q: find minimum weight set of vertices to remove to separate s and t 


Exercise 17:
- A perfect matching M is a bijection for A to B
- The domain and codomain have same size
Exercise 18:

Exercise 19
- Given matching M, constant after f(e)=1 if e\inM 0 o.n
- f(sv) = 1 if v in M 0 ow

- cap.
- conservation