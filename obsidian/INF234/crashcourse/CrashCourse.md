
# Longest Path in a DAG
- Directed
- Acyclic
- Is there a directed path in G that contains all vertices in order that they appear on the path, if such path exists. The algorithm must have running time O(n+m)
- The path only have 1 sink node

```
def lp(v):
	if dp[v]:
		return dp[v]
	neighbors = lp(x) for each of the neighbors	
	P = v + max(neighbors)
	dp[v] = p
	return p
```

$$
P
\begin{cases}
\text{v=v, if N(v)=Ø}\\
\text{v + max(lp(u) for u in N(V)}
\end{cases}
$$
# dynamic programming

**top down dynamic programming**
- bottom up, you recurse until you find a base case then build up
	- 
- top down, you fill out the table as you go
## Other
**Sink Node**: vertex w/ out degree 0


# Knapsack Problem
*0 - 1 version*


| i   | v   | w   |
| --- | --- | --- |
| 1   | 5   | 4   |
| 2   | 4   | 3   |
| 3   | 3   | 2   |
| 4   | 2   | 1   |

the colums is how many items we use
and the rows is how many knapsacks we are able to use

w equals the number of columns to go back
- you remove that much weight, then you look back that much in the table

| -   | 0   | 1   | 2   | 3   | 4   | 5   | 6   |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 0   | 0   | 0   | 0   | 0   | 0   | 0   |
| 1   | 0   | 0   | 0   | 0   | 5   | 5   | 5   |
| 2   | 0   | 0   | 0   | 4   | 5   | 5   | 5   |
| 3   | 0   | 0   | 3   | 4   | 5   | 3+4 | 3+5 |
| 4   | 0   | 2   | 3   | 3+2 | 4+2 | 5+2 | 7+2 |

$$
KS(i,w)
\begin{cases}
0, i=0, w=0\\
KS(i-1), if W_1 > W\\
max(KS(i-1, w), KS(i-1, W_i)+v_i) if w_i \leq W
\end{cases}
$$



# Subset Sum
- set of n integers
- task whether there is nonempty subset A'

- "Using the first i elements, is there a subset which sums to zero"
$$
S[i,k] = something
$$


# Huffman encoding
*Huffman encoding gives you optimal prefix code.*
- The algorithm works recursively by selecting the lowest frequency letters and encoding them

- pop the two smallest

**example**
A: 80
B: 20
C: 42
D: 10
E: 26
F: 66

-- added -- when combinded
BE: 30
DBE: 56

lowest one gets put into the left node

D <- DB -> B

BD <- DBE -> E

DBE <- DBEC -> C


F <- FA -> A

DBEC <- DBECFA -> FA


# Network Flow

## Ford-Fulkerson (FF)

```
while true do
	G_f <- residual(G,s,t,c,f)
	p <- path(G_f, s,t)
	if no path then
		break
	b <-bottleneck(p,G_f)
	foreach (u,v) in p do:
		if (u,v) in E(G) then
			f(u,v)
			...
```

- The size of the maximum flow from vertex s to vertex t is equal to the size of the minimum cut between s and t
- bipartite matching
- finding min cut




# P and NP problems


P are the problems that can be solved in polynomial time by a Turing machine
NP are the problems which can be solved by a non deterministic turing mahcine

### NP-Completeness
A problem X is NP-Complete when the following is satisfied
- Certifiers, a function which will check if the problem is solved in polynomial time with a yes/no answer


- NP complete problems are problems which are in NP and are at least as hard as all other problems in NP
- Someone showed that if we can solve 3-SAT in polynomial time, we can solve all problems in NP in polynomial time
- This mean that if we have a problem A somehting ...


# Polynomial time reductions

Vertex covers

VC=S
V(G)/S = I.S.

Contradiction.
Assume V(G)\S is not an independent Set
edge w/ both end points in V(G)\S


Dominating Set
- to show that a problem is in np-complete, you would have to reduce both a and b to eachother
- prove that a yesinstance goes both ways

- $VC \leq_P DS$
- G, K, yes for VC
	- S is VC
	- Let $D=S, |S| \leq k, |D| \leq k$
	- D is Dom.Set
	- Let $U \not \in D, UV \in E, U\in D \Rightarrow dom SU$



W = polytime reduction extra mnodes timing

G', k is yes for DS
D is dom set, |D| $\leq$ k
if $w \in D$ -> replace with
Let (u,v) \in E(G)
U doms v
V doms U


VC can be converted to DS




# 3-SAT to Clique Poly time reduction

$(x_i \lor \overline{x_2} \lor \overline{x_1})\land (x_2 \lor x_4 \lor x_3) \land (\overline{x_3} \lor x_2 \lor x_1)$ 
- Dont add edge if 
	- Between own negations
	- dont add w/in  clauses