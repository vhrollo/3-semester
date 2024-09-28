# 1. Basic stuff

1. O describes the upper bound for a function, which could represent time, space, or other things. It mainly focuses on catching how the function it is describing scales. It is usually written in notation as $f(x)\in O(n^2)$, which means for n elements time, space or some other unit will use maximum $n^2$ for any n. This means that $f(x)\in O(n^3)$, given that this is still a upper bound, but just not a tight one.

   $\Omega$ describes the the lower bound, and much of the same things as for O apply. It has to be lower or equal to O.
   
   $\Theta$ is called a tight bound, and can only be used if $O = \Omega$. More formally $\Theta (g) \Leftrightarrow f\in O(g), f\in \Omega (g)$ . 

2. $3n^3+2n -4n \in \Theta(n^3)$
   $13n^2+n/n^2\in \Theta(n^2)$
   $n^2+nlog_3(n)\in \Theta(n^2)$ 

3. Every O notation is transitive as mentioned above. So if we know that $f \leq g \leq f$, then g and f must be similar, then $f \in \Theta(g)$
   
   Using the same transitivity, if $f \leq g \leq h \Rightarrow f \leq h$ and $f \in O(h)$
   
   if f is upper and lower bounded by g, by definition $f \in \Theta (g)$

# 2. Graphs 

1. A strongly connected component is when there is a path from every u to  every w, and opposite. Every node is reachable from every other. We was not supposed to include reflexivity for this.
2. in a digraph, If a bulk of nodes is in a cycle, then that would mean that every node has a path to every other node, this means that they are strongly connected. Then if a another cycle uses a same node as another cycle then they together make a big cycle where everything is strongly connected. And a DAG, is a direct acyclic graph, which does never have cycles.
   Then if all cycles which is connected become a strongly connected component, a condensation graph would be one blob if there existed a cycle between the component.
   Therefore we can conclude that the condensation graph of a digraph has to be DAG.
   
# 3. Greedy stuff
1. 
```python 
def change(coins: dict, value) -> dict:
	coins = sorted(coins.items(), key=lambda x: x[0], reverse=True)
	change_dict = {}
	num = 0
	for v, i in coins:
		num = min(i, value//v)
		value -= v * num
		change_dict[v] = num
	return change_dict
```

2. When using \{1,4,5,10} and a number like 8 the greedy algorithm will choose {5: 1, 1: 3} instead of {4:2}
3. Very intuitively i i think of a situation where the only edge to node s is also the most expensive one. Then to span the whole tree, that edge has to be included. More formally Prims algorithm doesn't stop before all nodes is taken, this would mean a worst case scenario, as it would always try to search the  lowest available edges first. As for Kruskals, since this is the only edge that is connected to node s, and that means that it cant make a cycle, which means that it will add it when it comes to it.
   
   When you have a cycle of $v_1, v_2, ...v_n$ only e-1 is needed to span all vertices. We can proof that the most expensive edge is always the one that is left out with an contradiction. If we have $v_1, v_2, ...v_n$ in a cycle and the proof from 3.1 does not apply given that a cycle each node will have minimum 2 degrees. If we follow Kruskals algorithm, and given that we have choosen the most expensive edge means that every edge that has been tried is shorter, they wouldve either been choesen or abandoned due to making the tree cyclic. We in total need e edges to make it cyclic. When choosing away this edge did not have enough edges out to complete the cycle, and we know that this edge is smaller, and thus making an contridiction. (sry for a bulky proof)
   
   The important thing to note is that all edges have unique weights, we can prove this using Kruskal's and Prim's algorithm. The weights should be sorted in the same order absolutely every time. Here it will choose the smallest first which wont make a cycle, and given the same set, this will always give the same result. We can also look at this from Prim's algorithm where we can where each step also will be unique given the unique weights. This will lead to the same edges chosen every time. Therefore we know that both of these will give one mst for a unique set of edges in both algorithms that we know gives an optimal solution.

# Divide & Conquer