#include <stdbool.h>
#include <stdlib.h>
#include <Eigen/Dense>

typedef enum {
  NULL_DATA_VEC = 1,
  DATA_TOO_SMALL,
} DynprogErrorCodes;

double get_cost(int start, int end, Eigen::VectorXd cumSquareVec, Eigen::VectorXd cumDataVec);
Eigen::VectorXd cumsum(Eigen::VectorXd inData, const int nObservations);
int whichMin(Eigen::VectorXd inData);
int dynprog(const int K,
            const Eigen::VectorXd *inData, // n observations
            const int nObservations,
            Eigen::MatrixXd *outMatrix // K x n observations
            );
Eigen::VectorXd square(Eigen::VectorXd inData);
Eigen::VectorXd slice(Eigen::VectorXd inData, int start, int end);
