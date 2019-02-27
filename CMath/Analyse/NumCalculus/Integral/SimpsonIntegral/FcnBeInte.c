#include <stdio.h>
#include <math.h>

//被积函数计算
double FcnBeInte(float x)
{
    //变量定义
    double FcnResult;   //被积函数在x点处的计算结果
    
    
    //初始化
    FcnResult = 0.0;
    
    
    //被积函数在x处的计算
    FcnResult = sin(x);
    
    
    //返回结果
    return FcnResult;
}

