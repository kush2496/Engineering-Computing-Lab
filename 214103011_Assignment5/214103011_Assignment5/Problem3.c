#include <stdio.h>
#include <stdlib.h>
#include<math.h>

double fun1(float a,float b,float c)
{
    float f;
    f=(3*b-a*c-20*a-5*a*a)/3.0;
    return(f);
}
double fun2(float c)
{
    return(c);
}

double g1(float a)
{
    return(a*a*a+5*a*a+19*a+10);
}

double g2(float a)
{
    return(3*a*a+10*a+19.0);
}

int main()
{
FILE *out_file1 = fopen("Problem3_1.txt","w");
FILE *out_file2 = fopen("Problem3_2.txt","w");
fprintf(out_file2,"N\t\tEy_L2\t\tEy'_L2\n");
int p=1;


while(p==1)
{
int i,N;
float a,b,h,esum1=0.0,esum2=0.0;

a=0.0;
b=5.0;
printf("No of intervals\n");
scanf("%d",&N);
h=(b-a)/N;
float x[N+1];
x[0]=a;
x[N]=b;

//RK-4 Method
float k1,k2,k3,k4,l1,l2,l3,l4;
esum1=0.0;
esum2=0.0;
float y[N+1],u[N+1];
y[0]=10;
u[0]=19;
float L2_norm1,L2_norm2;
for(i=0;i<N;i++)
{
    k1=h*fun1(x[i],y[i],u[i]);
    l1=h*fun2(y[i]);
    k2=h*fun1(x[i]+(h/2),y[i]+(k1/2),u[i]+(l1/2));
    l2=h*fun2(y[i]+(k1/2));
    k3=h*fun1(x[i]+(h/2),y[i]+(k2/2),u[i]+(l2/2));
    l3=h*fun2(y[i]+(k2/2));
    k4=h*fun1(x[i]+h,y[i]+k3,u[i]+l3);
    l4=h*fun2(y[i]+k3);
    u[i+1]=u[i] +(k1+2*k2+2*k3+k4)/6;
    y[i+1]=y[i] +(l1+2*l2+2*l3+l4)/6;
    x[i+1]=x[i]+h;
    esum1=esum1+pow((g1(x[i]) - y[i+1]),2);
    esum2=esum2+pow((g2(x[i]) - u[i+1]),2);
}
L2_norm1=sqrt(esum1)/N;
L2_norm2=sqrt(esum2)/N;
fprintf(out_file1,"\t\t\t\tNo of intervals : %d\t\t\t\t\n",N);
fprintf(out_file1,"x\t\tAnalytic y(x)\t\tRK4 y(x)\t\t Analytic u(x)\t\tRK4 u(x)\n");
fprintf(out_file2,"%d\t\t%f\t%f\n",N,L2_norm1,L2_norm2);
float g,f;
for(i=0;i<N;i++)
{
g=g1(x[i]);
f=g2(x[i]);

fprintf(out_file1,"%f\t%f\t\t%f\t\t%f\t\t%f\n",x[i],g,y[i],f,u[i]);
}
printf("Do you want to continue for another interval? (y:1/n:0):\n");
scanf("%d",&p);
}

}



