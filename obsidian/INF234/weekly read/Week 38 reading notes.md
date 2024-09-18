## 4.7 - Clustering
Given a collectioin of objects, we want to try to organize into coherent groups

**Clusterings of Maximum Spacing**
- *K - clustering*
- Distances between points
	- symmetric
	- non negativ
	- zero distance is only with itself
		- basically saying every node is unique
- Spacing of a cluster
	- Defined as the **minimum distance between any pair of points that are in different clusters**.
	- Our goal is to **maximize** this spacing.

- Designing the algorithm
	- Given distance of pairs
	- add an edge between the closest pair of points
	- continue in increasing order
	- avoid cycles

	- basically krugals algorithm
	- stop adding edges when you have exactly k clusters
	- this means you stop just before you reduce the number of clusters

Krugals algorithm, but we stop early
- essentially, we don't add the last k -1 edge

Why does this work?
- by stopping early we only have the largest edges left, that wont merge the trees

- Optimal clustering
	- any other cluster would be closer together or not be optimal (criteriaon)

**Proof**
- d* is the spacing of clustering C ( of U)
- C' is another clustering of U 
- Since d* is a edge in in C, every edge has to be equal or smaller

- If (p, p*) is a edge in P in C, it would have to be equal or less than d*
- by defenition the spacinng is the minimum distance between any pair of points in different clusters
	- since p and p' are in different clusters in C', and d(p, p') <= d* the spacing of C' is at most d*


## Huffman Codes and Data Compression



## 5.1 Divide & Conquer: merge sort and recurrence relations
*Simply divide the task into smaller tasks, and then solve each smaller task, and then combine them for the overall solution*

- Merge sort: statically divide & conquer
- Quick sort: dynamically divide & conquer

**Unrolling the Mergesort Recurrence**
- each level takes $n/2^j$ time, which makes the total which makes every level contribute $2^j(cn/2^j)$ 
- summing over the levels of recursion  that takes $log_2(n)$ time
- Bounded by $O(n\cdot log(n)$ 

**Substituting a Solution into Mergesort Recurrence**

**An Approach Using Partial Substitution**
- $T(n)\leq k\cdot n\cdot log_b(n)$
- $T(n)\leq 2k\cdot (\frac{n}{2}) log_b(\frac{n}{2}) +cn$ 
- $T(n)\leq kn \cdot log_b(\frac{n}{2}) +cn$ 
- Using b = 2
- $T(n)\leq kn \cdot (log_2(n)-1) +cn$
- $T(n)\leq kn \cdot log_2(n) -kn +cn$
- $kn \cdot log_2(n) -kn +cn \leq k\cdot n\cdot log_b(n)$
- therfore k has to be equal or less than c