**Convolutional nn**
- CNNs are commonly used with image data

**Convoutional layer**
- preserve spatial structure
- a filter which ends up in an activation map

**Properties of convolutional layers**
- sparse connectivity
- units are indirectly connected 
 ![[Pasted image 20240926143440.png]]

**Pooling**
![[Pasted image 20240926144726.png]]
getting rid of redundant information. In the example we are picking the maximum activation in larger portions of the image.

**Image classification**
- backbone
	- ReLu
	- Convolutions
- classifier head
	- 

**Deep learning for natural language processing**
- Word embeddings
- Word2Vec
- Breaking down words to sub-categories

**Recurrent neural networks**
- Traditional assumption: All inputs are independent
- Store a state of previous input and combine it with current input


**Autoregressive models**
- P(machine learning is fun) = P(machine) $\cdot$ P(learning|machine)....

**Attention**
- Mechanism that allows the network to focus on specific parts of information while ignoring others
**Transformers**
- A neual network architercutre that uses the attention mechanism

**Encoder**
- Reads the input 
- Processes the input, creates a representation("understanding") 

**Decoder**
- Reads the representation
- Produces the output


**Generative adversial networks ( GANs )**
- Train two neural networks that compete with each other
	- **Generator** treis to produce data that cannot be distinguished from real data
	- **Discriminator** treis to predict whether data is real or comes from the generator

**Diffusion**
- magic

**Optimization**
- Optimization surface can be very complex with lots of local minima, saddle points and plateaus
- There exists serveral types of "tweaks"  to the SGD
	- Momentum
		- parameter update depends on the current gradient and the sum of previous gradient
	- Adaptive learning rates
		- adjust learning rate during training
		- AdaGrad, RMSProp, Adam


**Regularization**
- Deep neural networkds are extremly powerful representation
	- complex, can overfit
- parameter norm reguralization
	- add peneltaty term
- data set augmentation
	- rotate, light, zoom on a image f.ex
	- To avoid overfitting
	- create transformed or noisy data from training data


**Regularization in deep learning (cont.)**
- Early stopping
	- return the param values that resulted in lowest val err

- Dropout
	- For each minibatch, randomly ignore part of the input and hidden units
	- approx with bagged ensemble
