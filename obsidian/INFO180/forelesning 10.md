## Real-World Applications

- **Autonomous Driving**:
    - Vehicles with their own goals must account for other drivers and unknown scenarios.
- **Invitation Game**:
    - Choosing guests for a party considering overlap in preferences and alternatives.

## Multi-Agent Systems

- **Characteristics**:
    - Agents act autonomously.
    - Each agent has its own information about the world.
    - Mechanisms define outcomes of actions.
- **Types**:
    - **Cooperative Agents**: Shared utility, collaborative strategies.
    - **Competitive Agents**: Opposing utilities, balancing gains and losses.
    - **Zero-Sum Games**: Gains of one agent are losses of another.



## Rock, Paper, Scissors Payoff Matrix
- **Rules**:
  - Rock beats scissors but loses to paper.
  - Paper beats rock but loses to scissors.
  - Scissors beats paper but loses to rock.

- **Zero-Sum Game**:
  - The sum of payoffs for Alice and Bob is always \(0\).
  - Winning gives \(+1\), losing gives \(-1\), and ties give \(0\).

#### Payoff Matrix:
| **Alice \ Bob** | **Rock**    | **Paper**   | **Scissors** |
|------------------|-------------|-------------|--------------|
| **Rock**         | \(0,0\)    | \(-1,1\)    | \(1,-1\)     |
| **Paper**        | \(1,-1\)   | \(0,0\)     | \(-1,1\)     |
| **Scissors**     | \(-1,1\)   | \(1,-1\)    | \(0,0\)      |

## Game Theory

- **Definitions**:
    - Agents $1, 2, \ldots, n$.
    - Action profiles: $(a_1, a_2, \ldots, a_n)$.
    - Utility: $(u_1, u_2, \ldots, u_n)$, where $u_i$ is the utility for agent $i$.
- **Rock-Paper-Scissors**:
    - Example of a zero-sum game with utility matrix.

## Game Trees

- **Structure**:
    - Nodes represent states; edges represent actions.
    - Leaves represent outcomes with utilities for agents.
- **Strategies**:
    - A strategy specifies an action for every node controlled by an agent.
    - **Backward Induction**:
        - Start from leaf nodes and calculate optimal actions up to the root.

## Games with Imperfect Information

- **Features**:
    - Agents do not know the exact state but know possible actions.
    - Use **information sets**:
        - Probability distribution over possible nodes.
- **Expected Utility**: $u_i(N) = \sum_{n \in N} p(n) u_i(n)$
    - Choose strategies maximizing expected utility.

## Minimax and Alpha-Beta Pruning

- **Minimax**:
    - Perfect information game where:
        - MAX maximizes utility.
        - MIN minimizes utility.
    - Used in games like chess, Go, and tic-tac-toe.
- **Alpha-Beta Pruning**:
    - Avoid exploring nodes guaranteed to be worse than current options.
    - Algorithm: $\alpha = \text{best value for MAX so far}, \; \beta = \text{best value for MIN so far}$
    - Prune branches where:
        - $v \geq \beta$ (MAX node).
        - $v \leq \alpha$ (MIN node).

## Efficiency

- **Search Complexity**:
    - Alpha-Beta reduces the number of nodes evaluated to $O(b^{d/2})$, where $b$ is branching factor and $d$ is depth.
- **Heuristics**:
    - Evaluate game states using metrics like:
        - Material advantage (e.g., number of pieces in chess).
        - Positional freedom (e.g., potential moves).

## Key Concepts

- Multi-agent systems and their strategies.
- Game trees and backward induction.
- Minimax and Alpha-Beta pruning.
- Evaluating imperfect information games.
