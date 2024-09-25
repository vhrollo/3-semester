# Divide & Conqueror

$T(n) \leq 2T(\frac{n}{2})+cn$ 
```
def margesort(P)
	if len(P) then P
	L = P[:len(P)/2]
	R = P[len(P)/2]
	L = mergesort(L)	
	R = mergesort(R)
	return merge(L,R)
```

Proof techniques:
- Unrolling
- Substitution (induction)

Work in level j per node: $c \cdot \frac{n}{2^j}$ 
Total work per level i: $c \cdot \frac{n}{n^j} \cdot 2^j$
Num levels: if we make it to reach level 1: $log_2(n)$ many

$T(n) \leq \sum_{j=0}^{log_2(n)} c \cdot \frac{n}{n^j} \cdot 2^j$ = $cn\sum_{j=0}^{log_2(n)} (\frac{2}{2})^j$ = $cn \cdot log(n)(1)$

##### Geometric progression
$\sum_{j=0}^N q^j$ 
for q = 1:
- $\sum_{j=0}^N 1^j=N$ 
for q < 1:
- $\sum_{j=0}^N \frac{1}{2}^j=1+\frac{1}{2}+...= O(1)$ 
- always constant time
for q = 2:
- $\sum_{j=0}^N 2^j=1 +2 +4+...+2^N = \Theta(2^N)$ 

Three cases
- q < 1: O(1)
- q = 1:$\Theta$(N)
- q >1: $\Theta$(q^N)


##### Unrolling
- write/draw a tree enter the node value
- find a pattern
	- work per node
	- nodes per level
	- number of levels
	- use $\sum$ to geometric progression


**Example**
$T(n) \leq 5T(\frac{n}{3}) +2n$
- work per node $\frac{cn}{3^i}$
- work per level j: $5^j$
- number of levels: $log_3(n)$
- $\sum_{j=0}^{log_2(n)} c \cdot \frac{n}{3^j} \cdot 5^j$ 
- $T(n) \leq cn \cdot \sum_{j=0}^{log_3(n)} (\frac{5}{3})^j$ = $cn \cdot (\frac{5}{3})^{log_3(n)}$ = $cn \cdot \frac{5^{log_3(n)}}{3^{log_3(n)}}$ = $cn \cdot \frac{n^{log_3(5)}}{n^{log_3(3)}}$ = $c \cdot n^{log_3(5)}$
- $O(n^{1.465})$
- Java BigIntegers Multiplication

$T(n) \leq 8T(\frac{n}{2}) + O(n^2)$ 
- work per node: $c(\frac{n}{2^j})^2$
- work per level: $8^j$
- number of levels: $log_2(n)$
- 

Straus(1969)
- $T(n) \leq 7T(\frac{n}{2}) +O(n^2)$
- O(n^2.81) ish


##### Substitution
$T(n) \leq 2T(\frac{n}{2}) +cn$
$T(1) = T(2) \leq c$

Suppose you belive that $T(n) \leq c \cdot n log_2 n)$ we try to prove it (by induction)

Base case. $T(2) \leq c \leq cnlog_2n =2c$
Induction hypothesis: $T(m) \leq cm\cdot log_2(m)$ for all $m<n$
Induction step: $T(n) \leq 2T(\frac{n}{2}) +cn \leq 2\cdot c \cdot \frac{n}{2} log_2(\frac{n}{2}) +cn$ 
	$= cn log_2 \frac{n}{2} +cn = cn(log_2n-1) +cn = cn \cdot log_2(n)$ 

##### Another Unrolling examples
$T(n)\leq 2T(\frac{n}{2}) +cn \Rightarrow O(n\cdot log(n))$
$T(n)\leq 1T(\frac{n}{2}) +cn \Rightarrow O(n)$
$T(n)\leq aT(\frac{n}{2}) +cn, a \geq 3 \Rightarrow O(n^{log_2(a)})$

work per node $cn/2^j$ 
work per level $a^j$ 
levels: $log_2(n)$
$O(n^{log_2(a)})$


##### Masters Theorem
Let $T(n) \leq a T(n/b) +O(n^d)$
then
$O(n^d), d>log_b(a)$
$O(n^dlogn) d=log_b(a)$
$O(n^{log_ba}), d < log_ba$

**Proof**
d: "work done"
a: "branching factor"
b: "scaling of subproblems"

