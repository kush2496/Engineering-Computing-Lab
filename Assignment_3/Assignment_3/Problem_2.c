#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>


float fun(float);
float der(float);

int main()
{
    char outfile[15];
    printf("ENTER FULL OUTPUT FILE NAME : ");
	scanf("%s",&outfile);

    FILE *out_file = fopen(outfile,"w");
    float y_0,u,y_d,y,x,R,TOL;
    int N,N_max;
    R=1000,N=1;
    x=1.00,u=0.0;
    R = 1000, TOL=0.000001,N_max=1000;
    y_0 = fun(x);
    y_d = der(x);
    printf("Iteration No    Sqrt value              Error\n");
    fprintf(out_file,"Iteration No    Sqrt value              Error\n");
    while(R>TOL && N<N_max)
    {
        y = fun(x);
        y_d = der(x);
        u = -(y/y_d);
        printf("%d\t\t %f\t\t%f\n",N,x,u);
        fprintf(out_file,"%d\t\t %f\t\t%f\n",N,x,u);

        x=x+u;
        R=fabs(y/y_d);
        N=N+1;
    }


}

float fun(float a)
{
    return(29*a -1.0);
}
float der( float a)
{
    return(29.0);
}
