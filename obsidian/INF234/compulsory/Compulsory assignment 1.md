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