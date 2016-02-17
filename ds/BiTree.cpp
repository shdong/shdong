#include<iostream>
typedef char ElemType;


typedef struct _binode {
	ElemType data;
	struct _binode *lchild;
	struct _binode *rchild;
}BiTNode;

void Scanf(ElemType &e) {
	std::cin >> e;
}

void PreOrderCreatBiTree(BiTNode* &T)
{
	ElemType ch;
	Scanf(ch);
	if (ch == '#') { T = 0; return; } //递归出口

	if (!(T = new BiTNode)) { //处理根
		throw "内存不够!";  
		return;
	}
	T->data = ch;

	PreOrderCreatBiTree(T->lchild);//左子树
	PreOrderCreatBiTree(T->rchild);//右子树
}


void PreOrderTraverseBiTree(BiTNode* &T)
{
	if (T == 0) {
		std::cout << "#";
		return;
	};
	std::cout << T->data;
	PreOrderTraverseBiTree(T->lchild);//左子树
	PreOrderTraverseBiTree(T->rchild);//右子树
}




void MidOrderTraverseBiTree(BiTNode* &T)
{
	if (T == 0) {
		std::cout << "#";
		return;
	};
	
	MidOrderTraverseBiTree(T->lchild);//左子树
	std::cout << T->data;
	MidOrderTraverseBiTree(T->rchild);//右子树
}


//-------------------
#define MAXQSIZE 20
#define ERROR -1
#define OK 0
typedef BiTNode* PElemType;
typedef struct {
	PElemType *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q)
{
	Q.base = (PElemType*)malloc
		(MAXQSIZE*sizeof(PElemType));
	if (!Q.base) return ERROR;
	Q.front = Q.rear = 0;
	return OK;
}

int AddQueue(SqQueue &Q, PElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;  //满队列
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}

int DeQueue(SqQueue &Q,	PElemType &e) {
	if (Q.front == Q.rear)
		return ERROR;   //空队列
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}

bool QueueEmpty(SqQueue &Q ) {
	return Q.front == Q.rear;
}
//--------------------------------------

int LevelOrderTraverse(BiTNode* T)
{
	SqQueue Q; BiTNode* p;
	InitQueue(Q);  AddQueue(Q, T); //树根入队
	while (!QueueEmpty(Q)) {        //只要队列非空
		DeQueue(Q, p);          //出队一个结点
		std::cout << p->data; ////if (!Visit(p->data))         //访问之
			return -1;
		if (p->lchild)               //左孩子入队
			AddQueue(Q, p->lchild);
		if (p->rchild)               //右孩子入队
			AddQueue(Q, p->rchild);
	}
	return 0;
}


int main() {
	BiTNode *tree; 
	PreOrderCreatBiTree(tree);
	
	PreOrderTraverseBiTree(tree);
	std::cout << "\n";
	MidOrderTraverseBiTree(tree);
	std::cout << "\n";

	LevelOrderTraverse(tree);

	return 0;
}
