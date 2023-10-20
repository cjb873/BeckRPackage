#include "kmeans.h"
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

void initializeMatrix(matrix *matrix, const int nRow, const int nCol, const double* data) {

  matrix->nRow = nRow;
  matrix->nCol = nCol;

  for(int row = 0; row < nRow; row++) {
    for(int col = 0; col < nCol; col++) {

      matrix->matrix[row][col] = data[row+col];
    }
  }

}

vector<double> getAbsDiffVec(const vector<double> one, const vector<double> two) {

  vector<double> returnVec(one.size());

  for(int index = 0; index < one.size(); index++) {
    returnVec[index] = fabs(one[index] - two[index]);
  }

  return returnVec;
}

double getDotProduct(const vector<double> one, const vector<double> two) {

  double sum = 0;

  for(int index = 0; index < one.size(); index++) {
    sum += one[index] * two[index];
  }

  return sum;

}

bool alreadySelected(const int randAssn[], const int val, const int selIndex) {

  for(int index = 0; index < selIndex; index++) {

    if(val == randAssn[index]) return true;
  }
  return false;

}

double calcDistance(const vector<double> one, const vector<double> two) {

  vector<double> diffVec = getAbsDiffVec(one, two);
  return getDotProduct(diffVec, diffVec);

  }

void setRow(matrix *one, const vector<double> rowVec, const int row) {

  for(int col = 0; col < one->matrix[row].size(); col++) {
    one->matrix[row][col] = rowVec[col];
  }
}

void addRows(matrix *one, const matrix *two, const int row) {

  for(int col = 0; col < one->matrix[row].size(); col++) {
    one->matrix[row][col] += two->matrix[row][col];
  }
}

void setZero(matrix *matrix, const int row) {
  for(int col = 0; col < matrix->matrix[row].size(); col++) {
    matrix->matrix[row][col] = 0;
  }
}

void divideRow(matrix *matrix, const vector<int> counts, const int row){
  for(int col = 0; col < matrix->matrix[row].size(); col++) {
    matrix->matrix[row][col] /= counts[col];
  }
}

int findMinimum(const vector<double> inVec) {
  int minIndex = 0;

  for(int index = 0; index < inVec.size(); index++) {
    if(inVec[index] < inVec[minIndex]) minIndex = index;
  }

  return minIndex;
}

int kmeans(
  const int K,
  double *inData, // n_observations x n_features,
  const int nObservations,
  const int nFeatures,
  int *clusterAssignments // n_observations
) {

  if(K > nObservations) return K_TOO_LARGE;
  else if(inData == NULL) return NULL_DATA_MAT;

  matrix dataMatrix;

  matrix clusterCenters;

  initializeMatrix(&dataMatrix, nObservations, nFeatures, inData);

  double zeros[K * nFeatures];

  for(int index = 0; index < K * nFeatures; index++) {
    zeros[index] = 0;
  }

  initializeMatrix(&clusterCenters, K, nFeatures, zeros);


  // initialize cluster centers
  srand(time(NULL));
  int randAssn[K];


  for(int index = 0; index < K; index++) {

    int val = rand() % nObservations;

    while(alreadySelected(randAssn, val, index)) {
      val = rand() % nObservations;
    }

    randAssn[index] = val;


    setRow(&clusterCenters, dataMatrix.matrix[randAssn[index]], index);
  }

  // make assignments and recompute means
  int changes = 1;
  while(changes > 0) {
    changes = 0;
    // make assignments
    for(int row = 0; row < nObservations; row++) {

      vector<double> distances(K);

      for(int col = 0; col < K; col++) {
        distances[col] = calcDistance(dataMatrix.matrix[row], clusterCenters.matrix[row]);
      }

      int minIndex = findMinimum(distances);

      int formerAssignment = clusterAssignments[row];
      clusterAssignments[row] = minIndex;

      if(formerAssignment != minIndex) {
        changes++;
      }
    }



    // recompute means
    for(int row = 0; row < K; row++) {
      setZero(&clusterCenters, row);

    }

    vector<int> clusterCounts(K, 0);

    for(int row = 0; row < nObservations; row++) {
      int cluster = clusterAssignments[row];
      addRows(&clusterCenters, &dataMatrix, row);
      clusterCounts[cluster] += 1;

    }

    for(int row = 0; row < K; row++) {
      divideRow(&clusterCenters, clusterCounts, row);
    }
  }
  return 0;
}
