```python
def sort_and_count(L):
	if len(L) <= 1:
		return (0, L)

	inv_1, L_1 = sort_and_count(L[:len(L)//2])
	inv_2, L_2 = sort_and_count(L[len(L)//2:])

	P_1 = P_2 = 0
	L = []
	count = 0

	#for double inversion counting
	for i in range(len(L_1)):
		#it has to be biger than double
		while P_2 < len(L_2) and L_1[i] > 2 * L_2[P_2]:
			P_2 += 1
		count += P_2
	  
	P_1 = P_2 = 0
	while P_1 < len(L_1) and P_2 < len(L_2):
		if L_1[P_1] < L_2[P_2]:
			L.append(L_1[P_1])
			P_1 += 1
		else:
			L.append(L_2[P_2])
			P_2 += 1

	return (inv_1 + inv_2 + count, L + L_1[P_1:] + L_2[P_2:])
  
a = [1,2,3,12,11,10,4,5,6,7]
  
sort_and_count(a)
```


# Task 2

Operation on each node has to be constant and you have to half the operation each time.
Only check the children, if both are bigger then you have found a local minima
If some of the children are smaller recursive go into that
We dont need to check both techically since both have to have a minima
The max scenario is that we go d deep, and d is log_2(n)

- **Compare the current node with its children**:
    - If the current node is smaller than both children, it's a local minimum.
    - If both children are smaller than the current node, move to the child with the smaller label.
    - If only one child is smaller, move to that child.
- **Recursively repeat** until a local minimum is found.

# Task 3

- **Compare the current node with its neighboors**:
    - If the current node is smaller than all neighboors, it's a local minimum.
    - If all neighboors are smaller than the current node, move to the neighboor with the smaller label.
    - If only one neighboor is smaller, move to that neighboor.
- **Recursively repeat** until a local minimum is found.


- We can run it like n +  n/c2 + n/c'4 where n is highest

Find the median along the rows and check all vals
take the smallest
check over and under if it is smaller above check all value above 

and do the same with rows
and this goes on recursivly

cut the board horisontally then vertically and so on