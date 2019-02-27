#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "Files.h"

//Start
int *Start()
{
    int row, list;
    int number;
    int *re;

    //Variable initialization
    row = 0;
    list = 0;
    number = 0;

    //Clear screen
    system("cls");   //Windows
    //system("clear");   //Linux

    printf("\nMatrix Sum_Sub:\n\n");
    printf("Please input the number of row: ");
    scanf("%d",&row);
    printf("Please input the number of list: ");
    scanf("%d",&list);
    printf("Please input the number of Matrix: ");
    scanf("%d",&number);

    re=(int*)malloc(sizeof(int)*3);
    memset(re, 0, sizeof(int)*3);
    if(re != NULL)
    {
        re[0] = row;
        re[1] = list;
        re[2] = number;
    }
    else
    {
        printf("Memory of start is error!\n");
        exit(0);
    }

    //File that saving the information of start
    File_Start(re);

	return re;
}
