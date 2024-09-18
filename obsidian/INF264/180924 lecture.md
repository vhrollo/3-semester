

### Multivariate linear regression



**Loss functions**

MSE
- Computationally convenient
- sensitive to outliers

MSA
- Complex computations become more complex


### Non - linearities
- Heteroskedastic
- linear models are unable to capture complex non-linear relations

- Mapping a polinomial in a linear models $f(x) = w^T\phi (x)$
- where $\phi (x): R^d \rightarrow R^{d'}$

Basis functions
- input $(x_1, x_2) ->_{\phi} \text{transformed}(z_1, z_2, z_3)$
- 
Radial basis functions

Feature engineering
- Use domain knowledge to construct transformations of the original features
- Can be achived by basis functions

## Bias-variance tradeoff



## Simple vs complex models
- Simple models cannot predict complex phenomena eccurately
- Complex models can predict complex phenomena but they require lots of training data
- the more training data -> more complex model

### Regularization
- Rgression with L2-regularizer is called ridge regression

- $||(y-w^TX^T)||^2_2 + ||\lambda||^2_2$ 
- 