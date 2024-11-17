Here are the summarized notes in Obsidian format with inline and block LaTeX for proper formatting:

---

# Machine Learning (INFO180)

## What is Learning?
- **Definition**:
  - Agents improve tasks using experience.
- **Goals**:
  - Derive rules or hypotheses for predictions or decisions.
- **Types**:
  - **Supervised Learning**:
    - Training examples include classification or regression targets.
  - **Unsupervised Learning**:
    - Detect patterns and categories in data.
  - **Reinforcement Learning**:
    - Agents learn actions based on rewards and penalties.

## $k$-Nearest Neighbors ($k$-NN)
- **Steps**:
  1. Place training examples in an $n$-dimensional space.
  2. Compute distance between new example $X_{new}$ and existing examples.
  3. Classify $X_{new}$ based on majority class of $k$ nearest neighbors.
- **Distance**:
  $$ d(X_1, X_2) = \sqrt{\sum_{i=1}^n (x_{1,i} - x_{2,i})^2} $$
- **Adjustments**:
  - Normalize features to $[0, 1]$ using Min-Max scaling.

## Indicators and Encoding
- **Binary Variables**:
  - Represent as $\{0, 1\}$.
- **Categorical Variables**:
  - Use one-hot encoding:
    - Example: $\text{Color} = \{\text{Red}, \text{Green}, \text{Blue}\}$ becomes:
      $$ \text{Red} \rightarrow [1, 0, 0], \; \text{Green} \rightarrow [0, 1, 0], \; \text{Blue} \rightarrow [0, 0, 1] $$

## Hypothesis and Models
- **Hypothesis**:
  - Function mapping data to predictions.
  - Found by searching hypothesis space.
  - Example for regression:
    $$ \hat{Y}(e) = w_0 + \sum_{i=1}^n w_i X_i $$
- **Criteria**:
  - Simplicity and precision (Occam's razor).

## Supervised Learning Workflow
1. Preprocess data (e.g., normalize, encode).
2. Split into training and test sets.
3. Train model on training set.
4. Evaluate on test set.

## Linear and Logistic Regression
- **Linear Regression**:
  $$ \hat{Y}(e) = w_0 + \sum_{i=1}^n w_i X_i $$
  - Minimize squared error:
    $$ \text{Error} = \sum_e \left( Y(e) - \hat{Y}(e) \right)^2 $$
- **Logistic Regression**:
  $$ f(X) = \frac{1}{1 + e^{-z}}, \; z = w_0 + \sum_{i=1}^n w_i X_i $$
  - Predict $Y(X) = 1$ if $f(X) > 0.5$.

## Gradient Descent
- **Optimization**:
  - Update weights to minimize loss:
    $$ w_i = w_i - \eta \frac{\partial \text{Loss}}{\partial w_i} $$
  - Use total error over dataset:
    $$ \text{Total Error} = \eta \cdot \text{Sum of individual errors} $$

## Evaluation Metrics
- **Accuracy**:
  $$ \text{Accuracy} = \frac{\text{Correct predictions}}{\text{Total examples}} $$
- **Error**:
  - Absolute: $\sum |Y - \hat{Y}|$
  - Squared: $\sum (Y - \hat{Y})^2$
- **Precision and Recall**:
  - Precision: $\frac{\text{True Positives}}{\text{True Positives} + \text{False Positives}}$
  - Recall: $\frac{\text{True Positives}}{\text{True Positives} + \text{False Negatives}}$