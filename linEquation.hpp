#pragma once
#include <vector>
#include <random>
#include <iostream>

// The data structure for the equation Ax = b
// A : transformation
// x : preimage
// b : image
struct equation
{
    std::vector<std::vector<float>> transformation;
    std::vector<float> image;
    std::vector<float> preimage;
};

// For testing purposes
equation randGenerator(int matrixSizeRandomnessParam = 5, int matrixValueRandomnessParam = 5, int imageValueRandomnessParam = 5);
equation randGenerator(std::vector<float> preimage, int matrixSizeRandomnessParam = 5, int matrixValueRandomnessParam = 5, int imageValueRandomnessParam = 5);


// For debugging purposes
void printMatrix(std::vector<std::vector<float>>& matrix);
void printVector(std::vector<float>& vector);


