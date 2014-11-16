#include<stdio.h>
char * data1[19] = {   //1-19
"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
"eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};
char * data2[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninty"};

//不超过99的数
void translate1(int num)
{
	int temp; 
	if (num <=19)
	{
		printf("%s ", data1[num - 1]);
	}
	else
	{
		temp = num / 10;
		printf("%s ", data2[temp - 2]);
		temp = num % 10;
		printf("%s ", data1[temp - 1]);
	}
} 

//不超过999的数 
void translate2(int num)
{
	int temp;
	temp = num / 100;
	if (temp != 0)
	{
		translate1(temp);
		printf("hundred ");
	}	
	temp = num % 100;
	if (temp != 0)
	{
		translate1(temp);
	}
}

//不超过 999999的数
void translate3(int num)
{
	int temp;
	temp = num / 1000;
	if (temp != 0)
	{
		translate2(temp);
		printf("thousand ");
	}	
	temp = num % 1000;
	if (temp != 0)
	{
		translate2(temp);
	}
} 

int main()
{
	int num;
	puts("请输入一个0-999999的数字：");
	scanf("%d", &num);
	translate3(num);
}
