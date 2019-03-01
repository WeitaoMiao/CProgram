#include <stdio.h>
#include <math.h>

//被积函数
double IntegrandFcn(float x)
{
    double FcnResult;
    
    //初始化
    FcnResult = 0;
    
    //被积函数
    FcnResult = sin(x);
    
    return FcnResult;
}
