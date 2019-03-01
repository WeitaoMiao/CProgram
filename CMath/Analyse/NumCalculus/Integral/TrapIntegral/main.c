#include <stdio.h>
#include <math.h>

//(复合形式)梯形公式
double TrapezoidalFormula(float Ceiling, float Lower, float H, int N);
//被积函数
double IntegrandFcn(float x);

int main(void)
{
    //变量定义
    float Ceiling, Lower;   //定积分上限, 定积分下限
    float H;                //梯形法系数
    int N;                  //区间等分的个数
    double Integral;        //定积分结果
    
    //变量初始化
    Ceiling = 0;
    Lower = 0;
    H = 0;
    N = 0;
    
    //输入工作
    printf("\n数值积分之梯形法计算\n\n");
    printf("请输入定积分上限: ");
    scanf("%f", &Ceiling);
    printf("请输入定积分下限: ");
    scanf("%f", &Lower);
    printf("请输入定积分区间的等分数(N>=2): ");
    scanf("%d", &N);
    //核心工作
    if((Ceiling>Lower) && (N>=2))
    {
        H = (Ceiling-Lower)/N;
        Integral = TrapezoidalFormula(Ceiling, Lower, H, N);
        printf("定积分结果: %lf", Integral);
    }
    else
    {
        printf("输入有错误：1 定积分的上限必须大于下限\n2 且定积分区间等分数必须为不小于2的整数");
    }
    
    printf("\n");
    return 0;
}


//梯形法计算公式
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
