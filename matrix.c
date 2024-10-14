#include <stdio.h>
#define SIZE 5


void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int resultm[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            resultm[row][col] = m1[row][col] + m2[row][col];
        }
    }
}

void multMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int resultm[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            resultm[row][col] = 0;
            for (int k = 0; k < SIZE; k++){
                resultm[row][col] += m1[row][k] * m2[k][col];
            }
        }
    }
}

void transposeMatrix(int m[SIZE][SIZE], int resultm[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            resultm[col][row] = m[row][col];
        }
    }
}

void printMatrix(int m[SIZE][SIZE]){
    for (int row = 0; row < SIZE; row++){
        for (int col = 0; col < SIZE; col++){
            printf("%d ", m[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    int resultm[SIZE][SIZE];

    printf("Addition of matrices: \n");
    addMatrices(m1, m2, resultm);
    printMatrix(resultm);

    printf("Multiplication of matrices: \n");
    multMatrices(m1, m2, resultm);
    printMatrix(resultm);

    printf("Transposition of first matrix: \n");
    transposeMatrix(m1, resultm);
    printMatrix(resultm);

    printf("Transposition of second matrix: \n");
    transposeMatrix(m2, resultm);
    printMatrix(resultm);

    return 0;
}
