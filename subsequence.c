#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define FAIL 0
#define SUCCESS 1

//贪心法
int getSubsequence(char P[], char T[])
{
    int j = 0;
    int i;
    int m = strlen(P);
    int n = strlen(T);
    for (i = 0; i < m; i++)
    {
        //让P序列中的每一个字符和T序列中的字符进行比较
        while (P[i] != T[j])
        {
            j++;
            if (j == n)
            {
                return FAIL;
            }
        }
        j++;
        if (j == n)
        {
            return FAIL;
        }
    }
    return SUCCESS;
}

//动态规划法
void longestCommonSubsequence(char R[], char Q[])
{
    int m = strlen(R);    //R序列的长度
    int n = strlen(Q);    //Q序列的长度
    char (*W)[m+1];       //W指向m+1个char值构成的数组
    W = (char (*)[m+1])malloc((n+1)*(m+1)*sizeof(int)); //动态申请n+1行m+1列的二维数组
    
    int i, j;
    for (i = 0; i <= m; i++)
    {
        W[0][i] = 0;     //将第一行置为0
    }
    for (j = 1; j <= n; j++)
    {
        W[j][0] = 0;   //将第一列置为0
    }

    for (i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if (R[i-1] == Q[j-1])
            {
                W[i][j] = W[i-1][j-1] + 1;
            }
            else
            {
                if (W[i][j-1] >= W[i-1][j])
                {
                    W[i][j] = W[i][j-1];
                }
                else
                {
                    W[i][j] = W[i-1][j];
                }
            }
        }
    }
    
    //输出这个二维数组W
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%d\t", W[i][j]);
        }
        printf("\n");
    }

    //逆序打印最大公共序列
    for (i = m, j = n; i >= 1 && j >= 1;)
    {
        if (R[i-1] == Q[j-1])
        {
            printf("%c ", R[i-1]);
            i--;
            j--;
        }
        else
        {
            if (W[i][j-1] > W[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    free(W);
    printf("\n");

}
int main()
{
    char P[] = "ACAB";
    char T[] = "ABCACABA";

   // P是T的子序列，当且仅当P中所有字符都以相同的顺序在T中出现
   if (getSubsequence(P, T))
   {
       puts("P是Q的子序列。");
   }
   else
   {
       puts("P不是Q的子序列。");
   }
    
   //最长公共子序列，X是Y的子序列，当且仅当X中的所有字符在Y中以相同的顺序出现
   char R[] = "ABBCADC";
   char Q[] = "BABBAC";
   longestCommonSubsequence(R, Q);
}
