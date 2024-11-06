- Graphs (a domain with properties of objects and binary relations) can represent a huge variety of things.
- A particularly important thing to represent: ontologies (concepts and their relationships).
- Graphs can be described by a variety of languages.
- The decision: expressivity vs. complexity.
- DL languages: good balance between those.
- Each DL formula is understood as a concept
- Each DL formula is true/false in a given object of a given graph.
- DL formulas are built from basic concepts and roles.

The EL language: “C” and “$\top$” plus “$\sqcap$” and “∃ r”.

A knowledge base in DLs has two parts:
a TBox, containing concept hierarchies (“ϕ v ψ”, “ϕ ≡ ψ”)
an ABox, containing assertions (“C(a)”, “r(a, b)”)
Each concept hierarchy is true/false in a given graph.
Each assertion is true/false in a given graph.


What is the difference between using some DL, say EL, and using other languages?
Answer: expressivity (and, therefore, complexity)!

$\mathcal{EL}$ vs propositional logic
Let “C”/“p” describe basic/atomic properties of objects.
- EL cannot talk about lack of a property; PL can (“¬”).
- EL cannot talk about union of properties; PL can (“∨”).
- EL can talk about relationship with objects (“∃ r”); PL cannot.

$\mathcal{EL}$ vs the predicate language fol
Let “C”/“P (. . .)” describe basic/atomic properties of objects.
- EL cannot talk about lack of a property; FOL can (“¬”).
- EL cannot talk about union of properties; FOL can (“∨”).
- EL has only unary/binary predicates; FOL has no restriction.
- EL cannot quantify universally; FOL can (“∀”).
- EL has a fixed quantification pattern (see below!); FOL has no restriction.
- Formulas in EL are evaluated locally; formulas in FOL are evaluated globally.


**propositional modal languages**, the basic one being:
  $$
  \text{p} \quad \text{plus} \quad \neg, \; \lor, \; \land, \; \rightarrow, \; \leftrightarrow, \; \Diamond, \; \Box
  $$
- **Modal Operators**:
  - $\neg$ (not): Negation.
  - $\lor$ (or): Disjunction.
  - $\land$ (and): Conjunction.
  - $\rightarrow$ (implies): Implication.
  - $\leftrightarrow$ (if and only if): Biconditional.
  - $\Diamond$ (diamond): Typically represents "possibly" in modal logic.
  - $\Box$ (box): Typically represents "necessarily" in modal logic.

EL A propositional modal language ($ML_1$)
- EL and ML1 are equally expressive (in fact, just syntactic variations).

ALC The basic modal language (ML)
- ALC and ML are equally expressive (in fact, just syntactic variations).


Compared with EL, the language ALC has
- an additional basic concept (⊥),
- additional operators for constructing complex roles (¬, t, ∀).



### The Language $ALC$

Take names for **individuals** $N_I$, **basic concepts** $N_C$, and **roles** $N_R$.

**Definition: Language $ALC$**

Formulas (i.e., concepts) $\varphi$ and $\psi$ in $ALC$ are built by:
$$
\varphi, \psi ::= C \;|\; \top \;|\; \bot \;|\; \neg \varphi \;|\; \varphi \sqcap \psi \;|\; \varphi \sqcup \psi \;|\; \exists r.\varphi \;|\; \forall r.\varphi
$$
with $C \in N_C$ and $r \in N_R$.

**Intuitive Meanings**:
- $\bot$ contains no object.
- $\neg \varphi$ contains all objects *not* belonging to $\varphi$.
- $\varphi \sqcup \psi$ contains all objects belonging to *at least one* of $\varphi$ and $\psi$.
- $\forall r.\varphi$ contains all objects that can reach, through role $r$, only $\varphi$-objects.


### Examples of Concepts

- $\bot$  
  - no object

- **Person**  
  - all persons

- $\neg \text{Cat}$  
  - all entities that are not cats

- $\text{Cat} \sqcup \text{Dog}$  
  - all entities that are cats or dogs

- $\exists \text{is\_friend\_of} . \text{Cat}$  
  - all that are friends of at least one cat

- $\forall \text{is\_friend\_of} . \text{Cat}$  
  - all that are friends of only cats

- $\forall \text{is\_friend\_of} . \neg (\text{Cat} \sqcup \text{Dog})$  
  - all that are friends of neither cats nor dogs

- $\forall \text{is\_friend\_of} . \bot$  
  - all that have no friends



- Every formula in EL is logically equivalent to some formula in the predicate language.
- Every formula in ALC is logically equivalent to some formula in the predicate language

### $ALC$ vs the Predicate Language

