#include <stdio.h>
#include <stdlib.h>


/*
	��������˵��:
		�������ļ��ж�ȡ����
    
	��������˵��:
		float **DataArray:		�洢�����ļ��е�����
		int Row: 				�����ļ�������
		int Column: 			�����ļ�������
		char *Filename: 		�����ļ�������
*/


float **DataArrayFcn(float **DataArray, int Row, int Column, char *FileName)
{
	float Data;
	int i, j;
	FILE *fp;
	
	
	/*������ʼ��*/
	Data = 0.0;
	fp = NULL;
	
	
	/*���붯̬�����ڴ�(��ά)*/
	DataArray = (float **)malloc(sizeof(float *)*Row);
	for(i=0; i<Row; i++)
	{
		DataArray[i] = (float *)malloc(sizeof(float)*Column);
	}
	/*��������(��ά)��ʼ��*/
	for(i=0; i<Row; i++)
	{
		for(j=0; j<Column; j++)
		{
			DataArray[i][j] = 0;
		}
	}
	
	
	/*���txt�ļ��Ƿ�����ȷ��*/
	fp=fopen(FileName, "r");
	if(fp==NULL)
	{
		printf("Can't open %s file", FileName);
		exit(0);
	}
	else
	{
		/*��ֵ����*/
		for(i=0; i<Row; i++)
		{
			for(j=0; j<Column; j++)
			{
				fscanf(fp, "%f", &Data);
				DataArray[i][j] = Data;
			}
			fscanf(fp, "\n");
		}
		
		/*�ر��ļ�*/
		fclose(fp);
	}
	
	
	return DataArray;
}

