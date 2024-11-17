## Architectures in Deep Learning

- Components:
    - Units (Neurons)
    - Layers
    - Activation functions
    - Learning:
        - Loss functions
        - Backpropagation
        - Gradient descent
- **Advanced Architectures**:
    - Fully connected networks.
    - Convolutional networks:
        - Filters for data like images, audio.
        - Filters learn patterns (e.g., edges, textures).
    - Sequence networks:
        - Embeddings for categorical data.
        - Recurrent networks (RNNs).
    - Attention-based networks.
    - Diffusion models.

## Convolutional Networks

- **Filters**:
    - 1D filters for sequential data: $v_i = \sum_{j} w_j x_{i+j}$
    - 2D filters for images:
        - Defined by a rectangular (often square) size.
        - Output forms new layers (channels).
        - $C \cdot N \cdot M + 1$ parameters per filter.
- **Pooling**:
    - Reduces size by aggregating values.
    - Types: max-pooling, average-pooling.
- **Output layers**:
    - Flattened for dense layers.

## Embeddings

- **Purpose**:
    - Represent categorical data in an $n$-dimensional space.
    - Related items are closer together in the space.
- **Training**:
    - CBOW (Continuous Bag of Words): Predict target word from context.
        - Example: $\text{Input} = [\text{`to''}, \text{`learn''}, \text{`AI''}], \text{Target} = \text{`philosophy''}$
    - Skip-gram: Predict context words from the target.

## Recurrent Networks (RNNs)

- Models sequential data.
- Includes weights:
    - $u$: input to hidden.
    - $v$: hidden to output.
    - $w$: hidden to hidden.
- Can predict:
    - Text.
    - Time series (e.g., traffic, stocks).
- **LSTMs**:
    - Long-term dependencies with states.
    - Functions:
        - Forget ($f$), Remember ($r$), Direction ($w$), Output ($s+o$).

## Attention Mechanisms

- Self-attention:
    - Example: In "the bank is on the river bank," "bank" is influenced by context.
- **Transformer Encoder-Decoder**:
    - Maps inputs to outputs using positional encoding and attention matrices.
    - Outputs a modified representation.

## Diffusion Networks

- Generate noisy versions of data, e.g., images.
- Train models to reverse noise.