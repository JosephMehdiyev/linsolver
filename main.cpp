#include  <stdio.h>
#include <iostream>
#include "linEquation.hpp"
int main()
{
    std::vector<float> testVector = {3,2,1};
    equation test = randGenerator();
    printMatrix(test.transformation);
    printVector(test.image);
    return 0;
}
