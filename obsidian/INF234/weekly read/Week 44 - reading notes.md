# NP and Computational Intractability

**Gray area** - NP-complete:
- *A polynomial time algorithm for any one of them would imply the existence of a polynomial algorithm for all of them*
- A group of algorithms

**NP-completeness** essentially means:
- “computationally hard for all practical purposes, though we can’t prove it.”
- classification in computational complexity theory used to describe a specific set of problems that are particularly challenging to solve efficiently.


### Polynomial time reductions
*Problem X is at leas as hard as problem Y*

- *Can arbitrary instances of problem Y be solved using a polynomial number of standard computational steps, plus a polynomial number of calls to a black box that solves problem X?*
- If yes then we write Y $Y \leq_P X$
	- “Y is polynomial-time reducible to X”
	- “X is at least as hard as Y (with respect to polynomial time).”