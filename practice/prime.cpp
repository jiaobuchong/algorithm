#include<stdio.h>
int main()
{
	int n, i;

	
	for(n = 100; n <= 200; n++)
	{
		int flag = 1;
		for(i = 2; i <= n-1; i++)
		{
			if(n % i == 0)
			{
				flag = 0;
				break;
			}		
		}
	//	printf("%d\n", flag);
		if(flag)
		{
			printf("%d\n", n);
		}
			
	}
		
	return 0;
}
