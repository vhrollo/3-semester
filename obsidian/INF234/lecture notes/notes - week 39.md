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

