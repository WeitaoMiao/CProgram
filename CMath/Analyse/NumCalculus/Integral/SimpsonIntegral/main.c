#include <stdio.h>
#include "SimpsonInte.h"


int main(void)
{
    //变量定义
    float UpperLim, LowerLim;   //定积分的积分区间上限, 下限
    int NumInterval;            //积分区间的等分数量
    double IntegralResult;      //定积分结果
    
    
    //变量初始化
    UpperLim = 0.0;
    LowerLim = 0.0;
    NumInterval = 2;
    IntegralResult = 0.0;
    
    
    //输入
    printf("\nSimpson法数值积分\n\n");
    printf("请输入定积分的积分区间上限:");
    scanf("%f", &UpperLim);
    printf("请输入定积分的积分区间下限:");
    scanf("%f", &LowerLim);
    printf("请输入对定积分区间的等分数量(>=2):");
    scanf("%d", &NumInterval);
    if(UpperLim>LowerLim)
    {
        if(NumInterval>=2)
        {
            //调用Simpson法进行数值计算
            IntegralResult = SimpsonInte(UpperLim, LowerLim, NumInterval);
            printf("Simpson法计算结果: %.8lf", IntegralResult);
        }
        else
        {
            printf("输入错误, 积分区间的等分数量必须>=2");
        }
    }
    else
    {
        printf("输入错误, 积分区间的上限必须大于下限");
    }
    
    
    printf("\n\n");
    return 0;
}

