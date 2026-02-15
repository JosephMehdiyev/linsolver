#pragma once
#include <stdexcept>
#include <vector>
#include <random>
#include <iostream>
#include "Mat.hpp"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

template<typename T>
T randomUniform(T range_from, T range_to) 
{
    static std::random_device           rand_dev;
    static std::mt19937                 generator(rand_dev());
    std::uniform_int_distribution<T>    distr(range_from, range_to);
    return distr(generator);
}

template<typename T>
std::vector<T> operator*(const Mat<T> mat, const std::vector<T>& vec)
{
    if (mat.empty())
        throw std::invalid_argument("Matrix is empty");
    if (vec.empty())
        throw std::invalid_argument("Vector is empty");

    int n = mat.rows;
    int m = mat.cols;
    if (vec.size() != m)
        throw std::invalid_argument("Matrix columns must equal vector size");

    std::vector<T> result(n, 0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            result[i] += mat[i][j] * vec[j];

    return result;
}

template<typename T>
void printVec(const std::vector<T>& vector)
{
    std::cout << GREEN << "Printing Vector:" << RESET << std::endl;
    for(const auto&x : vector)
    {
        std::cout << x << " ";
        std::cout << std::endl;
    }
}


template<typename T>
T dotProduct(const std::vector<T>& vec1, const std::vector<T>& vec2)
{
    if (vec1.empty() || vec2.empty())
        throw std::invalid_argument("Vectors cannot be empty");
    if (vec1.size() != vec2.size())
        throw std::invalid_argument("Vectors must be same dimension");
    T result;
    for(int i = 0; i < vec1.size(); i++)
    {
        result += vec1[i] * vec2[i];
    }
    return result;
}



struct equation
{
    Mat<double>                      transformation;
    std::vector<double>              image;
    std::vector<double>              preimage;
};


// Generates random preimage and transformation
equation randEqGen(int matrDimRandParam = 5, int matValRandParam = 5, int imageValRandParam = 5);

Mat<double> randMatGen(int MatDimRandParam = 5, int matValRandParam = 5, bool isSquareMat = false, int rowN = 0, int columnM = 0);
std::vector<double> randVecGen(int vecDim, int vecValRandParam = 5);



