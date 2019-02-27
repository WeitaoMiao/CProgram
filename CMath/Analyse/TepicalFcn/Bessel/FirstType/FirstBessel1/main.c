#include <stdio.h>
#include "TrapFormNum.h"
#include "File.h"

#define Pi 3.141592

int main(void)
{
    //变量定义
    int n;      //第一类Bessel函数的阶数
    float z;    //第一类Bessel函数的自变量
    double Jn;  //第一类Bessel函数的计算结果
    //变量初始化
    n = 0;
    z = 0.00;
    
    //开始计算
    printf("\n计算第一类Bessel函数\n\n");
    printf("请输入所求第一类Bessel函数的阶数n: ");
    scanf("%d", &n);
    printf("%d阶第一类Bessel函数:\n", n);
    while(z<15.00)
    {
        Jn = TrapezoidalFormula(n, z)/(2*Pi);
        printf("z=%.2f, J%d(z)= %.4lf\n", z, n, Jn);
        FileBessel(n, z, Jn);  //将数值结果存储进文件保存
        z = z+0.01;
    }
    
    printf("\n\n");
    return 0;
}

