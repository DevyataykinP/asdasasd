#include <iostream>

using namespace std;

void printMatrix(float **matrix, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n + 1; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main(){
    int n;
    cout << "Число переменных: ";
    cin >> n;
    float **matrix = (float **)malloc(n * sizeof(float *));
    float result[n];

    cout << "Элементы матрицы: " << "\n";
    for (int i = 0; i < n; i++){
        matrix[i] = (float *)malloc((n + 1) * sizeof(float));
        for (int j = 0; j < n + 1; j++){
            cout << "m[" << i << "][" << j << "] = ";
            cin >> matrix[i][j];
        }
    }
    cout << "\n";

    printMatrix(matrix, n);

    for (int j = 0; j < n - 1; j++){
        for (int i = j + 1; i < n; i++){
            float temp = matrix[i][j] / matrix[j][j];
            for (int k = 0; k < n + 1; k++){
                matrix[i][k] -= matrix[j][k] * temp;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--){
        result[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++){
            if (i != j){
                result[i] -= matrix[i][j] * result[j];
            }
        }
        result[i] = result[i] / matrix[i][i];
    }

    cout << "\n";
    for (int i = 0; i < n; i++){
        cout << "X"<<i<<" = "<<result[i];
        cout << "\n";
    }
    cout << "\n";
}
