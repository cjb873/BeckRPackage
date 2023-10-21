#include "kmeans.h"
#include <vector>
#include <math.h>
#include <time.h>
#include <iostream>
using namespace std;

void initializeMatrix(vector<vector <double>> *matrix, const int nRow, const int nCol, const double* data) {
  double tempData[nRow * nCol];

  for(int index = 0; index < nRow * nCol; index++) {
    if(index % 2 == 0) {
      tempData[index] = data[index / 2];
    }
    else {
      tempData[index] = data[(index - 1) / 2 + nRow];
    }
  }
  for(int row = 0; row < nRow; row++) {
    vector<double> v;
    for(int col = 0; col < nCol; col++) {
      v.push_back(tempData[(row * nCol)+col]);
    }
    matrix->push_back(v);
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
    sum += (one[index] * one[index]);
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

void setRow(vector<double> *row, const vector<double> inVec) {

  for(int col = 0; col < (*row).size(); col++) {
    (*row)[col] = inVec[col];
  }
}

vector<double> addRows(vector<double> one, vector<double> two) {
  vector<double> returnVec(one.size());

  for(int col = 0; col < one.size(); col++) {
    returnVec[col] = one[col] + two[col];
  }
  return returnVec;
}

void setZero(vector<double> *row) {
  for(int col = 0; col < (*row).size(); col++) {
    (*row)[col] = 0;
  }
}

void divideRow(vector<double> *row, const int count){
  for(int col = 0; col < (*row).size(); col++) {
    (*row)[col] = (*row)[col] / count;
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

  cout << endl;
  vector<vector<double>> dataMatrix;

  vector<vector<double>> clusterCenters;

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


    setRow(&clusterCenters[index], dataMatrix[randAssn[index]]);
  }


  // make assignments and recompute means
  int changes = 1;
  while(changes > 0) {

    changes = 0;
    // make assignments
    for(int row = 0; row < nObservations; row++) {

      vector<double> distances(K);

      for(int cluster = 0; cluster < K; cluster++) {
        distances[cluster] = calcDistance(dataMatrix[row], clusterCenters[cluster]);
      }

      int minIndex = findMinimum(distances);

      int formerAssignment = clusterAssignments[row];
      clusterAssignments[row] = minIndex;

      if(formerAssignment != minIndex) {
        changes++;
      }
    }

    vector<int> clusterCounts(K);

    // recompute means
    for(int row = 0; row < K; row++) {
      setZero(&clusterCenters[row]);
      clusterCounts[row] = 0;
    }




    for(int row = 0; row < nObservations; row++) {
      int cluster = clusterAssignments[row];

      clusterCenters[cluster] = addRows(clusterCenters[cluster], dataMatrix[row]);
      clusterCounts[cluster] += 1;

    }



    for(int row = 0; row < K; row++) {
      divideRow(&clusterCenters[row], clusterCounts[row]);
    }


  }
  return 0;
}
