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
	QueuePtr front;   //��������ָ��
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
	p = (QueuePtr)malloc(sizeof(QNode));   //����һ��QNode���
	if(!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;   //����һ������nextָ��ָ��ǰ��㣬�γ���ʽ�ṹ
	Q->rear = p;        //�ö�βָ��ָ��ǰ���
	return OK;
}


Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QNode *p;
	if(Q->front == Q->rear)    //�����ͷָ��ָ���βָ�룬����Ϊ��
		return ERROR;
	p = Q->front->next;     //��Ҫ���ӽ���ݴ浽p��
	*e = p->data;          //��ʵ��ֵ����e
	Q->front->next=p->next; //�ö�ͷָ��ָ����һ��

	if(Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return OK;
}

int main()
{
	LinkQueue Q;    //����һ������
	InitQueue(&Q);   

	//���
	printf("����Ҫ������ٸ�����\n");
	int num, i, m, e;
	scanf("%d", &num);
	for(i=1; i <= num; i++)
	{
		printf("������Ҫ��������֣�");
		scanf("%d", &m);
		EnQueue(&Q, m);
	}

    //����	
	for(i=1; i <= num; i++)
	{
		printf("�Ƚ��ȳ������г���Ϊ%d��: ", i);
		DeQueue(&Q, &e);
		printf("%d", e);
		printf("\n");
	}
	
	return 0;
}