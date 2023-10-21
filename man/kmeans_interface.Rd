\name{kmeans_interface}
\alias{kmeans_interface}
\title{Kmeans}
\description{
  Run the kmeans algorithm as implemented in C++ with the function
  \code{kmeans_interface}.
}


\usage{
kmeans_interface(K, data_matrix)
}

\arguments{
  \item{K}{an integer specifying how many clusters the kmeans algorithm
    should find.}
  \item{data_matrix}{an N x P matrix, where N is the number of observations and
    P is the number of features.}
}

\examples{
# create data matrix from the petal length and width values of the iris data set
data_matrix <- as.matrix(iris[3:4])

# save the number of clusters
K <- 4

# run kmeans 
kmeans <- kmeans_interface(K, data_matrix)
}
\keyword{data_matrix}
