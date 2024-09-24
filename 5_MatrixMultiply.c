//Multiplcation of two Matrix using Divide and Conquer

#include <stdio.h>

void printMatrix(int matA[4][4], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void matrixMultiplyDivideConquer(int n, int A[][n], int B[][n], int C[][n]) {
    // If the matrices are 1x1, just do a simple multiplication
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Split matrices into quarters
    int size = n / 2;
    int a11[size][size], a12[size][size], a21[size][size], a22[size][size];
    int b11[size][size], b12[size][size], b21[size][size], b22[size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + size];
            a21[i][j] = A[i + size][j];
            a22[i][j] = A[i + size][j + size];
            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + size];
            b21[i][j] = B[i + size][j];
            b22[i][j] = B[i + size][j + size];
        }
    }

    // Recursively compute products
    int p1[size][size], p2[size][size], p3[size][size], p4[size][size], p5[size][size], p6[size][size], p7[size][size], p8[size][size];

    matrixMultiplyDivideConquer(size, a11, b11, p1);
    matrixMultiplyDivideConquer(size, a12, b21, p2);
    matrixMultiplyDivideConquer(size, a11, b12, p3);
    matrixMultiplyDivideConquer(size, a12, b22, p4);
    matrixMultiplyDivideConquer(size, a21, b11, p5);
    matrixMultiplyDivideConquer(size, a22, b21, p6);
    matrixMultiplyDivideConquer(size, a21, b12, p7);
    matrixMultiplyDivideConquer(size, a22, b22, p8);

    // Compute result matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = p1[i][j] + p2[i][j];
            C[i][j + size] = p3[i][j] + p4[i][j];
            C[i + size][j] = p5[i][j] + p6[i][j];
            C[i + size][j + size] = p7[i][j] + p8[i][j];
        }
    }
}

int main() {
    
    int a[4][4] = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
    int b[4][4] = {{2,2,2,2},{2,2,2,2},{2,2,2,2},{2,2,2,2}};

    printf("Matrix 1:\n");
    printMatrix(a, 4, 4);
    printf("Matrix 2:\n");
    printMatrix(b, 4, 4);

    int resultMatrix[4][4];
    matrixMultiplyDivideConquer(4, a, b, resultMatrix);
    printMatrix(resultMatrix, 4, 4);

    return 0;
}