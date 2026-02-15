#include  <stdio.h>
#include <iostream>
#include "linEquation.hpp"
int main()
{
    equation test = randEqGen(1000);
    std::vector<double> testVector = randVecGen(test.transformation.cols);
    Mat<double> testMatrix = test.transformation;
    Mat<double> mat1 = randMatGen(5 , 5, false, 0, 0);
    (mat1 * randMatGen(5,5, false, mat1.cols, 0)).display();

    return 0;
}
