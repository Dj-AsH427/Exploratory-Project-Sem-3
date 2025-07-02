
#include <bits/stdc++.h>
using namespace std;

// Define constants
const long double R=8.314;        // Gas constant J/(mol·K)
const long double P=1.6e5;        // Pressure in Pa (1.6 atm)
const long double Fa_init=0.0376; // Initial molar flow rate of A (mol/s)
const long double T_init=1035;    // Initial temperature in K
const long double V0_init=0.0;    // Initial volume (m^3)
const long double V_max=4.0e-3;   // Final volume (m^3)
const long double h=1.0e-5;       // Step size for volume (m^3)
const long double U =110;          // Overall Heat transfer coefficient (W/m^2·K)
const long double D =0.0254;       // Reactor diameter (m)
long double flowrate(long double Fa,long double T) {
return (-19499.64)*(Fa/(T*(0.0752-Fa)))*exp(34.34 - 34222 / T);
}
long double temp(long double Fa,long double T) {
long double dfA_dV = flowrate(Fa, T);
return ((80770) / (9 * Fa + 5.7904)) * dfA_dV;
}
long double temp2(long double Fa, long double T) {
long double dfA_dV = flowrate(Fa, T);
return (((80770)*dfA_dV + (17322.83)*(1150-T))/(9 * Fa + 5.7904));
}

int main() {
long double Fa = Fa_init;
long double T = T_init;
long double V0 = V0_init;
int flag;
cout<<"ENTER 1 FOR ADIABATIC 0 FOR HEAT TRANSFER(THROUGH HEAT EXCHANGER)"<<endl;
cin>>flag;
if(flag){

while (V0 < V_max) {
long double k1 = h * flowrate(Fa, T);
long double T1 = h * temp(Fa, T);

long double k2 = h * flowrate(Fa + k1 / 2, T + T1 / 2);
long double T2 = h * temp(Fa + k1 / 2, T + T1 / 2);

long double k3 = h * flowrate(Fa + k2 / 2, T + T2 / 2);
long double T3 = h * temp(Fa + k2 / 2, T + T2 / 2);

long double k4 = h * flowrate(Fa + k3, T + T3);
long double T4 = h * temp(Fa + k3, T + T3);

long double Fa1 = Fa + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
long double Tf1 = T + 1.0 / 6.0 * (T1 + 2 * T2 + 2 * T3 + T4);

V0 += h;
Fa = Fa1;
T = Tf1;
}
cout<<"Adiabatic Conditons"<<endl;
cout << "Fa="<<Fa<<"mol/s" << endl;
cout << "T="<<T <<"K"<< endl;
}else{
long double V_max2=1.0e-3;
while (V0 < V_max2) {
long double k1 = h * flowrate(Fa, T);
long double T1 = h * temp2(Fa, T);
long double k2 = h * flowrate(Fa + k1 / 2, T + T1 / 2);
long double T2 = h * temp2(Fa + k1 / 2, T + T1 / 2);
long double k3 = h * flowrate(Fa + k2 / 2, T + T2 / 2);
long double T3 = h * temp2(Fa + k2 / 2, T + T2 / 2);
long double k4 = h * flowrate(Fa + k3, T + T3);
long double T4 = h * temp2(Fa + k3, T + T3);

long double Fa1 = Fa + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
long double Tf1 = T + 1.0 / 6.0 * (T1 + 2 * T2 + 2 * T3 + T4);

V0 += h;
Fa = Fa1;
T = Tf1;
}
cout<<"Heat Transfer Conditons"<<endl;
cout << "Fa="<<Fa<<"mol/s" << endl;
cout << "T="<<T <<"K"<< endl;
}

return 0;
}