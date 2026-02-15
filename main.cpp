#include  <stdio.h>
#include <iostream>
#include "linEquation.hpp"
int main()
{
    equation test = randEqGen(1000);
    std::vector<double> testVector = randVecGen(test.transformation[0].size());
    std::vector<std::vector<double>> testMatrix = test.transformation;
    std::vector<std::vector<double>> mat1 = randMatGen(1000 , 1000, false, 0, 0);
    printMat(mat1 * randMatGen(1000,1000, false, mat1[0].size(), 0));

    return 0;
}
