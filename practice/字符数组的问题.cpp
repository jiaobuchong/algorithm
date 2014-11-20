#include<stdio.h>
int main()
{
	char s1[50], s2[50];
	int i;
	printf("ÊäÈëÒ»×é×Ö·û£º\n");
	scanf("%s", s1);
	
	for(i = 0; s1[i] != '\0'; i++)
	{
		if(s1[i] >= 'A' && s1[i] <='Z')
		{
			s2[i] = s1[i] + 32;
		}	
		else if(s1[i] >= 'a' && s1[i] <= 'z')
		{
			s2[i] = s1[i] - 32;
		}	
		else
		{
			s2[i] = s1[i];
		}
	}
	
	s2[i] = '\0';
	printf("%s\n", s2);
	return 0;
}
