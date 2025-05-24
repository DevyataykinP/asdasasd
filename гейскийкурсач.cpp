#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double differentialEquation(double x, double y) {
    return x + y;
}

double rungeKuttaSolver(double start, double end, double stepSize, double initialY) {
    if (stepSize <= 0) {
        cerr << "Ошибка: шаг интегрирования должен быть положительным!\n";
        return NAN;
    }

    double currentX = start;
    double currentY = initialY;
    int maxIterations = 100000;
    int iterations = 0;

    while (currentX < end && iterations < maxIterations) {
        double slope1 = stepSize * differentialEquation(currentX, currentY);
        double slope2 = stepSize * differentialEquation(currentX + stepSize / 2, currentY + slope1 / 2);
        double slope3 = stepSize * differentialEquation(currentX + stepSize / 2, currentY + slope2 / 2);
        double slope4 = stepSize * differentialEquation(currentX + stepSize, currentY + slope3);
        
        currentY += (slope1 + 2 * slope2 + 2 * slope3 + slope4) / 6;
        currentX += stepSize;
        iterations++;
    }

    if (iterations >= maxIterations) {
        cerr << "Предупреждение: достигнуто максимальное число итераций!\n";
    }

    return currentY;
}

int main() {
    double startPoint, endPoint, stepSize, initialValue;

    cout << "Введите начало отрезка интегрирования: ";
    cin >> startPoint;

    cout << "Введите конец отрезка: ";
    cin >> endPoint;

    if (startPoint > endPoint) {
        cerr << "Ошибка: начало отрезка должно быть меньше конца!\n";
        return 1;
    }

    cout << "Введите шаг интегрирования: ";
    cin >> stepSize;

    if (stepSize <= 0) {
        cerr << "Ошибка: шаг интегрирования должен быть положительным!\n";
        return 1;
    }

    cout << "Введите начальное значение y(" << startPoint << "): ";
    cin >> initialValue;

    cout << "\nРезультаты численного решения:\n";
    cout << setw(8) << "x" << setw(16) << "y(x)" << endl;
    cout << "-------------------------" << endl;
    
    for (double x = startPoint; x <= endPoint; x += 1.0) {
        double y = rungeKuttaSolver(startPoint, x, stepSize, initialValue);
        if (!isnan(y)) {
            cout << setw(8) << x << setw(16) << fixed << setprecision(4) << y << endl;
        }
    }

    return 0;
}
