#include <iostream>
#include <cmath>
using namespace std;
double K;
// Define the differential equation dCa/dt = -K*Ca
double dydx(double t0, double Ca) {
    return (-1)*K*Ca;
}

// Runge-Kutta 4th order method
double rungeKutta(double Ca0, double t0, double t, double h) {
    double Cinit=Ca0;
    while(t>t0) {
        double k1, k2, k3, k4;
        k1 = h * dydx(t0, Ca0);
        k2 = h * dydx(t0 + 0.5*h, Ca0+0.5 * k1);
        k3 = h * dydx(t0 + 0.5*h, Ca0+0.5 *k2);
        k4 = h * dydx(t0 + h, Ca0 + k3);

        Ca0 = Ca0 + (k1 + 2*k2 + 2*k3 + k4)/6.0;
        
        if (fabs(t0 - 1) < 1e-4 || fabs(t0 - 2) < 1e-4 || fabs(t0 - 3) < 1e-4 || fabs(t0 - 5) < 1e-4 || fabs(t0 - 10) < 1e-4) {
            cout << "At t = " << t0 << " s, Ca = " << Ca0 << " and analytical solution is: " << Cinit * exp((-1)*K * t0) << endl;
        }
        t0 = t0 + h;
    }
    return Ca0;
}

int main() {
    // Single Ordinary Differential Equation

    double Ca0, t0, t, h;
    
    cout << "Enter initial value t0: ";
    cin >> t0;
    cout << "Enter initial value Ca0: ";
    cin >> Ca0;
    cout << "Enter the final t: ";
    cin >> t;
    cout << "Enter the step size h: ";
    cin >> h;
    cout << "Enter the rate constant K: ";
    cin >> K;

    double Caf = rungeKutta(Ca0, t0, t, h);
    cout << "NUMERICAL SOLUTION: The value of Ca at t = " << t << " is " << Caf << endl;
    cout << "ANALYTICAL SOLUTION: The value of Ca at t = "<< t << " is " << Ca0*exp(-K*t) << endl;
    return 0;
}