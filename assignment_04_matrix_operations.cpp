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
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_SIZE = 10;

// Reads a rows x cols matrix from the user, prompting for each element.
void readMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

// Displays a rows x cols matrix in a neat, aligned grid.
void printMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << mat[i][j];
        }
        cout << endl;
    }
}

// PART A: Computes the transpose of a rows x cols matrix into result.
void transposeMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

// PART B: Computes the element-wise sum of two rows x cols matrices.
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART C: Computes the product of an (rowsA x colsA) matrix and a
// (colsA x colsB) matrix, storing the (rowsA x colsB) result.
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int rowsA, int colsA, int colsB,
                       int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int choice;

    cout << "Matrix Operations Menu" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    cout << endl;

    if (choice == 1) {
        // ----- PART A: Transpose -----
        int rows, cols;
        int mat[MAX_SIZE][MAX_SIZE];
        int result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(mat, rows, cols);
        transposeMatrix(mat, rows, cols, result);

        cout << endl << "Original Matrix:" << endl;
        printMatrix(mat, rows, cols);

        cout << endl << "Transposed Matrix:" << endl;
        printMatrix(result, cols, rows);

    } else if (choice == 2) {
        // ----- PART B: Addition -----
        int rows, cols;
        int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << endl << "Enter values for Matrix A:" << endl;
        readMatrix(a, rows, cols);

        cout << endl << "Enter values for Matrix B:" << endl;
        readMatrix(b, rows, cols);

        addMatrices(a, b, rows, cols, result);

        cout << endl << "Matrix A:" << endl;
        printMatrix(a, rows, cols);

        cout << endl << "Matrix B:" << endl;
        printMatrix(b, rows, cols);

        cout << endl << "Sum (A + B):" << endl;
        printMatrix(result, rows, cols);

    } else if (choice == 3) {
        // ----- PART C: Multiplication -----
        int rowsA, colsA, rowsB, colsB;
        int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

        cout << "Enter number of rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter number of columns for Matrix A: ";
        cin >> colsA;

        cout << "Enter number of rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter number of columns for Matrix B: ";
        cin >> colsB;

        if (colsA != rowsB) {
            cout << endl << "Error: Number of columns in A must equal "
                 << "number of rows in B." << endl;
            return 0;
        }

        cout << endl << "Enter values for Matrix A:" << endl;
        readMatrix(a, rowsA, colsA);

        cout << endl << "Enter values for Matrix B:" << endl;
        readMatrix(b, rowsB, colsB);

        multiplyMatrices(a, b, rowsA, colsA, colsB, result);

        cout << endl << "Matrix A:" << endl;
        printMatrix(a, rowsA, colsA);

        cout << endl << "Matrix B:" << endl;
        printMatrix(b, rowsB, colsB);

        cout << endl << "Product (A x B):" << endl;
        printMatrix(result, rowsA, colsB);

    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

