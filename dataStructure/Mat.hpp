#include <iostream>
#include <vector>
#include <stdexcept>

#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T>
class Mat {
public:
    size_t rows;
    size_t cols;
    std::vector<T> data; 

    Mat(size_t r = 0, size_t c = 0, T init = T()) : rows(r), cols(c), data(r * c, init) {}

    T& operator()(size_t r, size_t c) { return data[r * cols + c]; }
    const T& operator()(size_t r, size_t c) const { return data[r * cols + c]; }

    Mat t() const 
    {
        Mat result(cols, rows); 
        for (size_t i = 0; i < rows; ++i) 
        {
            for (size_t j = 0; j < cols; ++j) 
            {
                result(j, i) = (*this)(i, j);
            }
        }
        return result;
    }

    Mat operator*(const Mat& other) const 
    {
        if (this->cols != other.rows) 
        {
            throw std::invalid_argument("Matrix dimensions mismatch!");
        }

        Mat result(this->rows, other.cols, 0);
        for (size_t i = 0; i < this->rows; ++i) 
        {
            for (size_t k = 0; k < this->cols; ++k) 
            {
                for (size_t j = 0; j < other.cols; ++j) 
                {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }
        return result;
    }

    bool empty() const
    {
        if (this->rows == this->cols && this->cols == 0)
            return true;
        else return false;
    }

    void display() const {
        printMat(*this);
    }

private:
    static void printMat(const Mat<T>& matrix) {
        std::cout << GREEN << "Printing Matrix (" << matrix.rows << "x" << matrix.cols << "):" << RESET << std::endl;
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                std::cout << matrix(i, j) << " ";
            }
            std::cout << std::endl;
        }
    }
};
