#include "linEquation.hpp"


std::vector<std::vector<double>> randMatGen(int matDimRandParam, int matValRandParam, bool isSquareMatrix, int rowN, int columnM)
{
    if (rowN == 0)
        rowN = randomUniform(1, matDimRandParam);
    if (isSquareMatrix)
        columnM = rowN;
    else if (columnM ==0) 
        columnM = randomUniform(1, matDimRandParam);

    std::vector<std::vector<double>> tempMatrix(rowN, std::vector<double>(columnM));
    for (auto& row : tempMatrix)
    {
        for(auto& val : row)
        {
            val = randomUniform(-matValRandParam, matValRandParam);
        }
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
    std::vector<double> tempVector(final.transformation.size());
    for (auto& val : tempVector)
    {
        val = randomUniform(-imageValRandParam, imageValRandParam);
    }

    final.image = tempVector;
    return final;
}

// Generate random Preimage and Matrix, unknown image
equation randEqGen(std::vector<double> preimage, int matDimRandParam, int matValRandParam)
{
    int rowN = randomUniform(1, matDimRandParam);

    int columnM = size(preimage);
    std::vector<std::vector<double>> tempMatrix(rowN, std::vector<double>(columnM));
     for (auto& row : tempMatrix)
    {
        for(auto& val : row)
        {
             val = randomUniform(-matValRandParam, matValRandParam);
        }
    }

    std::vector<double> res(rowN);
    int h = 0;
    for(auto& row : tempMatrix)
    {
        double dot = 0;
        for(int i = 0; i < columnM; i++)
        {
            dot += row[i] * preimage[i];
        }
        res[h] = dot;
        h++;
    }

    equation final;
    final.transformation = tempMatrix;
    final.image = res;
    return final;
}



