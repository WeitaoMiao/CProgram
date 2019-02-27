#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Generate the file to save information about start
void File_Start(int *re)
{
    int fc;
    FILE *fp;

    //Variable initialization
    fc = 0;
    fp = NULL;

    fp = fopen("File_Start.txt", "w");
    if(fp != NULL)
    {
        fprintf(fp, "Row of matrix is %d\n", re[0]);
        fprintf(fp, "List of matrix is %d\n", re[1]);
        fprintf(fp, "Number of matrix is %d\n", re[2]);

        fc = fclose(fp);
        if(fc == 0)
        {
            ;
        }
        else
        {
            printf("Close File_Start.txt is Error!\n");
            exit(0);
        }
    }
    else
    {
        printf("Open File_Start.txt is Error!\n");
        exit(0);
    }
}

//Generate the file to save information about calculate method
void Calculate_Way(char ca)
{
    int fc;
    FILE *fp;

    //Variable initialization
    fc = 0;
    fp = NULL;

    fp = fopen("Calculate_Way.txt", "w");
    if(fp != NULL)
    {
        fprintf(fp, "The way of calculate is: ' %c '\n", ca);

        fc = fclose(fp);
        if(fc == 0)
        {
            ;
        }
        else
        {
            printf("Close Calculate_Way.txt is Error!\n");
            exit(0);
        }
    }
    else
    {
        printf("Open Calculate_Way.txt is Error!\n");
        exit(0);
    }
}

//Generate the file to save information about the matrix of you input and result
void File_Matrix(float ***input_matrix, float **result_matrix, int number, int row, int list)
{
    int n,i,j;
    int fc_input, fc_result;
    FILE *fp_input;
    FILE *fp_result;

    //Variable initialization
    n = 0;
    i = 0;
    j = 0;
    fc_input = 0;
    fc_result = 0;
    fp_input = NULL;
    fp_result = NULL;

    //Creat File_Input_Matrix.txt
    fp_input = fopen("File_Input_Matrix.txt", "w");
    if(fp_input != NULL)
    {
        for(n=0; n<number; n++)
        {
            fprintf(fp_input, "The %d_ed Matrix:\n", n+1);
            for(i=0; i<row; i++)
            {
                for(j=0; j<list; j++)
                {
                    fprintf(fp_input, "%f\t", input_matrix[n][i][j]);
                    if((j+1)%list == 0)
                    {
                        fprintf(fp_input, "\n");
                    }
                }
            }
        }

        fc_input = fclose(fp_input);
        if(fc_input == 0 )
        {
            ;
        }
        else
        {
            printf("Close File_Input_Matrix.txt is Error!\n");
            exit(0);
        }
    }
    else
    {
        printf("Open File_Input_Matrix.txt is Error!\n");
        exit(0);
    }

    //Creat File_Result_Matrix.txt
    fp_result = fopen("File_Result_Matrix.txt", "w");
    if(fp_result != NULL)
    {
        fprintf(fp_result, "The result of Matrix:\n");
        for(i=0; i<row; i++)
        {
            for(j=0; j<list; j++)
            {
                fprintf(fp_result, "%f\t", result_matrix[i][j]);
                if((j+1)%list == 0)
                {
                    fprintf(fp_result, "\n");
                }
            }
        }

        fc_result = fclose(fp_result);
        if(fc_result == 0 )
        {
            ;
        }
        else
        {
            printf("Close File_Result_Matrix.txt is Error!\n");
            exit(0);
        }
    }
    else
    {
        printf("Open File_Result_Matrix.txt is Error!\n");
        exit(0);
    }
}
