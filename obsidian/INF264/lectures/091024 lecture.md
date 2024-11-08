# Clustering

*Identifying groups of data, finding the structure of the data*

**Preprocessing**:
- feature engineering
- quantization (lossy compression)

**Characterizing clusters**
- Centroid models
- Distribution models
- Connectivity models
- Density models


**Hard Clustering**
$D_1 U D_K = D$ 
$D_i \land D_j, j \not =i$  

**K-means**
- Centroid
- Lloyd's algorithm:
	- Pick initial cluster centroids
	- repeat until nothing changes
		- assign each data point to a cluster whose centroid is closest to that point
		- update the centroid: The new centroid of cluster is the mean of the data points assigned to that cluster


Choosing k
- Results of k-means clustering crucially depend on the parameter k



**Silhouette coefficient**
basically your own cluster compared how close it is to other clusters


**Gaussian mixture models**
- Guassian mixture models with k components has density
-$p(x) = \sum_{j=1}^k\pi_jN(x|\mu_j \sum_j)$ 

**Expectation-maximization**
- Find $\mu_j, \pi_j$ and $\sigma_j$ 
- Expectation find the distribution that best fit the cluster assignment $\pi_j^{somehting}$ 
- 


**Hierarchical clustering**
- Produces nested clusters organized in a hierarchy tree
- Convenient
	- no need to decide the number of clusters
	- inizalization not needed
- Challange:
	- linkage

- Types
	- Agglomerative:
		- bottom up:
		- merging them
	- Divisive:
		- Top-down
		- Splitting them


LInkage function
- Single likange
	- Distance between nearest neighboors
	- encourages growth of elongated
- complete
	- distance between farthest neighboors
	- compact cluster
- avarage
	- avarage between all pairs
	- compromise

Observations
- In contrast to k-means, standard hierarchial clustering does not have natural cost function that is optimized
- To get a "flat" clustering, one can cut the hiercarchy tree at an appropriate level



**Density-based clustering**
- Group together points that are closely packed together, and mark points in low density regions as outliers.
- DBSCAN
	- distance threshold, and minpoints
	- makes a point a cluster if it has the required minpoints inside its threshold
	- other datapoints are marked as ouliers
- Doesn't need to specify the number of clusters beforehand
- Weaknesses, not entirely deterministic
- Mostly stochastic