#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
    char ch;
    do
    {
    char infile[12],outfile[14];

	printf("file name format example : output_2h.txt\n\n");
	printf("ENTER FULL OUTPUT FILE NAME : ");
	scanf("%s",&outfile);
	printf("file name format example : input_2h.txt\n\n");
	printf("ENTER FULL INPUT FILE NAME : ");
	scanf("%s",&infile);
	printf("%s\n%s\n",infile,outfile);
    FILE *in_file = fopen(infile,"r");
    FILE *out_file = fopen(outfile,"w");

    if(in_file == NULL )
        printf("Error! Could not open file\n");

    int i,j,n;
    fscanf(in_file,"%d",&n);
    float A[n][n+1];
     for(i=0;i<n;i++)
		{   for(j=0;j<n+1;j++)

			{
			fscanf(in_file,"%f",&A[i][j]);
			}
		}




	float l,temp;
	int k,u,r;

	for(j=0;j<(n+1);j++)
        for(i=0;i<n;i++)
            {r=j;if(i>j)
                { while(j==r)
                      {
                 if(A[j][j]!=0.0)
                     {  r=r+1;
                         l= A[i][j] / A[j][j];
                         for(k=0;k<(n+1);k++)
                            {A[i][k] = A[i][k] - l*A[j][k];}
                     }
                 if(A[j][j]==0.0)
                             {
                                 for(u=j+1;u<n+1;u++)
                                {
                                    if (A[j][u] != 0.0)
                                        {
                                          for(k=0;k<n+1;k++)
                                          {
                                              temp = A[u][k];
                                              A[u][k] = A[j][k];
                                              A[j][k] = temp;
                                          }
                                          break;
                                        }
                                        if(k==n)
                                            break;
                                }
                                if(u==n+1)
                                    {printf("\n\nMatrix is singular\n\n");
                                    break;
                                    }
                              }
                        }
                     }

                 }
    for(i=0;i<n;i++)
		{
		       for(j=0;j<n+1;j++)
			{
                fprintf(out_file,"%f\t",A[i][j]);
                printf("%f\t",A[i][j]);
			}
			fprintf(out_file,"\n");
			printf("\n");
		}


   if(A[n-1][n-1]!=0)
   {fprintf(out_file,"Unique solution exists!\n");
    printf("Unique solution exists!");
   }
   else
    if(A[n-1][n]==0)
        {fprintf(out_file,"Multiple solution exists!\n");
        printf("Multiple solution exists!\n");
        }
    else if (A[n-1][n]!=0)
        {fprintf(out_file,"No solution exists!\n");
        printf("No solution exists!\n");
        }

    float sum,X[n];


    if(A[n-1][n-1]!=0)
        {
            for(i=n-1;i>=0;i--)
             {
                 sum = 0;
                for(j=i+1;j<n;j++)
                    {sum = sum + X[j]*A[i][j];}
                X[i] = (A[i][n] - sum) / A[i][i];

             }
            for(j=0;j<(n);j++)
                    fprintf(out_file,"x%d = %f\n",j,X[j]);
        }
    else
        if(A[n-1][n]==0)
            for(j=0;j<(n);j++)
                    fprintf(out_file,"x%d = Multiple solution\n",j);
        else
            if (A[n-1][n]!=0)
                for(j=0;j<(n);j++)
                    fprintf(out_file,"x%d = No solution\n",j);

    printf("\n\nDo you want to re-run the program? (y/n) ");
    scanf("%s",&ch);
}
while(ch=='y');
return 0;
}
