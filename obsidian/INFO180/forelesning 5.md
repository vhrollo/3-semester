
Eksplisitt representasjon av tilstandsroom
+ alle mulige tilstand i en tabell som fører til en ny tilstand ved en handling

Strips
+ pre-conditions
+ effects


**Regelbasserte handlinger**
- Alternativ til strips
- kausale regler
	- spesifiserer handlinger som gir en egenskap ny verdi 
		- hva handlig skedde
		- hva vilkår er sanne
- reammeregler
	- spesifiser når en egenskap holder den verdiern den hadde
	- hva handling gjelder for

**Regresjonsplanlegging**
- Goal driven
- actions and preconditions
	- every action has a precondition and effects. Preconditions are the conditions that must be true for the action to occur, and effects are the changes that the action causes in the world.
	- In regression planning, the effects of an action are used to match the goal, and then the preconditions of the action become new sub-goals.
	- updating the status as it goes
- Iterative process
	- finding subgoals
- a search \*
	- using a* to search
	- 