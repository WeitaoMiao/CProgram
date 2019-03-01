#include <stdio.h>

//(复合形式)梯形法计算公式
double TrapezoidalFormula(float Ceiling, float Lower, float H, int N)
{
    double Result;
    double PartFirst, PartSecond;
    double Sum;
    float xk;
    int k;
    
    //初始化
    Result = 0;
    PartFirst = 0;
    PartSecond = 0;
    xk = 0;
    Sum = 0;
    k = 0;
    
    //第一部分
    PartFirst = H*0.5*(IntegrandFcn(Ceiling)+IntegrandFcn(Lower));
    //第二部分
    for(k=1; k<=N-1; k++)
    {
        xk = Lower+k*H;
        Sum = Sum+IntegrandFcn(xk);
    }
    PartSecond = H*Sum;
    
    Result = PartFirst+PartSecond;
    
    return Result;
}
