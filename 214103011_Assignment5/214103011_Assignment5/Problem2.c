#include <stdio.h>
#include <stdlib.h>
#include<math.h>

double fun1(float a,float b)
{
    float f;
    f=a*b +a;
    return(f);
}
double fun2(float a,float b)
{
    float f;
    f=-2*exp(a)/b;
    return(f);
}

double g1(float a)
{
    return(a*a*exp(a));
}

double g2(float b)
{
    return(2/b);
}

int main()
{
FILE *out_file1 = fopen("Problem2_1.txt","w");
FILE *out_file2  = fopen("Problem2_2.txt","w");
int p=1,i,N;
fprintf(out_file2  ,"N\t\tEy_L2\t\t\tEz_L2\n");
float e,a,b,h,esum1=0.0,esum2=0.0;
while(p==1)
{
a=1.0;
b=5.0;
e=2.718282;
printf("No of intervals\n");
scanf("%d",&N);
h=(b-a)/N;
float x[N+1];
x[0]=a;
x[N]=b;


/*
//Euler Method
float y1[N+1],z1[N+1];
y1[0]=e;
z1[0]=2;
float L2_norm11,L2_norm21;
for(i=0;i<N;i++)
{
    y1[i+1]=y1[i] + h*fun1(y1[i],z1[i]);
    z1[i+1]=z1[i] + h*fun2(x[i],y1[i]);
    x[i+1]=x[i] +h;
    esum1=esum1+pow((g1(x[i]) - y1[i+1]),2);
    esum2=esum2+pow((g2(x[i]) - z1[i+1]),2);
}
L2_norm11=sqrt(esum1)/N;
L2_norm21=sqrt(esum2)/N;

//Mid-Point Method
float y2[N+1],z2[N+1];
y2[0]=e;
z2[0]=2;
float L2_norm12,L2_norm22;
y2[1]=y2[0] + h*fun1(y2[0],z2[0]);
z2[1]=z2[0] + h*fun2(x[0],y2[0]);
esum1=0.0;
esum2=0.0;
for(i=1;i<N;i++)
{
    y2[i+1]=y2[i] + h*fun1(y2[i],z2[i]);
    z2[i+1]=z2[i] + h*fun2(x[i],y2[i]);
    esum1=esum1+pow((g1(x[i]) - y2[i+1]),2);
    esum2=esum2+pow((g2(x[i]) - z2[i+1]),2);
}
L2_norm12=sqrt(esum1)/N;
L2_norm22=sqrt(esum2)/N;

//RK-2 Method
float y3[N+1],z3[N+1];
y3[0]=e;
z3[0]=2;
float L2_norm13,L2_norm23;
float k1,k2,l1,l2;
esum1=0.0;
esum2=0.0;
for(i=0;i<N;i++)
{

    k1=h*fun1(y3[i],z3[i]);
    l1=h*fun2(x[i],y3[i]);
    k2=h*fun1(y3[i]+k1,z3[i]+l1);
    y3[i+1]=y3[i] +0.5*(k1+k2);
    l2=h*fun2(x[i+1],y3[i]+k1);
    z3[i+1]=z3[i] +0.5*(l1+l2);
    esum1=esum1+pow((g1(x[i]) - y3[i+1]),2);
    esum2=esum2+pow((g2(x[i]) - z3[i+1]),2);
    }
L2_norm13=sqrt(esum1)/N;
L2_norm23=sqrt(esum2)/N;

*/


//RK-4 Method
float k1,k2,l1,l2,k3,k4,l3,l4;
esum1=0.0;
esum2=0.0;
float y4[N+1],z4[N+1];
y4[0]=e;
z4[0]=2;
float L2_norm14,L2_norm24;
for(i=0;i<N;i++)
{
    x[i+1]=x[i] +h;
    k1=h*fun1(y4[i],z4[i]);
    l1=h*fun2(x[i],y4[i]);
    k2=h*fun1(y4[i]+(k1/2),z4[i]+(l1/2));
    l2=h*fun2(x[i]+(h/2),y4[i]+(k1/2));
    k3=h*fun1(y4[i]+(k2/2),z4[i]+(l2/2));
    l3=h*fun2(x[i]+(h/2),y4[i]+(k2/2));
    k4=h*fun1(y4[i]+k3,z4[i]+l3);
    l4=h*fun2(x[i+1],y4[i]+k3);
    y4[i+1]=y4[i] +(k1+2*k2+2*k3+k4)/6;
    z4[i+1]=z4[i] +(l1+2*l2+2*l3+l4)/6;
    esum1=esum1+pow((g1(x[i]) - y4[i+1]),2);
    esum2=esum2+pow((g2(x[i]) - z4[i+1]),2);
}
L2_norm14=sqrt(esum1)/N;
L2_norm24=sqrt(esum2)/N;
fprintf(out_file1 ,"\t\t\t\t No of intervals: %d\n",N);
fprintf(out_file1,"x\t\tAnalytical y(x)\t\tRK4 y(x)\t\tAnalytical z(x)\t\tRK4 z(x)\n");

fprintf(out_file2 ,"%d\t\t%f\t\t%f\n",N,L2_norm14,L2_norm24 );
float g,f;
for(i=0;i<N;i++)
{
g=g1(x[i]);
f=g2(x[i]);
fprintf(out_file1 ,"%f\t%f\t\t%f\t\t%f\t\t%f\n",x[i],g,y4[i],f,z4[i]);
}
printf("Do you want to change the interval?: (yes:1/no:0)");
scanf ("%d",&p);
}
}



