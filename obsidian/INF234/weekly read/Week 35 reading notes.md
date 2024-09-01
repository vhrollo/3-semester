*chap 2.1 - 2.5*


# Computational Tractability
- Identify the broad themes and design principles in the development of algorithms. 
- We could see stable marching problem with an natural "size" parameter of N. N could be equal to $2n^2$ given that N is closely related to n

- to check if a running bound is weak, we can compare it to the brute-force search

Proposed Definition of Efficiency 2:
- *An algorithm is efficient if it achieves quantitatively better worst-case performance, at an analytical level, then brute-force search*

## Polynomial Time as a a Definition of Efficiency
- If an algorithm holds within $cN^d$ it is polynomial-time algorithm

Proposed Definition of Efficiency (3): 
- *An algorithm is efficient if it has polynomial running time.*
- just works gg
# Asymptotic Order of Growth
- notion of step may vary

## notions

- $T(n) = O(f (n)$   representing the upper asymptotic bound
- to get the definition into $cN^d$ we turn $T(n) = pn^2 + qn + r \leq pn^2 +qn^2 rn^2 = (q + p +r)n^2$ 
	- $T(n) \leq cn^2$ and $c = (q + p +r)$ 
- If we calculate that the upper bound of a function is O(n^2), it is also right that the upper bound is O(n^3), only that it wasn't as as tight as possible.
lower bound
- T(n) is $\Omega(f(n))$,  where an  constant $\epsilon * f(n) \leq T(n)$
- $T(n) = pn^2 + qn + r \geq pn^2$ 
- a weak lower bound could be $\Omega(n)$
tight bounds
- If both Big O and Omega is alike, then the asymptotically tight bound would be just that
- $T(n) = pn^2 + qn + r$ is both $O(n^2)$ and $\Omega(n^2).$ then $\Theta(n^2)$

- transivity holds
	- g is upperbounded by h, and h is upperbounded by f
	- g is upperbounded by f

- f is tight(g) and g is tight(h), then f is tight(h)

### Asymptotic bounds for some common functions

Polynomials
- $n^2$    også $n^{\frac{1}{2}}$ 
- Using the heighest polynomials in the O()
- If an algorithm has running time O(n log(n)) would also have a running time of O(n^2), therfore polynomial

Logarithms
- $log_a n = \frac{log_b n}{log_b a}$
- the base of logarithm is not needed. Notice that $\frac{1}{\log_b a}$ is just a constant, because it only depends on the bases a and b, not on n. therefore each logarithmic growth is just multiplied by a constant factor

Exponentials
- An **exponential function** is of the form $f(n) = r^n$, where r is a constant base and r>1.
- $n^d = O(r^n), r>1,  d>0$ 
- This means that every exponential function grows faster than any polynomial function as n becomes large. In other words, no matter how large d is, eventually $r^n$ will outgrow $n^d$ because the exponential function grows much faster.
- $r^n≤c⋅s^n$
	- there is no c where $s^n$ is true for all sufficiently large n

# A survey of common running time
- Computing maximum O(n)


#### O(n log(n))
- It is the running time of any algorithm that splits its input into two equal-sized pieces, solves each piece recursively, and then combines the two solutions in linear time.
- Mergesort

$O(n^k)$

# Data structure for implementing a priority queue
- The definitions of heaps
	-  for every element v, at a node i, the element w it i's parent satisfies $key(w) \leq key(v)$




# Graphs
- path undirected path
- cycle - path taht starts and ends at the same vertex with no other repeated vertices or edges
- curcuit - path that starts and ends at the same vertex with no repeated edges
- hamilton circuit - circuit that touches every node
- eularian circuit - circuit that thouches every edge
- connected - no loners
- in a directed graph, a strongly connected graph has for every two nodes, there is a path between u and v, and vice verca
- Trees
	- tree if it is strongly connected, and contain no cycle


### 3.3 
- wtih at most one edge between a pair of nodes
- m can at most be $\binom{n}{2} \leq n^2$  given n nodes
- connected graphs must have $m \geq n-1$ 
- Running time of O(m + n) is the same as O(m)
- adjeceny matrix is bad, given that we have to check what edges are present

- adjacency list works better for sparse graphs