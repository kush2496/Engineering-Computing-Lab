#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>

int main()
{
    char outfile[23];
    printf("ENTER FULL OUTPUT FILE NAME FOR PROBLEM 4: ");
	scanf("%s",&outfile);

    FILE *out_file = fopen(outfile,"w");
    double u[2],y_d[2][2],y[2],x[2],y_d_inv[2][2],det,error;
    double max=0.000003,TOL;
    int N,N_max;
    N=1,N_max=1000;
    x[0]=0,x[1]=0,u[0]=0.0,u[1]=0.0;
    TOL=0.000001;

    printf("Iteration No\t\t\tx1\t\t\tx2\t\t\tError\n");
    fprintf(out_file,"Iteration No\t\t\tx1\t\t\tx2\t\t\tError\n");
    while(max>TOL && N<N_max)
    {
        max=0.000000001;
        y[0] =1200*x[0]+50*x[0]*x[0]+200*x[0]*x[1]-100*x[1]*x[1]-500*x[1];
        y[1] =500*x[1]-500*x[0]+100*x[1]*x[1]+100*x[0]*x[0]-200*x[1]*x[0]-350;

        y_d[0][0] = 1200+100*x[0]+200*x[1];
        y_d[0][1] =-200*x[1]+200*x[0]-500;
        y_d[1][0] =-500+200*x[0]-200*x[1];
        y_d[1][1] =500+200*x[1]-200*x[0];

        det=((y_d[0][0])*(y_d[1][1])) - ((y_d[1][0])*(y_d[0][1]));

        y_d_inv[0][0] =y_d[1][1]/det;
        y_d_inv[0][1] =-1*y_d[0][1]/det;
        y_d_inv[1][0] =-1*y_d[1][0]/det;
        y_d_inv[1][1] =y_d[0][0]/det;

        int i,j;
        for(i=0;i<2;i++)
            {   u[i]=0.0;
                for(j=0;j<2;j++)
            {
                u[i]= u[i]+ y_d_inv[i][j]*y[j];
            }
            }

        for(i=0;i<2;i++)
        {
            x[i]=x[i]-u[i];
        }
        for(i=0;i<2;i++)
        {
            error=fabs(u[i]);
            if(error>max)
            {max=error;}
        }



        printf("%d\t\t\t%0.5f\t\t\t%0.5f\t\t\t%E\n",N,x[0],x[1],max);
        fprintf(out_file,"%d\t\t\t%0.5f\t\t\t%0.5f\t\t\t%E\n",N,x[0],x[1],max);
        N=N+1;
    }

}
