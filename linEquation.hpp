#pragma once
#include <stdexcept>
#include <vector>
#include <random>
#include <iostream>

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
std::vector<T> operator*(const std::vector<std::vector<T>>& mat, const std::vector<T>& vec)
{
    if (mat.empty())
        throw std::invalid_argument("Matrix is empty");
    if (vec.empty())
        throw std::invalid_argument("Vector is empty");

    int n = mat.size();
    int m = mat[0].size();
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
void printMat(const std::vector<std::vector<T>>& matrix)
{
    std::cout << GREEN <<  "Printing Matrix:" << RESET <<std::endl;
    for(auto& x :matrix)
    {
        for(auto& y : x)
        {
            std::cout << y << " ";
        }
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

template<typename T>
std::vector<std::vector<T>> operator*(const std::vector<std::vector<T>>& mat1, const std::vector<std::vector<T>>& mat2)
{
    if (mat1.empty() || mat2.empty())
        throw std::invalid_argument("Matrixes cannot be empty");
    if (mat1[0].size() != mat2.size())
        throw std::invalid_argument("Matrixes must have right dimensions");

    std::vector<std::vector<T>> result(mat1.size(), std::vector<T>(mat2[0].size()));

    for (size_t i = 0; i < mat1.size(); ++i) {
        for (size_t k = 0; k < mat2.size(); ++k) { // 'k' loop moved up for "Cache Friendliness"
            for (size_t j = 0; j < mat2[0].size(); ++j) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;

}



struct equation
{
    std::vector<std::vector<double>> transformation;
    std::vector<double>              image;
    std::vector<double>              preimage;
};


// Generates random preimage and transformation
equation randEqGen(int matrDimRandParam = 5, int matValRandParam = 5, int imageValRandParam = 5);
// Generates random tranformation from an known image
equation randEqGen(std::vector<double> preimage, int matDimRandParam = 5, int matValRandParam = 5);

std::vector<std::vector<double>> randMatGen(int MatDimRandParam = 5, int matValRandParam = 5, bool isSquareMat = false, int rowN = 0, int columnM = 0);
std::vector<double> randVecGen(int vecDim, int vecValRandParam = 5);

// For debugging purposes
void printMat(std::vector<std::vector<double>>& matrix);


