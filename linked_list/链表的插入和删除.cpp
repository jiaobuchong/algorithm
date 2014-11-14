#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

int num = 0;     //统计进入链表中数的个数 

typedef int Status; 
typedef int ElemType;

typedef struct LNode	//定义单链表结点类型
{
	ElemType data;
    struct LNode *next;
}LinkList;

LinkList * InitList() //初始化链表，若要重新输入数据，就应该先初始化链表 
{
	LinkList *p , *q, *L;
	int i;	
	
	L = (LinkList *)malloc(sizeof(LinkList));  	//创建头结点
	L->next = NULL;
	p = q = L;
	for (i = 1; i <= 5; i++)
	{
		p = (LinkList *)malloc(sizeof(LinkList));
		p->data = i;  //赋值 
		
		q->next = p;
		q = p;
		p->next = NULL;	

	}
	printf("初始化链表成功！\n");
	return L;
}

Status ListInsert(LinkList * L, int i, ElemType e)//在第i个位置插入元素e
{
	LinkList * p = L;    //创建一个结构体指针 ，指向头结点   
	LinkList * s; 
	int j = 0;

	while(p && j < i-1)   //找到要插入位置的前一个节点 
	{
		p = p->next;
		++j;
	}

	if(!p || j > i - 1)
		return ERROR;
		
	s = (LinkList *)malloc(sizeof(LinkList));
	s->data = e;
	s->next = p->next;
	p->next = s;	
	return OK;
}


Status ListDelete(LinkList * L, int i, ElemType * e)//删除第i个元素用e返回值
{
	LinkList * p = L;    //创建一个结构体指针 ，指向头结点   
	LinkList * q; 
	int j = 0;
	while(p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i - 1)
		return ERROR;
	
	q = p->next;       //让q指向要删除的节点 
	p->next = q->next;
	*e = q->data;
	
	free(q);
	return OK;
}

Status GetElem(LinkList * L, int i, ElemType *e)//显示某个某个值
{
	
	LinkList * p = L;
	int j = 0;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	
	if(!p || j > i)
		return ERROR;
	*e = p->data;
	return OK;
}


void display(LinkList * L)
{	
	LinkList * p = L->next;
	
	while(p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
}

int main()
{
	LinkList * L;
	int i;
	int e;
	
	L = InitList();
	  
	printf("在链表中插入了5个值：\n");	
	display(L);
	
	
	printf("\n请输入要删除的值的位置:\n");
	scanf("%d", &i);
	if(i > 6)
	{
		exit(0);	
	}
	
	if(i>0 && i<6)
	{
		if (ListDelete(L, i, &e))
	    	printf("已成功删除此位置的值。\n");
	}
	
	display(L);
	//printf("%d", e);
	
	printf("\n你想显示链表中的哪个数：\n");
	scanf("%d", &i);
	if (GetElem(L, i, &e))
		printf("此位置元素的值为:%d\n", e);
		
	printf("请输入你想在链表的哪个位置插入一个什么数(输入格式如3 4):\n");
	scanf("%d %d", &i, &e);
	if (ListInsert(L, i, e))
	{
		printf("插入成功!更新后的链表数据为：\n");
		display(L); 
	}
		
	return 0;
}
