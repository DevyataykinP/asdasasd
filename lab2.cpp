#include <iostream>
#include <cmath>

using namespace std;

const int matrix_size = 3;
const double Epsilon = 1e-6;

float matrix[matrix_size][matrix_size + 1] = {
        {9, 1, 1, 12},
        {2, 10, 1, 13},
        {2, 6, 10, 14}
};

float A[matrix_size][matrix_size] = {};
float B[matrix_size] = {};
float C[matrix_size][matrix_size] = {};
float E[matrix_size][matrix_size] = {};
float x[matrix_size] = {};

void printMatrix(const float matrix[][matrix_size + 1]) {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            printf(" %6.2f ", matrix[i][j]);
        }
        printf(" | %6.2f \n", matrix[i][matrix_size]);
    }
    cout << endl;
}

void printMatrix(const float matrix[][matrix_size]) {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            printf(" %6.2f ", matrix[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}

void printVector(const float vector[], int size) {
    for (int i = 0; i < size; i++) {
        printf(" %6.2f \n", vector[i]);
    }
    cout << endl;
}

void divideMatrix() {
    for (int i = 0; i < matrix_size; i++) {
        float diagonalElement = matrix[i][i];
        for (int j = 0; j < matrix_size + 1; j++) {
            matrix[i][j] = matrix[i][j] / diagonalElement;
        }
    }
}

void getMatrixAB() {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            A[i][j] = matrix[i][j];
        }
    }

    for (int k = 0; k < matrix_size; k++) {
        B[k] = matrix[k][matrix_size];
    }
}

double maxB(const float odnomer[], int size) {
    double maxVal = fabs(odnomer[0]);
    for (int i = 1; i < size; i++) {
        if (fabs(odnomer[i]) > maxVal) {
            maxVal = fabs(odnomer[i]);
        }
    }
    return maxVal;
}

double maxC(const float matrix[][matrix_size], int size) {
    double maxVal = 0;
    for (int i = 0; i < size; i++) {
        double rowSum = 0;
        for (int j = 0; j < size; j++) {
            rowSum += fabs(matrix[i][j]);
        }
        if (rowSum > maxVal) {
            maxVal = rowSum;
        }
    }
    return maxVal;
}

void matrixE() {
    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            if (i == j) {
                E[i][j] = 1;
            } else {
                E[i][j] = 0;
            }
        }
    }
}

void iterate() {
    double temp = 0;
    double Cmax = maxC(C, matrix_size);
    double Bmax = maxB(B, matrix_size);
	cout << "Cmax = " << Cmax << endl;
	cout << "Bmax = " << Bmax << endl;
    double N = ceil(log((Epsilon * (1 - Cmax)) / Bmax) / log(Cmax));

    cout << "Количество шагов: " << N << endl;
   
    cout << "Результат:" << endl;

    for (int i = 0; i < matrix_size; i++) {
        x[i] = 0;
    }

    int steps = N;

    for (int j = 0; j < steps; j++) {
        float newX[matrix_size] = {0};

        for (int i = 0; i < matrix_size; i++) {
            temp = 0;
            for (int k = 0; k < matrix_size; k++) {
                temp += C[i][k] * x[k];
            }
            newX[i] = B[i] - temp;
        }

        for (int i = 0; i < matrix_size; i++) {
            x[i] = newX[i];
        }

        cout << "Шаг " << j + 1 << ":" << endl;
        printVector(x, matrix_size);
    }
}

int main() {
    cout << "Начальная матрица:" << endl;
    printMatrix(matrix);

    divideMatrix();

    cout << "Матрица после деления:" << endl;
    printMatrix(matrix);

    getMatrixAB();

    cout << "Матрица A:" << endl;
    printMatrix(A);

    cout << "Матрица B:" << endl;
    printVector(B, matrix_size);

    cout << "Матрица E:" << endl;
    matrixE();
    printMatrix(E);

    for (int i = 0; i < matrix_size; i++) {
        for (int j = 0; j < matrix_size; j++) {
            C[i][j] = A[i][j] - E[i][j];
        }
    }

    cout << "Матрица C (A - E):" << endl;
    printMatrix(C);

    iterate();

    cout << "Результат:" << endl;
    printVector(x, matrix_size);

    return 0;
}
