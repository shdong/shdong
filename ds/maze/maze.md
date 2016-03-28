迷宫问题：迷宫可以看成一个由房间组成的二维矩阵，其中有一个入口、一个（若干）出口，其他位置可以是堵塞的墙或可进的房间，要求从入口出发，寻找一个到达一个出口的路径。  
不同迷宫问题，从当前的位置可以有不一样的下一步探索方向（如东南西北4个方向，有的问题也可能再加上对角线四个方向如东南、西南、西北、东北）。

程序中通常可以用一个二维数据表示迷宫，如：
```
int maze[5][5] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
}; 
```
其中的1表示墙壁，0表示可以走的位置。通常约定每个位置的探索方向有哪些，比如“只能横着走或竖着走，不能斜着走”，即只有最多4个方向可前进。

由于边缘和角点位置只有3个和2个可前进位置，为避免程序对这些位置坐特殊的处理，我们习惯在这个迷宫外围再认为地增加一堵墙，以方便算法的编写，即将迷宫数组转化成如下形式：
```
int maze[7][7] = {
  1, 1, 1, 1, 1, 1, 1,
  1, 0, 1, 0, 0, 0, 1,
  1, 0, 1, 0, 1, 0, 1,
  1, 0, 0, 0, 0, 0, 1,
  1, 0, 1, 1, 1, 0, 1,
  1, 0, 0, 0, 1, 0, 1,
  1, 1, 1, 1, 1, 1, 1
}; 
```

求解算法：有深度优先搜索和广度优先搜索两种探索方式。

深度优先搜索又称为“回溯法”，即每次沿着能走的路径走下去，并记录下走过的位置，当发现某个位置不通时，就回溯到其前一个位置。由于回退的过程是一个“后进先出”的过程，因此，保持这个历史路劲可采用“堆栈”这种数据结构。根据堆栈是否在程序中自己构造堆栈，这种“回溯法”的迷宫求解算法可以分为“递归法” 和“非递归法”。

为了避免循环探索，对走过的位置需要标记，即"留下足迹"。“留下足迹”的一种方法是将走过的位置对应的迷宫数组的值修改为不同于0和1的一个值，比如2.

**1. 递归法**
   基本原理：  
     对当前位置，如果其是出口位置，则路径找到。如果其可通，则前进到其每个方向进一步探索。
```
typedef struct Postion_
{
      int x;
      int y;
} Postion;

Postion *end=0;

bool canGo(Postion pos){
    return maze[pos.x][pos.y]==0; 
}

bool isExitPos(Postion pos){
	if(pos.x==end->x &&pos.y==end->y) return true;
	return false;
}

void makeFoot(Postion pos){
	maze[pos.x][pos.y]=2; 
}

bool goMaze(Postion pos){
     if( !canGo(pos) ) return false; //该位置是墙或已经探索过
     if(isExitPos(pos)) return true; //已经走到出口，不再探索
    
     makeFoot(pos);     //留下足迹

     Postion next_pos;
     next_pos.x = pos.x+1; next_pos.y = pos.y;      
     if(goMaze(next_pos) ) return true; 

     next_pos.x = pos.x; next_pos.y = pos.y+1;
     if(goMaze(next_pos) ) return true; 

     next_pos.x = pos.x-1; next_pos.y = pos.y;
     if(goMaze(next_pos) ) return true; 

     next_pos.x = pos.x; next_pos.y = pos.y-1;
     if(goMaze(next_pos) ) return true; 
     return false;
}
int main(){
	Postion start_pos,end_pos;
	start_pos.x = 1,start_pos.y = 1;
	end_pos.x = 5,  end_pos.y = 5;
	end = &end_pos;
	goMaze(start_pos);

	return 0;
}
```
然而，上述程序中，虽然能走到迷宫出口，走过的路劲距离在哪里呢？因此我们需要在从一个位置pos走到下一个位置next_pos的时候，将这种行走的路径也记录下来。一种常用方法是定义一个和迷宫一样大小的数据类型是Position的二维数组，记录每个位置(next_pos)的前驱位置(pos)。
```
Postion pre_position[5][5]=
{  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
};  
```
或
```
Postion pre_position[7][7]=
{  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
};  
```
我们只要在上述的makeFoot函数中当从pos走到next_pos时，在next_pos对应的pre_position处做一下记录就可以了, 即：
```
pre_position[next_pos.x][next_pos.y] = pos;
```
为此，需要修改一下留下足迹函数makeFoot用于记录其前一个位置，同时修改goMaze函数，提供当前位置pos的前一个位置pre_pos
```
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
	
	if (goMaze(pos,next_pos)) return true;     //从pos走到next_pos

	next_pos.x = pos.x; next_pos.y = pos.y + 1;
	if (goMaze(pos, next_pos)) return true;     //从pos走到next_pos
  
	next_pos.x = pos.x - 1; next_pos.y = pos.y;
	if (goMaze(pos, next_pos)) return true;     //从pos走到next_pos

	next_pos.x = pos.x; next_pos.y = pos.y - 1;
	if (goMaze(pos, next_pos)) return true;     //从pos走到next_pos
	return false;
}

/输出逆向的路径
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
```
[完整源代码](maze.cpp)