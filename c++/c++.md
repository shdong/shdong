
**C++ 简介**  
C++是C语言的扩展(超集)，C语言编写的程序也是合法的C++程序，C++语言除包含“过程式”(即函数)C语言的特征外，还增加了“面向对象语言”的特征。即程序可以看成许多对象通过发送、接受消息完成程序的功能。具有相同属性（即数据成员）和功能（即函数成员）的对象用一个“类”(class)来刻画它们。
  
例如一个游戏程序有”精灵“、”怪物“、”子弹“、”事件“、”事件监听器“等不同类的对象。比如一个”触摸监听器“对象检测到一个”触摸“事件对象，它可向某个”精灵“对象sprite发送一个带有该触摸对象信息touch的触摸消息 "OnTouchBegin"。sprite对象就执行自己的“OnTouchBegin”过程： sprite.OnTouchBegin(touch);

面向对象程序设计的关键要素是“类和对象”，类即数据类型，即类似于C语言中的int类型，而对象就是具体的变量，用以表示实际的数据。类则是用于刻画同类对象的共同特性有哪些。 类类似于C语言的结构，实际上C语言的结构在C++中就称之为"类"。因此类表示了某种抽象概念，描述了该类对象具有哪些数据(成员变量)和功能（成员函数）。如在游戏中定义一个怪物monster类,具有比如名字、位置、颜色、纹理等信息，还具有比如 “移动”、“死亡”等功能。

```
struct student{
	int id; 
	double score;

	double get_id() {
	    return score; 
	}
	double get_id() {
	    return score; 
	}
	double set_id( int i) {
		id = i;
	double set_score(double s) {
		score = s;
	}
};
```

上述代码就定义了一个叫做“student”的类型，这种类的对象具有类型分别为int和double的数据成员id和score。 此外，这种类的对象还具有 查询 (如get_id) 和 修改 (如set_id)的函数成员，用于获取或修改其数据成员id和score。

```
int main(){
	student stu;

    /* 下列2句的结果是一样的，都是修改stu对象的数据成员id */
	stu.id = 2;
	stu.set_id(2) ; 

	return 0；
}
```


**输入输出**

```
#include <iostream>   
int main_00() {
	int x, y;
	std::cin >> x >> y;   //std是标准库名字空间
	std::cout << x << " " << y << '\n';
	return 0;
}
```

C++增加了一个新的单行注释，即从“//”开头的这一行后面的都是程序注释而不是代码。

C++提供了实现各种输入输出功能的各种类，成为“输入输出流库”，它将输入输出看成从或向一个对象流动的数据流。如<iostream>就是一个输入输出库的头文件，其中包含了各种输入输出相关的类的定义。

为了避免程序中变量或类的名称相同发生冲突(如不同的软件库都提供了一个叫做Vector3的数学向量类，就会发生冲突)，通过将 类型名、变量名等都放入某个所谓的“名字空间(namespace)”就可以避免这种名字冲突。如两个不同班级都有一个叫做“李平”的同学，我们就可以通过这两个李平所属的“班级（相当于名字空间）”来区分它们。如 “班级A::李平”、“班级B::李平”。



1.  [C++ tutorial for C users](http://www.4p8.com/eric.brasseur/cppcen.html)

2. [http://www.tutorialspoint.com/cplusplus/cpp_quick_guide.htm](http://www.tutorialspoint.com/cplusplus/cpp_quick_guide.htm)

3. [http://www.w3schools.in/cplusplus/intro/](http://www.w3schools.in/cplusplus/intro/)