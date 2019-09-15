#include<cstdio>
#include<cmath>
#define TimeLimit 1000
#define GAP 0.01
#define INIT 100
#define V (3.1416*500*25)
#define C 0.85
#define Phigh 160
#define Precision 0.001
#define DIF 0
#define phinit 0.5
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
inline double E(double p)
{
    return (0.0001*p*p*p-0.001082*p*p+5.474*p+1532);
}
inline int delta(double ph, double p)
{
    return (ph >= p);
}
inline double Theta(double t)
{
    return (omege*t+3.14-6.28*(int)((omege*t+3.14)/6.28));
}
inline double R(double theta)
{
    return (4.826+2.413*sin(theta+1.5708));
}
double Vh(double t)
{
    return (20+(7.239-R(Theta(t)))*3.1416*2.5*2.5);
}
double h(double t)
{
    double temp = t - ((int)(t/50))*50;
    if(temp < 0.3309)
    {
        return (0.5342*temp*temp-0.04835*temp+0.000726)/(temp*temp-0.7362*temp+0.1716);
    }
    else if(temp >= 0.3309 && temp <= 2.1213)
    {
        return 1.1532;
    }
    else if(temp > 2.1213 && temp < 2.45)
    {
        return (0.5358*temp*temp-2.576*temp+3.096)/(temp*temp-4.163*temp+4.368);
    }
    else
    {
        return 0;
    }
}
double B(double t)
{
    return 3.1416*((1.25+h(t)*0.1584)*(1.25+h(t)*0.1584)-1.25*1.25);
}
double Qout(double t, double p)
{
    return (0.85*B(t)*sqrt(2*p/rho(p)));
}
double p()//for question 2
{
    double t = 0;
    double press = INIT;
    double pressh = phinit;
    // printf("%f\n%f\n",t,press);
    while (t < TimeLimit)
    {
        // printf("press=%f\t",press);
        t += GAP;
        if(omege*t/6.2832-(int)(omege*t/6.2832) < 0.001 && omege*t/6.2832-(int)(omege*t/6.2832) > -0.001)
        {
            pressh = phinit;
        }
        // printf("Qout = %f\t",Qout(t,press));//喷油
        if(delta(pressh,press))
        {
            // printf("inittime = %f\tpressh = %f\tpress = %f\n",t,pressh,press);
            pressh = pressh + (GAP*E(pressh)/Vh(t))*(-0.85*3.1416*0.49*sqrt(2*(pressh - press)/rho(pressh))*(rho(press)/rho(pressh)) - (Vh(t) - Vh(t - GAP))/GAP);
            if(delta(pressh,press))
            {
                press = press + (GAP*E(press)/V)*(0.85*3.1416*0.49*sqrt(2*(pressh - press)/rho(pressh)) - Qout(t,press));        
            }
            else
            {
                press = press + (GAP*E(press)/V)*( - Qout(t,press));
            }    
        }
        else
        {
            pressh = pressh + (GAP*E(pressh)/Vh(t))*( - (Vh(t) - Vh(t - GAP))/GAP);
            press = press + (GAP*E(press)/V)*( - Qout(t,press));
        }
        // printf("time = %f\tpressh = %f\tpress = %f\n",t,pressh,press);
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
    omege = start + (end - start)/2;
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
    // printf("%f",(GAP*E(102)/V)*( - Qout(57,102)) );
    binarysearch(0.03,0.1);

    return 0;
}