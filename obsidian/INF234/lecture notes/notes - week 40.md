# Dynamic Programming
not relevant name



**flow**
1. identify subproblems
2. find base case
3. state recurrence

Trade space for time

functools cache
- dict

Catepillar tree
- 

# Segmented Least Squares

- Input: $(x_1, y_1),(x_2, y_2),...,(x_n, y_n)$
- output: A segmentation (cnotiguous partitioning)
- $S_1, S_2, ..., S_5$ 
- Such that 
- $ct+\sum_{i=1}^terror(S_i)$ is minimized

- $opt[n] = min J<n \{ c+ error(PjiPjn, Pn), +opt[i-1]\}$


per iteration find the most optimal split for a given j which is between 0< j < i