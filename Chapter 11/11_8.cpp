#include <bits/stdc++.h>
using namespace std;
long double k_1=0.194,k_2=0.111,K1=0.31,K2=0.48;
long double Ft;
long double f1(long double V,long double Fa,long double Fb, long double Fc, long double Fd){
    // Ft=Fa+Fb+Fc+Fd;
    return (-2)*k_1*((pow(0.7077,2)*pow(Fa,2)-1/K1*pow(0.7077,2)*Fb*Fc))-k_2*((pow(0.7077,2)*Fa*Fb-pow(0.7077,2)/K2*Fc*Fd));
}
long double f2(long double V,long double Fa,long double Fb, long double Fc, long double Fd){
    // Ft=Fa+Fb+Fc+Fd;
    return k_1*((pow(0.7077,2)*pow(Fa,2)-1/K1*pow(0.7077,2)*Fc*Fb))-k_2*((pow(0.7077,2)*Fa*Fb-pow(0.7077,2)/K2*Fc*Fd));
}
long double f3(long double V,long double Fa,long double Fb, long double Fc, long double Fd){
    // Ft=Fa+Fb+Fc+Fd;
    return k_1*((pow(0.7077,2)*pow(Fa,2)-1/K1*pow(0.7077,2)*Fc*Fb))+k_2*((pow(0.7077,2)*Fa*Fb-pow(0.7077,2)/K2*Fc*Fd));}
long double f4(long double V,long double Fa,long double Fb, long double Fc, long double Fd){
    // Ft=Fa+Fb+Fc+Fd;
    return k_2*((pow(0.7077,2)*Fa*Fb-pow(0.7077,2)/K2*Fc*Fd));
}

int main(){
    
    long double Fa,Fb,Fc,Fd,V;
    Fa=16.67; Fb=0; Fc=0; Fd=0; 
    V=0;
    
    float h=1e-6;
   

    while(Fa>8.335){
        

        long double k1=h*f1(V,Fa,Fb,Fc,Fd);
        long double l1=h*f2(V,Fa,Fb,Fc,Fd);
        long double m1=h*f3(V,Fa,Fb,Fc,Fd);
        long double n1=h*f4(V,Fa,Fb,Fc,Fd);

        // Ft=Fa+k1/2 + Fb +l1/2 + Fc+m1/2 + Fd+n1/2;

        long double k2= h*f1(V+h/2,Fa+k1/2,Fb+l1/2,Fc+m1/2,Fd+n1/2);
        long double l2= h*f2(V+h/2,Fa+k1/2,Fb+l1/2,Fc+m1/2,Fd+n1/2);
        long double m2= h*f3(V+h/2,Fa+k1/2,Fb+l1/2,Fc+m1/2,Fd+n1/2);
        long double n2= h*f4(V+h/2,Fa+k1/2,Fb+l1/2,Fc+m1/2,Fd+n1/2);

        // Ft=Fa+k2/2 + Fb +l2/2 + Fc+m2/2 + Fd+n2/2;

        long double k3= h*f1(V+h/2,Fa+k2/2,Fb+l2/2,Fc+m2/2,Fd+n2/2);
        long double l3= h*f2(V+h/2,Fa+k2/2,Fb+l2/2,Fc+m2/2,Fd+n2/2);
        long double m3= h*f3(V+h/2,Fa+k2/2,Fb+l2/2,Fc+m2/2,Fd+n2/2);
        long double n3= h*f4(V+h/2,Fa+k2/2,Fb+l2/2,Fc+m2/2,Fd+n2/2);

        // Ft=Fa+Fb+Fc+Fd + k3+l3+m3+n3;

        long double k4=h*f1(V+h,Fa+k3,Fb+l3,Fc+m3,Fd+n3);
        long double l4=h*f2(V+h,Fa+k3,Fb+l3,Fc+m3,Fd+n3);
        long double m4=h*f3(V+h,Fa+k3,Fb+l3,Fc+m3,Fd+n3);
        long double n4=h*f4(V+h,Fa+k3,Fb+l3,Fc+m3,Fd+n3);

        long double A1=Fa+1.0/6.0*(k1+2*k2+2*k3+k4);
        long double B1=Fb+1.0/6.0*(l1+2*l2+2*l3+l4);
        long double C1=Fc+1.0/6.0*(m1+2*m2+2*m3+m4);
        long double D1=Fd+1.0/6.0*(n1+2*n2+2*n3+n4);

      

        V+=h;
        Fa=A1;
        Fb=B1;
        Fc=C1;
        Fd=D1;
        // cout<<"Fa="<<Fa<<"Fb="<<Fb<<"Fc="<<Fc<<"Fd="<<Fd<<endl;
    }
    cout<<"V="<<V<<endl;
    cout<<"Fb="<<Fb<<"Fc="<<Fc<<"Fd="<<Fd;

    return 0;

}