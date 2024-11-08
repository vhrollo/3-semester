# Bayesian Modeling
- Explain differences between different probability interpretations
- Probabilistic modeling is a systematic approach to address these problems
- They know when they don't know

Aleatory uncertainty
- due to randomness
- we are not to obtain observations which can reduce this uncertainty

Epistemic uncertainty
- due to lack of knowledge
- we are able to obtain observations which can reduce this uncertainty
- two observers may have different epistemic uncertainty


Frequentist
- frequencies forom repetitions of experiment
- handles aleatory uncertainty

Bayesian
- Here A are propositions and P(A) is a degree of belief in A being true
- "i believe to the extent of P(a) that a is true"
- frequentist interpretation: there P(A) is the proportions of times A occurs to be true
- handles both aleatory and epistemic uncertainty

Conditional probability
- So far, we have selected one model that is in some sense "best"
	- using empirical risk minimization that often corerspnds to maximium liklihood argmax(P|D)

- Bayesian methods don't return a single model a probabiliy distribution over models
	- summerize the current knowledge in prior distros
	- update the belief based on observed data D
	- posterior distributions P that summarizes the knowledge after observing D


**Terminology**
- Likelihood: P(D|$\theta$) is the probability of observing the particular data D given that the data was generated from a model with parameters $\theta$ 
	- loss
- Prior $P(\theta)$ is the probability distro of params before seeing the data
	- does not depend on data
	- is our subjective uncertainty about parameters before we see any data
	- epestemic uncertainty
	- reguralization
- posterior $P(D|\theta)$ is the probability of parameters given data
	- probability of a model after seeing data
	- our prior belives are updated based on the data we see

Take the weighted average of predictions over all models

**Naive Bayes Classifier**
- A probabilistic classifier that applies Bayes' theorem
- Naive assumption: all features are conditionally independent given the class
- $P(C, x_1, x_2, ..., x_d) = P(C)\prod^d_{i=1}P(x_i|C)$ 
- Calculate through joint probability^


**Example: Spam filtering**
spam 30%
ham 70%
prior:
- P(s) = 0.3
- p(h) = 0.7

that a word inlcude "money"
- P(money | s) = 25%
- P(money | h) = 5%

**Learning parameters**
- let N_ijk be the nubmer of the training examples with class k and jth feature taking value i 
**Maximum likelihood**
- problem: what if N_ijk = 0 for some i, j and k
**maximum a posterior**
- dirichlet prior

