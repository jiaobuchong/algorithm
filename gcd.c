#include<stdio.h>
int gcd(int a, int b);
int exgcd(int a, int b, int * x, int * y);
int main()
{
    int a, b, x, y;
    printf("请输入第一个数: ");
    scanf("%d", &a);
    printf("请输入第二个数: ");
    scanf("%d", &b);
    
    //使用扩展欧几里德算法求最大公因数
    //printf("%d 和 %d的最大公因数是: %d\n", a, b, gcd(a, b));

    //使用扩展欧几里德算法计算a b的最大公因数
    int maxComDivi = exgcd(a, b, &x, &y);
    printf("\n%d 和 %d的最大公因数是: %d\n", a, b, maxComDivi);
    printf("并且%d = %d * %d + %d * %d\n", maxComDivi, x, a, y, b);

}
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a%b);
    }
}

int exgcd(int a, int b, int * x, int * y)
{
    int r;   //最大公因数
    int temp;  //暂时保存x
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;    //a是最大公因数
    }
    r = exgcd(b, a % b, x, y);  //x，y是一个指针
    //x1 = y2, y1 = x2 - (a / b) * y2
    
    temp = *x;
    *x = *y;
    *y = temp - (a / b) * (*y);
    return r;     //返回最大公因数
}
