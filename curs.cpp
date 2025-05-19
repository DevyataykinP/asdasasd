#include <iostream>
#include <iomanip>
using namespace std;

double func(double x, double y){
    return (x+y);
}

double rk(double a, double b, double step, double y0){
    double k1,k2,k3,k4;
    double x=a;
    double y=y0;
    
    while(x<b){
        k1=step*func(x,y);
        k2=step*func(x+step/2,y+k1/2);
        k3=step*func(x+step/2,y+k2/2);
        k4=step*func(x+step,y+k3);

        x+=step;
        y+=(k1+2*k2+2*k3+k4)/6;
    }
    return y;
}

int main(){
    double a,b,step,y0;

    cout<<"Введите начало отрезка: ";
    cin>>a;

    cout<<"Введите конец отрезка: ";
    cin>>b;

    cout<<"Введите шаг;  ";
    cin>>step;

    cout<<"Введите y(0): ";
    cin>>y0;

    for(int x=a;x<=b;x++){
        cout<<setw(6)<<x<<setw(15)<<fixed<<setprecision(4)<<rk(a,x,step,y0)<<endl;
    }
}
