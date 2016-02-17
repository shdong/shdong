#include <iostream>

#define OK 0
#define ERROR 1
#define NoMemory 2
#define STACK_INIT_SIZE 5
#define STACKINCREMENT 5

typedef char  ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int       stacksize;
} SqStack;

int InitStack(SqStack &S) {
	//����ռ�
	S.base = (ElemType*)malloc
		(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base)	return NoMemory;
	S.top = S.base;           //����ָ��
	S.stacksize = STACK_INIT_SIZE;  //���ô�С
	return OK;
}

int Push(SqStack &S, ElemType e) {
	//���ռ䲻�������·���
	if (S.top - S.base >= S.stacksize) {
		S.base = (ElemType *)realloc
			(S.base, (S.stacksize +
				STACKINCREMENT)*
				sizeof(ElemType));
		if (!S.base) return NoMemory;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e; //��������
	return OK;
}

int Pop(SqStack &S, ElemType &e)
{
	if (S.top == S.base)  //��ջ
		return ERROR;
	e = *--S.top;       //��ջ
	return OK;
}

bool Top(SqStack &S, ElemType &e)
{
	if (S.top == S.base)  //��ջ
		return false;
	e = *(S.top-1);       //��ջ
	return true;
}

bool IsEmpty(SqStack S) {
	return S.top==S.base;
}

bool isBracketMatch(char left_ch,char right_ch) {
	if (left_ch == '{'&&right_ch == '}') return true;
	if (left_ch == '['&&right_ch == ']') return true;
	if (left_ch == '('&&right_ch == ')') return true;
	return false;
}
bool isLeftBracket(char ch) {
	if (ch == '{' || ch == '[' || ch == '(')
		return true;
	return false;
}
bool isRightBracket(char ch) {
	if (ch == '}' || ch == ']' || ch == ')')
		return true;
	return false;
}
bool isBracketsMatching(char * str) {
	SqStack S;
	InitStack(S);
	char e;
	char *p = str;
	while (*p != '\0') {
		if (isLeftBracket(*p))
			Push(S, *p);
		else if (isRightBracket(*p)) 
		{
			if (Top(S, e) == false)
				return false;
			if (isBracketMatch(e, *p) == false)
				return false;
			Pop(S, e);
		}

		p++;
	}

	if ( !IsEmpty(S) ) return false;
	return true;

}

int main(){
	char * s = "-{}[+([9]-[])]"; // [(])��(()]";
	bool ret = isBracketsMatching(s);
	if (ret == false)
		std::cout << "���Ų�ƥ��\n";
	else std::cout << "����ƥ��\n";

	return 0;

	SqStack ss;
	ElemType a = 30;
	InitStack(ss);
	Push(ss, a);
	a = 40;
	Push(ss, a);
	a = 50;
	Push(ss, a);
	Top(ss, a);
	std::cout << a << "\n";

	while (!IsEmpty(ss)) {
		Pop(ss, a);
		std::cout << a << "\n";
	}
	return 0;
}