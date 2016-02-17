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
	//分配空间
	S.base = (ElemType*)malloc
		(STACK_INIT_SIZE * sizeof(ElemType));
	if (!S.base)	return NoMemory;
	S.top = S.base;           //设置指针
	S.stacksize = STACK_INIT_SIZE;  //设置大小
	return OK;
}

int Push(SqStack &S, ElemType e) {
	//若空间不够，重新分配
	if (S.top - S.base >= S.stacksize) {
		S.base = (ElemType *)realloc
			(S.base, (S.stacksize +
				STACKINCREMENT)*
				sizeof(ElemType));
		if (!S.base) return NoMemory;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e; //插入数据
	return OK;
}

int Pop(SqStack &S, ElemType &e)
{
	if (S.top == S.base)  //空栈
		return ERROR;
	e = *--S.top;       //出栈
	return OK;
}

bool Top(SqStack &S, ElemType &e)
{
	if (S.top == S.base)  //空栈
		return false;
	e = *(S.top-1);       //出栈
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
	char * s = "-{}[+([9]-[])]"; // [(])，(()]";
	bool ret = isBracketsMatching(s);
	if (ret == false)
		std::cout << "括号不匹配\n";
	else std::cout << "括号匹配\n";

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