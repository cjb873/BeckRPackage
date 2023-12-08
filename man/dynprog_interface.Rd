\name{dynprog_interface}                                                                                        
\alias{dynprog_interface}                                                                                       
\title{DYNPROG}                                                                                                 
\description{                                                                                                  
  Run the optimal segmentation via dynamic programming algorithm as implemented in C++ with the function               
  \code{dynprog_interface}.                                                                                     
}                                                                                                              
                                                                                                               
                                                                                                               
\usage{                                                                                                        
dynprog_interface(K, data_vec)                                                                               
}                                                                                                              
                                                                                                               
\arguments{                                                                                                    
  \item{K}{an integer specifying how many changepoints the algorithm         
    should find.}                                                                                              
  \item{data_vec}{a numeric vector of N datapoints.}                                                                              
}                                                                                                              
                                                                                                               
\examples{                                                                                                     
# Select data 
data.vec <- as.matrix(iris[3])[,1]                                                 

# Pull in the package
require("BeckRPackage")                                                            

# Run the code
dynprog_interface(5, data.vec)                                                                                      
}                                                                                                              
\keyword{data_vec}                                                                                          
