
**Kruskal's algorithm**
*Add smallest edge not creating a cycle*
T ={}
E = sorted(E)

for u,v in E:
	if u


**Prim's algorithm**
*Add smallest edge leaving our tree/compn*


**Union-find**
- Union($e_1, e_2$)
	- unifies the set of $e_1, e_2$
- find(e)
	-  returns a pointer to the set containing e
- O($\alpha(n)$) - inverse Achermann function


**Proof of correctness**

Lemma( cut property )
- Let G = (E, V), $l$ : E -> N be a weighter graph, assume that all edges have unique weights
- Let $Ø \in S \in V$ and let e = vw be the unique smallest edge with $v \subset S$, $w \not\subset S$
- Then every MST contains e

Proof ( Exchange argument) 
- Let T be a spanning tree not containing e ( will show: T is not minimal)
- proof that e' is not the smallest edge leaving a set
- e' is the unique edge leaving S on the path for v to w
1. let $T' = T - e' +e$ The weight of T' is stricktly smaller than th weight of T, since $l(e') \ge l(e)$
2.  T' is spanning  since all vertecies are still in A
3. m' = n - 1
4. T' is connected
	1. therfore acyclic
- Therefore tree T is not a minimum spanning tree

#### Clustering
*application of MST algorithms*

Suppose we have some point in the poane with $dist(p,q) = \sqrt{(p_x - q_x)^2 + (p_y - q_y)^2}$  (euclidian)

We want to partition the set of points into k clusters such that for $p,q \in C_i, C_j, i\not = j$  that minimum distance is maximized

Kruskals's algorithm but we stopped early, so there is k many clusters left
- We stop at the k - 1 edge left

Def. ( Spacing )
- Given D, d $\mathcal{C} = C_1, ... , C_k$  
- The spacing of $\mathcal{C}$  is min d(p,q) with $p \ in C_i, q \in C_j, j \not = i$ 

Clustering of maximum spacing
- In $P, d: P \times P \rightarrow \mathcal{R_{\geq 0}}$ $k \in N$
- Task compute a k-clustering of maximum spacing

- Sum of minimum spacing is done differently and is np-complete

Observation
- We iteratevly add cycles in Kruskals
- When we add p, q the spacing is $\geq d (p, q)$
- Proof:
	- Because when we add p, q all edges with smaller distance has been considered 

Lemma: Let $\mathcal{C}^* = C_1^*, ..., C_k^*$ be the clustering found by kruskalsæs after adding n - k edges
- The $\mathcal{C}^*$ is a k-clustering of max spacing
- Proof
	- Let $\mathcal{C} = C_1, ..., C_k$ be any other k - clustering 
	- show spacing of $\mathcal{C}^* \geq$ spacing of $\mathcal{C}$
	- Let $P_j \cdot P \in C_r^*$, but $P_i \in C_S, P_j \in C_t$
	- The spaceing of $\mathcal{C}$ is the length of the (k-1) longest edge in the MST
	- $P_i \cdot P_j \in \mathcal{C}_r^*$
	- Some edge qp on the $P_i \cdot P_j$ path end up in differnet clusters in $\mathcal{C}$
	- The spacing of $\mathcal{C}^* \geq d(p,q)$
	- The spacing of $\mathcal{C} \leq d(p,q)$




## Data Compression

If text is n long the "encoding" $\cdot$ n
We want frequent symbols to have a shorter encoding

Def (prefix code)
- A prefix code is an encoding is which no symbols is a prefix of another's

**Hoffman Compression**
A binary tree in which every internal node has two children. The leaves are labeled with symbol
Encoding of a symbol give a tree T is the label  of the edges on the lavel of the edges on the path from the root to the symbol.
- The encoding from T is prefix free
- Because any prefix of an code corresponds to a path from the root to an internal node in the tree, where not a symbol
****

**Huffman codes**
- Encode ( compress ) mesage using variable-length encoding
- How to create prefix-free codes
	- using binary tree with the leaves as the corrosponding symbols

Suppose that the alphbet is $\Sigma$, and $f_\sigma$ for the frequency of $\sigma$ in the message
Let $\gamma : \Sigma \rightarrow B^*$. 
Let $|\gamma (\sigma) |$ be the length of $\sigma$'s code
Note: If our message  M has length n, then $n \cdot f_\sigma$ is the number where $\sigma$ appears in message M.
$n \cdot f_\sigma \cdot |\gamma (\sigma)| \rightarrow$ how much $\sigma$ contributes to the total length of the message 

Total encoding length:

$\sum_{\sigma \in \Sigma} \cdot f_\sigma |\gamma (\sigma) | = n \cdot \sum_{\sigma \in \Sigma} \cdot f_\sigma |\gamma (\sigma)|$
Avarage bit length: 
$\sum_{\sigma \in \Sigma} \cdot f_\sigma |\gamma (\sigma)|$

Encoding:
- input Alphabet Sigma, $f_\sigma$ frequencies
- output: encoding of Sigma that minimizes average bit length

Expansion for finding a prefix tree minimizing
- $\sum_{\sigma \in \Sigma} \cdot f_\sigma \cdot depth(\sigma)$

Def. 
- A full binary tree is a tree in which every node has children/degree in {0,2}

Claim: A binary tree represents an optimal ... in a ufll tree. 

Proof: Suppose that T has a role node with 1 child. Let $\sigma$ be some symbold corresponding to a elaf under that node. Contrary the degree 1-edge decreases the exeding of $\sigma$, and does not somehting after ...


Lemma if fx< fy then depthT(x)$\geq$ depthT(y) for an optimal tree T
Proof. Suppose fx < fy & depthT(x)< depthT(y)
- The cost of T is
	- ABL(T)=$\Sigma$ fs ds = S
	- ABL(T')=S-fxdx - fydy + fxdy + fydx
	- S - $\epsilon$  < ABS(T) = S

Alg (Huffman)
priority queue Q = {(f_v, v): $v \in \Sigma$}
while $|Q| \geq 2$:
	$v_1, v_2 = pop(Q), pop(Q)
	create node (f_1 + f_2, (v_1, v_2))
	push (Q, v)
	return pop(Q)


# Divide & Conquer

Suppose we spend T(n) on sorting a list of n, with merge sort
$T(n) = O(n)+O(n)+T(\frac{n}{2}) + T(\frac{n}{2}) + O(n)$ 
Recurrence relation
$T(n) = 2T(\frac{n}{2})+O(n)$
base case
$T(1)=T(0)=1$ 

**Recurrence relation**
$cn \rightarrow \frac{cn}{2} + \frac{cn}{2}$
each level in the binary tree is cn big
 This etnries tree tells us how much work we much do in each node in each level, cn in total
Total work:
- $cn \cdot log(n)$


Lemma: Any algorithm with reacurence $T(n)=2T \frac{n}{2} + O(n)$ has the running time of O(n log(n))
- $T(n) = aT(\frac{n}{b} + nd)$

**Binary search**
$T(n) = cT(\frac{n}{2}) = T(\frac{n}{2}) + O(1)$

Lemma: An algorithm with recursion $T(n) = T(\frac{n}{2}) + c$  has running time of O(logn)