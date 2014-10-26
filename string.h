//串
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 40

typedef int Status;
typedef int ElemType;

typedef char String[MAXSIZE + 1];
Status StrAssign(String T, char *chars)
{
	if (strlen(chars) > MAXSIZE)
		return ERROR;
	else
	{
		T[0] = strlen(chars);
		for (int i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return OK;
	}
}

Status StrCopy(String S, String T)
{
	for (int i = 0; i <= S[0]; i++)
		T[i] = S[i];
	return OK;
}

Status StrEmpty(String S)
{
	if (S[0] == 0)
		return TRUE;
	else
		return FALSE;
}

int StrCompare(String S, String T)
{
	for (int i = 0; i <= S[0] && i <= T[0];++i)
	if (S[i] != T[i])
		return S[i] = T[i];
	return S[0] = T[0];
}

int StrLength(String S)
{
	return S[0];
}
Status ClearString(String S)
{
	S[0] = 0;
	return OK;
}

Status Concat(String T, String S1; String S2)
{
	if (S1[0] + S2[0] <= MAXSIZE)
	{
		for (int i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (int i = 1; i <= S2[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = S1[0] + S2[0];
		return TRUE;
	}
	else
	{
		for (int i = 1; i <= S1[0]; i++)
			T[i] = S1[i];
		for (int i = 0; i <= MAXSIZE - S1[0]; i++)
			T[S1[0] + i] = S2[i];
		T[0] = MAXSIZE;
		return FALSE;
	}
}

Status SubString(String Sub, String S, int pos, int len)
{
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1)
		return ERROR;
	for (int i = 1; i < +len; i++)
		Sub[i] = S[pos + i - 1];
	Sub[0] = len;
	return OK;
}

int index(String S, String T, int pos)
{
	int i = pos;
	int j = 1;
	while (i <= S[0] && j < T[0])
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

int index2(String S, String T, int pos)
{
	int n, m, i;
	String sub;
	if (pos > 0)
	{
		n = StrLength(S);
		m = StrLength(T);
		i = pos;
		while (i <= n - m + 1)
		{
			SubString(sub, S, i, m);
			if (StrCompare(sub, T) != 0)
				++i;
			else
				return i;

		}
	}
	return 0;
}

Status StrInsert(String S, int pos, String T)
{
	int i;
	if (pos<1 || pos>S[0] + 1)
		return ERROR;
	if (S[0] + T[0] <= MAXSIZE)
	{
		for (i = S[0]; i >= pos; i--)
			S[i + T[0]] = S[i];
		for (i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = S[0] + T[0];
		return OK;
	}
	else
	{
		for (i = MAXSIZE; i <= pos; i--)
			S[i] = S[i = T[0]];
		for (i = pos; i < pos + T[0]; i++)
			S[i] = T[i - pos + 1];
		S[0] = MAXSIZE;
		return FALSE;
	}
}

Status StrDelete(String S, int pos, int len)
{
	if (pos<1 || pos>S[0] - len + 1 || len < 0)
		return ERROR;
	for (i = pos + len; i <= S[0]; i++)
		S[i - len] = S[i];
	S[0] -= len;
	return OK;
}

Status Replace(String S, String T, String V)
{
	int i = 1;
	if (StrEmpty(T))
		return ERROR;
	do{
		i = index(S, T, V);
		if (i)
		{
			StrDelete(S, i, StrLength(T));
			StrInsert(S, i, V);
			i += StrLength(V);
		}
	} while (i);
	return OK;
}

void StrPrint(String T)
{
	for (int i = 1; i <= T[0]; i++)
		printf("%c", T[i]);
	printf("\n");

}
void NextPrint(int next[], int length)
{
	for (int i = 1; i <= length; i++)
		printf("%d", next[i]);
	printf("\n");
}
void getnext(String T, int *next)
{
	int i, j;
	i = 1;
	j = 0;
	next[1] = 0;
	while (i < T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int indexkmp(String S, String T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	getnext(T, next);
	while (i<=S[0]&&j<=T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}

void getnextval(String T, int *nextval)
{
	int i, j;
	i = 1;
	j = 2;
	nextval[1] = 0;
	while (i<T[0])
	{
		if (j == 0 || T[i] == T[j])
		{
			++i;
			++j;
			if (T[i] != T[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}

int indexkmpupdata(String S, String T, int pos)
{
	int i = pos;
	int j = 1;
	int next[255];
	getnextval(T, next);
	while (i <= S[0] && j <= T[0])
	{
		if (j == 0 || S[i] == T[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j > T[0])
		return i - T[0];
	else
		return 0;
}
