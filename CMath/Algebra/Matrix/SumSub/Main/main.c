/*矩阵的加减法*/
//Producer: WeitaoMiao@163.com
/*作者: 游里工夫独造微*/

#include <stdio.h>
#include <stdlib.h>

#include "Start.h"
#include "IniMatrix.h"
#include "Print.h"
#include "Free.h"
#include "Other.h"
#include "Files.h"

#define filename1 "File_Memory.txt"
#define filename2 "File_Release_Memory.txt"

int main()
{
    int row, list;    //The number of rows and list in a matrix
    int number;    //The number of matrices to be calculated
    int *re;
    char ca;
    char choice;

    float ***input_matrix;   //A matrix that requires calculation
    float **result_matrix;   //Result matrix

    //Variable initialization
    row = 0;
    list = 0;
    number = 0;

    do
    {
        //Start
        re = Start();
        row = re[0];
        list = re[1];
        number = re[2];
        getchar();   //Remove the carriage return
        printf("Please input Calculation, '+' or '-':  ");
        scanf("%c", &ca);
        //Creating file that saving the method you want to caluate
        Calculate_Way(ca);

        //Initialize memory that you apply for matrix of input, and input matrix
        input_matrix = Initialize_Input_Matrix(number, row, list);
        //Initialize memory that you apply for matrix of result, and calculate
        result_matrix = Initialize_Result_Matrix(input_matrix, number, row, list, ca);
        //Print the matrix of input and result
        Print_Matrix(input_matrix, result_matrix, number, row, list);
        //Output other information
        Other(input_matrix, result_matrix, re, filename1);
        //Free the memory you apply
        Free(&result_matrix, &input_matrix, &re, number, row);
        //Output other information
        Other(input_matrix, result_matrix, re, filename2);

        printf("\n\n");
        getchar();   //Remove the carriage return
        printf("Do you want input again? (y/n) or (Y/N): ");
        scanf("%c", &choice);
        }while(choice == 'y' || choice == 'Y');

    return 0;
}
