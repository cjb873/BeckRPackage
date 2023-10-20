#include "kmeans.h"
#include <eigen3/Eigen/Dense>
#include <stdlib.h>
#include <time.h>
#include <iostream>


bool already_selected(int randAssn[], int val, int i){

  for(int j = 0; j < i; j++) {

    if(val == randAssn[j]) return true;
  }
  return false;

}

double calc_distance(Eigen::VectorXd one, Eigen::VectorXd two)
  {

  Eigen::VectorXd diff_vec = one - two;
  diff_vec = diff_vec.cwiseAbs();
  return diff_vec.dot(diff_vec);

  }

int kmeans(
  const int K,
  double *in_data, // n_observations x n_features,
  const int n_observations,
  const int n_features,
  int *cluster_assignments // n_observations
) {

  if(K > n_features) return K_TOO_LARGE;
  else if(in_data == NULL) return NULL_DATA_MAT;


  Eigen::Map<Eigen::MatrixXd> data_matrix(in_data, n_observations, n_features);
  Eigen::MatrixXd cluster_centers(K, n_features);

  // initialize cluster centers
  srand(time(NULL));
  int randAssn[K];


  for(int i = 0; i < K; i++) {

    int val = rand() % n_observations;

    while(already_selected(randAssn, val, i)) {
      val = rand() % n_observations;
    }

    randAssn[i] = val;

    cluster_centers.row(i) = data_matrix.row(randAssn[i]);
  }

  // make assignments and recompute means
  int changes = 1;
  while(changes > 0) {
    changes = 0;
    // make assignments
    for(int i = 0; i < n_observations; i++) {

      Eigen::VectorXd distances(K);

      for(int j = 0; j < K; j++) {
        distances[j] = calc_distance(data_matrix.row(i), cluster_centers.row(j));
      }

      int min_index;
      distances.minCoeff(&min_index);
      int former_assignment = cluster_assignments[i];
      cluster_assignments[i] = min_index;

      if(former_assignment != min_index) {
        changes++;
      }
    }



    // recompute means
    for(int i = 0; i < K; i++) {
      cluster_centers.row(i).setZero();

    }

    Eigen::VectorXd cluster_counts(K);

    for(int i = 0; i < n_observations; i++) {
      int cluster = cluster_assignments[i];
      cluster_centers.row(cluster) += data_matrix.row(i);
      cluster_counts[cluster] += 1;

    }

    for(int i = 0; i < K; i++) {
       cluster_centers.row(i) = cluster_centers.row(i) / cluster_counts[i];
    }
  }
  return 0;
}
