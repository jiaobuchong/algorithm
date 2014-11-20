#include<stdio.h>
int main()
{
    int i,j,n=0;
    for(i=2;i<=100;i++)
    {
        for(j=2;j<=i-1;j++)
        {
            if(i%j==0) 
                break;
        }
        if(j>=i)
        {
            printf("%d\t", i);
            n++;
            if(n==5)
            {
                n=0;
                printf("\n");

            }
        }
    }
return 0;
} 