node size: $n/b^j$
depth: $log_bn$
level j has $a^j$ many nodes
work done per node $(\frac{n}{b^j})^d$ 

In total: $T(n) = \sum^{log_bn}_{j=0} c\cdot a^j (\frac{n}{b^j})^d$ = $cn^d \sum^{log_b(n)} (\frac{a}{b^d})^j$ 


# Integer Multiplication
*In: A, B*
*Out: A times B*

Assume that |x|=|y| is a power of 2.

$|x|=|y| \in \{0,1,2,4,8,16\}$

$x = 123 \Rightarrow 0123$

$x = x_1 \cdot 2^{n/2} + x_0$

It is not multiplying, but it is only bit-shifting. It is the same as adding 0s at the end of the n

$x\cdot y = (x_1 \cdot^{n/2} + y_0)\cdot(y_1 \cdot^{n/2} + y_0)$
$2^nx_1y_1 + 2^{n/2}(x_1y_0 + x_0y_1) +x_0y_0$ 


**Karatsuba's algorithm (1962)**
$P = (x_1 + x_0)(y_1 + y_0)$
	$= x_1y_1+ x_1y_0 + x_0y_1 + x_0y_0$
	$A = x_1y_1$
	$B = x_0y_0$

$P = A + x_1y_0 + x_0y_1 + B$
$P - A - B = x_1y_0 + x_0y_1 = S$
$2^nA+ n^{n/2}(x_1y_0 + x_0y_1) + B$

$T(n) \leq 3T(n/2)+O(n)$
$O(n^{log_23}) = O(n^{1.59})$ 


# Counting Inversions
*in: list of itnergers L*
*out: number of pairs taht are inverted i, j s.l i< j ,b but L\[i] > L\[j]*

Social choice thoery
Clustering on counting inversions

**Observe**
- We can have $\Omega (n^2)$ many inversions
**Corollary**
- counts using count +=1
- it runs in the $\Omega (n^2)$.

```psudo
Count(L):
	inv_1 = count(L_1)
	inv_2 = count(L_2)
	count(L_1, L_2)	
```

Basically merge to check of inversions in the L_1 and L_2 lists given that L_1 and L_2 is sorted

```python
def sort_and_count(L):
	if len(L) =< 1: return (0, L)
	inv_1, L_1 = sort_and_count(L[:len(L)//2])
	inv_2, L_2 = sort_and_count(L[len(2)//2:])
	p_1 = p_2 = 0
	L = [0]
	count = 0
	while p_1 < len(L_1) and P_2 < len(L_2):
		if L_1[p_1] < L_2[p_2]:
			L.append(L_1[p_1])
			p_1 += 1
		else:
			count += len(L_1)-P_1
			L.append(L_2[p_2])
	return (inv_1 +inv_2 + count, L + L_1[p_1:], + L_2[p_2:])
```


# Closest pair 
*input: set of points in the plane*
*output: A pair with minimum distance*

The closest pair is either full

def closest pair(P):
	L =P\[:n/2] 
	R = p\[n/2:]
	D_L = closest_pair(L)
	D_R = closest_pair(R)
	d = mm(d_L, d_R)
	S={all pairs s away for x}
	for i in range(len(S))
		F = \[i:i + somthing]
		bruteforce(F)

let $\delta = mm(\delta_L, \delta_R)$
We need to find if there are
	$P \in L, q\in R s.t$
		dist(p,q)
Observation. Let x be the dividing line between L and R
If p and q are as above then p and q are $\leq \delta$ for away from x*

Let S be all points at most $\delta$ for away from x* " S is the Strip"

But: S can have sfsd $\Omega(n)$ so we count all pairs

Suppose S is sorted by Y-coordinate
	Claim. Let s_i be the ith element in S.
		Let s_i and s_j be points in s
		If |j-i| >7 then dist(s_i, s_j) > $\delta$


**Proof**:
1. Consider one box of size $\delta / 2$ and $\delta / 2$
2. Obs. If a box  contains two points then they are closer then $\delta$ apart
3. Any two points on the same side of x^s ahve dist $\geq \delta$
4. If |j-i| > 7. then s_j is not in any box, hense s_j is at least $\delta$ away from s_j

**Other**
hence we can try every consecutive "windows" in S of side $\leq$ 8