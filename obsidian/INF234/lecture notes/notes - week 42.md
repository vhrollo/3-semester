# Spellchecking
*Given a word, is it in a dict*
*If not? Find the cloest word*

Three types of mistakes:
- Omission of a character
- Insertion of a character
- Character replacement



**Definition(word distance)**:
- Given two words X and Y, the distance between them is the **smallest** number of operations we have to do on X to obtain Y, where operations:
	- delete a char in X
	- insert a char into X
	- replace a char in X in pos i with another char
	- 
**Edit distance / Levenchten dsitane / sequence alignment**

Example:
- X = sunny -> snny -> snony -> snowy 

Base case:
- if y or x is = 0, then the it is the max of the string lengths
- OPT(i,0) = i
- OPT(0, j) = j

Reoccurrence:
- OPT(i-1, j-1) if $x[i] = y[j]$
- OPT(i,j) = min(
	- 1 + OPT(i-1, j-1) # replacing a char
	- 1 + OPT(i, j-1) # adding a char
	- 1 + OPT(i-1, j)  # removing a char
- )

Proof of dynamic problem
- induction
- check dynamic programming pdf



# Knapsack(1-0)
- In : A = {$(v_1, w_1), (v_2, w_2), (v_n, w_n)$}, $W\in \mathbb{N}$
- out: maximum val constrained by W

- OPT(i, w) = maximum value we can get using items 1, ..., i, weighing at most W
- OPT(0, w) = 0
- OPT(i,w) )= max{opt(i-1, w-wi)+vi, opt(i-q, w)}
	- for all 