1. From **formulas/concepts** in $ALC$ to **formulas** in $FOL$. Crucial observation: a *translation*.

Formulas/concepts in $ALC$, describing objects, are:
$$
C \;|\; \top \;|\; \bot \;|\; \neg \varphi \;|\; \varphi \sqcap \psi \;|\; \varphi \sqcup \psi \;|\; \exists r . \varphi \;|\; \forall r . \varphi
$$

Define:
$$
\tau_x(C) := C(x)
$$
$$
\tau_x(\top) := x = x
$$
$$
\tau_x(\bot) := \neg (x = x)
$$
$$
\tau_x(\neg \varphi) := \neg \tau_x(\varphi)
$$
$$
\tau_x(\varphi \sqcap \psi) := \tau_x(\varphi) \land \tau_x(\psi)
$$
$$
\tau_x(\varphi \sqcup \psi) := \tau_x(\varphi) \lor \tau_x(\psi)
$$
$$
\tau_x(\exists r . \varphi) := \exists y . (r(x, y) \land \tau_y(\varphi))
$$
$$
\tau_x(\forall r . \varphi) := \forall y . (r(x, y) \rightarrow \tau_y(\varphi))
$$

with $y$ a ‘fresh’ variable.

Then, for any $\varphi$ in $ALC$ and any $\langle \mathcal{D}, \mathcal{I}, g \rangle$,
$$
o \in \mathcal{I}(\varphi) \text{ if and only if } \langle \mathcal{D}, \mathcal{I}, g[x \rightarrow o] \rangle \models \tau_x(\varphi)
$$

$\tau$ is used to formalize the translation process from description logic ALC to first-order logic.


2. From **concept inclusion/definition** in $ALC$ to **formulas** in $FOL$. The crucial observation is a *translation*.

Concept inclusion/definition in $ALC$, relating concepts, are:
$$
\varphi \sqsubseteq \psi \quad | \quad \varphi \equiv \psi
$$

Define:
$$
T(\varphi \sqsubseteq \psi) := \forall x . (\tau_x(\varphi) \rightarrow \tau_x(\psi))
$$
$$
T(\varphi \equiv \psi) := \forall x . (\tau_x(\varphi) \leftrightarrow \tau_x(\psi))
$$

Then, for any $\varphi, \psi$ in $ALC$ and any $\langle \mathcal{D}, \mathcal{I}, g \rangle$,
$$
\langle \mathcal{D}, \mathcal{I} \rangle \models \varphi \sqsubseteq \psi \quad \text{if and only if} \quad \langle \mathcal{D}, \mathcal{I}, g \rangle \models T(\varphi \sqsubseteq \psi)
$$

3. From **concept/role assertions** in $ALC$ to **formulas** in $FOL$. There is a direct correspondence.

Concept/Role assertions in $ALC$, asserting properties/relations, are already $FOL$ formulas:
$$
C(a) \quad | \quad r(a, b)
$$

Then, for any concept/role assertions in $ALC$ and any $\langle \mathcal{D}, \mathcal{I}, g \rangle$,
$$
\langle \mathcal{D}, \mathcal{I} \rangle \models C(a) \quad \text{if and only if} \quad \langle \mathcal{D}, \mathcal{I}, g \rangle \models C(a)
$$
$$
\langle \mathcal{D}, \mathcal{I} \rangle \models r(a, b) \quad \text{if and only if} \quad \langle \mathcal{D}, \mathcal{I}, g \rangle \models R(a, b)
$$

### Quantifying with Numbers
- $\geq n \; r . \varphi$: all objects that can reach, via $r$, **at least** $n$ $\varphi$-objects.
- $\leq n \; r . \varphi$: all objects that can reach, via $r$, **at most** $n$ $\varphi$-objects.

### Using the Names of Individual Objects
- $\{a\}$: the set containing **the specific object** $\mathcal{I}(a)$.

### More Complex Roles
- $\exists (r \sqcap s) . \varphi$: all objects that can reach, via **both** $r$ **and** $s$, **at least one** $\varphi$-object.
- $\exists r^{-1} . \varphi$: all objects **that can be reached**, via $r$, by **at least one** $\varphi$-object.

### Additional Expressions in ABoxes and TBoxes
- $p(a)$: object $\mathcal{I}(a)$ is in the **complex concept** $\mathcal{I}(\varphi)$.
- $a \neq b$: objects $\mathcal{I}(a)$ and $\mathcal{I}(b)$ are **different**.
- $r \sqsubseteq s$: all **pairs** in $\mathcal{I}(r)$ are **also in** $\mathcal{I}(s)$.
