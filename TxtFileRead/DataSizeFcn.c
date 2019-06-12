#include <stdio.h>
#include <stdlib.h>


/*
	��������˵��:
		��ȡ�����ļ����С����������ػ�ȡ�Ľ��
    
	�����Ĳ���˵��:
		int *Datasize: ���������ļ����С�����, Ϊһ����������
		char *Filename: �����ļ����ļ���, Ϊһ���ַ�������
*/


int *DataSizeFcn(int *DataSize, char *FileName)
{
	int Row, Column;
	int i;
	char Temp1, Temp2;
	FILE *fp;
	
	
	/*������ʼ��*/
	Row = 0;
	Column = 1;
	Temp1 = '\0';
	Temp2 = '\0';
	fp = NULL;
	
	
	/*���붯̬����(һά)�ڴ�*/
	DataSize = (int *)malloc(sizeof(int)*2);
	/*��������(һά)��ʼ��*/
	for(i=0; i<2; i++)
	{
		DataSize[i] = 0;
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
		/*���txt�ļ������ݵ�����*/
		while(!feof(fp))
		{
			/*fgetc(fp): ��txt�ı��ж�ȡһ���ַ�*/
			Temp1 = fgetc(fp);
			if(Temp1 == '\n')
			{
				Row++;
			}
		}
		
		/*�ر��ļ�*/
		fclose(fp);
	}
	
	
	fp=fopen(FileName, "r");
	if(fp==NULL)
	{
		printf("Can't open %s file", FileName);
		exit(0);
	}
	else
	{
		/*���txt�ļ��ڵ�һ�����ݵ�����*/
		while(!feof(fp))
		{
			Temp2 = fgetc(fp);
			if(Temp2 == ' ')
			{
				Column++;
			}
			else if(Temp2 == '\n')
			{
				break;
			}
		}
		
		/*�ر��ļ�*/
		fclose(fp);
	}
	
	
	DataSize[0] = Row;
	DataSize[1] = Column;
	
	
	return DataSize;
}

