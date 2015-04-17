#include<stdio.h>

//x, y, z 分别代表这三根柱子
//借助c柱将盘子移动到b柱上
void hanoi(int n, char a, char b, char c) 
{
    if (n == 0)
    {
        //do nothing
        ;
    }
    else
    {
        hanoi(n - 1, a, c, b);  //前n-1个盘子以b为中转轴将盘子从a移到c
        printf("%c->%c ", a, b); //输出起点轴和目标轴
        hanoi(n - 1, c, b, a);  //前n-1个盘子以a为中转轴将盘子从c移到b

    }
}
int main()
{
    //汉诺塔程序
    hanoi(3, 'A', 'B', 'C');   //A B C 这三根柱子
    printf("\n");
    return 0;
}
