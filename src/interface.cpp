#include "kmeans.h"
#include <Rcpp.h>
#include <stdlib.h>
#include <iostream>


// [[Rcpp::export]]
Rcpp::IntegerVector kmeans_interface(
  Rcpp::IntegerVector K,
  Rcpp::NumericMatrix data_matrix // n_observations x n_features,
){

  int n_observations = data_matrix.nrow();
  int n_features = data_matrix.ncol();
  int clusters[n_observations];

  int status_code = kmeans(K[0], &data_matrix[0],
                           n_observations, n_features, clusters);

  if(status_code == K_TOO_LARGE) {
    Rcpp::stop("K should be less than or equal to the number of observations.");

  }

  else if(status_code == NULL_DATA_MAT) {
    Rcpp::stop("The data matrix should have data in it.");

  }

  Rcpp::IntegerVector outVec(n_observations);

  for(int i = 0; i < n_observations; i++) {
    outVec[i] = clusters[i];
  }




  return outVec;


}
