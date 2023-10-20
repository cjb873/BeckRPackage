\name{HCLUST}
\alias{HCLUST}
\title{HCLUST}
\description{
  Use hierarchical clustering to create clusters for a given data set and 
  number of clusters.
}

\usage{
  HCLUST(data.mat, n.clusters)
}

\arguments{
  \item{data.mat}{An N x P matrix where N corresponds to the number of observations
    and P is the number of features.}
  \item{n.clusters}{The number of clusters the \code{HCLUST} function should find.}
}

\examples{
# get the data from the iris dataset as a matrix
data.mat <- as.matrix(iris[3:4])

# save the number of clusters
n.clusters <- 3

# run the algorithm on the first 20 data points
hclust <- HCLUST(data.mat[1:20,], n.clusters)
}
