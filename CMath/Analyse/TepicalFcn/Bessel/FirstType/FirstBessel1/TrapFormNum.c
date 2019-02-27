#include <stdio.h>
#include "IntegrandFcn.h"

#define Pi 3.1415926
#define N 10000

//梯形法计算公式
double TrapezoidalFormula(int n, float z)
{
    //变量定义
    float Ceiling, Lower;   //定积分上限, 定积分下限
    float H;                //梯形公式系数
    double Result;          //定积分计算结果
    double PartFirst, PartSecond;
    float xk, Sum;
    int k;
    
    //初始化1
    Ceiling = Pi;
    Lower = -Pi;
    H = (Ceiling-Lower)/N;
    //初始化2
    Result = 0;
    PartFirst = 0;
    PartSecond = 0;
    xk = 0;
    Sum = 0;
    k = 0;
    
    //算法
    //第一部分
    PartFirst = H*0.5*(IntegrandFcn(Ceiling, n, z)+IntegrandFcn(Lower, n, z));
    //第二部分
    for(k=1; k<=N-1; k++)
    {
        xk = Lower+k*H;
        Sum = Sum+IntegrandFcn(xk, n, z);
    }
    PartSecond = H*Sum;
    Result = PartFirst+PartSecond;
    
    return Result;
}

