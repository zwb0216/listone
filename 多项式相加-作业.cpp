/*问题描述：有两个指数递减的一元多项式，写一程序先求这两个多项式的和，再求它们的积。
基本要求：用带表头结点的单链表作为多项式的存储表示；要建立两个单链表；多项式相加就是要把一个单链表中的结点插入到另一个单链表中去，要注意插入、删除操作中指针的正确修改。*/
#include <iostream>
using namespace std;

typedef struct Poly//定义一个多项式
{
	float coef;//多项式系数
	int   exp;//多项式指数
	struct Poly *next;
}Poly;

typedef Poly *Polynomial;//重定义一个多项式名字

void creatPoly(Polynomial &P, int n)
{
	P = new Poly;
	P->next = NULL;

	Poly *p, *q;
	p = P;

	for (int i = 1; i <= n; i++)
	{
		q = new Poly;
		cout << "第" << i << "项的系数：";
		cin >> q->coef;
		cout << "第" << i << "项的指数：";
		cin >> q->exp;
		q->next = NULL;
		p->next = q;
		p = q;
	}
}

int lengthPoly(Polynomial &P)//计算多项式项数的函数
{
	Poly *p;
	int i;

	p = P->next;
	i = 0;

	while (p != NULL)
	{
		p = p->next;
		i++;
	}

	return i;
}


void outputPoly(Polynomial &P)//输出合并后的多项式
{
	Poly *p;
	p = P->next;

	int i;
	for (i = 0; i<lengthPoly(P); i++)
	{
		cout << p->coef << "^ " << p->exp << " +";
		p = p->next;
	}
	cout << "0" << endl;
}

Poly * addPoly(Polynomial &Pa, Polynomial &Pb)//A与B相加
{
	Poly *p, *q, *h, *s;

	p = Pa->next;
	q = Pb->next;

	h = Pa;

	while (p&&q)//A与B都不为0
	{
		if (p->exp<q->exp)//A的指数小于B的指数
		{
			Pb->next = q->next;
			s = q;
			h->next = s;
			s->next = p;
			h = s;
			q = Pb->next;
		}
		else if (p->exp > q->exp)//A的指数大的话
		{
			h = p;
			p = p->next;
		}
		else//A与B的指数相等的话
		{
			p->coef = p->coef + q->coef;//A与B对应项系数求和
			if (p->coef == 0)//系数和为0
			{
				Poly *temp1;
				Poly *temp2;
				temp1 = p;
				temp2 = q;
				h->next = p->next;//删除该项数
				p = p->next;
				q = q->next;

				delete temp1;
				delete temp2;
			}
			else//A与B的指数相等的话,系数和不为0
			{
				Poly *temp;
				temp = q;

				h = p;
				p = p->next;
				q = q->next;
				delete temp;
			}
		}
	}

	if (q)  h->next = q;

	delete Pb;
	return Pa;

}
Poly * mulPoly(Polynomial &Pa, Polynomial &Pb)//A与B相乘
{
	Poly *p, *q, *h, *m;
	Poly *a, *b, *c;

	Polynomial Pc = new Poly;

	Polynomial Pd = new Poly;
	Pd->next = NULL;
	c = Pd;

	p = Pa->next;
	q = Pb->next;
	m = Pc;

	if (p&&q)//A与B都不为0
	{
		while (q)
		{
			p = Pa->next;
			while (p)//A的每一项与B的第一项相乘
			{
				h = new Poly;
				h->coef = p->coef*q->coef;//系数相乘
				h->exp = p->exp + q->exp;//指数相加
				m->next = h;
				h->next = NULL;
				m = h;
				p = p->next;
			}

			if (!Pd->next)//当Pd为空，将Pc的值复制到Pd中
			{
				a = Pc->next;
				while (a)
				{
					b = new Poly;
					b->coef = a->coef;
					b->exp = a->exp;
					b->next = NULL;
					c->next = b;
					c = b;
					a = a->next;
				}
				q = q->next;
			}
			else
			{
				Pd = addPoly(Pd, Pc);
				q = q->next;
			}
		}
	}
	return Pd;
}

void main()
{
	Polynomial Pa, Pb, Pd,Pc;//定义三个多项式类型的变量
	int a, b;//a,b为两个多项式的整体的项数
	cout << "请输入第一个一元多项式的项数:";
	cin >> a;
	cout << "请输入第二个一元多项式的项数:";
	cin >> b;

	cout << "请输入一元" << a << "项式(先输入系数，再输入指数):";
	creatPoly(Pa, a);

	cout << "请输入一元" << b << "项式(先输入系数，再输入指数):";
	creatPoly(Pb, b);

	Pd = mulPoly(Pa, Pb);
	cout << "相乘得到的多项式:";
	outputPoly(Pd);

	Pc = addPoly(Pa, Pb);
	cout << "相加得到的多项式:";
	outputPoly(Pc);1

}
