# P vs. NP

Plan:
- NP
- $\leq_P$ (reducibility)
- I.S, V.C, Clique, Set Color
- Independent set  $\leq_P$ Vertex Cover $\leq_P$ Set Coloring
- I.S $\equiv_P$ Clique

If the complexity is not of polynomial, it is good to check if the problem is NP

Np-Complete problems:
- Ind Set
- Clique
- Vector Cover
- Satisfaction SAT
- 3-coloring
- $\dots$ 

weak NP-Complete - *almost polynomial*
- knapsack
- subset sum

---

## Definitions

Def. (Polynomial time)
- **P** is the class of problems that can be solved in polynomial time. I.e. there exists an algorithm and a constant c that this algorithm solves the problem in time $O(n^c)$ where the input n is the size of the input. *This has to be done on a deterministic Turing machine*

Def. (NP) - *Non-deterministic polynomial time*
- **NP** is the class of problem that can be solved in polynomial time on a non-deterministic Turing Machine.

Def. (NP) - *relevant for 234 class*
- **NP** is the class of problems whose solutions can be verified in polynomial time
	- the you should have all info to verify in polynomial time

---

**Example**: Independent set (decision problems -> answer is yes/no)
	In: G. k
	Out: Does G have an independent set of size k? such that I.S = pairwise non adjacent


We can verify that $\mathcal{S}\leq V(G)$ is an independent set of size k in polynomial time
- check |S| = k
- check $\mathcal{S}$ has no edges
- That means that $I.S \in NP$ 

Crux
P -  Problems we can solve in polynomial time
Np - Problems whose solution can be verify in polynomial
P vs. NP - is it harder to solve a problem than verify a solution 

**Vertex cover**
	In: G, k
	Out Does G have a VC size can that is a size of vertices such that every edge is incident in some vertex in C?
		- Every edge has a vertex cover

adjecent: missing vertex
indicent: e = u, then e in incident on u and v


Lemma: A set $S \in V$ is an independent set if if and only if $C=V-S$ is a vector cover
*Proof*
- If S is I independent set then for every edge has an endpoint in $C \rightarrow G$ is a VC
- If C is a VC, every edge has an endpoint in C, hence S is an I.S

Corollary:
- G has an independent set of size k $\Leftrightarrow$ G has a vertex cover of size n-k

--- 

Q. How did we solve Biparting matchings
-  By running algorithm for max-flow
- Transom G into G', s,t, c obtain solution, then transform it back
- BM $\leq_p$ MF

Def. (Polynomial reduction) 
	Problem X time reduces to problem Y if instances of X can be solved using:
	- a polynomial number of computational steps
	- a polynomial number of calls to a oracle (blackbox which computes in constant time) that solves problem Y
	We write $X \leq_p Y$


$X \leq_p Y$
- Y is more powerful, since Y can solve X
- This means that X is easier than Y


Lemma. $I.S \leq_p V.C$
- Let (G,k ) be an instance for I.S
- We write G'=G, k'=|v|-k=n-k
- Solve V.C on instance(G',k')
- using oracle if the output is yes, we output yes, and if output is no we output no


Since G has a I.S of size k if and oly if G'=G has a V.C of size k'=n-k Our algorithm is correct


Lemma $V.C \leq_p I.S$
- same as the other


Then $VC \equiv_P IS$


**Set cover**
- Input set $\mathcal{U}=\{e_1, e_2, \dots, e_n\}$
	- collection of $\mathcal{S}=\{S_1, S_2, \dots, S_n\}$ 
	- where $S_i \leq U$,
	- $k \in \mathbb{N}$
- Output are there k sets in S whose union is U	

Let (G,k) be aan instance to VC
- create $\mathcal{U}=E(G)$
- For each vertex $v \in V(C)$
- Let $S_v = \{uv \in N(v\}$
- $\{\mathcal{S} \in ll : v \in V(g)\}$
- k'=k

- Run oracle for SC and output yes if SC a oracle does.
- Claim (G, k) is a yes-instance to vertex cover if and only if $(\mathcal{U, S},k)$ is yes to S.C

Proof of claim:
- Let G, k be yes to VC, and $C\in  V$ a cover of size k
	- Let $\mathcal{F} = \{ S_v : v \in C \}$ 
	- |F| =k size |c|=k
	- let $e\in U = E(G)$, let e=uv since C is a vertex cover and e=uv is an edge
	- $u\in$ Cor $V\in C$, suppose without loss of generality $u\in C$ the $S_n \in \mathcal{F}$, e=uv $\in S_u$
	- Since e uses a arbitrary, F covers all of U
- Let (U, S, k) be yes to S.C, and F is a solution of size k.
	- Let $C = \{v \in V(G) : S_v \in F\}$
	- Prove that |C|=|F|=k
	- C is a vertex cover let e =uv be an edge, e \in U, so exist S in F set e in S
	
---
### Clique
- In: G, k
- Out Does G have a clique of size k i.e a set of k verteices s.t all are freinds?