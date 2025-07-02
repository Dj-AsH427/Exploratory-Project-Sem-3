#include<bits/stdc++.h>
using namespace std;
long double f1( long double V, long double Fa){
    return (-1)*1.54*Fa/(0.036-Fa);
}


int main(){
    // vA0 = 5.83e(-4), T as 791 K and P as 2 atm.
    // Reactor volume is to be found.
    // xa=0.35, so final Ca=Fa0(1-xa)=0.0117 mol/s.
    long double V; 
    long double K=0.05; 
    long double h=1e-6; // For precise result
    long double Fa0 = 0.018;
    long double V0=0; //initial value
    while(Fa0>0.0117){     // 35% conversion achieved
    long double K1=h*f1(V0,Fa0);

    long double K2=h*f1(V0+h/2, Fa0+K1/2);
    // long double L2=h*f2(V0+h/2, Fa0+K1/2, Fb0+L1/2);

    long double K3=h*f1(V0+h/2, Fa0+K2/2 );
    // long double L3=h*f2(V0+h/2, Fa0+K2/2, Fb0+L2/2 );

    long double K4=h*f1(V0+h, Fa0+K3);
    // long double L4=h*f2(V0+h, Fa0+K3, Fb0+L3);

    long double Fa=Fa0+1.0/6.0*(K1+2*K2+2*K3+K4);
    // long double Fb=Fb0+1.0/6.0*(L1+2*L2+2*L3+L4);

    V0=V0+h;
    Fa0=Fa; 

    }
    
    cout<<"Volume of reactor = "<<V0;
    return 0;
}