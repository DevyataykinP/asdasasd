#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void read_matrix_from_file(double **a, double *b, int n, const char *filename) {
    FILE *file = fopen(filename, "r");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%lf", &a[i][j]);
        }
        fscanf(file, "%lf", &b[i]);
    }
    fclose(file);
}

void print_matrix(double **a, double *b, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%7.2f ", a[i][j]);
        }
        printf(" %7.2f\n", b[i]);
    }
    printf("\n");
}

double determinant(double **a, int n) {
    if (n == 1) return a[0][0];
    double det = 0;
    double **submatrix = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; i++) {
        submatrix[i] = (double *)malloc((n - 1) * sizeof(double));
    }

    for (int col = 0; col < n; col++) {
        for (int i = 1; i < n; i++) {
            int sub_i = i - 1;
            for (int j = 0; j < n; j++) {
                if (j != col) {
                    submatrix[sub_i][j < col ? j : j - 1] = a[i][j];
                }
            }
        }
        det += pow(-1, col) * a[0][col] * determinant(submatrix, n - 1);
    }

    for (int i = 0; i < n - 1; i++) free(submatrix[i]);
    free(submatrix);

    return det;
}

void gauss_method(double **a, double *b, double *x, int n) {
    int i, j, k;
    double c;

    for (k = 0; k < n; k++) {//прямой ход
        printf("Шаг %d:\n", k + 1);
        print_matrix(a, b, n);

        
        if (fabs(a[k][k]) < 1e-9) {//вырожденность
            printf("Ошибка: матрица вырождена.\n");
            return;
        }

        c = 1 / a[k][k];//нормализация
        for (i = k; i < n; i++) {
            a[k][i] *= c;
        }
        b[k] *= c;

        for (i = k + 1; i < n; i++) {//обнуление ниже главной диагонали
            c = a[i][k];
            for (j = k; j < n; j++) {
                a[i][j] -= c * a[k][j];
            }
            b[i] -= c * b[k];
        }
    }

    for (i = n - 1; i >= 0; i--) {//обратный ход
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
    }
}

int main() {
    int n;
    printf("Введите размерность матрицы (n): ");
    scanf("%d", &n);

    
    double **a = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));

    
    const char *filename = "input.txt";
    read_matrix_from_file(a, b, n, filename);

    printf("Матрица:\n");
    print_matrix(a, b, n);

    
    double det = determinant(a, n);
    if (fabs(det) < 1e-9) {
        printf("Матрица вырождена (определитель = %.2e).\n", det);
        return 1;
    }
    printf("Определитель: %.2e\n", det);

   
    gauss_method(a, b, x, n);

    
    printf("Решение:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i, x[i]);
    }

   
    for (int i = 0; i < n; i++) free(a[i]);
    free(a);
    free(b);
    free(x);

    return 0;
}
