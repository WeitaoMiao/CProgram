#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "Input.h"
#include "Calculate.h"

//Initialize the matrix of you input
float ***Initialize_Input_Matrix(int number, int row, int list)
{
    float ***input_matrix;
    int n, i;

    //Variable initialization
    n = 0;
    i = 0;

    //Apply dynamically memory for the matrix of you input
    //Number of matrix you input
    input_matrix = (float***)malloc(sizeof(float**)*number);
    memset(input_matrix, 0, sizeof(float**)*number);   //Initialize the memory you apply
    if(input_matrix != NULL)
    {
        //Number
        for(n=0; n<number; n++)
        {
            //Row of matrix you input
            input_matrix[n] = (float**)malloc(sizeof(float*)*row);
            memset(input_matrix[n], 0, sizeof(float*)*row);
            if(input_matrix[n] != NULL)
            {
                //Row
                for(i=0; i<row; i++)
                {
                    //List of matrix you input
                    input_matrix[n][i] = (float*)malloc(sizeof(float)*list);
                    memset(input_matrix[n][i], 0, sizeof(float)*list);
                    if(input_matrix[n][i] != NULL)
                    {
                        //List
                        ;
                    }
                    else
                    {
                        printf("Memory of list is error\n");
                        exit(0);
                    }
                }
            }
            else
            {
                printf("Memory of row is error!\n");
                exit(0);
            }
        }
    }
    else
    {
        printf("Memory of number is error!\n");
        exit(0);
    }

    //Input matrix that you want
    Input(input_matrix, number, row, list);

    return input_matrix;
}

//Initialize the result matrix
float **Initialize_Result_Matrix(float ***input_matrix, int number, int row, int list, char ca)
{
    float **result_matrix;
    int i;

    //Variable initialization
    i = 0;

    //Apply dynamically memory
    //Row of matrix of result
    result_matrix = (float**)malloc(sizeof(float*)*row);
    memset(result_matrix, 0, sizeof(float*)*row);   //Initialize
    if(result_matrix != NULL)
    {
        //Row
        for(i=0; i<row; i++)
        {
            //List of matrix
            result_matrix[i] = (float*)malloc(sizeof(float)*list);
            memset(result_matrix[i], 0, sizeof(float)*list);
            if(result_matrix[i] != NULL)
            {
                //List
                ;
            }
            else
            {
                printf("Memory of list is error\n");
                exit(0);
            }
        }
    }
    else
    {
        printf("Memory of Row is error\n");
        exit(0);
    }

    //Calculate result
    Calculate(result_matrix, input_matrix, number, row, list, ca);

    return result_matrix;
}
