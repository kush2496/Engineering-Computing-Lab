#include <stdio.h>
#include <stdlib.h>
#include<math.h>

double fun(float a,float b)
{
    float f;
    f=a*a +2*b/a;
    return(f);
}

double g(float a)
{
    return(a*a*a+5*a*a);
}

int main()
{
FILE *out_file1 =fopen("Problem1_1.txt","w");
FILE *out_file2 =fopen("Problem1_2.txt","w");
fprintf(out_file2 ,"N\t\tEuler\t\t\tMidpoint\t\tRK2\t\t\tRK4\n");
int i,N,p=1;
float a,b,h,esum=0.0;

while(p==1)
{
a=1.0;
b=6.0;
printf("No of intervals\n");
scanf("%d",&N);
h=(b-a)/N;
float x[N+1],y1[N+1],y2[N+1],y3[N+1],y4[N+1],L2_norm1,L2_norm2,L2_norm3,L2_norm4;
y1[0]=6;
x[0]=a;
x[N]=b;

//Euler Method

for(i=0;i<N;i++)
{
    y1[i+1]=y1[i] + h*fun(x[i],y1[i]);
    x[i+1]=x[i] +h;
    esum=esum+pow((g(x[i]) - y1[i+1]),2);
}
L2_norm1 =sqrt(esum)/N;

//Mid-Point Method

y2[0]=6.0;
y2[1]=y2[0]+h*fun(x[0],y2[0]);
esum=0.0;
L2_norm2=0.0;
for(i=1;i<N;i++)
{
    y2[i+1]=y2[i-1] + 2*h*fun(x[i],y2[i]);
    esum=esum+pow((g(x[i]) - y2[i+1]),2);
}
L2_norm2 =sqrt(esum)/N;

//RK-2 Method
float k1,k2;
y3[0]=6.0;
esum=0.0;
for(i=0;i<N;i++)
{
    k1=h*fun(x[i],y3[i]);
    k2=h*fun(x[i+1],y3[i]+k1);
    y3[i+1]=y3[i] +0.5*(k1+k2);
    esum=esum+pow((g(x[i]) - y3 [i+1]),2);
}
L2_norm3 =sqrt(esum)/N;


//RK-4 Method
float k3,k4;
y4[0]=6.0;
esum=0.0;
for(i=0;i<N;i++)
{
    k1=h*fun(x[i],y4[i]);
    k2=h*fun(x[i]+(h/2),y4[i]+(k1/2));
    k3=h*fun(x[i]+(h/2),y4[i]+(k2/2));
    k4=h*fun(x[i+1],y4[i]+k3);
    y4[i+1]=y4[i] +(k1+2*k2+2*k3+k4)/6;
    esum=esum+pow((g(x[i]) - y4 [i+1]),2);
}
L2_norm4 =sqrt(esum)/N;
float j;
fprintf(out_file1 ,"\t\t\t\t No of intervals: %d\n",N);
fprintf(out_file1,"x\t\tAnalytical\t\tEuler\t\tMidpoint\t\tRK2\t\tRK4\n");
for(i=0;i<N;i++)
{
j=g(x[i]);
fprintf(out_file1 ,"%f\t%f\t\t%f\t%f\t\t%f\t%f\n",x[i],j,y1[i],y2[i],y3[i],y4[i]);
}

fprintf(out_file2 ,"%d\t\t%f\t\t%f\t\t%f\t\t%f\n",N,L2_norm1,L2_norm2,L2_norm3,L2_norm4 );

printf("Do you want to change the interval?: (yes:1/no:0)");
scanf ("%d",&p);

}

}



