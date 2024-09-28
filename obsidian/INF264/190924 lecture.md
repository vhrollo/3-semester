**Logistic classification**



**Support Vector Machine**
*margin*, the distance betweeen parallel hyperplanes $X^T x + b = -1$ and $X^T x + b = 1$ 

**Hyperplane**
In an N-dimensional space( where N is the number of features), a hyperplane is a flat affine subspace of dimension N-1, in a 2D space, it is a line, in a 3D space it is a plane

Margin: The distsance between the hyperplane and the closest points (support vectors) of each class. SVM maximizes the margin
$w = w - \alpha \left( 2 \lambda w + y_ix_i \right)$
$b = b - \alpha y_i$

Hyperplane
$w_1x_1 + \ldots + w_p x_p - b = 0$

Point on the boundry:
$\vec{w}^T \vec{x} - b = 0$ 

Stepping along the normal along the hyperplane we want to hit the first class label 1 to find  out how long half of the marign is

$\vec{w}^T (\vec{x}+k \frac{\vec{w}}{||w||}) - b = 1$

This is the same as:
$k \frac{\vec{w}\cdot \vec{w}}{||w||} = 1$

which means that k must be
$k = \frac{1}{||w||}$

then the margin must be:
$k = \frac{2}{||w||}$
So to maximize the margin, we minimize length of w

This will lead to:
$y_i = 1 \Rightarrow X^T x + b \geq 1$ 
$y_i = -1 \Rightarrow X^T x + b \geq -1$ 

or shortened
$y_i (\vec{w}\vec{x_i}-b)\geq 1$

A loss function for this can be defined as a Hinge loss
$\mathcal{L} = max(0, 1=y_i ( w*x_i - b))$ 
which means if it goes the wrong way, it will be positive
and if it is under 1 it will b, and if it goes positive it will be negative, which means 0 is bigger

This basically means:
$$
l = 
\begin{cases} 
0 & \text{if } y \cdot f(x) \geq 1 \\
1 - y \cdot f(x) & \text{otherwise} 
\end{cases}
$$
which then can be derivated for b w or whatever function f(x) one is using partial derivation to find how it should move about:

And then we can add regularization on top of this: ( in this case Ridge regularization)
$$
J = \lambda ||w||^2 + \frac{1}{n} \sum_{i=1}^{n} \max(0, 1 - y_i (w \cdot x_i - b))
$$

if $( y_i \cdot f(x) \geq 1 )$:
$$
J_i = \lambda ||w||^2
$$

else:
$$
J_i = \lambda ||w||^2 + 1 - y_i (w \cdot x_i - b)
$$


Cover's theorem s