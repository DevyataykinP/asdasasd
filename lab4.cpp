#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int MAX_POINTS = 100;

int main() {
    double x;
    cout<<"Введите Х: ";
    cin>>x;

    ifstream input("in.txt");

    double a[MAX_POINTS], y[MAX_POINTS];
    int n = 0;

    string line;

    if (getline(input, line)) {
        stringstream ss(line);
        while (ss >> a[n] && n < MAX_POINTS) {
            n++;
        }
    }

    if (getline(input, line)) {
        stringstream ss(line);
        int count = 0;
        while (ss >> y[count] && count < n) {
            count++;
        }
    }

    double table[MAX_POINTS][MAX_POINTS];

    for (int i = 0; i < n; i++) {
        table[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            table[i][j] = (table[i+1][j-1] - table[i][j-1]) / (a[i+j] - a[i]);
        }
    }

    double result = table[0][0];
    double product = 1.0;

    for (int i = 1; i < n; i++) {
        product *= (x - a[i-1]);
        result += table[0][i] * product;
    }

    cout << result << endl;

    return 0;
}
