#include "dynprog.h"

double get_cost(int start, int end, Eigen::VectorXd cumSquareVec, Eigen::VectorXd cumDataVec) {

    int size = end - start + 1;
    double squareTerm = cumSquareVec[end+1] - cumSquareVec[start];
    double dataTerm = cumDataVec[end+1] - cumDataVec[start];

    return squareTerm - (dataTerm * dataTerm) / size;
}

Eigen::VectorXd cumsum(Eigen::VectorXd inData, const int nObservations) {

    Eigen::VectorXd returnVec(nObservations+1);
    returnVec.setZero();

    returnVec[0] = 0;

    for(int i = 1; i <= nObservations; i++)
        returnVec[i] = inData(Eigen::seq(0, i-1)).sum();

    return returnVec;

}

int whichMin(Eigen::VectorXd inData) {

    int returnVal = 0;
    int size = inData.size();

    for(int i = 1; i < size; i++) {

        if(inData[i] < inData[returnVal])
            returnVal = i;
    }
    return returnVal;

}

Eigen::VectorXd square(Eigen::VectorXd inData) {

    int size = inData.size();

    Eigen::VectorXd squared(size);

    for(int i = 0; i < size; i++)
        squared[i] = inData[i] * inData[i];

    return squared;
}

Eigen::VectorXd slice(Eigen::VectorXd inData, int start, int end) {


    if(start == end) {
        Eigen::VectorXd returnVec(1);
        returnVec[0] = inData[start];

        return returnVec;
    }

    int size = end - start;
    Eigen::VectorXd returnVec(size);

    for(int i = 0; i < size; i++) {
        returnVec[i] = inData[i+start];
    }

    return returnVec;
}

int dynprog(const int K,
            const Eigen::VectorXd *inData, // n observations
            const int nObservations,
            Eigen::MatrixXd *outMatrix // K x n observations
            ) {

    if(K > nObservations) return DATA_TOO_SMALL;
    else if(inData == NULL) return NULL_DATA_VEC;

    Eigen::MatrixXd costMatrix(K, nObservations);
    Eigen::VectorXd meanVec(K);
    Eigen::VectorXd dataVec = *inData;
    Eigen::VectorXd cumDataVec = cumsum(dataVec, nObservations);
    Eigen::VectorXd cumSquareVec = cumsum(square(dataVec), nObservations);

    costMatrix.setZero();

    int firstDataFirstSeg = 0;

    for(int i = 0; i < nObservations; i++) {
        costMatrix(firstDataFirstSeg, i) = get_cost(firstDataFirstSeg, i, cumSquareVec, cumDataVec);

    }


    for(int seg = 1; seg < K; seg++) {
        for(int t = seg; t < nObservations; t++) {
            Eigen::VectorXd tPrimeVec(t);
            tPrimeVec.setZero();
            for(int tPrime = seg; tPrime < t-1; tPrime++) {
                tPrimeVec[tPrime] = costMatrix(seg-1, tPrime) + get_cost(tPrime + 1, t, cumSquareVec, cumDataVec);
            }

            if(seg == t) {
                costMatrix(seg, t) = 0;
            }
            else {
                Eigen::VectorXd sliceOne = slice(tPrimeVec, seg, t-1);

                int tStar = whichMin(sliceOne);

                costMatrix(seg, t) = sliceOne[tStar];
            }
        }
    }


    *outMatrix = costMatrix;

    return 0;
}
