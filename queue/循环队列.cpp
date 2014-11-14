#include<stdio.h>  
#include<malloc.h>   
#include<process.h>  

#define OVERFLOW -2
#define OK 1
#define ERROR 0
#define MAXQSIZE 100

typedef int Status;
typedef int QElemType; 

typedef struct
{
	QElemType *base;
	int front;
	int rear;
}SqQueue;

Status InitQueue(SqQueue *Q)
{
	Q->base = (QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q->base)
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}


Status EnQueue(SqQueue *Q, QElemType e)
{
	if((Q->rear+1) % MAXQSIZE == Q->front)    //队列满的条件
		return ERROR;
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXQSIZE;    //让rear指针向后移一个位置
	return OK;
}


Status DeQueue(SqQueue *Q, QElemType *e)
{
	if(Q->front == Q->rear)   //队列为空
		return ERROR;
	*e = Q->base[Q->front];
	Q->front = (Q->front+1) % MAXQSIZE;
	return OK;
}


int main()
{
	SqQueue Q;
	InitQueue(&Q);

	//入队
	printf("请问要输入多少个数？\n");
	int num, i, m, e;
	scanf("%d", &num);
	for(i=1; i <= num; i++)
	{
		printf("请输入要输入的数字：");
		scanf("%d", &m);
		EnQueue(&Q, m);
	}

    //出队	
	for(i=1; i <= num; i++)
	{
		printf("先进先出，队列出队为%d号: ", i);
		DeQueue(&Q, &e);
		printf("%d", e);
		printf("\n");
	}

	return 0;
}

