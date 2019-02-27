#include <stdio.h>
#include <math.h>

float IntegrandFcn(float xk, int n, float z)
{
    float theta;
    float FcnResult;
    
    //初始化
    FcnResult = 0;
    theta = 0;
    
    //被积函数
    theta = n*xk-z*sin(xk);
    FcnResult = cos(theta);
    
    return FcnResult;
}
