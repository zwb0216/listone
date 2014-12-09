//实验四：实现对图的一个指定的操作或用图解决一个应用问题
//问题描述：n个村庄之间的无向图，边上的权值w(i, j)表示村庄i和j之间道路长度．
//现要从这n个村庄中选择一个村庄新建一所医院，
//使离医院最远的村庄到医院的路程最短．
//设计一程序求解此问题．
//基本要求：
//用邻接矩阵表示无向网，应显示所选中的村庄到各村庄的最短距离。
#include <iostream>
#include <string>
using namespace std;
#define MAX 100000
#define MAX_VERTEX_NUM 30//最大顶点
typedef struct Adjmat
{
	double adj;
}Adjmat,AdjMAT[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//构建邻接矩阵
typedef struct
{
	string verx[MAX_VERTEX_NUM];
	AdjMAT arcs;
	int vexnum, arcnum;

}MGraph;//构建无向图
int LocateVex(MGraph &G, string v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.verx[i] == v)
			return i;
	}
	return -1;
}
int create(MGraph &G)
{
	int i, j, k;
	string v1, v2;
	double w;
	cout << "请输入村庄个数" << endl;
	cin >> G.vexnum;
	cout << "请输入村庄之间的道路数目" << endl;
	cin >> G.arcnum;
	for (i = 0; i < G.vexnum; i++)
	{
		cout << "请输入村庄" << i + 1 << "的名称" << endl;
		cin >> G.verx[i];
	}
	for (i = 0; i < G.vexnum;i++)
	for (j = 0; j < G.vexnum; j++)
		G.arcs[i][j].adj = MAX;
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "请输入第" << k + 1 << "线路的起点， 终点以及权值" << endl;
		cin >> v1 >> v2 >> w;
		i = LocateVex(G,v1);
		j = LocateVex(G, v2);
		G.arcs[i][j].adj = w;
		G.arcs[j][i].adj = G.arcs[i][j].adj;
	}
	return 0;
}
void Floyd(MGraph G, string P[][20], double D[][20])//寻求全源最短路径
{
	int  v, w, u;
	for (v = 0; v < G.vexnum;v++)
	for (w = 0; w < G.vexnum; w++)
	{
		D[v][w] = G.arcs[v][w].adj;
		if (D[v][w] < MAX)
			P[v][w] = G.verx[v] + "-------------->" + G.verx[w];
	}
	for (u = 0; u < G.vexnum;u++)
	for (v = 0; v < G.vexnum;v++)
	for (w = 0; w < G.vexnum; w++)
	{
		if (D[v][u] + D[u][w] < D[v][w])
		{
			D[v][w] = D[v][u] + D[u][w];
			P[v][w] = P[v][u] + "-------------->" + G.verx[w];

		}
	}
}
int main()
{
	MGraph G;
	int i, j;
	double a[MAX_VERTEX_NUM] = { 0 };
	string P[20][20];
	double D[20][20];
	double min = MAX;
	create(G);
	Floyd(G, P, D);
	for (i = 0; i < G.vexnum;i++)
	for (j = 0; j < G.vexnum; j++)
	{
		if (a[i] < D[i][j])
			a[i] = D[i][j];
	}
	for (i = 0; i < G.vexnum; i++)
	{
		if (a[i] < min)
			j = 1;
	}
	cout << "医院应建在" << G.verx[j] << "处" << endl;
	for (i = 0; i < G.vexnum; i++)
	{
		if (i != j)
		{
			cout << "村庄" << G.verx[i] << "到医院的距离是" << D[j][i];
			cout << "路径为" << P[j][i] << endl;

		}
	}
	system("pause");
}
