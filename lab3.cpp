#include <iostream>
#include <cmath>
#include <iomanip>
  
using namespace std;

double func(double x) {
    return 1-x*log(x)+0.3*sqrt(x);
}

double diff_func(double x) {
    return -1*log(x) +3 /(20*sqrt(x)) - 1;
}

double epsilon = 1e-6;
int step = 50;

double Newton(double x0) {
    double x = x0;
    cout << "Method Newton:" << endl;
    cout << "x0 = " << fixed << setprecision(3) << x << "  f(x0) = " << func(x) << "  diff_func(x0) =" << diff_func(x) << endl;

    for (int i = 0; i < step; i++) {
        double x_next = x - func(x) / diff_func(x);
        cout << "x" << i + 1 << " = " << fixed << setprecision(3) << x_next << "  f(x" << i + 1 << ") = " << func(x_next) << "  diff_func(x" << i + 1 << ") = " << diff_func(x_next) << endl;
  
        if (abs(x_next - x) < epsilon) {
            return x_next;
        }

        x = x_next;
    }
    return x;
}

int main() {
    double x0 = 2.1;
    double result3 = Newton(x0);
    cout << "Result: " << result3 << endl;

    return 0;
}
