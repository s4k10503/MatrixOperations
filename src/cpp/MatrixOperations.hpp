#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

#include <iostream>
#include <vector>
#include <cmath>

class MatrixOperations
{
public:
    // Add two matrices
    std::vector<float> add(const std::vector<float> &A, const std::vector<float> &B, int rows, int cols);

    // Subtract two matrices
    std::vector<float> subtract(const std::vector<float> &A, const std::vector<float> &B, int rows, int cols);

    // Multiply two matrices
    std::vector<float> multiply(const std::vector<float> &A, const std::vector<float> &B, int rowsA, int colsA, int colsB);

    // Transpose a matrix
    std::vector<float> transpose(const std::vector<float> &A, int rows, int cols);

    // Invert a matrix
    std::vector<float> invertMatrix(const std::vector<float> &M, int N);

    // Print a matrix in a NumPy-like format
    void printMatrix(const std::vector<float> &mat, int rows, int cols);
};

// Add two matrices
std::vector<float> MatrixOperations::add(const std::vector<float> &A, const std::vector<float> &B, int rows, int cols)
{
    std::vector<float> C(rows * cols, 0.0);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            C[i * cols + j] = A[i * cols + j] + B[i * cols + j];
        }
    }
    return C;
}

// Subtract two matrices
std::vector<float> MatrixOperations::subtract(const std::vector<float> &A, const std::vector<float> &B, int rows, int cols)
{
    std::vector<float> C(rows * cols, 0.0);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            C[i * cols + j] = A[i * cols + j] - B[i * cols + j];
        }
    }
    return C;
}

// Multiply two matrices
std::vector<float> MatrixOperations::multiply(const std::vector<float> &A, const std::vector<float> &B, int rowsA, int colsA, int colsB)
{
    std::vector<float> C(rowsA * colsB, 0.0);
    for (int i = 0; i < rowsA; ++i)
    {
        for (int j = 0; j < colsB; ++j)
        {
            for (int k = 0; k < colsA; ++k)
            {
                C[i * colsB + j] += A[i * colsA + k] * B[k * colsB + j];
            }
        }
    }
    return C;
}

// Transpose a matrix
std::vector<float> MatrixOperations::transpose(const std::vector<float> &A, int rows, int cols)
{
    std::vector<float> B(rows * cols, 0.0);
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            B[j * rows + i] = A[i * cols + j];
        }
    }
    return B;
}

// Invert a matrix (as previously implemented)
std::vector<float> MatrixOperations::invertMatrix(const std::vector<float> &M, int N)
{
    std::vector<float> tempM = M; // Temporary copy of M for manipulation
    std::vector<float> inv(N * N, 0.0);

    // Initialize the inv matrix as the identity matrix
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            inv[i * N + j] = (i == j) ? 1.0f : 0.0f;
        }
    }

    // Perform Gaussian elimination
    for (int i = 0; i < N; ++i)
    {
        float maxEl = std::abs(tempM[i * N + i]);
        int maxRow = i;

        // Find the pivot row
        for (int k = i + 1; k < N; ++k)
        {
            if (std::abs(tempM[k * N + i]) > maxEl)
            {
                maxEl = std::abs(tempM[k * N + i]);
                maxRow = k;
            }
        }

        // Check if the matrix is singular
        if (maxEl == 0)
        {
            return std::vector<float>{}; // Return an empty vector
        }

        // Swap rows
        for (int k = i; k < N; ++k)
        {
            std::swap(tempM[maxRow * N + k], tempM[i * N + k]);
            std::swap(inv[maxRow * N + k], inv[i * N + k]);
        }

        // Normalize the pivot row
        float pivot = tempM[i * N + i];
        for (int k = 0; k < N; ++k)
        {
            tempM[i * N + k] /= pivot;
            inv[i * N + k] /= pivot;
        }

        // Eliminate other rows
        for (int j = 0; j < N; ++j)
        {
            if (j != i)
            {
                float ratio = tempM[j * N + i];
                for (int k = 0; k < N; ++k)
                {
                    tempM[j * N + k] -= ratio * tempM[i * N + k];
                    inv[j * N + k] -= ratio * inv[i * N + k];
                }
            }
        }
    }
    return inv;
}

// Print a matrix in a NumPy-like format
void MatrixOperations::printMatrix(const std::vector<float> &mat, int rows, int cols)
{
    std::cout << "[";
    for (int i = 0; i < rows; ++i)
    {
        std::cout << "[";
        for (int j = 0; j < cols; ++j)
        {
            std::cout << mat[i * cols + j];
            if (j < cols - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i < rows - 1)
        {
            std::cout << ",\n";
        }
    }
    std::cout << "]\n";
}

#endif // MATRIX_OPERATIONS_HPP