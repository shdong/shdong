int maze[7][7] = {
	1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 0, 0, 1,
	1, 0, 1, 0, 1, 0, 1,
	1, 0, 0, 0, 0, 0, 1,
	1, 0, 1, 1, 1, 0, 1,
	1, 0, 0, 0, 1, 0, 1,
	1, 1, 1, 1, 1, 1, 1
};

typedef struct Position_
{    /* i=-1��j=-1��ʾδ���ʹ����λ�� */
	int i,j;
} Position;

Position predecessor[7][7] = {
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
};

Position *end = 0;

bool isExitPos(Position pos) {
	if (pos.i == end->i &&pos.j == end->j) return true;
	return false;
}


/*����ʵ��һ������Ԫ����Position���͵�һ������*/
typedef Position ElemType;

typedef struct {
	ElemType *data; //
	int capacity;
	int front, rear;
}SqQueue;

int capacity = 100;

//------------------queue Start--------------
#include <malloc.h>
bool InitQueue(SqQueue &Q) {
	Q.data = (ElemType *)malloc(capacity* sizeof(ElemType));
	if (!Q.data) return false;
	Q.rear = Q.front = 0; //�ն���
	return true;
}

bool EnQueue(SqQueue &Q, ElemType e) {
	if ((Q.rear + 1) % Q.capacity == Q.front) return false;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.capacity;
	return true;
}

bool DeQueue(SqQueue &Q, ElemType &e) {
	if (Q.front == Q.rear) 	return false;   //�ն���
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % Q.capacity;
	return true;
}

bool IsEmpty(SqQueue Q) {
	return Q.rear == Q.front;
}




//------------------queue End--------------
void makeFoot(Position pre_pos, Position cur_pos) {
	predecessor[cur_pos.i][cur_pos.j] = pre_pos;
}
bool isVisited(Position pos) {
	return predecessor[pos.i][pos.j].i != -1
		&& predecessor[pos.i][pos.j].j != -1;
}

bool canGo(Position pos) {
	return maze[pos.i][pos.j] == 0 && !isVisited(pos);
}

void goMaze(Position start_pos) {
	SqQueue Q; InitQueue(Q);
	Position pre_pos = { 0,0 }, cur_pos, next_pos;
	EnQueue(Q, start_pos);
	makeFoot(pre_pos, start_pos);

	while (!IsEmpty(Q)) {
		DeQueue(Q, cur_pos);
		if (isExitPos(cur_pos))
			break; //�ҵ�����

		next_pos.i = cur_pos.i ; 
		next_pos.j = cur_pos.j + 1; //��
		if (canGo(next_pos)) { //δ���ʹ�
			EnQueue(Q, next_pos);
			makeFoot(cur_pos, next_pos);
		}

		next_pos.j = cur_pos.j - 1;//��	
		if (canGo(next_pos)) { //δ���ʹ�
			EnQueue(Q, next_pos);
			makeFoot(cur_pos, next_pos);
		}

		next_pos.i = cur_pos.i +1 ; //��	
		next_pos.j = cur_pos.j;		
		if (canGo(next_pos)) { //δ���ʹ�
			EnQueue(Q, next_pos);
			makeFoot(cur_pos, next_pos);
		}

		next_pos.i = cur_pos.i - 1; //��		
		if (canGo(next_pos)) { //δ���ʹ�
			EnQueue(Q, next_pos);
			makeFoot(cur_pos, next_pos);
		}
	}
}

//��������·��
#include <iostream>
void printPath(Position end_pos) {
	Position pos = end_pos;
	while ( pos.i != 0 
		&& pos.j != 0 ) {
		std::cout << pos.i << "," << pos.j << "\n";
		pos = predecessor[pos.i][pos.j];		
	}
}

int main() {
	Position start_pos, end_pos;
	start_pos.i = 1, start_pos.j = 1;
	end_pos.i = 5, end_pos.j = 5;
	end = &end_pos;
	goMaze(start_pos);

	printPath(end_pos);
	return 0;
}