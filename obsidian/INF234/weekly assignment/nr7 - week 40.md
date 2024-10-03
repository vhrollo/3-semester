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
- $dp[i] = \max_{0\leq j < i}(dp[j] + quality(y[j:i]))$ , where the maximum at at each e3

finds the best split given a n in the string, it will then check what the left side would be, but we have already calculated it as we go form left to right.

so you would more efficiently need to have a prev split to find the best given split if you want the word in the end, then just backtrack in it
```python
def segment_word(word: str, word_dict: dict):
    n = len(word)

    dp = [-float('inf')] * (n + 1)
    dp[0] = 0
    prev = [-1] * (n + 1)

    for i in range(1, n + 1):
        for j in range(i):
            if word[j:i] in word_dict:
                quality = word_dict[word[j:i]]
            else:
                quality = -5

            if dp[j] + quality > dp[i]:
                dp[i] = dp[j] + quality
                prev[i] = j

    segments = []
    i = n
    while i > 0:
        j = prev[i]
        segments.append(word[j:i])
        i = j

    segments.reverse()
    return segments, dp[n]

word = "iamaboy"
word_dict = {'i': 1, 'am': 5, 'a':2, "boy": 3}
segmentation, total_quality = segment_word(word, word_dict)
print(segmentation, total_quality)
```
