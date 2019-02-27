#include <stdio.h>
#include <stdlib.h>

//Print other information
void Other(float ***input_matrix, float **result_matrix, int *re, char *filename)
{
    int fc;
    FILE *fp;

    fp = NULL;

    fp = fopen(filename, "w");
    if(fp != NULL)
    {
        fprintf(fp, "Address of ***input_matrix: %p\n", input_matrix);
        fprintf(fp, "Address of **result_matrix: %p\n", result_matrix);
        fprintf(fp, "Address of *re: %p\n", re);

        fc = fclose(fp);
        if(fc == 0)
        {
            ;
        }
        else
        {
            printf("Close %s is Error!\n", filename);
            exit(0);
        }
    }
    else
    {
        printf("Open %s is Error!\n", filename);
        exit(0);
    }
}
