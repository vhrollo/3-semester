Design artificial enteties for perofrming tasks
- Collect data
- Design entities searching implicit patterns
- Use them sub-symbolic ai

- Represent this knowledge
- Design entities using it
- Symbolic ai

Sub-symbolic ai
- data is provided
- ai entetiy finds implicit patterns
- robust against noice, no need to experts

Symbolic ai
- knowledge is explicitly represented
- ai entety reasons with it
- behaviour is easier to debug, control and explain
- good for abstract
- inference, search, rules, ontologies


Terminology
Premises P, and Conclusion C
$$\frac{P_1,...,P_n}{C}$$


Some type of inference

inductive: generization
- bird one fly
- brid two fly
- then all birds fly

Valid/Deductive inference
- if chilly whilly is a bird, then it has feathers
- chilly willy is a bird
- then chilly willy has feathers

C is a logical consequence of $P_1,...,P_n$
We write $P_1, ... , P_n \models C$  
If C is false, that doesnt mean that P has to be true

Deductive reasoning, abstractly
- Reflexivity
	- A entails A
	- Order of premises doesnt matter
	- Contraction: A and A premises, will be seen as A
- Cut
	- B entails C, and A entails B, then A entails C
- Monotonicity
	- $.... \models C$ is the same as $...A...\models C$ 


