*We have to come up with a small number of subproblems so that each subproblem can be solved easily from "smaller" subproblems, and the solution to the original problem can be obtained easily once we know the solution to all subproblems*
# Subset sum problem
input: n items, n weights, and n vals
You have a knapsack, or a bag, that can carry up to W amount of weight.
Output: select a subset of items that fits within the wight limit W and gives the highest total value.

```Opt(i,w)``` is the optimal value you can get with val i with max weight w. So when solving the smaller problems that consider fewer items and less weight capacity, gradually building up to the full problem
```OPT(i, w) = max(OPT(i - 1, w), wi + OPT(i - 1, w - wi)).```
When the current weight limit exceeds w you cannot take the item

**try to make the knapsack problem or subset sum problem**
either time and interval i
or space and item i

# Sequence Alignment
dunno






# 6.8 Search algorithm with dynamic programming

### Bellman-Ford Algorithm
- If G has no negative cycles, then there is a shortest path from s to t that is simple (i.e., does not repeat nodes), and hence has at most n − 1 edges
- $i>0$
- $OPT(i,v) = min(OPT(i-1,v), min_{W\in V}(OPT(i-1,w)+c_{vw}))$ 
