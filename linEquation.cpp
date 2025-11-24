#include "linEquation.hpp"
#include <cstdlib>

equation randGenerator()
{
      srand ( time(NULL) );
    int rowN = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10)) + 1;
    int columnM = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/10)) + 1;
    std::vector<std::vector<float>> tempMatrix(rowN, std::vector<float>(columnM));
    std::cout << rowN << " " << columnM << std::endl;
    for (auto& row : tempMatrix)
    {
        for(auto& val : row)
        {
            val = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/1000000));
;
        }
    }
    std::vector<float> tempVector(rowN);
    for (auto& val : tempVector)
    {
        val =  static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/1000000));
    }
    equation final;
    final.matrix = tempMatrix;
    final.vector = tempVector;
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

