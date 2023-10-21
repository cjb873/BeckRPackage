#include <stdbool.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef enum {
  NULL_DATA_MAT = 1,
  K_TOO_LARGE,
} ErrorCodes;

typedef struct matrixStruct {
  int nCol;
  int nRow;
  vector<vector<double>> matrix;
  } matrix;


void initializeMatrix(vector<vector<double>> *matrix, const int nRow, const int nCol, const double* data);
vector<double> getAbsDiffVec(const vector<double> one, const vector<double> two);
double getDotProduct(const vector<double> one, const vector<double> two);
bool alreadySelected(const int randAssn[], const int val, const int selIndex);
double calcDistance(const vector<double> one, const vector<double> two);
void setRow(vector<double> *row, const vector<double> inVec);
vector<double> addRows(vector<double> one, const vector<double> two);
void setZero(vector<double> *row);
void divideRow(vector<double> *row, const int count);
int findMinimum(const vector<double> inVec);
bool already_selected(int randAssn[], int val, int i);

int kmeans(
  const int K,
  double *inData, // n_observations x n_features,
  const int nObservations,
  const int nFeatures,
  int *clusterAssignments // n_observations
);




