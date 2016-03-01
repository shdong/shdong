#include <iostream>
using namespace std;
typedef double ElemType;

typedef struct lnode {
	ElemType data;
	struct lnode *next;
}LNode;

//�����Ǵ�ͷ���ĵ�������һ��Ԫ�ؽ�����׽��
bool initLkList(LNode* &L) {
	L = new LNode;  if (!L) return false;
	L->next = 0;
	return true;
}

//------����1---------
//��Դ������srcL(source List)���ƴ���һ������һ���ĵ�����tgtL (target List)
//�����淶Ҳ����д��bool copyLkList(LNode* s, LNode* t) {
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

//------����2���������û�������insert_back�����copyLkList����������---------
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