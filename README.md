# BeckRPackage

<!-- badges: start -->
[![R-CMD-check](https://github.com/cjb873/BeckRPackage/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/cjb873/BeckRPackage/actions/workflows/R-CMD-check.yaml)
<!-- badges: end -->


This package implements four R functions, `kmeans_interface`, `dynprog_interface`, `BINSEG`, and `HCLUST`. The functions `kmeans_interface` and `dynprog_interface` are written in C++ and then called using the `Rcpp` package. 
The functions `HCLUST` and `BINSEG` are written natively in R.

### Dependencies
To ensure that this package will correctly build, you will need to install the [Rcpp](https://www.rcpp.org/) package in R.

### Building
To build the library, run the command `R CMD INSTALL <path_to_package>`.

### Testing
To run the tests, run the command `R CMD check <path_to_package>`.

## Examples

### kmeans_interface
```
# create data matrix from the petal length and width values of the iris data set
data_matrix <- as.matrix(iris[3:4])

# save the number of clusters
K <- 4

# run kmeans 
kmeans <- kmeans_interface(K, data_matrix)
```

### dynprog_interface
```
# Select data 
data.vec <- as.matrix(iris[3])[,1]                                                 

# Pull in the package
require("BeckRPackage")                                                            

# Run the code
dynprog_interface(5, data.vec)
```

### HCLUST
```
# get the data from the iris dataset as a matrix
data.mat <- as.matrix(iris[3:4])

# save the number of clusters
n.clusters <- 3

# run the algorithm on the first 20 data points
hclust <- HCLUST(data.mat[1:20,], n.clusters)
```

### BINSEG
```
# Select data                                              
data.vec <- as.matrix(iris[3])[,1]                                                   
                                                                                   
# Pull in the package                                                              
require("BeckRPackage")                                                            
                                                                                   
# Run the code                                                                     
BINSEG(5, data.vec)
```




