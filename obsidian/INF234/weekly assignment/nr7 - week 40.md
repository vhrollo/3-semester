# Task 1 

- the optimal solution in figure 1 is 1 , 6, 6, where the heaviest is not included in the optimal set. 
- Given 8, 1, 1, 8, the best possible set would be 9, if we use alg 2, therefore we have to keep in mind that there is also an option to skip two nodes
- Given an undirected graph of n

gives back max sum
```python
# P[i] = max(A[i] + P[i-2], P[i-1])

A = [1,8,6,3,6]

def compute_P(A, n):
	if n < 0:
		return 0
	if d[n] == None:
		d[n] = max(A[n] + compute_P(A, n-2), compute_P(A, n-1))
	return d[n]
	
n = len(A) - 1
d = [None] * (n + 1)
compute_P(A, n)
```
gives back a list
```python
A = [1,8,6,3,6]

def compute_P(A, n):
	if n < 0:
		return []
	if d[n] == None:
		l1 = [A[n]] + compute_P(A, n-2)
		l2 = compute_P(A, n-1)
	  
		if sum(l1) > sum(l2):
			d[n] = l1
		else:
			d[n] = l2
	return d[n]
	
n = len(A) - 1
d = [None] * (n + 1)
compute_P(A, n)
```
# Task  2
a)
$1\rightarrow 2, 1\rightarrow 3, 2 \rightarrow 6, 3\rightarrow 4, 4\rightarrow 6$ 
Here this algo will choose 1, 2, 6, instead of 1, 3, 4, 6

b)
Given a set of N initialize values from 1 to N
```python
def longest_path(n, edges):
	# Initialize the longest path lengths
	L = [-float('inf')] * (n + 1)
	L[1] = 0 # The path length at the starting node v1 is 0
	# For each node v_i from 1 to n-1
	for i in range(1, n):
		# For each node v_j such that j > i
		for j in range(i + 1, n + 1):
			if (i, j) in edges: # If there's an edge from v_i to v_j
				L[j] = max(L[j], L[i] + 1)
	
	return L[n] # The length of the longest path from v1 to vn

  

edges = {(1,2), (3,4), (2,4), (1,4), (2,5), (4,5)}

print(longest_path(5, edges))
```


# Task 3

Least segmentation problem

- Input: $(x_1, y_1),(x_2, y_2),...,(x_n, y_n)$
- output: A segmentation (cnotiguous partitioning)
- $S_1, S_2, ..., S_5$ 
- Such that 
- $ct+\sum_{i=1}^terror(S_i)$ is minimized

- $opt[n] = min J<n \{ c+ error(PjiPjn, Pn), +opt[i-1]\}$
- 