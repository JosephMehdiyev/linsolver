#pragma once
#include <vector>
#include <random>
#include <iostream>

struct equation
{
    std::vector<std::vector<float>> matrix;
    std::vector<float> vector;
};

equation randGenerator();
void printMatrix(std::vector<std::vector<float>>& matrix);
void printVector(std::vector<float>& vector);


