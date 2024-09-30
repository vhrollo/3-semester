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
		while P_2 < len(L_2) and L_1[i] >= 2 * L_2[P_2]:
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


