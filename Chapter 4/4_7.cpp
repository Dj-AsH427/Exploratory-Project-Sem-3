#include <iostream>
#include <cmath>
using namespace std;

double dxdt(double t, double x,double y) {
    return x + 2*y;
}

double dydt(double t, double x,double y){
    return 3*x + 2*y;
}

int main(){
    double t = 0.0, x = 6.0, y = 4.0, h = 0.01;
    double K1, K2, K3, K4, L1, L2, L3, L4;

    while (t<0.2){
    
    K1 = h * dxdt(t,x,y);
    L1 = h * dydt(t,x,y);

    K2 = h * dxdt(t+h/2, x + 0.5 * K1, y + 0.5 * L1);
    L2 = h * dydt(t+h/2, x + 0.5 * K1, y + 0.5 * L1);

    K3 = h * dxdt(t+h/2, x + 0.5 * K2, y + 0.5 * L2);
    L3 = h * dydt(t+h/2, x + 0.5 * K2, y + 0.5 * L2);

    K4 = h * dxdt(t+h, x + K3, y + L3);
    L4 = h * dydt(t+h, x + K3, y + L3);

    t+=h;
    x += (K1 + 2 * K2 + 2 * K3 + K4) / 6.0;
    y += (L1 + 2 * L2 + 2 * L3 + L4) / 6.0;}

    cout << "x(0.2) =" << x << endl;
    cout << "y(0.2) =" << y << endl;

    return 0;
}
