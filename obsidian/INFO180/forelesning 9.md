## Decision-Making Under Uncertainty

- Challenges:
    - Short deadlines, lack of information, and numerous outcomes.
    - Example: Diagnosing dental issues (many possible causes, incomplete knowledge).

## Beliefs and Probabilities

- **Aleatoric Uncertainty**: Probability before an event occurs.
- **Epistemic Uncertainty**: Probability after observing evidence.
- **Belief Updating**:
    - Use probability theory to adjust beliefs based on new information.

## Probability Basics

- Definitions:
    - **Worlds**: Sets of mutually exclusive and exhaustive outcomes.
    - Axioms:
        - $0 \leq P(\omega) \leq 1$.
        - $\sum_{\omega \in \Omega} P(\omega) = 1$.
    - Conditional probability: $P(a|b) = \frac{P(a \land b)}{P(b)}$

## Inference with Probabilities

- Marginalization:
    - Compute probabilities for subsets of variables.
- Normalization:
    - Ensure total probability sums to $1$: $P(x) = \alpha \cdot \text{unnormalized probabilities}$

## Bayes' Rule

- Formula: $P(a|b) = \frac{P(b|a) \cdot P(a)}{P(b)}$
- Applications:
    - Combine evidence from multiple sources.
    - Calculate posterior probabilities.

## Bayesian Networks

- **Structure**:
    - Directed Acyclic Graph (DAG).
    - Nodes: Random variables.
    - Edges: Direct causal relationships.
- **Advantages**:
    - Simplify calculations by modeling conditional independence.
    - Efficient representation of joint probabilities: $P(X_1, \dots, X_n) = \prod_{i=1}^n P(X_i| \text{Parents}(X_i))$

## Example: Dental Diagnosis

- Variables: Toothache, cavity, X-ray.
- Compute posterior probability: $P(\text{Cavity}|\text{Toothache} \land \text{Shadow}) = \alpha \cdot P(\text{Toothache}|\text{Cavity}) \cdot P(\text{Shadow}|\text{Cavity}) \cdot P(\text{Cavity})$

## Key Takeaways

- Use Bayesian networks to:
    - Represent expert knowledge.
    - Update probabilities as new evidence is added.
- Challenges:
    - Collecting reliable subjective probabilities.
    - Handling exponential growth in joint probability tables.