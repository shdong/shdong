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
{
	int i;
	int j;
} Position;

Position *end = 0;

bool canGo(Position pos) {
	return maze[pos.i][pos.j] == 0;
}

bool isExitPos(Position pos) {
	if (pos.i == end->i &&pos.j == end->j) return true;
	return false;
}

Position pre_position[7][7] =
{
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
};

void makeFoot(Position pre_pos, Position pos) {
	pre_position[pos.i][pos.j] = pre_pos; //记录路径
	maze[pos.i][pos.j] = 2;
}


bool goMaze(Position pre_pos,Position pos) {
	if (!canGo(pos)) return false; //该位置是墙或已经探索过
	makeFoot(pre_pos, pos);
	if(isExitPos(pos)) return true; //已经走到出口，不再探索	

	Position next_pos;
	next_pos.i = pos.i + 1; next_pos.j = pos.j;
	
	if (goMaze(pos,next_pos)) return true; 

	next_pos.i = pos.i; next_pos.j = pos.j + 1;
	if (goMaze(pos, next_pos)) return true;

	next_pos.i = pos.i - 1; next_pos.j = pos.j;
	if (goMaze(pos, next_pos)) return true;

	next_pos.i = pos.i; next_pos.j = pos.j - 1;
	if (goMaze(pos, next_pos)) return true;
	return false;
}

//输出逆向的路径
#include <iostream>
void printPath(Position start_pos, Position end_pos) {
	for (Position pos = end_pos; pos.i != -1&&pos.j != -1;
	      pos = pre_position[pos.i][pos.j]) {
		std::cout << pos.i << "," << pos.j << "\n";
	}	
}
int main() {
	Position start_pos, end_pos;
	start_pos.i = 1, start_pos.j = 1;
	end_pos.i = 5, end_pos.j = 5;
	end = &end_pos;

	Position pre_pos; pre_pos.i = -1; pre_pos.j = -1;
	goMaze(pre_pos,start_pos);

	printPath(start_pos, end_pos);

	return 0;
}