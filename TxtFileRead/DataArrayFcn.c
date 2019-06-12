#include <stdio.h>
#include <stdlib.h>


/*
	函数功能说明:
		从数据文件中读取数据
    
	函数参数说明:
		float **DataArray:		存储数据文件中的数据
		int Row: 				数据文件的行数
		int Column: 			数据文件的列数
		char *Filename: 		数据文件的名字
*/


float **DataArrayFcn(float **DataArray, int Row, int Column, char *FileName)
{
	float Data;
	int i, j;
	FILE *fp;
	
	
	/*变量初始化*/
	Data = 0.0;
	fp = NULL;
	
	
	/*申请动态数组内存(二维)*/
	DataArray = (float **)malloc(sizeof(float *)*Row);
	for(i=0; i<Row; i++)
	{
		DataArray[i] = (float *)malloc(sizeof(float)*Column);
	}
	/*将该数组(二维)初始化*/
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Column; j++)
		{
			DataArray[i][j] = 0;
		}
	}
	
	
	/*检查txt文件是否能正确打开*/
	fp=fopen(FileName, "r");
	if(fp==NULL)
	{
		printf("Can't open %s file", FileName);
		exit(0);
	}
	else
	{
		/*赋值操作*/
		for(i=0; i<Row; i++)
		{
			for(j=0; j<Column; j++)
			{
				fscanf(fp, "%f", &Data);
				DataArray[i][j] = Data;
			}
			fscanf(fp, "\n");
		}
		
		/*关闭文件*/
		fclose(fp);
	}
	
	
	return DataArray;
}

