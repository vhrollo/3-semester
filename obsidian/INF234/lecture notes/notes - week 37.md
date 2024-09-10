
Interval partitioning
- input: {$I_1, I_2, ..., I_n$}
- output: A partition of I into fewest possible partitions of pairwise non-overlapping intervals
$\mathcal{I}$

depth($\mathcal{I}$) = max$_t$ | {$I \in \mathcal{I} : s(I) \leq t \leq f(I)$}

$\underline{WLOG}$. Assume all timesteps are unique
Compute depth depth(I) = 3
stack of colors
list of the steps sorted
For each timestep t:
	if I starts at t: (works ish)
		c = pop color -> I
	if I ends at t
		push back its color

Corollary:
- For interval graphs the size o fthe maximum clique is equal to its chrolic(?) number
- Corollary C_5 is 2

Lemma. The algorithm colors every interval using depth(I) many colors
	- Proof: Observation: The number of t available colors at time t is depth(I) -  | {$I \in \mathcal{I} : s(I) \leq t \leq f(I)$}|
	- Because we have popped each color ending before and pushed before ending too

Claim:
- There is avaible color at time t = s(I) (before we give it to (I)
- Proof of claim: Suppose k intervals started and did not finish before s(I)
 Then at t'= S(I) we have k+1 overlapping intervals. So k+1$\leq$ d, and d-k \leq 1,

Scheduling to minimize lateness
- Each request has a timespan and a deadline

A request i has $t_i$ and $d_i$.
- e.g if $t_1$ = 3 hrs, $d_1$ =13.00
- f(i) = s(i) + t(i)

The lateness of i is how delayed i is:
- $l_i  = max(O, f(i) - d(i))$

Latenes scheduling
- input: $\mathcal{I}=I_1, I_2, ..., I_n$
- task. assign start time to each request so that no two requests overlap with L max_i $\mathcal{L}_i$ minimized

- Earliest deadline first
	- Sort requests according to deadlines
	- i.e $d_1 \leq d_{...} \leq d_n$
	- let now s_1 = 0
	- for i = 1..n
		- assign request i to \[now, now\]
		- now <- now + t_i

Theorem. Earliest deadline first yields optimal maximum lateness
- Proof: Suppose requests are sorted by deadline

- Definition
	- Given a schedule S, an inversion is a pair of requests i < j (ie d_i <= d_j), but j comes before i
- Observation
	- unique idle free

Claim: If an idle-free schedule has an inversion it has a back to back inversion
- no element between the closest invrsion, as this will make an contra

Lemma. (exchange argument)
- Exchanging two adjecent inverted requests reduces the number of inversions without increasing maximum lateness