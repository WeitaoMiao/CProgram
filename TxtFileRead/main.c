#include <stdio.h>
#include <stdlib.h>

#include "DataSizeFcn.h"
#include "DataArrayFcn.h"


/*数据文件名*/
char FileName1[] = "InputMatrix1.txt";
char FileName2[] = "InputMatrix2.txt";


int main(void)
{
	int Row1, Column1;
	int Row2, Column2;
	int *DataSize1, *DataSize2;
	float **DataArray1, **DataArray2;
	float **DataArrayReault;
	int i, j;
	
	
	/*变量初始化*/
	Row1 = 0;
	Column1 = 0;
	Row2 = 0;
	Column2 = 0;
	
	
	/*读取第1个输入矩阵*/
	DataSize1 = DataSizeFcn(DataSize1, FileName1);
	Row1 = DataSize1[0];
	Column1 = DataSize1[1];
	DataArray1 = DataArrayFcn(DataArray1, Row1, Column1, FileName1);
	/*读取第2个输入矩阵*/
	DataSize2 = DataSizeFcn(DataSize2, FileName2);
	Row2 = DataSize2[0];
	Column2 = DataSize2[1];
	DataArray2 = DataArrayFcn(DataArray2, Row2, Column2, FileName2);
	
	
	/*矩阵求和*/
	if( (Row1==Row2) && (Column1==Column2) )
	{
		/*满足矩阵求和条件, 申请数组内存用来存储求和结果*/
		DataArrayReault = (float **)malloc(sizeof(float *)*Row1);
		for(i=0; i<Row1; i++)
		{
			DataArrayReault[i] = (float *)malloc(sizeof(float)*Column1);
		}
		/*初始化*/
		for(i=0; i<Row1; i++)
		{
			for(j=0; j<Column1; j++)
			{
				DataArrayReault[i][j] = 0;
			}
		}
		
		
		/*矩阵求和操作*/
		for(i=0; i<Row1; i++)
		{
			for(j=0; j<Column1; j++)
			{
				DataArrayReault[i][j] = DataArray1[i][j]+DataArray2[i][j];
			}
		}
		/*打印矩阵和*/
		for(i=0; i<Row1; i++)
		{
			for(j=0; j<Column1; j++)
			{
				printf("%f ", DataArrayReault[i][j]);
			}
			printf("\n");
		}
		
		
		/*释放申请的动态数组的内存*/
		for(i=0; i<Row1; i++)
		{
			free(DataArrayReault[i]);
		}
		free(DataArrayReault);
	}
	else
	{
		printf("矩阵求和的条件不符\n");
	}
	
	
	/*释放申请的动态数组的内存*/
	free(DataSize1);
	for(i=0; i<Row1; i++)
	{
		free(DataArray1[i]);
	}
	free(DataArray1);
	
	free(DataSize2);
	for(i=0; i<Row2; i++)
	{
		free(DataArray2[i]);
	}
	free(DataArray2);
	
	
	return 0;
}

