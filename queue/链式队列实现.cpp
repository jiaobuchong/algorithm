#include<stdio.h> 
#include<malloc.h>    
#include<process.h>  

#define OVERFLOW -2
#define OK 1
#define ERROR 0

typedef int Status;
typedef int QElemType; 

typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;   //两个队列指针
	QueuePtr rear;    
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(OVERFLOW);
	Q->front->next=NULL;
	return OK;
}


Status EnQueue(LinkQueue *Q, QElemType e)
{
	QNode *p;
	p = (QueuePtr)malloc(sizeof(QNode));   //申请一个QNode结点
	if(!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;   //让上一个结点的next指针指向当前结点，形成链式结构
	Q->rear = p;        //让队尾指针指向当前结点
	return OK;
}


Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QNode *p;
	if(Q->front == Q->rear)    //如果队头指针指向队尾指针，队列为空
		return ERROR;
	p = Q->front->next;     //将要出队结点暂存到p中
	*e = p->data;          //将实际值赋给e
	Q->front->next=p->next; //让队头指针指向下一个

	if(Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}

int main()
{
	LinkQueue Q;    //定义一个队列
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