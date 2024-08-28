Tilstandsrom - A set of states, actions, start, and a goal
- usually has a criterion for an acceptable solution
- asyclic graph, an graph with no cycles
- kanter kan ha konstader
Forgreningsfaktor
+ framlengs forgrening (kanter til nabonoder)
+ baklengs forgrening (kanter fra nabonoder)


- frontier is the nodes which is not searched but seen

- breadth first
	- search using a queue
	- space $O(b^d)$ 
- depth first
	- search using a stack
	- space $O(b * d)$
- best first
	- disjstra
	- alle noder som er beøkt, vil alltid bli besøkt av den korteste stien
	- space $O(b^d)$
- A*
	- if there is an solution, a* always finds a solution, and the first solution found is an optimal solution.
	- arc costs are gerater than some e > 0
	- h(n) is a lower bound on the actual (minimum) cost of the lowest-cost path from n to goalnode
	- space $O(b^d)$ 