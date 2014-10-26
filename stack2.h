//两栈共享空间：对于两个相同类型的栈，可以利用共享空间来节省内存。
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
typedef struct
{
	SElemType data[MAXSIZE];
	int top1;
	int top2;
}SqDoubleStack;
Status visit(SElemType c)
{
	printf("%d", c);
	return OK;
}
Status InitStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}
Status ClearStack(SqDoubleStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}
Status StackEmpty(SqDoubleStack S)
{
	if (S.top1 == -1 && S.top2 == MAXSIZE)
		return TRUE;
	else
		return FALSE;
}
int StackLength(SqDoubleStack S)
{
	return (S.top1 + 1) + (MAXSIZE - S.top2);
}
Status Push(SqDoubleStack *S, SElemType e, int StackNumber)
{
	if (S->top1 + 1 == S->top2)
		return ERROR;
	if (StackNumber == 1)
		S->data[++S->top1] = e;
	else if (StackNumber == 2)
		S->data[--S->top2] = e;
	return OK;
}
Status Pop(SqDoubleStack  *S, SElemType *e, int StackNumber)
{
	if (StackNumber == 1)
	{
		if (S->top1 == -1)
			return ERROR;
		*e = S->data[S->top1--];
	}
	else if (StackNumber == 2)
	{
		if (S->top2 = MAXSIZE)
			return ERROR;
		*e = S->data[S->top2++];
	}
	return OK;
}
Status StackTraverse(SqDoubleStack S)
{
	int i;
	i = 0;
	while (i <= S.top1)
	{
		visit(S.data[i++]);
	}
	i = S.top2;
	while (i < MAXSIZE)
	{
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;
}
