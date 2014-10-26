//循环队列，顺序存储
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
typedef int QElemType;

typedef struct
{
	QElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

Status visit(QElemType c)
{
	printf("%d", c);
	return OK;
}

Status InitQueue(SqQueue *Q)
{
	Q->front = 0;
	Q->rear = 0;
	return OK;
}

Status ClearQueue(SqQueue *Q)
{
	Q->front = Q->rear = 0;
	return OK;
}

Status QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status GetHead(SqQueue Q, QElemType *e)
{
	if (Q.front == Q.rear)
		return ERROR;
	*e = Q.data[Q.front];
	return OK;
}

Status EnQueue(SqQueue *Q, QElemType e)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
		return ERROR;
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	return OK;
}

Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)
		return ERROR;
	*e = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	return OK;
}

Status QueueTraverse(SqQueue Q)
{
	int i = Q.front;
	while ((i+Q.front)!=Q.rear)
	{
		visit(Q.data[i]);
		i = (i + 1) % MAXSIZE;
	}
	printf("\n");
	return OK;
}
