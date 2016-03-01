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
bool insert_front(LNode *L,ElemType e) {
	LNode *p = new LNode;  if (!p) return false;
	p->data = e;
	
	p->next = L->next;
	L->next = p;
	return true;
}

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

LNode *mergeLkList(LNode *L1, LNode *L2) {
	LNode *L ; //新链表的头结点指针变量
	initLkList(L);

	LNode *p = L1->next, *q = L2->next;
	while (p &&q) { //p,q分别指向两个链表的结点，是都存在的
		if (p->data < q->data) {			
			insert_back(L, p->data);
			p = p->next;
		}
		else {
			insert_back(L, q->data);
			q = q->next;
		}
	}
	while (p) {
		insert_back(L, p->data);
		p = p->next;
	}
	while (q) {
		insert_back(L, q->data);
		q = q->next;
	}
	return L;
}

void outLkList(LNode* &L) {
	LNode *p = L->next;
	while (p) {
		std::cout << p->data << "\n";
		p = p->next;
	}
	std::cout << "\n";
}

int main() {
	LNode *L1, *L2, *L;
	ElemType e;
	initLkList(L1);
	initLkList(L2);

	//输入两个 CTRL+z就结束输入
	std::cout << "插入到L1:\n";
	while (cin >> e)
		insert_back(L1, e);
	cin.clear();  //必须清空输入缓冲

	outLkList(L1);

	std::cout << "插入到L2:\n";
	while (cin >> e)
		insert_back(L2, e);

	outLkList(L2);


	L = mergeLkList(L1, L2);
	outLkList(L);
	return 0;
}