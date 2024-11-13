
# KR & R

*How can we represent the required knowledge and how do we reason with it*
### Deductive, Inductive, Abductive, and Default Reasoning

---

**Deductive Reasoning**

- **Definition**: Inference $\varphi_1, \ldots, \varphi_n \models \psi$ is valid if truth of all $\varphi_i$ guarantees $\psi$.
- **Key Properties**:
  - *Monotonicity*: Adding information does not change the conclusion.
  - *Example*: If $KB \models \psi$, then $KB \cup \{\varphi\} \models \psi$ for any $\varphi$.
- **Use**: All premises must be true to support the conclusion.

---

**Inductive Reasoning**

| Aspect              | Description                                                                 |
|---------------------|-----------------------------------------------------------------------------|
| **Definition**      | Generalizes from specific cases to a general rule                          |
| **Example**         | Observing "Some Greeks are mortal" → Generalize "All Greeks are mortal"    |
| **Intuitive**       | $\varphi_1, \ldots, \varphi_n / \psi$ is inductive if $\psi$ generalizes $\varphi_i$ |
| **Characteristics** | - **Non-Monotonicity**: Adding info may invalidate the conclusion.<br>- **Use**: Hypothesis formulation when data is insufficient.|

---

**Abductive Reasoning**

| Aspect              | Description                                                                                                                   |
| ------------------- | ----------------------------------------------------------------------------------------------------------------------------- |
| **Definition**      | Provides best explanation for an observation                                                                                  |
| **Example**         | Observing "The street is wet" → Infer "It rained" as possible cause                                                           |
| **Intuitive**       | $\varphi_1, \ldots, \varphi_n / \psi$ is abductive if $\psi$ explains $\varphi_i$                                             |
| **Characteristics** | - **Non-Monotonicity**: New info can revise the explanation.<br>- **Use**: Everyday/scientific explanations for observations. |

---

**Default Reasoning**

| Aspect                          | Description                                                                                                                                                            |
| ------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Definition**                  | Draws conclusions using typical (implicit) assumptions                                                                                                                 |
| **Example**                     | "Chilly Willy is a bird" → Assume "Chilly Willy flies" (default assumption)                                                                                            |
| **Intuitive**                   | $\varphi_1, \ldots, \varphi_n / \psi$ is default if $\psi$ holds with assumptions                                                                                      |
| **Characteristics**             | - **Non-Monotonicity**: New info may alter the default conclusion. As the assumption necessarily is not always correct<br>- **Use**: Assumptions when info is lacking. |
| **Example of Non-Monotonicity** | Learning "Chilly Willy is a penguin" negates the default assumption that "Chilly Willy flies."                                                                         |


## Formalizing Default reasoning
*reasoning with additional (often implicit) default assumptions about the situation.*


**Use cases**:
- *General cases*
	- normality (under typical circumstances, Ps are Qs)
	- statistical ( Most Ps are Qs)
- lack of information to the contrary, as
	- familiarity ( if P was not a Q, I would know it )
- conventional uses ( A P is a Q, unless told otherwise)
- persistence ( A P is a Q unless something changes it)
	- the wall is red unless something changes it ig


**How can this be done**
- Syntactic: assume additional formulas
- Semantic: not all possible situations are equally plausible

the idea:
*If the statement is true, then it is known to be true*
*If a statement is not known to be true, then it is false.*
- Any KB can be extended into an extended knowledge base with new assumptions

### Consistency and Completeness in a Knowledge Base (KB)

1. **Consistency**:
   - A KB is *consistent* if there are no contradictions.
   - **Formal**: There is no formula $\psi$ such that $\text{KB} \models \psi$ and $\text{KB} \models \neg \psi$.
   - **Interpretation**: No conflicting information in the KB.

2. **Completeness**:
   - A KB is *complete* if it can conclude the truth or falsity of every formula.
   - **Formal**: For every $\psi$, either $\text{KB} \models \psi$ or $\text{KB} \models \neg \psi$.
   - **Interpretation**: The KB has an "opinion" on everything.

3. **Typical Characteristics**:
   - KBs are usually **incomplete** (don’t know everything).
   - KBs should ideally be **consistent** (free of contradictions).

## Closed-world assumption (CWA)

**Definition: Extended Knowledge Base with Closed-World Assumption**

- Let $KB$ be a knowledge base, and $FN := P$ be the set of atomic propositions, representing the statements for which we are allowed to assume negations if they are not entailed by $KB$.

