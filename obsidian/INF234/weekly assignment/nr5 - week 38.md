## Task 1

balanced binary tree with n leaves
n is a power of 2
each edge has length $\ell_e$ 

Given that the root to leaf is the sum of all $\ell_e$ in its path

from the root node
find the max $\mathcal{L}_e$ path of edges
first maximize each edge on the root until one of the paths to its leaf nodes is equal to $\mathcal{L}_e$ . 
Then traverse down the tree and do the same

we could also just check the biggest $\mathcal{L}_e$ inlcuding each of the nodes child, and a adjust just one of them to match the other, with the edges from parent to children. Then do this recurivly
## Task 2