//https://github.com/dstnbrkr/complexity/blob/master/graph.c

typedef double InfoType;
typedef char ElemType;
#define MAX_VEX_NUM 1000

typedef struct _ArcNode {
	int      adjvex;   //�����±�
	struct	_ArcNode  *next; //ָ����һ������
	InfoType info;    //ָ������Ϣ
}ArcNode;

typedef struct {	
	ElemType data;  //���������	
	ArcNode    *firstarc; //ָ���һ������
}VNode;

typedef struct{
	VNode vertices[MAX_VEX_NUM];  
	int v_num;//ʵ�ʶ������	
} Graph;

void initGraph(Graph &G) {
	G.v_num = 0;
}

bool AddVetex(Graph &G, ElemType e) {
	if (G.v_num == MAX_VEX_NUM) 
		return false;
	G.vertices[G.v_num].data = e;
	G.vertices[G.v_num].firstarc = 0;
	G.v_num++;
	return true;
}

bool AddArc(Graph &G,int vi,int vj, InfoType info) {
	ArcNode *p = new ArcNode();
	p->adjvex = vj;
	p->info = info;
	p->next = G.vertices[vi].firstarc;
	G.vertices[vi].firstarc = p;
	return true;
}


#include <iostream>
using std::cin;
using std::cout;
void InputGraph(Graph &G) {
	ElemType vdata;
	cout << "���������붥�����ݣ���'ctrl+Z' 'ctrl+Z'��������\n";
	while (cin >> vdata) {
		AddVetex(G,vdata);
	}
	cin.clear();  //��Ϊ����״̬

	int v1, v2;
	InfoType weight;
	cout << "�����뻡��Ϣ(��ʽΪ v1 v2 weight):";

	cin >> v1 >> v2 >> weight;
	while (v1 >= 0 && v2 >= 0) {
		AddArc(G,v1, v2, weight);
		cout << "���������Ϣ(��ʽΪ v1 v2 weight):";
		cin >> v1 >> v2 >> weight;
	}
}

void OutGraph(Graph &G) {
	for (int v = 0; v < G.v_num; v++) {
		ArcNode *p = G.vertices[v].firstarc;
		std::cout << G.vertices[v].data << "| ";
		while (p) {
			std::cout << "-->" << p->adjvex << "," << p->info;
			p = p->next;
		}
		std::cout << "\n";

	}
}

#include <fstream>
void InputGraph(Graph &G,const char *file) {
	std::ifstream iF(file);
	if (!iF) return;
	int vn, en;
	ElemType vdata;
	iF >> vn >> en;
	for (int i = 0; i < vn; i++) {
		iF >> vdata;
		AddVetex(G, vdata);
	}

	int v1, v2; InfoType info;
	for (int i = 0; i < en; i++) {
		iF >> v1>>v2>>info;
		AddArc(G, v1,v2,info);
	}

}
void Dijkstra(Graph G,int v0) {
	const double Infinity = 10000000;
	int vn = G.v_num;
	double *D = new double[vn];
	int *P = new int[vn];
	bool *S = new bool[vn];

	for (int i = 0; i < vn; i++) S[i] = false;
	S[v0] = true;
	for (int i = 0; i < vn; i++) P[i] = v0;  //P[i]�ȼ��� *(P+i)
	for (int i = 0; i < vn; i++) D[i] = Infinity;

	ArcNode *p = G.vertices[v0].firstarc;
	while (p) {
		D[p->adjvex] = p->info;
		p = p->next;
	}

	while (1) {
		double minDist = Infinity; int w = -1;
		for (int i = 0; i < vn; i++) {
			if (S[i]==false && D[i] < minDist) {
				minDist = D[i]; w = i;
			}
		}
		if (w == -1) break;
		S[w] = true;// ��w����S
		
		ArcNode *p = G.vertices[w].firstarc;
		while (p) {
			int v = p->adjvex; // w,v,cost

			if (D[w] + p->info  < D[v]) {
				D[v] = D[w] + p->info;
				P[v]= w;
			}
			p = p->next;
		}
	}

	std::cout <<v0 <<"��������ľ����ǣ�\n ";
	for (int i = 0; i < vn; i++) {
		std::cout << D[i]<<"\n";
	}

	return;
}
int main() {
	Graph graph;
	ElemType ee;
	initGraph(graph);
	InputGraph(graph, "graph.txt"); //InputGraph(graph);
	OutGraph(graph);

	Dijkstra(graph,0);

	return 0;

}

/*
1)
typedef struct{
ElemType *vertices; int capacity;
int length;
}SqList;
2)
typedef struct{
ElemType vertices[100];
int length;
}SqList;
*/
