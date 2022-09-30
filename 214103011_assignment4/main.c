#include <stdio.h>
#include <stdlib.h>
#include<math.h>


double integrate(double a,double x,float n)
{   double f;
    f=a*pow(x,n+1)/(n+1);
    return(f);
}

double funx(double x)
{   double f;
    f=x*x-1.0;
    return(f);
}

double funy(double x)
{   double f;
    f=x*x+1.0-2.0*x;
    return(f);
}


double wgh(int n,int i)
{
    if(n==2)
        {if(i==1)
            return(1.0);
        if(i==2)
            return(1.0);}
    if(n==3)
        {if(i==1)
            return(0.888889);
        if(i==2)
            return(0.555556);
        if(i==3)
            return(0.555556);}
    if(n==4)
        {if(i==1)
            return(0.652145);
        if(i==2)
            return(0.347855);
        if(i==3)
            return(0.347855);
        if(i==4)
            return(0.652145);}
    if(n==5)
        {if(i==1)
            return(0.568889);
        if(i==2)
            return(0.478629);
        if(i==3)
            return(0.236927);
        if(i==4)
            return(0.236927);
        if(i==5)
            return(0.478629);}
    if(n==6)
        {if(i==1)
            return(0.467914);
        if(i==2)
            return(0.360762);
        if(i==3)
            return(0.171324);
        if(i==4)
            return(0.171324);
        if(i==5)
            return(0.360762);
        if(i==6)
            return(0.467914);}
    if(n==7)
        {if(i==1)
            return(0.417959);
        if(i==2)
            return(0.381830);
        if(i==3)
            return(0.279705);
        if(i==4)
            return(0.129485);
        if(i==5)
            return(0.129485);
        if(i==6)
            return(0.279705);
        if(i==7)
            return(0.381830);}
    if(n==8)
        {if(i==1)
            return(0.362684);
        if(i==2)
            return(0.313707);
        if(i==3)
            return(0.222381);
        if(i==4)
            return(0.101229);
        if(i==5)
            return(0.101229);
        if(i==6)
            return(0.222381);
        if(i==7)
            return(0.313707);
        if(i==8)
            return(0.362684);}
}


double zi(int n,int i)
{
    if(n==2)
        {if(i==1)
            return(0.577350);
        if(i==2)
            return(-0.577350);}
    if(n==3)
        {if(i==1)
            return(0.0);
        if(i==2)
            return(0.774597);
        if(i==3)
            return(-0.774597);}
    if(n==4)
        {if(i==1)
            return(0.339981);
        if(i==2)
            return(0.861136);
        if(i==3)
            return(-0.861136);
        if(i==4)
            return(-0.339981);}
    if(n==5)
        {if(i==1)
            return(0.0);
        if(i==2)
            return(0.538470);
        if(i==3)
            return(0.906180);
        if(i==4)
            return(-0.906180);
        if(i==5)
            return(-0.538470);}
    if(n==6)
        {if(i==1)
            return(0.238620);
        if(i==2)
            return(0.661209);
        if(i==3)
            return(0.932470);
        if(i==4)
            return(-0.932470);
        if(i==5)
            return(-0.661209);
        if(i==6)
            return(-0.238620);}
    if(n==7)
        {if(i==1)
            return(0.0);
        if(i==2)
            return(0.405845);
        if(i==3)
            return(0.741531);
        if(i==4)
            return(0.949108);
        if(i==5)
            return(-0.949108);
        if(i==6)
            return(-0.741531);
        if(i==7)
            return(-0.405845);}
    if(n==8)
        {if(i==1)
            return(0.183435);
        if(i==2)
            return(0.525532);
        if(i==3)
            return(0.796666);
        if(i==4)
            return(0.960290);
        if(i==5)
            return(-0.960290);
        if(i==6)
            return(-0.796666);
        if(i==7)
            return(-0.525532);
        if(i==8)
            return(-0.183435);}
}


int main()
{
   FILE *out_file = fopen("p5.txt","w");
   float bx,ax,by,ay,Xnmax,Ynmax;
   fprintf(out_file,"\n\t\t\t Determination of integral using Gauss Quadrature\n\n");
   printf("Upper integration limit for x\n");
   scanf("%f",&bx);
   printf("Lower integration limit for y\n");
   scanf("%f",&ax);
   printf("Upper integration limit for y\n");
   scanf("%f",&by);
   printf("Lower integration limit for x\n");
   scanf("%f",&ay);
   printf("Highest degree of polynomial function for x variable\n");
   scanf("%f",&Xnmax);
   printf("Highest degree of polynomial function for y variable\n");
   scanf("%f",&Ynmax);
   double FGQ=0.0,EXCT_x=0.0,EXCT_y=0.0,EXCT=0.0,x=0.0,y=0.0,d=0.0,e=0.0,ex=0.0,ey=0.0;
   int i,j,nx,ny;

   //Exact Integral
   EXCT_x = integrate(1.0,bx,2.0) - integrate(1.0,ax,2.0) -(integrate(1.0,bx,0.0)-integrate(1.0,ax,0.0));  //function to integrate = 5x^4 + 3x^2
   EXCT_y = integrate(1.0,by,2.0) - integrate(1.0,ay,2.0) + (integrate(1.0,by,0.0)-integrate(1.0,ay,0.0)) - (integrate(2.0,by,1.0)-integrate(2.0,ay,1.0));
   EXCT = EXCT_x * EXCT_y;
   //Gauss Quadrature

   //highest power of integrable function must be equal to or less than no of unknown in Legendre polynomial
   nx=ceil((Xnmax+1.0)/2.0);
   ny=ceil((Ynmax+1.0)/2.0);


   for(i=1;i<nx;i++)
    for(j=1;j<ny;j++)
    {
     x=zi(nx,i)*(bx-ax)/2.0+(bx+ax)/2.0;
     y=zi(ny,j)*(by-ay)/2.0+(by+ay)/2.0;
     d=wgh(nx,i)*wgh(ny,j);
     ex=funx(x);
     ey=funy(y);
     e=ex*ey;
     FGQ=FGQ+(d*e);
     x=0.0,y=0.0,d=0.0,e=0.0;
    }
    FGQ=(bx-ax)*(by-ay)*FGQ/4.0;
    fprintf(out_file,"Legend Poly nx      ny  \t2-D GaussQuad Value  \tExact Value\n");
    fprintf(out_file,"%d\t\t     %d\t\t%f\t\t%f\n",nx,ny,FGQ,EXCT);
}

