\name{kmeans_interface}
\alias{kmeans_interface}
\title{Kmeans}
\description{
  Run the kmeans algorithm as implemented in C++ with the function
  \code{kmeans_interface}.
}


\usage{
kmeans_interface(n.clusters, data.matrix)
}

\arguments{
  \item{n.clusters}{an integer specifying how many clusters the kmeans algorithm
    should find.}
  \item{data.matrix}{an N x P matrix, where N is the number of observations and
    P is the number of features.}
}

\examples{
# create data matrix from the petal length and width values of the iris data set
data.mat <- as.matrix(iris[3:4])

# save the number of clusters
n.clusters <- 4

# run kmeans 
kmeans <- kmeans_interface(n.clusters, data.mat)
}
\keyword{data.matrix}
