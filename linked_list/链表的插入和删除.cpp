#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

int num = 0;     //ͳ�ƽ������������ĸ��� 

typedef int Status; 
typedef int ElemType;

typedef struct LNode	//���嵥����������
{
	ElemType data;
    struct LNode *next;
}LinkList;

LinkList * InitList() //��ʼ��������Ҫ�����������ݣ���Ӧ���ȳ�ʼ������ 
{
	LinkList *p , *q, *L;
	int i;	
	
	L = (LinkList *)malloc(sizeof(LinkList));  	//����ͷ���
	L->next = NULL;
	p = q = L;
	for (i = 1; i <= 5; i++)
	{
		p = (LinkList *)malloc(sizeof(LinkList));
		p->data = i;  //��ֵ 
		
		q->next = p;
		q = p;
		p->next = NULL;	

	}
	printf("��ʼ������ɹ���\n");
	return L;
}

Status ListInsert(LinkList * L, int i, ElemType e)//�ڵ�i��λ�ò���Ԫ��e
{
	LinkList * p = L;    //����һ���ṹ��ָ�� ��ָ��ͷ���   
	LinkList * s; 
	int j = 0;

	while(p && j < i-1)   //�ҵ�Ҫ����λ�õ�ǰһ���ڵ� 
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


Status ListDelete(LinkList * L, int i, ElemType * e)//ɾ����i��Ԫ����e����ֵ
{
	LinkList * p = L;    //����һ���ṹ��ָ�� ��ָ��ͷ���   
	LinkList * q; 
	int j = 0;
	while(p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i - 1)
		return ERROR;
	
	q = p->next;       //��qָ��Ҫɾ���Ľڵ� 
	p->next = q->next;
	*e = q->data;
	
	free(q);
	return OK;
}

Status GetElem(LinkList * L, int i, ElemType *e)//��ʾĳ��ĳ��ֵ
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
	  
	printf("�������в�����5��ֵ��\n");	
	display(L);
	
	
	printf("\n������Ҫɾ����ֵ��λ��:\n");
	scanf("%d", &i);
	if(i > 6)
	{
		exit(0);	
	}
	
	if(i>0 && i<6)
	{
		if (ListDelete(L, i, &e))
	    	printf("�ѳɹ�ɾ����λ�õ�ֵ��\n");
	}
	
	display(L);
	//printf("%d", e);
	
	printf("\n������ʾ�����е��ĸ�����\n");
	scanf("%d", &i);
	if (GetElem(L, i, &e))
		printf("��λ��Ԫ�ص�ֵΪ:%d\n", e);
		
	printf("������������������ĸ�λ�ò���һ��ʲô��(�����ʽ��3 4):\n");
	scanf("%d %d", &i, &e);
	if (ListInsert(L, i, e))
	{
		printf("����ɹ�!���º����������Ϊ��\n");
		display(L); 
	}
		
	return 0;
}
