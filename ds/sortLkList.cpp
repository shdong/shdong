#include<iostream>
using namespace std;
typedef double ElemType;

typedef struct lnode{
	ElemType data;
	struct lnode *next;
}LNode;

void InputList(LNode* &L) {
	L = new LNode;
	L->next = 0;
	ElemType data;
	while (cin >> data) {
		LNode *p = new LNode;
		p->data = data;

		LNode *q = L;
		while (q->next) {
			if (p->data > q->next->data)
				q = q->next;
			else break;
		}

		p->next = q->next;
		q->next = p;
	}
}

void Output(LNode* L) {
	LNode* p = 0;
	for (p = L->next; p; p = p->next) {
		std::cout << p->data << "\n";
	}
}


int main() {
	LNode* list;
	InputList(list);
	Output(list);
	return 0;
}