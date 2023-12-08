\name{BINSEG}                                                                                            
\alias{BINSEG}                                                                                           
\title{BINSEG}                                                                                                     
\description{                                                                                                      
  Run the binary segmentation algorithm as implemented in R with the function                   
  \code{BINSEG}.                                                                                         
}                                                                                                                  
                                                                                                                   
                                                                                                                   
\usage{                                                                                                            
BINSEG(K, data.vec)                                                                                     
}                                                                                                                  
                                                                                                                   
\arguments{                                                                                                        
  \item{K}{an integer specifying how many changepoints the algorithm               
    should find.}                                                                                                  
  \item{data.vec}{a numeric vector of N datapoints.}                                                                
}                                                                                                                  
                                                                                                                   
\examples{                                                                                                         
# Select data                                              
data.vec <- as.matrix(iris[3])[,1]                                                   
                                                                                   
# Pull in the package                                                              
require("BeckRPackage")                                                            
                                                                                   
# Run the code                                                                     
BINSEG(5, data.vec)                                                                                      
}                                                                                                                  
\keyword{data.vec}                                                                                                 
