#include <stdio.h>
#include <stdlib.h>


/*
	函数功能说明:
		获取数据文件的行、列数并返回获取的结果
    
	函数的参数说明:
		int *Datasize: 返回数据文件的行、列数, 为一个整数数组
		char *Filename: 数据文件的文件名, 为一个字符串数组
*/


int *DataSizeFcn(int *DataSize, char *FileName)
{
	int Row, Column;
	int i;
	char Temp1, Temp2;
	FILE *fp;
	
	
	/*变量初始化*/
	Row = 0;
	Column = 1;
	Temp1 = '\0';
	Temp2 = '\0';
	fp = NULL;
	
	
	/*申请动态数组(一维)内存*/
	DataSize = (int *)malloc(sizeof(int)*2);
	/*将该数组(一维)初始化*/
	for(i=0; i<2; i++)
	{
		DataSize[i] = 0;
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
		/*检查txt文件内数据的行数*/
		while(!feof(fp))
		{
			/*fgetc(fp): 从txt文本中读取一个字符*/
			Temp1 = fgetc(fp);
			if(Temp1 == '\n')
			{
				Row++;
			}
		}
		
		/*关闭文件*/
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
		/*检查txt文件内第一行数据的列数*/
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
		
		/*关闭文件*/
		fclose(fp);
	}
	
	
	DataSize[0] = Row;
	DataSize[1] = Column;
	
	
	return DataSize;
}

