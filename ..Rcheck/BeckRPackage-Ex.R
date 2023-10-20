pkgname <- "BeckRPackage"
source(file.path(R.home("share"), "R", "examples-header.R"))
options(warn = 1)
library('BeckRPackage')

base::assign(".oldSearch", base::search(), pos = 'CheckExEnv')
base::assign(".old_wd", base::getwd(), pos = 'CheckExEnv')
cleanEx()
nameEx("HCLUST")
### * HCLUST

flush(stderr()); flush(stdout())

### Name: HCLUST
### Title: HCLUST
### Aliases: HCLUST

### ** Examples

# get the data from the iris dataset as a matrix
data.mat <- as.matrix(iris[3:4])

# save the number of clusters
n.clusters <- 3

# run the algorithm on the first 20 data points
hclust <- HCLUST(data.mat[1:20,], n.clusters)



cleanEx()
nameEx("kmeans_interface")
### * kmeans_interface

flush(stderr()); flush(stdout())

### Name: kmeans_interface
### Title: Kmeans
### Aliases: kmeans_interface
### Keywords: data.matrix

### ** Examples

# create data matrix from the petal length and width values of the iris data set
data.mat <- as.matrix(iris[3:4])

# save the number of clusters
n.clusters <- 4

# run kmeans 
kmeans <- kmeans_interface(n.clusters, data.mat)



### * <FOOTER>
###
cleanEx()
options(digits = 7L)
base::cat("Time elapsed: ", proc.time() - base::get("ptime", pos = 'CheckExEnv'),"\n")
grDevices::dev.off()
###
### Local variables: ***
### mode: outline-minor ***
### outline-regexp: "\\(> \\)?### [*]+" ***
### End: ***
quit('no')
