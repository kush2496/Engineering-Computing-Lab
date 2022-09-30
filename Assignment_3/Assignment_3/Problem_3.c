#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>


double determinant(double [][3], int);
int main()
{
    char outfile[23];
    printf("ENTER FULL OUTPUT FILE NAME FOR PROBLEM 3: ");
	scanf("%s",&outfile);

    FILE *out_file = fopen(outfile,"w");
    double u[3],y_d[3][3],y[3],x[3],y_d_inv[3][3];
    double error=0.0000000003,TOL;
    int N,N_max;
    N=1,N_max=1000;
    x[0]=0.1,x[1]=0.1,x[2]=-0.1,u[0]=0.0,u[1]=0.0,u[2]=0.0;
    TOL=0.0000000001;

    printf("Iteration No\tx1\t\t\tx2\t\t\tx3\t\t\tError\n");
    fprintf(out_file,"Iteration No\t\tx1\t\t\tx2\t\t\tx3\t\t\tError\n");
    while(error>TOL && N<N_max)
    {
        y[0] =3*x[0] - cos(x[1]*x[2]) -0.5;
        y[1] =x[0]*x[0]-81.0*pow((x[1] + 0.1),2.0) + sin(x[2]) +1.06;
        y[2] =exp(-1*x[1]*x[2]) +20.0*x[2] +(10*22/7 - 3.0)/3.0;

        y_d[0][0] = 3.0;
        y_d[0][1] =x[2]*sin(x[1]*x[2]);
        y_d[0][2] =x[1]*sin(x[1]*x[2]);
        y_d[1][0] =2*x[0];
        y_d[1][1] =-162.0*(x[1] + 0.1);
        y_d[1][2] =cos(x[2]);
        y_d[2][0] = -x[1]*exp(-1*x[0]*x[1]);
        y_d[2][1] = -x[0]*exp(-1*x[0]*x[1]);
        y_d[2][2] =20.0;


 double b[3][3],fac[3][3],c[3][3],d;
 int p, q, m, n, i, j;
 for (q = 0;q < 3; q++)
 {
   for (p = 0;p < 3; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < 3; i++)
     {
       for (j = 0;j < 3; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = y_d[i][j];
            if (n < 1)
             n++;
            else
             {
               n = 0;
               m++;
             }
          }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b,2);
    }
 }

 // transpose and iverse of co factor
    for (i = 0;i < 3; i++)
    {
     for (j = 0;j < 3; j++)
       {
         c[i][j] = fac[j][i];
        }
    }
  d = determinant(y_d, 3);
  for (i = 0;i < 3; i++)
    {
     for (j = 0;j < 3; j++)
       {
        y_d_inv[i][j] = (-1*c[i][j]) / d;
        }
    }
        for(i=0;i<3;i++)
            {   u[i]=0.0;
                for(j=0;j<3;j++)
            {
                u[i]= u[i]+ y_d_inv[i][j]*y[j];
            }
            }
        for(i=0;i<3;i++)
        {
            x[i]=x[i]+u[i];
        }

        double max=-1.0;
        for(i=0;i<3;i++)
        {
            error=fabs(u[i]);
            if(error>max)
            {max=error;}
        }

        printf("%d\t\t%0.5f\t\t\t%0.5f\t\t\t%0.5f\t\t\t%E\n",N,x[0],x[1],x[2],max);
        fprintf(out_file,"%d\t\t%0.5f\t\t\t%0.5f\t\t\t%0.5f\t\t\t%E\n",N,x[0],x[1],x[2],max);
        N=N+1;
        }

}
// Calling function to find out the determinant value of 3x3 matrix
double determinant(double a[3][3],int k)
{
  double s = 1, det = 0, b[3][3];
  int i, j, m, n, c;
  if (k == 1)
    {
     return (a[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = a[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (a[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
    return (det);
}

