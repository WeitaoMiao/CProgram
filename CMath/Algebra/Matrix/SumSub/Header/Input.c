#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

//The max value of the row and list of the matrix you input
#define Max 1000
//The max value of the number of the matrix you input
#define Max_number 1000

//Input matrix
void Input(float ***input_matrix, int number, int row, int list)
{
    float element;    //Matrix element
    int n, i, j;

    //Variable initialization
    element = 0;
    n = 0;
    i = 0;
    j = 0;

    printf("\n\nPlease input matrix:\n");
    if(row>0 && row<=Max)
    {
        if(list>0 && list<=Max)
        {
            if(number>0 && number<=Max_number)
            {
                //Input
                for(n=0; n<number; n++)
                {
                    printf("The %d_ed Matrix:\n", n+1);
                    for(i=0; i<row; i++)
                    {
                        for(j=0; j<list; j++)
                        {
                            //Input the element of you matrix
                            scanf("%f", &element);
                            input_matrix[n][i][j] = element;
                        }
                    }
                }
            }
            else
            {
                printf("Error,the number > 0 and number <=1000!\n");
                exit(0);
            }
        }
        else
        {
            printf("Error,the list > 0 and <= 1000 !\n");
            exit(0);
        }
    }
    else
    {
        printf("Error, the row > 0 and <=1000 ! \n");
        exit(0);
    }
}
