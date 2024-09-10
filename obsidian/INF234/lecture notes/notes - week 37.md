
Interval partitioning
- input: {$I_1, I_2, ..., I_n$}
- output: A partition of I into fewest possible partitions of pairwise non-overlapping intervals
$\mathcal{I}$

depth($\mathcal{I}$) = max$_t$ | {$I \in \mathcal{I} : s(I) \leq t \leq f(I)$}

Compute depth depth(I) = 3
stack of colors
list of the steps sorted
For each timestep t:
	if I starts at t:
		c = pop color -> I
	if I ends at t
		push back its color		