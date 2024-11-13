# Data handling
*bias, missing, and imbalanced data*

Data quality and quantity gives a upper bound for what can be learned
More data $\Rightarrow$ weaker signal can be detected 

**Bias**
systemic error
- Can be caused by unrealistic assumptions

Informal definition:
- The signal in the training data does not equal the true signal

Bias in the training data tend to lead to biased models
- sample, human, measurement bias

Sampling bias
- e.x suvivors bias

**Fairness**
Trying to represent to much

**The COMPAS algorithm**
US justice system for predicting if an inmate will re-offend based on high or low risk


## Missing data
**Missing completely at random (MCAR)**
- The probability of missingness does note depend on the value of the missing variable or any other variable
**Missing at random (MAR)**
- The probability of missingness depend on values of other featues but not on the value of missing feature itself
**Not Missing at random (NMAR) or Missing Not at Random (MNAR)**
- The probability of missingness depends on the value of the variable itself

Statistical tests
- Test whether data points with a missing value differ from data points with an observed value
- If yes then are are not mcar


Good approach
- minimize bias
- maximize available info
- yields good estimates of uncertainty


Handling missing data:
- Remove rows with missing values
- Impute missing value
	- replace the missing value with the mean of that particular feature
	- maintains the sample size
	- correlation
- advanced imputation methods
	- use values of other features to predict the missing value


Imbalanced data
- oversample (re-sampling)
- Synthetic samples
	- SMOTE
		- synthetic images between points
	- Focal loss
		- Putting more weight on difficult samples


**Sanity check**
- do not blindly trust the numbers
- look at the data gg
- use baselines