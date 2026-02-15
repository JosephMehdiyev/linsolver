#include "linEquation.hpp"


Mat<double> randMatGen(int matDimRandParam, int matValRandParam, bool isSquareMatrix, int rowN, int columnM)
{
    if (rowN == 0)
        rowN = randomUniform(1, matDimRandParam);
    if (isSquareMatrix)
        columnM = rowN;
    else if (columnM ==0) 
        columnM = randomUniform(1, matDimRandParam);

    Mat<double> tempMatrix(rowN, columnM);
    for(auto& val : tempMatrix.data)
        {
            val = randomUniform(-matValRandParam, matValRandParam);
        }
    return tempMatrix;
}

std::vector<double> randVecGen(int vecDim, int vecValRandParam)
{
    int rowN = vecDim;
    int columnM = 1;
    std::vector<double> vec(rowN);
    for(auto& val : vec)
    {
        val = randomUniform(-vecValRandParam, vecValRandParam);
    }
    return vec;
}

// Generate Random Matrix and Image, Unknown preimage
equation randEqGen(int matDimRandParam , int matValRandParam, int imageValRandParam)
{
    equation final;
    final.transformation = randMatGen(matDimRandParam, matValRandParam, 0);
    std::vector<double> tempVector(final.transformation.rows);
    for (auto& val : tempVector)
    {
        val = randomUniform(-imageValRandParam, imageValRandParam);
    }

    final.image = tempVector;
    return final;
}



