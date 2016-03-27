#include <iostream>
#include "SqList_Op.h"
int main() {
	SqList L;
	ElemType e;
	e = 10.5;
	L.push_back(e);
	e = 20.5;
	L.push_back(e);
	e = 30.5;
	L.push_back(e);
	std::cout << L.size() << "\n";

	L[1] = 200.5;
	std::cout << L[1] << "\n";


	for (int i = 0; i < L.size(); i++)
		std::cout << L[i] << "\n";

	return 0;
}