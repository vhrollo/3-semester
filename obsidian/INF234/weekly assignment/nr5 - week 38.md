## Task 1

balanced binary tree with n leaves
n is a power of 2
each edge has length $\ell_e$ 

Given that the root to leaf is the sum of all $\ell_e$ in its path

from the root node
find the max $\mathcal{L}_e$ path of edges
first maximize each edge on the root until one of the paths to its leaf nodes is equal to $\mathcal{L}_e$ . 
Then traverse down the tree and do the same

we could also just check the biggest $\mathcal{L}_e$ inlcuding each of the nodes child, and a adjust just one of them to match the other, with the edges from parent to children. Then do this recurivly
## Task 2

```python
def find_median_sorted_arrays(A, B):
    def median_recursive(A, B, a, b, n):
        print(f"n:{n}")
        #if n == 1:
        #    print("this will never happen")
        #    return min(A[a], B[b])
        if n == 2:
            return (max(A[a], B[b]) + min(A[a + 1], B[b + 1])) / 2.0

        k = (n - 1) // 2
        print(f"k: {k}")
        midA = A[a + k]
        midB = B[b + k]
        if midA > midB:
            #if you just want the min of the two median values
            #add b + k + 1 and n - k - 1
            # this will reach n == 1 as well
            return median_recursive(A, B, a, b + k, n - k)
        else:
            return median_recursive(A, B, a + k, b, n - k)
    
    n = len(A)
    return median_recursive(A, B, 0, 0, n)

# Example usage:
A = [1, 2, 3, 4, 5, 11]
B = [6, 7, 8, 9 ,10, 12]
median = find_median_sorted_arrays(A, B)
print("The median is:", median)

#Output:
#n:6
#k: 2
#n:4
#k: 1
#n:3
#k: 1
#n:2
#The median is: 6.5
```


Since n2 is always a even value, it would always be the mean of the two center values, and never a whole number, since every value is unique.
Given that the lower median is always the biggest value which could be in the (n-1)//2 position, it will always stay in the lists. 

So if you want the higher median, you would use the same but n // 2, which would always compare the upper one, this will be the opposite effect of the one over and you would have to max it


### Task 3
``` python
def find_majority_class(A: list):
    def recurisive_step(A: list):
        length = len(A) 
        i = 0
        els = []
        for i in range(0, length, 2):
            j = i + 1
            if j == length: 
                els.append(A[i])
                break
            if A[i] == A[j]:
                els.append(A[i])
        return els


    o = A.copy()
    o_l = len(A)

    while len(A) > 1:
        A = recurisive_step(A)
    
    if not A:
        print("There is not majority element in list")
        return;

    counts = [ (o.count(maj), maj) for maj in A]
    count, val = max(counts)
    print(counts)
    if count > o_l//2:
        print(f"The majority element is: {val}")
    else:
        print("There is not majority element in list")

elements = [2,1,2]

majority_els = find_majority_class(elements)

```

This works in tree steps:

It will first pairwise check every element, and it will remove elements which are not equal. For every equal one, one of its elements will be passed down to a new list.

So worst case scenario for this will be that all pairs are equal, and therefore it will only half, instead of getting less passed down

This will happen recursively until there is either two or one card left, just check that the two cards are different

One of these two cards really doesnt have to be the majority card, so therefore we have to compare each to all elements in the first list. If one of these are the majority we can safely give out the majority card.

Pairing up elements and comparing them: O(n)
Recursivlely doing this ^ where we at worst case scenario half O(log(n))
In the end check if the card is majority (O(n))

Total: $O(n\cdot log(n) + n)\approx O(n\cdot log(n))$  