## Neural Unit

- **Basic Unit**: Artificial neuron.
- Equation: $f(X) = w_0 + \sum_{i=1}^n w_i x_i$
- Activation function:
    - Logistic: $f(x) = \frac{1}{1 + e^{-x}}$
    - Sigmoid: $\sigma(x) = \frac{e^x}{1 + e^x}$
    - $\tanh$: $\tanh(x)$
    - ReLU: $\text{ReLU}(x) = \max(0, x)$
    - Softplus: $\text{Softplus}(x) = \log(1 + e^x)$

## Gradient Descent

- **Purpose**: Minimize loss by optimizing weights.
- Gradient definition: Direction of steepest descent.
- Formula for weight update: wi=wi−η⋅∂Loss∂wiw_i = w_i - \eta \cdot \frac{\partial \text{Loss}}{\partial w_i}wi​=wi​−η⋅∂wi​∂Loss​

## Backpropagation

- **Steps**:
    1. Compute loss: $\text{Loss} = \sum_{j} (v_j - y_j)^2$
    2. Compute gradients of loss with respect to weights: $\frac{\partial \text{Loss}}{\partial w_i}$.
    3. Propagate errors back through layers.

## Overfitting

- **Definition**: Model fits training data too well, performing poorly on new data.
- **Indicators**:
    - High training accuracy.
    - Low test accuracy.
- **Mitigation techniques**:
    - Cross-validation.
    - Regularization (e.g., weight regularization).
    - Dropouts.
    - Data augmentation.

## Example Architecture

- **Input features**: $n = 8$
- **Layer setup**:
    - Hidden Layer 1: $6$ neurons $\Rightarrow 6 \times (8+1)$ weights.
    - Hidden Layer 2: $8$ neurons $\Rightarrow 8 \times (6+1)$ weights.
    - Output Layer: $5$ neurons $\Rightarrow 5 \times (8+1)$ weights.
- **Total Weights**: $155$

## Training Techniques

- **Optimization Algorithms**:
    - Momentum: Adjust step length based on previous steps.
    - RMSProp: Scaled updates for each weight.
    - Adam: Combines momentum and RMSProp.
- **Loss Functions**:
    - Quadratic loss: $\text{Loss} = \sum_j (v_j - y_j)^2$.
- **Regularization**:
    - L1, L2 norms.
- **Augmentation**: Improve generalization by modifying training data.