#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "Files.h"

//Print the matrix of you input and result
void Print_Matrix(float ***input_matrix, float **result_matrix, int number, int row, int list)
{
    int n,i,j;

    //Variable initialization
    n = 0;
    i = 0;
    j = 0;

    printf("\n\n\nPrint matrix of input:\n");
    //Print the matrix of you input
    for(n=0; n<number; n++)
    {
        printf("The %d_ed Matrix:\n",n+1);
        for(i=0; i<row; i++)
        {
            for(j=0; j<list; j++)
            {
                printf("%f\t",input_matrix[n][i][j]);
                if((j+1)%list == 0)
                {
                    printf("\n");
                }
            }
        }
    }

    printf("\n\n\nPrint calculate of matrix:\n");
    //Print the matrix of result
    for(i=0; i<row; i++)
    {
        for(j=0; j<list; j++)
        {
            printf("%f\t",result_matrix[i][j]);
            if((j+1)%list == 0)
            {
                printf("\n");
            }
        }
    }

    File_Matrix(input_matrix, result_matrix, number, row, list);
}
