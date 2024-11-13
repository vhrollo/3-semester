# Ensemble Methods


Condorcet's jury theorem:
- The judgement of a committee is superior to those inviduals, provided that individuals have reasonable competence


Reducing error
- Bagging: reduce varience
- boosting: reduce bias


**Bagging sample**:
- One samlpes a new training by sampling n points with raplacement from D
- On avarage it will be 63.2%

Easily parralizable 

**Properties of bagging**
- need to have low bias base models
- loss of interpretability


**Boosting**:
- Create simple classifier based on subset of example
- repeat T times
- concentrate on "hardest" examples

**Adaboost**: intuitevly
- Given: ($x_1, (y))
- Initialize all points to have uqual weights
- For T
	- learn a classifier on weighted data
	- compute weighted training error
	- compute classifier weight
	- update wieghts for hte date points
	- $\alpha_t = \frac{1}{2}log(\frac{1-\epsilon_t}{\epsilon_t})$

**Practical considerations**



