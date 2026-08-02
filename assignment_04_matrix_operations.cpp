// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void readMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

void transposeMatrix(int matrix[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

void addMatrices(int a[10][10], int b[10][10], int result[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[10][10], int b[10][10], int result[10][10], int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int matrix[10][10], transposed[10][10];
    int rows, cols;

    // ----- PART A: Transpose -----
    cout << "--- PART A: Transpose a Matrix ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    readMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transposed, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(transposed, cols, rows);

    // ----- PART B: Addition -----
    cout << "\n--- PART B: Add Two Matrices ---" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matA[10][10], matB[10][10], sumResult[10][10];

    cout << "Enter Matrix A:" << endl;
    readMatrix(matA, rows, cols);
    cout << "Enter Matrix B:" << endl;
    readMatrix(matB, rows, cols);

    addMatrices(matA, matB, sumResult, rows, cols);

    cout << "\nSum Matrix:" << endl;
    printMatrix(sumResult, rows, cols);

    // ----- PART C: Multiplication -----
    cout << "\n--- PART C: Multiply Two Matrices ---" << endl;
    int m, n, p;
    cout << "Enter rows of Matrix A (M): ";
    cin >> m;
    cout << "Enter columns of Matrix A / rows of Matrix B (N): ";
    cin >> n;
    cout << "Enter columns of Matrix B (P): ";
    cin >> p;

    int mulA[10][10], mulB[10][10], productResult[10][10];

    cout << "Enter Matrix A (" << m << "x" << n << "):" << endl;
    readMatrix(mulA, m, n);
    cout << "Enter Matrix B (" << n << "x" << p << "):" << endl;
    readMatrix(mulB, n, p);

    multiplyMatrices(mulA, mulB, productResult, m, n, p);

    cout << "\nProduct Matrix:" << endl;
    printMatrix(productResult, m, p);

    return 0;
}
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

