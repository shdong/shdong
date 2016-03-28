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
} Postion;

Postion *end = 0;

bool canGo(Postion pos) {
	return maze[pos.x][pos.y] == 0;
}

bool isExitPos(Postion pos) {
	if (pos.x == end->x &&pos.y == end->y) return true;
	return false;
}



Postion pre_position[7][7] =
{
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
	{ { -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 },{ -1,-1 } },
};

void makeFoot(Postion pre_pos, Postion pos) {
	pre_position[pos.x][pos.y] = pre_pos; //记录路径
	maze[pos.x][pos.y] = 2;
}


bool goMaze(Postion pre_pos,Postion pos) {
	if (!canGo(pos)) return false; //该位置是墙或已经探索过
	makeFoot(pre_pos, pos);
	if(isExitPos(pos)) return true; //已经走到出口，不再探索	

	Postion next_pos;
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
void printPath(Postion start_pos, Postion end_pos) {
	for (Postion pos = end_pos; pos.x != -1&&pos.y != -1;
	      pos = pre_position[pos.x][pos.y]) {
		std::cout << pos.x << "," << pos.y << "\n";
	}	
}
int main() {
	Postion start_pos, end_pos;
	start_pos.x = 1, start_pos.y = 1;
	end_pos.x = 5, end_pos.y = 5;
	end = &end_pos;

	Postion pre_pos; pre_pos.x = -1; pre_pos.y = -1;
	goMaze(pre_pos,start_pos);

	printPath(start_pos, end_pos);

	return 0;
}