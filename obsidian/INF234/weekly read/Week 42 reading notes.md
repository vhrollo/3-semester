
# Negative Cycles in a Graph

*The augmented graph G' has a negative cycle C such that there is a path from C to the Sink t if and only if the original graph has a negative cycle.*


The negative cycle detection in $G'$ is equivalent to detecting a negative cycle in $G$ that has a path to the sink $t$. Therefore, the problem reduces to deciding whether there is a negative cycle in $G$ that leads to $t$. 

If node v can reach node t and is contained in a negative cycle then:
$$\lim_{i \to \infty} OPT(i, v) = -\infty.$$


If G has n nodes and OPT(n, v)$\not=$ OPT(n − 1, v), then a path P from v
to t of cost OPT(n, v) contains a cycle C, and C has negative cost.