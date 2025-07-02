#include <iostream>
#include <cmath>
using namespace std;

long double f1_func(long double x1, long double x2){
    long double Num=(x1-x2)*pow((3*x1+x2),3);
    long double Deno=(1-x1)*(5-x1-x2)*pow((6+2*x1),2);
    return((Num/Deno)-0.574);
}

long double f2_func(long double x1, long double x2){
    long double Num=x2*(3*x1+x2);
    long double Deno=(x1-x2)*(5-x1-x2);
    return((Num/Deno)-2.21);
}

long double df1dx1(long double x1, long double x2){
    long double num1=(12*x1-8*x2)*pow((3*x1+x2),2);
    long double deno1=(1-x1)*(5-x1-x2)*pow((6+2*x1),2);
    long double num2=(x1-x2)*pow((3*x1+x2),3)*(8*pow(x1,2)+6*x1*x2-24*x1+2*x2-16);
    long double deno2=pow((1-x1),2)*pow((5-x1-x2),2)*pow((6+2*x1),3);
    return((num1/deno1)-(num2/deno2));
}

long double df1dx2(long double x1, long double x2){
    long double num1=(3*(x1-x2)*pow((3*x1+x2),2))-pow((3*x1+x2),3);
    long double deno1=(1-x1)*(5-x1-x2)*pow((6+2*x1),2);
    long double num2=(x1-x2)*pow((3*x1+x2),3);
    long double deno2=(1-x1)*pow((5-x1-x2),2)*pow((6+2*x1),2);
    return((num1/deno1)+(num2/deno2));
}

long double df2dx1(long double x1, long double x2){
    long double num1=3*x2;
    long double deno1=(x1-x2)*(5-x1-x2);
    long double num2=x2*(3*x1+x2)*(5-2*x1);
    long double deno2=pow((x1-x2),2)*pow((5-x1-x2),2);
    return ((num1/deno1)-(num2/deno2));
}

long double df2dx2(long double x1, long double x2){
    long double num1=3*x1+2*x2;
    long double deno1=(x1-x2)*(5-x1-x2);
    long double num2=x2*(3*x1+x2)*(2*x2-5);
    long double deno2=pow((x1-x2),2)*pow((5-x1-x2),2);
    return ((num1/deno1)-(num2/deno2));
}

int main(){
    long double x1, x2, x1_new, x2_new, f1, f2, df1_dx1, df1_dx2, df2_dx1, df2_dx2;
    long double D, Delta_x1, Delta_x2;
    unsigned long long n=0;
    x1=0.5;
    x2=1;
    n=0;
    const long double error = 1e-6; // Tolerance for convergence

    // f1 = f1_func(x1, x2); 
    // f2 = f2_func(x1, x2); 

    long long diff1=1,diff2=1;

    while(abs(diff1) > error || abs(diff2) > error){
        

        f1=f1_func(x1,x2);
        f2=f2_func(x1,x2);
        df1_dx1=df1dx1(x1,x2);
        df1_dx2=df1dx2(x1,x2);
        df2_dx1=df2dx1(x1,x2);
        df2_dx2=df2dx2(x1,x2);

        D=(df1_dx1*df2_dx2)-(df1_dx2*df2_dx1);
        if (D == 0) {
            cout << "Determinant is zero, no solution exists." << endl;
            return -1;
        }
        Delta_x1=((f2*df1_dx2)-(f1*df2_dx2))/D;
        Delta_x2=((f1*df2_dx1)-(f2*df1_dx1))/D;
        x1_new=x1+Delta_x1;
        x2_new=x2+Delta_x2;
        n++;

        diff1=x1_new-x1;
        diff2=x2_new-x2;

        x1=x1_new;
        x2=x2_new;


    }
    cout << "x1 = " << x1_new << endl;
    cout << "x2 = " << x2_new << endl;
    cout<<"No. of iterations = "<<n;
    return 0;
}