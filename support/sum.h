#include<cmath>
double rho(double p){
    double sum=0;
    if(p>100){
        for(double i=100;i<=p;i+=0.001){
            sum+=0.001/(0.0001*i*i*i-0.001082*i*i+5.474*i+1532);
        }
        return 0.85*pow(2.718281828459,sum);
    }
    else if(p<100){
        for(double i=100;i>=p;i-=0.001){
            sum-=0.001/(0.0001*i*i*i-0.001082*i*i+5.474*i+1532);
        }
        return 0.85*pow(2.718281828459,sum);
    }
    return 0.85;
}