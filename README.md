#include <stdio.h>    
#include <string.h>
#include <ctype.h>     
#include <stdlib.h>   
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE 0

#define MAXSIZE 20 

typedef int Status;
typedef int ElemType;


Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

typedef struct Node
{
	ElemType data;
	Node *next;
}Node;
typedef struct Node *LinkList;
//构建一个空的线性表L
Status InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof (Node));//产生头结点
	if (!(*L))//内存分配失败
		return ERROR;
	(*L)->next = NULL;//建立空指针
}
//摧毁线性表
void DestroyList(LinkList *L)
{
	LinkList q;
	while (*L)
	{
		q = (*L)->next;
		free(*L);
		*L = q;
	}
}
//若L为空表，则返回TRUE，否则返回FALSE
Status ListEmpty(LinkList L){
	if (L->next)
		return FALSE;
	else
		return TRUE;
}
//将L重置为空表
Status ClearList(LinkList *L)
{
	LinkList p, q;
	p = (*L)->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	return OK;
}
//用e返回L中第i个数据元素的值
Status GetElem(LinkList L, int i, ElemType *e)
{
	int j;
	LinkList p;
	p = L->next;
	j = 1;
	while (p&&j<i)
	{
		p = p->next;
		++j;
	}
	if (!p || j>i)
		return ERROR;
	*e = p->data;
	return OK;

}
//返回L中第一个与e满足关系的排序，若不存在，返回0
int LocateElem(LinkList L, ElemType e)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		if (p->data == e)
			return i;
		p = p->next;
	}
}
//返回元素个数
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p = L->next;
	while (p)
	{
		i++;
		p = p->next;
	}
	return i;
}
//对每个元素调用visit
Status ListTraverse(LinkList L)
{
	LinkList p = L->next;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
//插入
Status ListInsert(LinkList *L, int i, ElemType e)
{
	int j;
	LinkList p, s;
	p = *L;
	j = 1;
	while (p&&j<i)
	{
		p = p->next;
		++j;

	}
	if (!p || j>i)
		return ERROR;
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//删除
Status ListDelete(LinkList *L, int i, ElemType *e)
{
	int j;
	LinkList p, q;
	p = *L;
	j = 1;
	while (p->next &&j<i)
	{
		p = p->next;
		++j;

	}
	if (!(p->next) || j>i)
		return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	return OK;
}
//头插法
void CreateListHead(LinkList *L, int n)
{
	LinkList p;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	for (i = 0; i < n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		p->next = (*L)->next;
		(*L)->next = p;
	}

}
//尾插法
void CreateListTail(LinkList *L, int n)
{
	LinkList p, r;
	int i;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;
	for (i = 0; i < n; i++)
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
//找前驱
Status PriorElem(LinkList L, ElemType r, ElemType *pre)
{
	LinkList q, p = L->next;
	while (p->next)
	{
		q = p->next;
		if (q->data=r)
		{
			*pre = p->data;
			return OK;
		}
		p = q;
		return INFEASIBLE;
	}
}
//找后继
Status NextElem(LinkList L, ElemType r, ElemType *next)
{
	LinkList p = L->next;
	while (p->next)
	{
		if (p->data = r)
		{
			*next = p->next->data;
			return OK;
		}
		p = p->next;
	}
	return INFEASIBLE;
}
