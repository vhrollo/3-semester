
# NP-completeness

$SAT\leq_p I.S \equiv_p V.C \leq_p S.C$
$I.S\leq_p Clique$

---
$I.S\equiv_p V.C$
$V.C\leq_p S.C$
- Set covering is a generalization of vertex covering

$SAT \leq_p I.S$  (gadget used to model behavior)
- clause gadget
	- to pick one variable in a clause
- literal gadget
	- to pick one literal or its negation, but not both


# Dominating Set
*In: $G=(V,E), k\in\mathbb{N}$*
*Out: Does there exist a set of $\leq$k vertices $D\in V$ such that every vertex is in D or has a neighbor in D?\[ a set of vertices that "cover" all vertices \]

**Proof**:
1. D.S is in NP. If we are given a dom.set D, check $|D|\leq k$ and that $v\in D$ or $N(v)\cap D\neq Ø$ (or $N[V] \cap D\neq Ø$) 
2. Pick an NP-complete problem. Vertex Cover
3. $VC\leq_p DS$
	- Reduce G(V,E), k to be an instance to VC
	- gadget
		- We do this by adding vertices between two vertices with an edge between them. We replace edge(x,y) with (xy),(xz),(zy)
	- fore each edge uv we create a vertex


**Claim**:
- $G,k$ is yes instance for $VC \Leftrightarrow G',k$ is yes instance for DS

**Proof**:
- $\rightarrow$
- Suppose G, k is yes for VC, let $C\leq V$ be a cover of size $\leq k$
- Let D=C, so $|D|\leq k$
- Let u be a vertex not in D. If $u=w_{ab}$, since $ab\in E(G)$
- Since C is a VC, a or b is in C=B is in C=D
- And N($w_{ab}$)=${a,b}$, so u is dominated
- If u is an original vertex let v be any neighbor $uv \in  E$. Since C in VC, $u\in C$ , $V\in C$ So u is in D or has neighbors in D

- $\leftarrow$
-  Let G', k be a yes instance to DS. Let D be a dominant set of size $\leq k$
- If $w_{ab}\in D$, replace it with a. Since $w_ab$ dominate only $\{w_{ab}, a,b\}$, and a dominates at least $\{w_{ab}, a,b\}$, as it can dominate more. The new set D' is a dominating set
- Let C=D' be a "cover" of G $|C|\leq k$. Let uv be a edge in G and consider $w_{uv}$ in G'. Since D' is a dom.set, $u\in D'$ or $v\in D'$, so uv is covered by C'.

---

Suppose we need actually solve an  NP-complete problem, we can only choose 2
- optimal solution - exact
- all instances - general
- efficiently - polytime

---

1. Design algorithm for special case
	- Tree -> I.S
	- interval graphs -> IS
	- planer graphs
	- sparse graphs
	- bipartite cases
	- small values
2. Approximate solutions
	- we return $\leq \mathcal{E} * OPT(x)$ 
	- E.g. vertex covor has a Z-approximate
	- $OPT\leq ALG(x)\leq\mathcal{E}* OPt(x)$
3. use exponential time


Let G,k be an instance to Vertex Cover.
One algorithm. Try all $C\subseteq V(G)$ of size $\leq k$
- $\rightarrow 2^n * (n+m)$ all subsets
- $\rightarrow k^k * (n+m)$ all k-subsets
- $\rightarrow 2^k * (n+m)$ this go brr. fast

---

### Small Vertex cover. (inf334)
```psudo
def Alg(G,k):
	#base check
	if G has no edge
		return True
	if k =0
		return False

	#this will delete all edges connected to u, and decrement k
	let uv be an edge
		return ALG(G-u, k-1) or ALG(g-v, k-1)
```


**Running time**:
- height = k 
- total number of nodes $n^k$
- $O(2^k(n+m))$

**Claim**:
- Let uv be an edge of G, G has a vertex cover of size k if and only if G-u or G-v have a cover of size k-1
- Let C be a VC of G of size k, suppose $u\in C$. Then $C' = C- \{u\}$, |C'| = k-1, and $C'$ is a vertex cover of G-u
- Let g-u have a vc of sice k-1. Let C' be a vc, then $c'\cup \{u\}$ is a vc of size k for g

if clique has such a O running time  then NP=Pf