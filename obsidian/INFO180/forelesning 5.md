## Planning Overview
- **Core Elements**:
  - Determine the current state.
  - Specify desired outcomes.
  - Identify actions and their consequences.
- **Applications**:
  - Robotics (e.g., Servus managing glasses).
  - General decision-making in deterministic environments.

## Servus's Problem
1. Observes table status.
2. Loads glasses from the kitchen.
3. Moves to tables to deliver and collect glasses.
4. Decides whether to return to the kitchen or visit another table.
5. Unloads empty glasses in the kitchen.
6. **Goal**:
   - Maximize full glasses on tables.
   - Minimize empty glasses on tables.
   - Return to the kitchen with empty hands.

## Preconditions for Planning
- **Assumptions**:
  - Single agent (robot).
  - Deterministic actions with predictable outcomes.
  - Observable environment.
  - Time progresses sequentially.

## State Representation
- **Attributes**:
  - $ServusLocation \in \{\text{Kitchen, Table1, Table2}\}$
  - $ServusFull, ServusEmpty \in \{0, 1, 2\}$
  - $TableNFull, TableNEmpty \in \{0, 1, 2, 3\}$ (for $N = 1, 2$).
- **Example State**:
  $$ \text{ServusLocation} = \text{Table1}, \text{ServusFull} = 1, \text{ServusEmpty} = 0, \text{Table1Full} = 1, \text{Table1Empty} = 1 $$

## Actions
- **Move Between Locations**:
  - Example: $\text{FromTable1ToKitchen}$.
- **Handle Glasses**:
  - Pick up or set down glasses at specific locations.
- Total: 12 possible actions.

## STRIPS Representation
- **Components**:
  - **Preconditions**: Conditions that must be true for an action to occur.
  - **Effects**: Changes to the state after the action.
- **Example Rule**: Setting a full glass on Table1:
  - Preconditions:
    $$ \text{ServusLocation} = \text{Table1}, \; \text{ServusFull} \geq 1, \; \text{Table1Full} + \text{Table1Empty} < 3 $$
  - Effects:
    $$ \text{ServusFull} = \text{ServusFull} - 1, \; \text{Table1Full} = \text{Table1Full} + 1 $$

## Planning Algorithms
1. **Forward Planning**:
   - Perform a graph-based search from the initial state to the goal state.
   - Algorithms: $A^*$, breadth-first search, depth-first search.
2. **Regression Planning**:
   - Start from the goal and work backward to determine actions.
   - Combine effects into logical conjunctions:
     $$ g_1 \land g_2 \leftarrow s_1 \land s_2 \land \text{Act} = a_1 $$

## Search and Optimization
- **Challenges**:
  - Large state spaces (e.g., Servus's max of 1800 states).
  - Managing dependencies between actions and states.
- **Strategies**:
  - Factorized states and actions.
  - Heuristic-guided search (e.g., $A^*$).

## Rule-Based Actions
- **Causal Rules**:
  - Specify new values for state properties based on actions.
- **Frame Rules**:
  - Preserve properties unaffected by actions.

## Key Takeaways
- **Skills to Master**:
  - Represent planning problems.
  - Formulate actions using STRIPS or rules.
  - Explain forward and regression planning.
  - Understand the interaction between states, actions, and goals.
