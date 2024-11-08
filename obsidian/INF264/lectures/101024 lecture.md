# Unsupervised dimensionality reduction 

### types
- features selection
- feature extraction

### feature selection:
- filter methods:
	- consider relationship between individual features and the label
- Wrapper methods
	- Generate models with subsets of varables
- Embedded methods
- unsupervised
	- remove redundant features
	- remove features with low variance

## Linear dim reduction
- linear combinations of of features which makes new vectors


### Principal component analysis
- learn the most interesting direction (new basis functions)
	- interesting direction = variation 
- Represent data using these directions

- Derivation of PCA
	- Each data point x_i is
	- The mean of hte projected data is U_1x


Non linear dimensionality reduction
- t-SNE
- umap


#### Autoencoder
- reconstruction loss
- std feedforward netwrork