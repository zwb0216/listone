//链式栈
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <math.h>
#include <time.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20
typedef int Status;
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;
typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;
Status visit(SElemType c)
{
	printf("%d", c);
	return OK;
}
Status InitStack(LinkStack *S)
{
	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
	if (!S->top)
		return ERROR;
	S->top = NULL;
	S->count = 0;
	return OK;
}
Status ClearStack(LinkStack *S)
{
	LinkStackPtr p, q;
	p = S->top;
	while (p)
	{
		q = p;
		p = p->next;
		free(q);
	}
	S->count = 0;
	return OK;
}
Status StackEmpty(LinkStack S)
{
	if (S.count == 0)
		return TRUE;
	else
		return FALSE;
}
int StackLength(LinkStack S)
{
	return S.count;
}
Status GetTop(LinkStack S, SElemType *e)
{
	if (S.top == NULL)
		return ERROR;
	else
		*e = S.top->data;
	return OK;
}
Status Push(LinkStack *S, SElemType e)
{
	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
	s->data = e;
	s->next = S->top;
	S->top = s;
	S->count++;
	return OK;
}
Status Pop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p;
	if (StackEmpty(*S))
		return ERROR;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	free(p);
	S->count--;
	return OK;
}
Status StackTraverse(LinkStack S)
{
	LinkStackPtr p;
	p = S.top;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}
