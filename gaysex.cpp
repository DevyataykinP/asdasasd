#include <iostream>
#include <cmath>
#include <iomanip>
  
using namespace std;

double f(double x) {
    return 1-0.5*x*x*log(x)+0.3*sqrt(x);
}

double epsilon = 1e-6;
int step = 44;

double Hord(double a, double b) {
    double c, c_old = 0.0;

    for (int i = 0; i < step; i++) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (abs(c - c_old) < epsilon) {
            return c;
        }

        if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }

        c_old = c;
    }
    return c;
}

int main() {
    double a = 1, b = 2;
    double result = Hord(a, b);
    cout << result << endl;

    return 0;
}