1. **Extended Knowledge Base with CWA**: 
   - The extended knowledge base under the Closed-World Assumption, $KB^+_{cwa}$, is defined as:
     $$
     KB^+_{cwa} := KB \cup \{\neg \gamma \ | \ \gamma \in P \text{ and } KB \not\models \gamma\}
     $$
   - This construction means that the negation $\neg \gamma$ is added to $KB^+_{cwa}$ only if $\gamma$ is an atomic proposition in $P$ and is **not** a consequence of $KB$.
   - The Closed-World Assumption here implies that any atomic statement in $P$ not entailed by $KB$ is assumed to be false, effectively “closing” the knowledge base by filling in gaps with negations.

2. **Consequence Relation under CWA**:
   - The consequence relation under the Closed-World Assumption, denoted $\approx_{cwa}$, is defined as:
     $$
     KB \approx_{cwa} \psi \ \text{iff} \ KB^+_{cwa} \models \psi
     $$
   - This indicates that $\psi$ is a consequence of the extended knowledge base $KB^+_{cwa}$.

---

**Notes**:
- The negation $\neg \gamma$ is added to $KB^+_{cwa}$ only when $\gamma$ is an atomic statement in $P$ and is not entailed by $KB$.
- $P$ represents the set of atomic propositions whose negations we are allowed to assume under the Closed-World Assumption.
- If $KB$ is **complete**, then $\approx_{cwa}$ coincides with standard entailment ($\models$), as there would be no need to assume additional negations.
- The extended knowledge base $KB^+_{cwa}$ is **complete** under the CWA, even if the original $KB$ is not, because it fills in all gaps by assuming unentailed statements in $P$ to be false.


#### Example
1. **Given**:
   - Set of propositions: $P = \{AtoB, BtoA, AtoC, CtoA\}$
   - Knowledge base: $KB = \{AtoB, BtoA, AtoC\}$

2. **Construct $KB^+_{cwa}$**:
   - Since $CtoA \not\in KB$ and $KB \not\models CtoA$, add $\neg CtoA$.
   - Result: $KB^+_{cwa} = \{AtoB, BtoA, AtoC, \neg CtoA\}$

3. **Consequence**:
   - $KB \approx_{cwa} \neg CtoA$, meaning $\neg CtoA$ is inferred under CWA.

**Summary**: Under CWA, if $KB$ does not entail $CtoA$, we assume $\neg CtoA$.

#### Example 2 - Inconsistency

1. **Given**:
   - Set of propositions: $P = \{AtoB, AtoC\}$
   - Knowledge base: $KB = AtoB \lor AtoC$

2. **Construct $KB^+_{cwa}$**:
   - Since $KB \not\models AtoB$ and $KB \not\models AtoC$, add $\neg AtoB$ and $\neg AtoC$.
   - Result: $KB^+_{cwa} = \{AtoB \lor AtoC, \neg AtoB, \neg AtoC\}$

3. **Inconsistency**:
   - $KB^+_{cwa}$ is inconsistent because it contains $AtoB \lor AtoC$ (at least one must be true) and $\neg AtoB \land \neg AtoC$ (both are false).

**Conclusion**: Applying CWA can make $KB^+_{cwa}$ inconsistent, even if $KB$ is consistent.


## More Deductive Reasoning

- **Definition**: Inference $\varphi_1, \ldots, \varphi_n \models \psi$ is valid if $\psi$ is true in **every** situation where all $\varphi_i$ are true.

- **Example**:
  - $b$: "Chilly Willy is a bird"
  - $f$: "Chilly Willy flies"
  - **Inference**: $b \not\models f$ (being a bird does not guarantee flight)

- **Intuition**: Although $b \not\models f$, the pair $\{b, f\}$ feels **more plausible** than $\{b, \neg f\}$, given typical assumptions about birds.

### Default reasoning again
- **Definition**: $\varphi_1, \ldots, \varphi_n / \psi$ is an **inference by default** ($\approx_\le$) if $\psi$ is true in **most likely** situations where all $\varphi_i$ are true.

- **Example**:
  - $b$: "Chilly Willy is a bird"
  - $f$: "Chilly Willy flies"
  - **Default Inference**: Assume $\{b, \neg f\}$ is less likely than $\{b, f\}$.
  - Result: $b \approx_\le f$ (by default, assume Chilly Willy flies if he's a bird).


#### Defining "More Likely" Formally

- **Relation**: $\le$ is a **binary relation** over valuations (possible outcomes) for inference.
- **Meaning**: $V_1 \le V_2$ means "$V_2$ is at least as plausible as $V_1$."
- **Diagram**: Represented as $V_1 \rightarrow V_2$.

- **Properties**:
  - **Reflexivity**: $V \le V$ for all $V$.
  - **Transitivity**: If $V_1 \le V_2$ and $V_2 \le V_3$, then $V_1 \le V_3$.
  - **Connectedness**: Any two valuations can be compared (either $V_1 \le V_2$ or $V_2 \le V_1$).

