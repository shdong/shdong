#include <iostream>
using namespace std;
typedef double ElemType;

typedef struct lnode {
	ElemType data;
	struct lnode *next;
}LNode;

//假设是带头结点的单链表，第一个元素结点是首结点
bool initLkList(LNode* &L) {
	L = new LNode;  if (!L) return false;
	L->next = 0;
	return true;
}

//------方法1---------
//从源单链表srcL(source List)复制创建一个与它一样的单链表tgtL (target List)
//函数规范也可以写成bool copyLkList(LNode* s, LNode* t) {
bool copyLkList(LNode* srcL, LNode* tgtL) {
	initLkList(tgtL);
	LNode *p = srcL;
	LNode *q = tgtL;
	while (p->next) {
		q->next = new LNode; q->next->next = 0;
		q->next->data = p->next->data;
		
		p = p->next;
		q = q->next;
	}
}

//------方法2，可以利用基本操作insert_back来完成copyLkList，代码如下---------
bool insert_back(LNode *L, ElemType e) {
	LNode *p = new LNode;  if (!p) return false;
	p->data = e;
	p->next = 0;

	//go to end of the list
	LNode *q = L;
	while (q->next)
		q = q->next;
	q->next = p;

	return true;
}

bool copyLkList_2(LNode* srcL, LNode* tgtL) {
	initLkList(tgtL);
	LNode *p = srcL->next;

	while (p) {
		insert_back(tgtL, p->data);
		p = p->next;
	}
}