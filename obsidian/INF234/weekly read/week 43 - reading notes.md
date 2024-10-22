
# The maximum-flow problem and the ford-Fulkerson algorithm

# Maximum flow
- flow chart
- source s
- sink t
- max units, and max capacity per node
- bottleneck value

- each edge in a flow graph has a certain flow and capacity specified by the fraction adjacent to each edge. The flow is initially 0
$$f^{out}(v) = \sum_{e \, \text{out of} \, v} f(e)$$
$$f^{in}(v) = \sum_{e \, \text{into} \, v} f(e)$$
residual graph