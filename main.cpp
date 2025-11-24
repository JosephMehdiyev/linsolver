#include  <stdio.h>
#include <iostream>
#include "linEquation.hpp"
int main()
{
    equation test = randGenerator();
    printMatrix(test.matrix);
    printVector(test.vector);
    return 0;
}
