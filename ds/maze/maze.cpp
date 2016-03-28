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
	int x;
	int y;
} Position;

Position *end = 0;

bool canGo(Position pos) {
	return maze[pos.x][pos.y] == 0;
}

bool isExitPos(Position pos) {
	if (pos.x == end->x &&pos.y == end->y) return true;
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
	pre_position[pos.x][pos.y] = pre_pos; //记录路径
	maze[pos.x][pos.y] = 2;
}


bool goMaze(Position pre_pos,Position pos) {
	if (!canGo(pos)) return false; //该位置是墙或已经探索过
	makeFoot(pre_pos, pos);
	if(isExitPos(pos)) return true; //已经走到出口，不再探索	

	Position next_pos;
	next_pos.x = pos.x + 1; next_pos.y = pos.y;
	
	if (goMaze(pos,next_pos)) return true; 

	next_pos.x = pos.x; next_pos.y = pos.y + 1;
	if (goMaze(pos, next_pos)) return true;

	next_pos.x = pos.x - 1; next_pos.y = pos.y;
	if (goMaze(pos, next_pos)) return true;

	next_pos.x = pos.x; next_pos.y = pos.y - 1;
	if (goMaze(pos, next_pos)) return true;
	return false;
}

//输出逆向的路径
#include <iostream>
void printPath(Position start_pos, Position end_pos) {
	for (Position pos = end_pos; pos.x != -1&&pos.y != -1;
	      pos = pre_position[pos.x][pos.y]) {
		std::cout << pos.x << "," << pos.y << "\n";
	}	
}
int main() {
	Position start_pos, end_pos;
	start_pos.x = 1, start_pos.y = 1;
	end_pos.x = 5, end_pos.y = 5;
	end = &end_pos;

	Position pre_pos; pre_pos.x = -1; pre_pos.y = -1;
	goMaze(pre_pos,start_pos);

	printPath(start_pos, end_pos);

	return 0;
}