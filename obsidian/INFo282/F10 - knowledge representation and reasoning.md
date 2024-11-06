
## On representing knowledge:

- the *propositional language*
  - symbols: `p`
  - operators: ¬, ∨, ∧, →, ↔

- the *predicate (first-order) language*
  - symbols: `a`, `x`, `f(...)`
  - functions/predicates: `P(t1)`, `P(t1, t2), ...`
  - operators: ¬, ∨, ∧, →, ↔, ∃, ∀
### Why use description logic (dl)
**clarity:**
- $\sqcap$ and $\sqsubseteq$ represents operations and relationships specific to concepts rather than individual instances (classes and categories)
- Emphasizes how concepts relate to each other rather than just properties of individual objects
- using $\sqsubseteq$ can represent an inherent part of ontology and taxonomy design.
- ontologies, concepts together with their properties and relationships

**expressiveness and computational properties**
- using $\bot$ we can denote unsatisfiable concepts

**abstracting from instances to concepts**
- Predicate
	- Human(Socrates)
- DL use class-level relationships
	- Cat ⊑ ∃HasColor.Orange
		- this states that all instances of the class cat may have the property of "HasColor" with the value "Orange" 
	- ig more generalized
	

## Describing graphs
- Propositional language
- predicate language

**Language for describing concepts**
- Basic concept: collection of objects
- Role : A relation between objects
- Complex concept: built via basic concepts, roles & operators
- $\sqcap, \sqsubseteq, \bot, \top, \equiv$     
- $\text{Minor} \sqcap \text{Driver}) \sqsubseteq \bot, \quad (\exists \text{has.RenalDisease}) \sqsubseteq \text{Sick}$

- Consept inclusion:
	- $\text{Minor} \sqcap \text{Driver}) \sqsubseteq \bot, \quad (\exists \text{has.RenalDisease}) \sqsubseteq \text{Sick}$
- Concept definition 
	- $\text{ Teacher } \equiv (\text{ Person } \sqcap \exists \text{ teaches.Course })$

**Different languages** 
- $\mathcal{EL}, \mathcal{FL}, \mathcal{AL}, \mathcal{ALC}, \dots$


**Predicate logic is undecidable**

- Description logic are designed with knowledge representation and reasoning in mind
	- decidable
	- expressive enough


$$Language - \mathcal{EL}$$
- Take names for individuals ($N_I$), basic concepts ($N_C$) and roles ($N_R$).

![[Pasted image 20241106225013.png]]
## Examples of Concepts

- **$\top$**: all objects
- **Person**: all persons
- **Male**: all males
- **Cat**: all cats
- **$Person \sqcap Male$**: all male persons
- **$\exists \text{is\_friend\_of} . \text{Cat}$**: all that are friends of at least one cat
- **$Person \sqcap \exists \text{is\_friend\_of} . \text{Female}$**: all persons that are friends with at least one female
- **$\exists \text{lives\_with} . (\exists \text{is\_friend\_of} . \text{Cat})$**: all that live with at least something that is a friend of at least one cat


Defining a model
- $\mathcal{D}$ is a non-empty domain
- the interpretation $\mathcal{J}$ assigns
	- an object $\mathcal{J}(a) \in \mathcal{D}$ to each individual name $a \in N_I$


### Knowledge Base Components
1. Terminological Box (TBox)
	- TBox contains concepts hierarchies, which describe relations between different concepts
	- terminological facts
	- structure of the domain by specifying types of entities and their relationships
		- f.ex all cats are animals, a human is a mammal
	- General relationships
1. AssertionBox (ABox)
	- particular facts about individuals and relationships between them
	- Garfield is a cat or john is friends with mary 
		- refer to individual entities in the domain and their relationship

A Knowledge base in discripntion logic is a finite colecction of statements that represent konwelde about a particular domain 
$$K =(T, A)$$
## Domain in Description Logic

- The **domain** \(\Delta\) is the set of all individuals over which concepts and roles are interpreted.
- A **DL interpretation** is defined as \(\mathcal{I} = (\Delta, \cdot^{\mathcal{I}})\), where:
  - Each **concept** \(C\) maps to a subset of \(\Delta\): \(C^{\mathcal{I}} \subseteq \Delta\).
  - Each **role** \(R\) maps to a subset of \(\Delta \times \Delta\): \(R^{\mathcal{I}} \subseteq \Delta \times \Delta\).
  - Each **individual** \(a\) maps to an element in \(\Delta\): \(a^{\mathcal{I}} \in \Delta\).

### Example
For \(\Delta = \{ \text{Alice}, \text{Bob}, \text{Whiskers} \}\):
- \(\text{Person}^{\mathcal{I}} = \{ \text{Alice}, \text{Bob} \}\)
- \(\text{Cat}^{\mathcal{I}} = \{ \text{Whiskers} \}\)
- \(\text{hasFriend}^{\mathcal{I}} = \{ (\text{Alice}, \text{Bob}) \}\)

## Domain in Description Logic

- The **domain** $\Delta$ is the set of all individuals over which concepts and roles are interpreted.
- A **DL interpretation** is defined as $\mathcal{I} = (\Delta, \cdot^{\mathcal{I}})$, where:
  - Each **concept** $C$ maps to a subset of $\Delta$: $C^{\mathcal{I}} \subseteq \Delta$.
  - Each **role** $R$ maps to a subset of $\Delta \times \Delta$: $R^{\mathcal{I}} \subseteq \Delta \times \Delta$.
  - Each **individual** $a$ maps to an element in $\Delta$: $a^{\mathcal{I}} \in \Delta$.

### Example
For $\Delta = \{ \text{Alice}, \text{Bob}, \text{Whiskers} \}$:
- $\text{Person}^{\mathcal{I}} = \{ \text{Alice}, \text{Bob} \}$
- $\text{Cat}^{\mathcal{I}} = \{ \text{Whiskers} \}$
- $\text{hasFriend}^{\mathcal{I}} = \{ (\text{Alice}, \text{Bob}) \}$
