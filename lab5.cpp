#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return exp(-x * x);
}

double trap(double a, double b, int N) {
    double h = (b - a) / N;
    double sum = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        sum += f(x);
    }
    
    return sum * h;
}

int main() {
    double a, b;
    int N;
    
    cout << "Введите a и b: ";
    cin >> a >> b;
    
    cout << "Введите N: ";
    cin >> N;
    
    cout << trap(a, b, N) << endl;
    
    return 0;
}
