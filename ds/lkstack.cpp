#include<malloc.h>
#include<iostream>

typedef int ElemType;

typedef struct lnode {
	ElemType data;
	struct lnode* next;
}LNode;

int add(int a, int b) {
	return a + b;
}
bool InitStack(LNode* &s) {
	s = (LNode *)malloc(sizeof(LNode));
	if (s == 0)
		return false;
	s->next = 0;
	return true;

}

bool Push(LNode *s, ElemType e) {
	LNode *p = (LNode *)malloc(sizeof(LNode));
	if (p == 0)
		return false;
	p->data = e;
	p->next = s->next;
	s->next = p;
	return true;

}

bool Pop(LNode* s, ElemType &e) {
	if (s->next == 0)
		return false;
	e = s->next->data;
	LNode *p = s->next;
	s->next = p->next;
	free(p);
	return true;
}

bool Top(LNode* s, ElemType &e) {
	if (s->next == 0)
		return false;
	e = s->next->data;
	return true;
}

bool IsEmpty(LNode *s) {
	return s->next == 0;
}


void conversion() {
	// 输入非负十进制整数，输出对应的八进制数
	LNode*  S; 
	int N,  e;
	InitStack(S); // 构造空栈
	std::cin >> N;
	while (N) {
		Push(S, N % 8);   N = N / 8;
	}
	while (!IsEmpty(S)) {
		Pop(S, e);
		std::cout << e;
	}
} // conversion


int main() {
	conversion();
	return 0;
	LNode* ss;
	InitStack(ss);
	ElemType a = 10;
	Push(ss, a);
	a = 20;
	Push(ss, a);
	a = 30;
	Push(ss, a);
	Top(ss, a);
	std::cout << a << "\n";
	while (!IsEmpty(ss)) {
		Pop(ss, a);
		std::cout << a << "\n";
	}
}
