#include <stdbool.h>
#include <stdlib.h>


typedef enum {
  NULL_DATA_MAT = 1,
  K_TOO_LARGE,
} ErrorCodes;


int kmeans(
  const int K,
  double *in_data, // n_observations x n_features,
  const int n_observations,
  const int n_features,
  int *cluster_assignments // n_observations
);

bool already_selected(int randAssn[], int val, int i);
