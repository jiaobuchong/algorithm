#include<stdio.h>

int count(int a, int b)
{
	return a / b;
}

int extendedGcd(int a, int b, int * x, int * y)
{
    int r;   //最大公约数
    int temp;  
    if (b == 0)
    {
        *x = 1;
        *y = 0;
        return a;    //a是最大公约数
    }
    r = extendedGcd(b, a % b, x, y);  //x和y是一个指针
    //x1 = y2, y1 = x2 - (a / b) * y2 
    
    temp = *x;
    *x = *y;
    *y = temp - (a / b) * (*y);
    return r;     //返回最大公约数
}

int main()
{
	/*求正整数N, 使N除以97余26,除以32余17*/
	int m1 = 97, m2 = 32;   //除数
	int a1 = 26, a2 = 17;   //余数
	int M = m1 * m2;  
	
	int M1 = count(M, m1);	
	int M2 = count(M, m2);
	
	int x1, y1; //通过扩展欧几里德算法求逆元，x1是M1模m1的逆
	int x2, y2;    //x2是M2模m2的逆
	extendedGcd(M1, m1, &x1, &y1);    //求M1的逆
	extendedGcd(M2, m2, &x2, &y2);    //求M2的逆 
	
	int num;   //满足要求的x
	num = (a1 * M1 * x1 + a2 * M2 * x2) % M;
	printf("所求的数字为: %d\n", num + M);
	
	return 0;
}

