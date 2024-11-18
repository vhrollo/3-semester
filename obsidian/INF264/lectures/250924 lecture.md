## from linear to non-linear

extend linear models to represent non-linear functions, we can use non-linear transom $\phi(x)$ 
- use a very generic high-dimentional $\phi$
- carfeully choose $\phi$
- learn $\phi$. Now $y = f(x|\Theta, w) = \phi(x;\Theta)^Tw$. Transform $\phi$ is parametrized and we can use an optimization algorithm to find the parameter values

- $y = w^T x$
- $y=w^T \varphi(x)$ 
- $y = w^T \varphi(x,\Theta)$

**Representation learning**
- $y = w^T \varphi(x,\Theta)$
- deep..

**The Perceptron / Artificial neuron**
- multiply each input with corresponding weight
- Take a sum of these products and feed it into a (non-linear)

**Outputs from one layer are inputs for the next layer** 

**Notation**
- feedforward network specifies a mapping $y \approx f(x, \Theta)$
-  $x \in R^d$ input vector
- y can be one or multiple outputs
- $\Theta$ is weights
- feedforward:
	- $f(x) =f^{3}(f^{2}(f^{1}(x)))$


**Learning features**
-  $f(x) =f^{2}(f^{1}(x))$
- $h=f^1(x)$
- output function can be a $y=v^Th+c$
- hidden uni $h=g(W^Tx+b)$

output units
- linear units for continuous
- sigmoid fo rbinary output
- softmax units for multinomial outputs
	- $z = W^Th +b$
	- $p(y =j|x) = \frac{exp(z_i)}{\sum_jexp_j(z_j)}$
		- normalization
	- look more into

**Traditional activation**
- Sigmoid
- Tanh

**Modern**
- Relu
- Leaky relu
- Expo LU


**Architecture**
- Already a neural network with one hidden layer is a universal approximator
	- can approximate any arbitrary function with ish precision given it has enough neurons
- several hidden layers allows for composing complex features using simpler features from earlier layers

**Learning neural networks**
- Forward: performance inference
- backward: performs learning
- back-propagation
- stochastic gradient descent

**Gradient-based learning**
- Goal is to minimize training loss by selecting appropriate values for the weights
- Update weights using gradient decent: stochastic is doing it with an subset

**Back - propagation**
- Backward propagation of errors
- An efficient algorithm for computing the gradient
- Apply the chain rule repeatedly

- adversarial attack
	- one changes the label and then it backpropagets to see how it changes the input data

**Stochastic gradient**
- fast and unstable B-)
- approximating

**Minibatch stochastic gradient descent**
- stochastic gradient decent 
	- sample minibatch of m training examples
	- forward pass to compute loss
	- back-propagate to change weights
	- update weights
- minibatches
	- minibatch is a often a power of 2
	- small minibatch size regularizes ( 1 is usually too unstable)
- Epoch
	- one pass true the whole training data (n / m SGD steps)

**What is deep learning**
- many layers
- Universal Approximator theorem

Sigmoid prevents earlier layers to learn if gradient decent
- Vanishing gradients
- modern activators prevents vanishing gradient decent

