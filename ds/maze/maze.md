**迷宫问题**：迷宫可以看成一个由房间组成的二维矩阵，其中有一个入口、一个（若干）出口，其他位置可以是堵塞的墙或可进的房间，要求从入口出发，寻找一个到达一个出口的路径。  
不同迷宫问题，从当前的位置可以有不一样的下一步探索方向（如东南西北4个方向，有的问题也可能再加上对角线四个方向如东南、西南、西北、东北）。

程序中通常可以用一个二维数据表示迷宫，如：
```c++
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
```c++
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

**求解算法**：有深度优先搜索和广度优先搜索两种探索方式。

深度优先搜索又称为“回溯法”，即每次沿着能走的路径走下去，并记录下走过的位置，当发现某个位置不通时，就回溯到其前一个位置。由于回退的过程是一个“后进先出”的过程，因此，保持这个历史路劲可采用“堆栈”这种数据结构。根据堆栈是否在程序中自己构造堆栈，这种“回溯法”的迷宫求解算法可以分为“递归法” 和“非递归法”。

为了避免循环探索，对走过的位置需要标记，即"留下足迹"。“留下足迹”的一种方法是将走过的位置对应的迷宫数组的值修改为不同于0和1的一个值，比如2.

**1. 递归法**
   基本原理：  
     对当前位置，如果其是出口位置，则路径找到。如果其可通，则前进到其每个方向进一步探索。
```c++
typedef struct Position_
{
      int x;
      int y;
} Position;

Position *end=0;

bool canGo(Position pos){
    return maze[pos.x][pos.y]==0; 
}

bool isExitPos(Position pos){
	if(pos.x==end->x &&pos.y==end->y) return true;
	return false;
}

void makeFoot(Position pos){
	maze[pos.x][pos.y]=2; 
}

bool goMaze(Position pos){
     if( !canGo(pos) ) return false; //该位置是墙或已经探索过
     if(isExitPos(pos)) return true; //已经走到出口，不再探索
    
     makeFoot(pos);     //留下足迹

     Position next_pos;
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
	Position start_pos,end_pos;
	start_pos.x = 1,start_pos.y = 1;
	end_pos.x = 5,  end_pos.y = 5;
	end = &end_pos;
	goMaze(start_pos);

	return 0;
}
```
然而，上述程序中，虽然能走到迷宫出口，走过的路劲距离在哪里呢？因此我们需要在从一个位置pos走到下一个位置next_pos的时候，将这种行走的路径也记录下来。一种常用方法是定义一个和迷宫一样大小的数据类型是Position的二维数组，记录每个位置(next_pos)的前驱位置(pos)。
```c++
Position pre_position[5][5]=
{  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
    {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},  
};  
```
或
```c++
Position pre_position[7][7]=
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
```c++
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
```
[完整源代码](maze.cpp)

**2. 非递归法**

上述的递归函数调用如同一般的函数调用一样，程序有一个运行栈管理这些调用和被调用函数的关系。我们也可以自己管理一个记录走过路的堆栈，来进行“回溯法”的回退。 迷宫问题的非递归深度优先探索的伪代码如下：
```c++
    初始化一个栈，入口位置入栈
	while(栈不空){
		//栈顶位置为当前位置
    	while(栈不空但栈顶位置四周均不通)
               弹出栈顶
        if(栈不空){
            前进到栈顶位置的下一个可通位置
        }	
	}
```
为了检测一个位置的四周探索方向有哪些已经探索过，我们可以修改类型Position，用于记录其哪些方向已经探索过，如下：
```c++
typedef struct Position_
{
      int x;
      int y;
      int direction; //0表示其四周未探索过，1,2,3,4分别表示其东南西北已经探索过。
} Position;
```
为此，我们需要一个数据元素类型是Position的堆栈，其代码如下：
```c++
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
	S.base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType)); //分配空间
	if (!S.base)	return false;
	S.top = S.base;           //设置指针
	S.stacksize = STACK_INIT_SIZE;  //设置大小
	return true;
}

bool Push(SqStack &S, ElemType e) {
	if (S.top - S.base >= S.stacksize) {//若空间不够，重新分配
		S.base = (ElemType *)realloc
			(S.base, (S.stacksize +
				STACKINCREMENT)*
				sizeof(ElemType));
		if (!S.base) return false;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e; //插入数据
	return true;
}

bool Pop(SqStack &S, ElemType &e)
{
	if (S.top == S.base)  //空栈
		return false;
	e = *--S.top;       //出栈
	return true;
}

bool Top(SqStack &S, ElemType &e)
{
	if (S.top == S.base)  //空栈
		return false;
	e = *(S.top - 1);       //出栈
	return true;
}

bool IsEmpty(SqStack S) {
	return S.top == S.base;
}
//---------------Stack end----------------------
```
**"前进到栈顶位置的下一个可通位置"**

我们可以将检查从当前位置cur_pos是否可前进到下一个位置next_pos的代码写成一个辅助函数如下：
```c++
//从cur_pos的四周找一个可前进的方向next_pos
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
```
因为有堆栈记录走过的路径，不需要一个pre_position这样的数组记录路径，留下足迹函数仍然是：
```c++
void makeFoot(Position pos){
	maze[pos.x][pos.y]=2; 
}

```

最后，将上述迷宫算法的伪代码变成可执行的C语言代码，如下：

```c++
//输出逆向的路径
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
			Push(S, cur_pos); //将修改了direction的当前位置cur_pos重新放回栈，走到next_pos
			
			Push(S, next_pos);		
			makeFoot(next_pos); //留下足迹
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

```
[完整代码](maze2.cpp)
