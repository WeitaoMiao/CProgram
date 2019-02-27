#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//Calculate
void Calculate(float **result_matrix, float ***input_matrix, int number, int row, int list, char ca)
{
    float result;
    int n, i, j;

    //Variable initialization
    result = 0;
    n = 0;
    i = 0;
    j = 0;

    //Calculate and assignment
    if(number>=2)
    {
        //To choice the method of caluate you input and to caluate
        switch(ca)
        {
            //Sum
            case '+':
                for(i=0; i<row; i++)
                {
                    for(j=0; j<list; j++)
                    {
                        result = input_matrix[0][i][j];
                        for(n=1; n<number; n++)
                        {
                            result = result + input_matrix[n][i][j];
                            result_matrix[i][j] = result;
                        }
                    }
                }
                break;

            //Sub
            case '-':
                for(i=0; i<row; i++)
                {
                    for(j=0; j<list; j++)
                    {
                        result = input_matrix[0][i][j];
                        for(n=1; n<number; n++)
                        {
                            result = result - input_matrix[n][i][j];
                            result_matrix[i][j] = result;
                        }
                    }
                }
                break;

            default:
                printf("\n\nError, The calculation you input should be '+' or '-'!\n");
                exit(0);
        }
    }
    else
    {
        for(i=0; i<row; i++)
        {
            for(j=0; j<list;j++)
            {
                result = input_matrix[0][i][j];
                result_matrix[i][j] = result;
            }
        }
    }
}
