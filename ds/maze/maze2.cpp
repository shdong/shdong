int maze[7][7] = {
	1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 1, 0, 1,
	1, 1, 1, 1, 1, 1, 1
};
typedef struct Postion_
{
	int x;
	int y;
	int direction; //0��ʾ������Ϊ̽������1,2,3,4�ֱ��ʾ�䶫�������Ѿ�̽������
} Position;

Position *end = 0;

bool canGo(Position pos) {
	return maze[pos.x][pos.y] == 0;
}

bool isExitPos(Position pos) {
	if (pos.x == end->x &&pos.y == end->y) return true;
	return false;
}

//--------------Stack start---------------
#include <malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef Position  ElemType;
typedef struct {
	ElemType *base;
	ElemType *top;
	int       stacksize;
} SqStack;

bool InitStack(SqStack &S) {
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType)); //����ռ�
	if (!S.base)	return false;
	S.top = S.base;           //����ָ��
	S.stacksize = STACK_INIT_SIZE;  //���ô�С
	return true;
}

bool Push(SqStack &S, ElemType e) {
	if (S.top - S.base >= S.stacksize) {//���ռ䲻�������·���
		S.base = (ElemType *)realloc
			(S.base, (S.stacksize +
				STACKINCREMENT)*
				sizeof(ElemType));
		if (!S.base) return false;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e; //��������
	return true;
}

bool Pop(SqStack &S, ElemType &e)
{
	if (S.top == S.base)  //��ջ
		return false;
	e = *--S.top;       //��ջ
	return true;
}

bool Top(SqStack &S, ElemType &e)
{
	if (S.top == S.base)  //��ջ
		return false;
	e = *(S.top - 1);       //��ջ
	return true;
}

bool IsEmpty(SqStack S) {
	return S.top == S.base;
}
//---------------Stack end----------------------

//��cur_pos��������һ����ǰ���ķ���next_pos
bool gotoNextPos(Position &cur_pos, Position &next_pos) {	
	if ( isExitPos(cur_pos)) return false;

	next_pos.x = cur_pos.x;
	next_pos.y = cur_pos.y;
	next_pos.direction = 0;
	while (cur_pos.direction < 4) {
		switch (cur_pos.direction) {
		case 0:  next_pos.x = cur_pos.x + 1;         break;
		case 1:  next_pos.y = cur_pos.y + 1;         break;
		case 2:  next_pos.x = cur_pos.x - 1;         break;
		case 3:  next_pos.y = cur_pos.y - 1;         break;
		}
		cur_pos.direction++;
		if (canGo(next_pos)) return true;
	}
	return false;
}

void makeFoot(Position pos) {
	maze[pos.x][pos.y] = 2;
}


//��������·��
#include <iostream>
void printPath(SqStack S) {
	Position pos;
	while (!IsEmpty(S)) {
		Pop(S, pos);
		std::cout << pos.x << "," << pos.y << "\n";
	}
}

void goMaze(Position start_pos) {
	Position cur_pos, next_pos;
	SqStack S;
	InitStack(S);
	Push(S, start_pos);
	makeFoot(start_pos);

	while (!IsEmpty(S)) {
		while (Top(S, cur_pos) && cur_pos.direction>=4)
			Pop(S, cur_pos);

		if ( Pop(S, cur_pos) && gotoNextPos(cur_pos, next_pos)) {
			Push(S, cur_pos); //���޸���direction�ĵ�ǰλ��cur_pos���·Ż�ջ���ߵ�next_pos
			
			Push(S, next_pos);		
			makeFoot(next_pos); //�����㼣
			if (isExitPos(next_pos)) break;
		}
	}
	printPath(S);
}

int main() {
	Position start_pos, end_pos;
	start_pos.x = 1, start_pos.y = 1;
	end_pos.x = 5, end_pos.y = 5;
	end = &end_pos;
	start_pos.direction = 0;
	goMaze(start_pos);

	return 0;
}