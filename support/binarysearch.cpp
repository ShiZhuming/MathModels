#include<cstdio>
#include<cmath>
#define TimeLimit 1000
#define GAP 0.0001
#define INIT 150
#define V (3.1416*500*25)
#define C 0.85
#define Phigh 160
#define Precision 0.001
#define DIF 0
double omege = 20;
// #define INF 
/*//this part for question 1
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
    // printf("%f\n%f\n",t,press);
    while (t < TimeLimit)
    {
        // printf("press=%f\t",press);
        if(press > Phigh)press = Phigh;
        press = press + ((C*A(t)*sqrt(2*(Phigh-press)/0.87113)-Qout(t))/V)*GAP*(0.0001*press*press*press-0.001082*press*press+5.474*press+1532);
        t += GAP;
        // printf("%f\n%f\n",t,press);
    }
    return (press - INIT);
}
*/
inline int delta(double ph, double p)
{
    return (ph >= p);
}
inline double Theta(double t)
{
    return (omege*r+3.14-6.28*(int)((omege*t+3.14)/6.28));
}
inline double R(double theta)
{
    return (4.826+2.413*sin(theta+1.5708));
}
double Vh(double t)
{
    return (20+(7.239-R(Theta(t)))*3.1416*2.5*2.5);
}

double p()//for question 2
{
    double t = 0;
    double press = INIT;
    // printf("%f\n%f\n",t,press);
    while (t < TimeLimit)
    {
        // printf("press=%f\t",press);
        if(press > Phigh)press = Phigh;
        press = press + ((C*A(t)*sqrt(2*(Phigh-press)/0.87113)-Qout(t))/V)*GAP*(0.0001*press*press*press-0.001082*press*press+5.474*press+1532);
        t += GAP;
        // printf("%f\n%f\n",t,press);
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
    
    // freopen("dataof1.out","w",stdout);
    // printf("%f",Qout(63));
    binarysearch(0.3,1);
    return 0;
}