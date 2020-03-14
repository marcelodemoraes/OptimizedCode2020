#include <iostream>

using namespace std;

int **readMatrix(int m, int n) {
    int **matrix = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * n);

        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            matrix[i][j] = a;
        }
    }

    return matrix;
}

void printMatrix(int **matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int **matrixMulti(int **A, int m1, int n1, int **B, int m2, int n2) {
    int **C = (int **)malloc(sizeof(int *) * m1);
    for (int i = 0; i < m1; i++) {
        C[i] = (int *)calloc(n2, sizeof(int));
    }

    for (int i = 0; i < m1; i++) {
        for (int k = 0; k < n1; k++) {
            for (int j = 0; j < n2; j++) {
             C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void freeMatrix(int **A, int m, int n) {
    for (int i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);
}

int main() {
    // cout << "Matrix Dim: " << endl;
    int m1, n1;  //LINHA E COLUNA
    int m2, n2;  //LINHA E COLUNA
    cin >> m1 >> n1;
    cin >> m2 >> n2;
    // cout << "Matrix Elements: " << endl;
    int **A = readMatrix(m1, n1);

    // cout << "\nMatrix Dim: " << endl;
    // cout << "Matrix Elements: " << endl;
    int **B = readMatrix(m2, n2);

    // cout << "Matrix Mult: " << endl;
    int **C = matrixMulti(A, m1, n1, B, m2, n2);

    // printMatrix(C, m1, n2);

    freeMatrix(A, m1, m2);
    freeMatrix(B, m2, m2);
    freeMatrix(C, m1, n2);
}