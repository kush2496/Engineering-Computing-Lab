#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()

{

    FILE *out;
    out=fopen("Table_1","w");

    int imax,jmax,i,j,n=0,Re=400;
    float dx=(1/129),dy =(1/129),error=10.0,errormax =0.0001,pi=(22.0/7.0);

    printf("Input the maximum value of grid point along x :");
    scanf("%d",&imax);
    printf("\nInput the maximum value of grid point along y :");
    scanf("%d",&jmax);
    //printf("\nInput the maximum value of error acceptable:");
    //scanf("%f",&errormax);
    //printf("\nInput the value of step size along x:");
    //scanf("%f",&dx);
    //printf("\nInput the value of step size along y:");
    //scanf("%f",&dy);

    float Y[imax][jmax],W[imax][jmax];
    for(i=2;i<=imax-1;i++)
        {W[i][jmax]=-(2/dy);}
    for(i=1;i<=imax;i++)
        for(j=1;j<=jmax;j++)
    {
        Y[i][j] =0;
        if(i!=2&&j!=jmax)
            W[i][j] = -(2/dy)*(j/jmax);
    }


    printf("\n\n\n                    Gaus Siedel Iterations begin                      ");
  //  printf("\nBC values at start of Gaus Siedel of TGS1_1:%f,  TGS21_35:%f",W[0][0],W[imax-1][34]);

   // printf("\nInitial values at start of Gaus Siedel of TGS3_3:%f",TGS[2][2]);

    while(error>=errormax)
    {error=0;

        while(n<6)
            for(i=2;i<=(imax-1);i++)
                for(j=2;j<=(jmax-1);j++)
                {
                     Y[i][j] = Y[i+1][j] + Y[i-1][j] + Y[i][j+1] +Y[i][j-1]+ W[i][j]*dx*dx;
                     n=n+1;
                }
            for(j=2;j<=(jmax-1);j++)
                W[1][j] = -2*Y[2][j]/(dx*dx);
            for(j=2;j<=(jmax-1);j++)
                W[imax][j] = -2*Y[imax-1][j]/(dx*dx);
            for(i=2;i<=(imax-1);i++)
                W[i][1] =-2*Y[i][2]/(dy*dy);
            for(i=2;i<=(imax-1);i++)
                W[i][jmax-1] = -(2*Y[i][jmax-1] + 2*dy)/(dy*dy);
        n=0;
        while(n<3)
            for(i=2;i<=(imax-1);i++)
                for(j=2;j<=(jmax-1);j++)
                {
                    error=fabs(W[i][j] = (W[i+1][j]+W[i-1][j]+W[i][j+1]+W[i][j-1] -0.25*Re*(W[i+1][j] -W[i-1][j])*(Y[i][j+1]-Y[i][j-1])+0.25*Re*(W[i][j+1] - W[i][j-1])*(Y[i+1][j] -Y[i-1][j]))/4 - W[i][j])/fabs(W[i][j] = (W[i+1][j]+W[i-1][j]+W[i][j+1]+W[i][j-1] -0.25*Re*(W[i+1][j] -W[i-1][j])*(Y[i][j+1]-Y[i][j-1])+0.25*Re*(W[i][j+1] - W[i][j-1])*(Y[i+1][j] -Y[i-1][j]))/4);
                    W[i][j] = (W[i+1][j]+W[i-1][j]+W[i][j+1]+W[i][j-1] -0.25*Re*(W[i+1][j] -W[i-1][j])*(Y[i][j+1]-Y[i][j-1])+0.25*Re*(W[i][j+1] - W[i][j-1])*(Y[i+1][j] -Y[i-1][j]))/4;
                    n=n+1;
                }
    }
   // printf("\nNo of iterations for Gauss siedel to converge: %d\n",iteration);

}

