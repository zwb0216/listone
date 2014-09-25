
//约瑟夫环问题(Josephus)
//用户输入M,N值，从1至N开始顺序循环数数，每数到M输出该数值，直至全部输出。写出C程序。

#include <stdio.h>
#include <stdlib.h>


//建立结点
typedef struct _RingNode
{
	int pos;  // 位置
	struct _RingNode *next;
}RingNode, *RingNodePtr;

// 创建约瑟夫环，pHead:链表头指针，count:链表元素个数
void CreateRing(RingNodePtr pHead, int count)
{
	RingNodePtr pCurr = NULL, pPrev = NULL;
	int i = 1;
	pPrev = pHead;
	while (--count > 0)
	{
		pCurr = (RingNodePtr)malloc(sizeof(RingNode));
		i++;
		pCurr->pos = i;
		pPrev->next = pCurr;
		pPrev = pCurr;
	}
	pCurr->next = pHead;  // 构成环状链表
}

void PrintRing(RingNodePtr pHead)
{
	RingNodePtr pCurr;
	printf("%d", pHead->pos);
	pCurr = pHead->next;
	while (pCurr != NULL)
	{
		if (pCurr->pos == 1)
			break;
		printf("\n%d", pCurr->pos);
		pCurr = pCurr->next;
	}
}

void KickFromRing(RingNodePtr pHead, int m)
{
	RingNodePtr pCurr, pPrev;
	int i = 1;    // 计数
	pCurr = pPrev = pHead;
	while (pCurr != NULL)
	{
		if (i == m)
		{
			// 踢出环
			printf("\n%d", pCurr->pos);    // 显示出圈循序
			pPrev->next = pCurr->next;
			free(pCurr);
			pCurr = pPrev->next;
			i = 1;
		}
		pPrev = pCurr;
		pCurr = pCurr->next;
		if (pPrev == pCurr)
		{
			// 最后一个
			printf("\n%d", pCurr->pos);    // 显示出圈循序
			free(pCurr);
			break;
		}
		i++;
	}
}

int main()
{
	int m = 0, n = 0;
	RingNodePtr pHead = NULL;
	printf("总人数是 ");
	scanf_s("%d", &n);
	printf("被踢出的号码是");
	scanf_s("%d", &m);
	if (n <= 0 || m <= 0)
	{
		printf("Input Error\n");
		system("pause");
		return 0;
	}
	// 建立链表
	pHead = (RingNodePtr)malloc(sizeof(RingNode));
	pHead->pos = 1;
	pHead->next = NULL;
	CreateRing(pHead, n);
	// 开始出圈
	printf("剔除的原始号码顺序 ");
	KickFromRing(pHead, m);
	printf("\n");
	system("pause");
	return 0;
}
/*
算法2
#include <stdio.h>

int main()
{
	int n, m, i, s = 0;
	printf("总人数是\n");
	scanf_s("%d", &n);
	printf("被踢序号\n");
	scanf_s("%d", &m);
	for (i = 2; i <= n; i++)
	{
		s = (s + m) % i;
	}
	printf("\n胜利者原始序号是%d\n", s + 1);
}
*/
