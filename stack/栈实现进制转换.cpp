#include<stdio.h>  
#include<stdlib.h>  

#define OK 1
#define ERROR 0   
#define MAXSIZE 100  

typedef int Status;   
typedef int SElemType; 
typedef struct
{
	SElemType data[MAXSIZE];
	int top;    /*用于栈顶指针*/
}SqStack;

Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)
	{
		return ERROR;
	}
	S->data[S->top] = e;
	S->top++;
	return OK;
}

Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
	{
		return ERROR;
	}
	S->top--;
	*e = S->data[S->top];
	return OK;
}

int main()
{
    SqStack S;
    int i, m, e, l;
    S.top = 0;         //初始化栈顶指针为0 

	printf("请输入一个整数:\n");
	scanf("%d", &i);
	
	while(i != 0) 
	{
		m = i % 2;
		i = i / 2;
		Push(&S, m);
	}
	
	l = S.top;
	for(; l > 0; l--)
	{
		Pop(&S, &e);
		printf("%d", e);
	}
	printf("\n");
	return 0;
}

