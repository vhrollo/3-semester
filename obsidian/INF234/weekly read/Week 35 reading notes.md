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