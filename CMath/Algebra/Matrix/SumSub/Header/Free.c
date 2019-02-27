#include <stdio.h>
#include <stdlib.h>

#include "Other.h"

//Release memory of you apply
void Free(float ***result_matrix, float ****input_matrix, int **re, int number, int row)
{
    int n, i;

    //Variable initialization
    n = 0;
    i = 0;

    //Release memory that the matrix of input
    if(input_matrix[0] !=  NULL)
    {
        for(n=0; n<number; n++)
        {
            for(i=0; i<row; i++)
            {
                if(input_matrix[0][n][i] != NULL)
                {
                    free(input_matrix[0][n][i]);
                    input_matrix[0][n][i] = NULL;
                }
            }

            if(input_matrix[0][n] != NULL)
            {
                free(input_matrix[0][n]);
                input_matrix[0][n] = NULL;
            }
        }

        free(input_matrix[0]);
        input_matrix[0] = NULL;
    }

    //Release memory that the result of matrix
    if(result_matrix[0] != NULL)
    {
        for(i=0; i<row; i++)
        {
            if(result_matrix[0][i] != NULL)
            {
                free(result_matrix[0][i]);
                result_matrix[0][i] = NULL;
            }
        }

        free(result_matrix[0]);
        result_matrix[0] = NULL;
    }

    //Release memory of re
    if(re[0] != NULL)
    {
        free(re[0]);
        re[0] = NULL;
    }
}
