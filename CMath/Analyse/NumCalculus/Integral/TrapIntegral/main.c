#include <stdio.h>
#include <math.h>
#include "TrapezoidalFormula.h"

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
