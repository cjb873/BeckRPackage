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
# Pull in data table                                                               
library(data.table)                                                                
                                                                                   
# Get the data                                                                     
data(neuroblastoma, package="neuroblastoma")                                       
                                                                                   
# Store as a data table                                                            
nb.dt <- data.table(neuroblastoma$profiles)                                        
                                                                                   
# Select a single profile                                                          
one.profile <- nb.dt[profile.id == 4 & chromosome == "2"]                          
                                                                                   
# Select one series of logratio values                                             
data.vec <- one.profile$logratio                                                   
                                                                                   
# Pull in the package                                                              
require("BeckRPackage")                                                            
                                                                                   
# Run the code                                                                     
BINSEG(5, data.vec)                                                                                      
}                                                                                                                  
\keyword{data.vec}                                                                                                 
