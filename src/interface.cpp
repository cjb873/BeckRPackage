#include "dynprog.h"
#include "kmeans.h"
#include <stdlib.h>
#include <iostream>
#include <Rcpp.h>
#include <RcppEigen.h>



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

// [[Rcpp::depends(RcppEigen)]]
// [[Rcpp::export]]
Eigen::MatrixXd dynprog_interface(
  Rcpp::IntegerVector K,
  Eigen::VectorXd data_vec // n observations
){

  int n_observations = data_vec.size();
  Eigen::MatrixXd outMat(K[0], n_observations);

  int status_code = dynprog(K[0], &data_vec, n_observations, &outMat);

  if(status_code == DATA_TOO_SMALL) {
    Rcpp::stop("K should be less than or equal to the number of observations.");

  }

  else if(status_code == NULL_DATA_VEC) {
    Rcpp::stop("The data vector should have data in it.");

  }
  return outMat;
}
