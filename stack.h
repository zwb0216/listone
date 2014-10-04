/*
栈，一种特殊的线性表.
顺序储存。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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
	int top;
}SqStack;
Status visist(SElemType c)
{
	printf("%d", c);
	return OK;
}
Status InitStack(SqStack *S)//初始化，构造
{
	S->top = -1;
	return OK;
}
Status ClearStack(SqStack *S)//清空
{
	S->top = -1;
	return OK;
}
Status StackEmpty(SqStack S)//判断空栈
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}
int StackLength(SqStack S)
{
	return S.top + 1;
}
Status GetTop(SqStack S, SElemType *e)//返回栈顶
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}
Status Push(SqStack *S, SElemType e)//插入
{
	if (S->top == MAXSIZE - 1)
	{
		return ERROR;
	}
	S->top++;
	S->data[S->top] = e;
	return OK;
}
Status Pop(SqStack *S, SElemType *e)//删除
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];
	S->top--;
	return OK;
}
Status StackTraverse(SqStack S)
{
	int i;
	i = 0;
	while (i <= S.top)
	{
		visist(S.data[i++]);
		printf("\n");
		return OK;
	}

}
