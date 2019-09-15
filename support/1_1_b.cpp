#include<cstdio>
#include<cmath>
#define filename "data.out"
#define TimeLimit 100000
#define INIT 100
#define V (3.1416*500*25)
#define C 0.85
#define Phigh 160
#define Precision 0.0001
#define DIF 0
#define dotsnum 100000
#define startpaint 0

double T = 0.2922,xwcin=0,xwcout=0,GAP=0.005;
double A(double t)
{
    double temp = t+xwcin-(double)((int)((t+xwcin)/(T+10)))*(T+10);
    if(temp <= T){
        return (0.49*3.1416);
    }
    else return 0;
}
double Qout(double t)
{
    double temp = t+xwcout-(double)((int)((t+xwcout)/(100)))*(100);
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
    //xwcin=T;
    double t = 0;
    double press = INIT;
    while (t < 97.6+100*(int)((TimeLimit-97.6)/100))
    {
        if(press > Phigh)press = Phigh;
        press = press + ((A(t)*C*sqrt(2*(Phigh-press)/0.87113)-Qout(t))/V)*GAP*(0.0001*press*press*press-0.001082*press*press+5.474*press+1532);
        t += GAP;
    }
    return (press - INIT);
}
double paintp()
{
    //xwcin=T;
    unsigned long long int longgap=(TimeLimit-startpaint)/GAP/dotsnum;
    unsigned long long int now=0;
    double t = 0;
    double press = INIT;
    while (t < 97.6+100*(int)((TimeLimit-97.6)/100))
    {
        if(press > Phigh)press = Phigh;
        press = press + ((A(t)*C*sqrt(2*(Phigh-press)/0.87113)-Qout(t))/V)*GAP*(0.0001*press*press*press-0.001082*press*press+5.474*press+1532);
        t += GAP;
        if(t>=startpaint){
        if(now==0){
        printf("%f %f\n",t,press);now=longgap;}
        else now--;}
    }
    double endpress=press;
    while(t<TimeLimit){
        if(endpress > Phigh)endpress = Phigh;
        endpress = endpress + ((A(t)*C*sqrt(2*(Phigh-endpress)/0.87113)-Qout(t))/V)*GAP*(0.0001*endpress*endpress*endpress-0.001082*endpress*endpress+5.474*endpress+1532);
        t += GAP;
        if(t>=startpaint){
        if(now==0){
        printf("%f %f\n",t,endpress);now=longgap;}
        else now--;}
    }
    printf("%f %f\n",t,endpress);
    printf("%f\n\n",T);
    return (press - INIT);
}
void binarypaintsearch(double start, double end)
{
    if (end - start < Precision)
    {
        return;
    }
    T = start + (end - start)/2;
    double mid=0;
    if(512*Precision<end - start&&end - start < Precision*1024)
    mid = paintp();
    else if(256*Precision<end - start&&end - start < Precision*512)
    mid = paintp();
    else if(128*Precision<end - start&&end - start < Precision*256)
    mid = paintp();
    else if(end - start < Precision*2)
    mid = paintp();
    else mid = p();
    if(mid - DIF > 0){
        binarypaintsearch(start, start + (end - start)/2);
    }
    else
    {
        binarypaintsearch(start + (end - start)/2, end);
    }
}
int main()
{
    freopen(filename,"w",stdout);
    xwcout=2.4;
    binarypaintsearch(0.1,1);
    return 0;
}