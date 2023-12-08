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
dynprog_interface(5, data.vec)                                                                                      
}                                                                                                              
\keyword{data_vec}                                                                                          
