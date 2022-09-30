#include<stdio.h>
#include<math.h>

void det_multiiply( float[][3], float[3]);

int main()
{
  float a[25][25], k, d,b[3];
  int i,j;
  b=[3,4,9];
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
    b= det_multiply(a,b);
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
