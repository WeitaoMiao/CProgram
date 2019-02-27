#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//存储数值结果
void FileBessel(int n, float z, double Jn)
{
    char *filename; //存储文件的名字
    char *firstName;
    char lastName[10];
    char *fileFormat;
    int fc;
    FILE *fp;
    
    //初始化
    firstName = "FileBessel";
    sprintf(lastName, "%d", n);
    fileFormat = ".txt";
    fc = 0;
    fp = NULL;
    
    //动态申请内存
    filename = (char *)malloc(strlen(firstName)+\
            strlen(lastName)+strlen(fileFormat));
    
    //拼接字符串
    strcpy(filename, firstName);
    strcat(filename, lastName);
    strcat(filename, fileFormat); 
    
    //文件操作
    fp = fopen(filename, "a+");
    if(fp!=NULL)
    {
        fprintf(fp, "%.2f %.4lf\n", z, Jn);
        fc = fclose(fp);
        if(fc!=0)
        {
            printf("Txt file is Error!\n");
            exit(0);
        }
     }
     else
     {
         printf("Open txt file is Error!\n");
         exit(0);
     }
     
     //释放之前申请的内存
     free(filename);
}

