#include <stdio.h>
#include <stdlib.h>

#include "DataSizeFcn.h"
#include "DataArrayFcn.h"


/*�����ļ���*/
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
	
	
	/*������ʼ��*/
	Row1 = 0;
	Column1 = 0;
	Row2 = 0;
	Column2 = 0;
	
	
	/*��ȡ��1���������*/
	DataSize1 = DataSizeFcn(DataSize1, FileName1);
	Row1 = DataSize1[0];
	Column1 = DataSize1[1];
	DataArray1 = DataArrayFcn(DataArray1, Row1, Column1, FileName1);
	/*��ȡ��2���������*/
	DataSize2 = DataSizeFcn(DataSize2, FileName2);
	Row2 = DataSize2[0];
	Column2 = DataSize2[1];
	DataArray2 = DataArrayFcn(DataArray2, Row2, Column2, FileName2);
	
	
	/*�������*/
	if( (Row1==Row2) && (Column1==Column2) )
	{
		/*��������������, ���������ڴ������洢��ͽ��*/
		DataArrayReault = (float **)malloc(sizeof(float *)*Row1);
		for(i=0; i<Row1; i++)
		{
			DataArrayReault[i] = (float *)malloc(sizeof(float)*Column1);
		}
		/*��ʼ��*/
		for(i=0; i<Row1; i++)
		{
			for(j=0; j<Column1; j++)
			{
				DataArrayReault[i][j] = 0;
			}
		}
		
		
		/*������Ͳ���*/
		for(i=0; i<Row1; i++)
		{
			for(j=0; j<Column1; j++)
			{
				DataArrayReault[i][j] = DataArray1[i][j]+DataArray2[i][j];
			}
		}
		/*��ӡ�����*/
		for(i=0; i<Row1; i++)
		{
			for(j=0; j<Column1; j++)
			{
				printf("%f ", DataArrayReault[i][j]);
			}
			printf("\n");
		}
		
		
		/*�ͷ�����Ķ�̬������ڴ�*/
		for(i=0; i<Row1; i++)
		{
			free(DataArrayReault[i]);
		}
		free(DataArrayReault);
	}
	else
	{
		printf("������͵���������\n");
	}
	
	
	/*�ͷ�����Ķ�̬������ڴ�*/
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

