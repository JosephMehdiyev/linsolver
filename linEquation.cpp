#include "linEquation.hpp"
#include <cstdlib>


equation randGenerator(int matrixSizeRandomnessParam , int matrixValueRandomnessParam, int imageValueRandomnessParam)
{
    srand(time(NULL));
    int rowN = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/matrixSizeRandomnessParam)) + 1;
    int columnM = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/matrixSizeRandomnessParam)) + 1;
    std::vector<std::vector<float>> tempMatrix(rowN, std::vector<float>(columnM));
    for (auto& row : tempMatrix)
    {
        for(auto& val : row)
        {
            val = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/matrixValueRandomnessParam));
        }
    }
    std::vector<float> tempVector(rowN);
    for (auto& val : tempVector)
    {
        val =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/matrixValueRandomnessParam));
    }
    equation final;
    final.transformation = tempMatrix;
    final.image = tempVector;
    return final;
}

equation randGenerator(std::vector<float> preimage, int matrixSizeRandomnessParam, int matrixValueRandomnessParam, int imageValueRandomnessParam)
{
    srand ( time(NULL) );
    int rowN = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/matrixSizeRandomnessParam)) + 1;
    int columnM = size(preimage);
    std::vector<std::vector<float>> tempMatrix(rowN, std::vector<float>(columnM));
     for (auto& row : tempMatrix)
    {
        for(auto& val : row)
        {
            val = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/matrixValueRandomnessParam));
        }
    }

    std::vector<float> res(rowN);
    int h = 0;
    for(auto& row : tempMatrix)
    {
        float dot = 0;
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


void printMatrix(std::vector<std::vector<float>>& matrix)
{
    std::cout << "Printing Matrix..." << std::endl;
    for(auto& x :matrix)
    {
        for(auto& y : x)
        {
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
}

void printVector(std::vector<float>& vector)
{
    std::cout << "Printing Vector..." << std::endl;
    for(auto& x : vector)
    {
        std:: cout << x << " ";
        std::cout << std::endl;
    }
}

