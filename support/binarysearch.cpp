#include<cstdio>
#include<cmath>
#define TimeLimit 10000
#define GAP 0.00001
#define INIT 100
#define V (3.1416*500*25)
#define C 0.85
#define Phigh 160
#define Precision 0.001
#define DIF 50
// #define INF 
double T = 0.3;
double A(double t)
{
    double temp = t-(double)((int)(t/(T+10)))*(T+10);
    if(temp <= T){
        return (0.49*3.1416);
    }
    else return 0;
}
double Qout(double t)
{
    double temp = t-(double)((int)(t/(100)))*(100);
    // printf("%f",temp);
    if(temp <= 0.2)
    {
        return 100*temp;
    }
    else if(temp >0.2 && temp < 2.2)
    {
        return 20;
    }
    else if(temp >= 2.2 && temp <= 2.4)
    {
        return temp*(-100)+240;
    }
    else return 0;
}
double p()
{
    double t = 0;
    double press = INIT;
    while (t < TimeLimit)
    {
        // printf("press=%f\t",press);
        if(press > Phigh)press = Phigh;
        press = press + ((C*A(t)*sqrt(2*(Phigh-press)/0.87113)-Qout(t))/V)*GAP*(0.0001*press*press*press-0.001082*press*press+5.474*press+1532);
        t += GAP;
    }
    return (press - INIT);
}
void binarysearch(double start, double end)
{
    printf("search[%f,%f]\t",start,end);
    if (end - start < Precision)
    {
        printf("found the solution : %f",end);
        return;
    }
    T = start + (end - start)/2;
    double mid = p();
    printf("mid p=%f\n",mid);
    if(mid - DIF > 0){
        binarysearch(start, start + (end - start)/2);
    }
    else
    {
        binarysearch(start + (end - start)/2, end);
    }
}
int main()
{
    // printf("%f",Qout(63));
    binarysearch(0.1,1);
    return 0;
}