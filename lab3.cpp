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

void localizeRoots(double a, double b, double epsilon) {
    double step=0.1;

    for (double x=a; x<b; x+=step) {
        if (func(x)*func(x+step)<=0) {
            double root=newtonMethod(x, x+step, epsilon);
            cout<<root<<endl;
        }
    }
}

int main() {
    double a, b, epsilon;

    cout << "Границы a, b: ";
    cin >> a >> b;

    cout<<"Введите epsilon: ";
    cin>>epsilon;

    cout<<"Локализация корней: "<<endl;
    localizeRoots(a, b, epsilon);

    return 0;
}
