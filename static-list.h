/*静态链表
实现静态链表的关键是构造malloc函数和free函数
利用大数组实现的静态链表，只需要修改游标，比顺序链表更方便*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000

typedef int Status;
typedef char ElemType;
Status visit(ElemType c)
{
	printf("%c", c);
	return OK;
}

typedef struct
{
	ElemType data;
	int cur;
}Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)//构造
{
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		space[i].cur = i + 1;
	space[MAXSIZE - 1].cur = 0;
	return OK;
}
int Malloc_SSL(StaticLinkList space)
{
	int i = space[0].cur;
	if (space[0].cur)
		space[0].cur = space[i].cur;
	return i;

}
void Free_SSL(StaticLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;

}
int ListLength(StaticLinkList L)
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}
Status ListInsert(StaticLinkList L, int i, ElemType e)//插入
{
	int j, k, l;
	k = MAXSIZE - 1;
	if (i < 1 || i>ListLength(L) + 1)
		return ERROR;
	j = Malloc_SSL(L);
	if (j)
	{
		L[j].data = e;
		for (l = 1; l <= i - 1; l++)
			k = L[k].cur;
		L[j].cur = L[k].cur;
		L[k].cur = j;
		return OK;
	}
	return ERROR;
}
Status ListDelete(StaticLinkList L, int i)//删除
{
	int j, k;
	if (i<1 || i>ListLength(L))
		return ERROR;
	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur;
	j = L[k].cur;
	L[k].cur = L[j].cur;
	Free_SSL(L, j);
	return OK;
}
Status ListTraverse(StaticLinkList L)//遍历
{
	int j = 0;
	int i = L[MAXSIZE - 1].cur;
	while (i)
	{
		visit(L[i].data);
		i = L[i].cur;
		j++;
	}
	return j;
	printf("\n");
	return OK;
}
