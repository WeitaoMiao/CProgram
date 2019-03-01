#include <stdio.h>
#include "FcnBeInte.h"

//(复合形式)Simpson数值积分算法
double SimpsonInte(float UpperLim, float LowerLim, int NumInterval)
{
    //变量定义
    double InteResult;  //计算结果
    double ResultPart1, ResultPart2, ResultPart3;   //计算结果分三个部分
    float h, H;            //积分系数
    int k;
    float x;            //被积函数的自变量
    
    
    //变量初始化
    InteResult = 0.0;
    ResultPart1 = 0.0;
    ResultPart2 = 0.0;
    ResultPart3 = 0.0;
    h = (UpperLim-LowerLim)/NumInterval;
    H = h/6;
    k = 1;
    x = 0.0;
    
    
    //算法
    //结果的第一部分:
    ResultPart1 = H*(FcnBeInte(UpperLim)+FcnBeInte(LowerLim));
    //结果的第二部分:
    for(k=1; k<=NumInterval; k++)
    {
        x = LowerLim+(2*k-1)*0.5*h;
        ResultPart2 = ResultPart2+FcnBeInte(x);
    }
    ResultPart2 = H*4*ResultPart2;
    //结果的第三部分:
    for(k=1; k<=NumInterval-1; k++)
    {
        x = LowerLim+k*h;
        ResultPart3 = ResultPart3+FcnBeInte(x);
    }
    ResultPart3 = H*2*ResultPart3;
    //总结果:
    InteResult = ResultPart1+ResultPart2+ResultPart3;
    

    //返回结果
    return InteResult;
}

