$a \equiv b$ if and only if $\models a \leftrightarrow b$   
$a \equiv b$ if and only if $a\models b$ && $b \models a$


**The predicate language**
- Constants(1, mary,...)
- Predicate labels(Walks, Brunette)
	- relationships between the objects under discussion
	- can be both unary and multi-ary
- Variables
	- "Truls sees her/him"
		- Sees(truls, x)
- functions
	- fatherOf(x)
		- returns a var
		- has to refer to an unique option

- Examples
	- Walks(john)
	- Loves(mary, mary)
	- "John gives Mary the book or Mary gives John the movie"
		- Gives(john, mary, book) $\lor$ Gives(john, mary, movie)

**Quantifiers**
- $\exists x.Loves(j,x)$ 
- $\forall x.Loves(j,x)$
- Some politicians are students
	- $\exists .x(P(x)\land S(x))$
	- $\neg \forall .x(P(x) \rightarrow S(x))$	
	
	closed formulas ( all variables are connected to a quanifier or somehting)
	