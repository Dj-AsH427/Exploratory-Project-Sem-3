#include <iostream>
#include <cmath>
using namespace std;

// Define the differential equation dy/dx = x + y
double dydx(double x, double y) {
    return (x+y);
}

// Runge-Kutta 4th order method
double rungeKutta(double x0, double y0, double x, double h) {
    int n = (int)((x - x0) / h);
    double k1, k2, k3, k4, y = y0;

    for (int i = 0; i < n; i++) {
        k1 = h * dydx(x0, y);
        k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * dydx(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * dydx(x0 + h, y + k3);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
    }

    return y;
}

int main() {
    double x0, y0, x, h;
    cout << "Enter the initial values of x and y: ";
    cin >> x0 >> y0;
    cout << "Enter the final value of x: ";
    cin >> x;
    cout << "Enter the step size h: ";
    cin >> h;

    double result = rungeKutta(x0, y0, x, h);
    cout << "The value of y at x = " << x << " is " << result << endl;
    cout << "The analytical solution at x = " << x << " is " << exp(x) - x - 1 << endl;
    return 0;
}