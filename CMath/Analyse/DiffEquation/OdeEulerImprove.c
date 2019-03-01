/*梯形方法(改进Euler方法): 数值求解ODE(常微分方程)的柯西问题(初值问题)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

#define Pi 3.1415926

//打印信息函数
int Print();
//用于数值计算的函数
float Function(float t, float u_n_last);
//Euler算法
float Euler(float t, float u_n_last, float u_n, float h);
//迭代算法
float Iteration(float t, float u_n_last, float u_n, float h);
//梯形算法(改进Euler算法)
float Euler_change(float t, float u_n_last, float u_n, float h);

int main(void)
{
	//声明运算变量
	int n;
	float *t;
	float *u;							//自变量t, 待求函数u
	float h;							//数值精度(步长)
	
	float t0, tmax;						//时间的初始值和终止值
	float u0;							//待求函数的初值
	
	int number_t;
	
	//声明文件变量
	int fc;
	FILE *fp;
	
	
	
	//初始化
	n = 0;
	h = 0;
	//
	t0 = 0;
	u0 = 0;
	tmax = 0;
	//
	number_t = 0;
	//
	fc = 0;
	fp = NULL;
	
	//输入所需信息
	Print();
	printf("请输入以下信息:\n");
	//时间
	printf("初始时间t0(t0>=0): ");
	scanf("%f", &t0);
	printf("终止时间tmax(tmax>t0): ");
	scanf("%f", &tmax);
	//待求函数
	printf("初始值u0: ");
	scanf("%f", &u0);
	//精度
	printf("所要求的求解精度h(h>0, 且h<(tmax-t0)): ");
	scanf("%f", &h);
	printf("\n");
	
	//判断所需信息是否符合正确范围以及判断后的处理
	if( (t0>=0) && (tmax>t0) && (h>0) && (h<(tmax-t0)) )
	{
		number_t = (int)((tmax-t0)/h);
		//动态申请自变量向量的内存大小, 初始化申请的内存
		t = (float*)malloc(sizeof(float)*number_t);
		memset(t, 0, sizeof(float)*number_t);
		//动态申请带球函数值向量的内存大小, 初始化申请的内存
		u = (float*)malloc(sizeof(float)*number_t);
		memset(t, 0, sizeof(float)*number_t);
		
		t[0] = t0;
		u[0] = u0;
		printf("t[%d]:%f \t\t u[%d]:%f\n", n, t[n], n, u[n]);
		for(n=1;n<number_t;n++)
		{
			//使用改进型Euler算法
			u[n] = Euler_change(t[n-1], u[n-1], u[n], h);
			t[n] = t[n-1]+h;
			
			printf("t[%d]:%f \t\t u[%d]:%f\n", n, t[n], n, u[n]);
		}
		if((t[n-1]+h)!=tmax)
		{
			printf("\n注: 因为步长的原因, 计算的最后一个值并非u(tmax), 而是u(t0+nh), 其中n为步长的总数\n\n\n");
		}
		
		//将计算的结果数据, 存储到文件中
		fp = fopen("Euler_change.txt", "w");
		if(fp!=NULL)
		{
			for(n=0;n<number_t;n++)
			{
				fprintf(fp, "%f \t %f\n", t[n], u[n]);
			}
			
			fc = fclose(fp);
			if(fc == 0)
			{
				;
			}
			else
			{
				printf("Close Differential_Equation.txt is error!\n");
				exit(0);
			}
		}
		else
		{
			printf("Open Differential_Equation.txt is error!\n");
			exit(0);
		}
		
		//释放之前申请的内存 
		free(t);
		free(u);
	}
	else
	{
		printf("输入的信息不符合要求:\n");
		printf("初始时间t0: t0>=0;   终止时间tmax: tmax>t0;   所要求的求解精度h: h>0, h<(t-t0)");
	}
	
	return 0;
}

//打印信息函数
int Print()
{
	printf("梯形方法(改进型Euler方法): 数值求解ODE(常微分方程)的柯西问题(初值问题)\n");
	printf("说明: 此程序所实现的内容, 为梯形方法(改进型Euler方法)求解ODE的柯西问题\n\n\n");
	
	return 0;
}

/*----------------------------------------------------------*/
//用于数值计算的函数, 可自己根据问题进行修改
float Function(float t, float u_n_last)
{
	float f_tu;
	
	//初始化
	f_tu = 0;
	
	//函数值
	f_tu = 0.5*u_n_last;
	
	return f_tu;
}

//Euler算法
float Euler(float t, float u_n_last, float u_n, float h)
{
	//调用函数
	u_n = u_n_last+h*Function(t, u_n_last);
	
	return u_n;
}
/*----------------------------------------------------------*/

/*----------------------------------------------------------*/
//迭代算法
float Iteration(float t, float u_n_last, float u_n, float h)
{
	int i;			//迭代次数
	
	//初始化
	i = 0;
	
	//算法
	for(i=0; i<1000; i++)
	{
		u_n = u_n_last+0.5*h*(Function(t, u_n_last)+Function(t+h, u_n));
	}
	
	return u_n;
}

//梯形算法(改进型Euler算法)
float Euler_change(float t, float u_n_last, float u_n, float h)
{	
	//调用Euler算法, 先用Euler算法给出预测值
	u_n = Euler(t, u_n_last, u_n, h);
	
	//调用迭代算法, 不断校正Euler算法的预测值
	u_n = Iteration(t, u_n_last, u_n, h);
	
	return u_n;
}
/*----------------------------------------------------------*/
