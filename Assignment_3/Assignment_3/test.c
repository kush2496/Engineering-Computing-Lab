#include <stdio.h>
#include <stdlib.h>


double det_multiply(double [][3],double [3]);


int main()
{
  float a[25][25],b[3],(*s)[3],k, d;
  int i, j;
  b[0]=3,b[1]=2,b[2]=7;
  printf("Enter the order of the Matrix : ");
  scanf("%f", &k);
  printf("Enter the elements of %.0fX%.0f Matrix : \n", k, k);
  for (i = 0;i < k; i++)
    {
     for (j = 0;j < k; j++)
       {
        scanf("%f", &a[i][j]);
        }
    }
s = &det_multiply(a,b);

}
float det_multiply( float x[3][3] , float y[3])
{   float e[3];
    int i,j;
    e[0] =0.0;
    e[1] =0.0;
    e[2] =0.0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            e[i] =e[i]+ x[i][j]*y[j];
        }
    return(e);
}
