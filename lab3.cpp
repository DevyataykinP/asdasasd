#include <cmath>
#include <iostream>

using namespace std;

double func(double x) { 
    return 1-x*log(x)+0.3*sqrt(x); 
}

double diff_func(double x, double h) {
    return (func(x+h)-func(x))/h;
}

double newtonMethod(double a, double b, double epsilon) {
    double x0=(a+b)/2;
    double h=0.0001;

    while (fabs(func(x0)) > epsilon) {
        x0=x0-func(x0)/diff_func(x0, h);
    }

    return x0;
}

int main() {
    double a, b, epsilon;

    cout << "Границы a, b: ";
    cin >> a >> b;

    cout<<"Введите epsilon: ";
    cin>>epsilon;

    cout<<newtonMethod(a, b, epsilon)<<endl;

    return 0;
}
