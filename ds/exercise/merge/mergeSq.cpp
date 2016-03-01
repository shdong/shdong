#include <iostream>
using namespace std;
typedef double ElemType;

typedef struct{
	ElemType *data;
	int capacity;
	int length;
}SqList;
SqList  merge(SqList &L1, SqList &L2 ) {
	SqList L;
	L.data = new ElemType[L1.length + L2.length];
	L.capacity = L1.length + L2.length;
	L.length = L1.length + L2.length;
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length) {//都没走完
		if (L1.data[i] <= L2.data[j]) {
			L.data[k] = L1.data[i];
			k++; i++;
		}
		else {
			L.data[k] = L2.data[j];
			k++; j++;
		}
	}

	while (i < L1.length) { //L1没走完，L2走完了
		L.data[k] = L1.data[i];
		k++; i++;
	}

	while (j < L2.length) { //L1没走完，L2走完了
		L.data[k] = L2.data[j];
		k++; j++;
	}
	return L;
}

/*将e加到L的最后*/
bool insert_back(SqList &L,ElemType e) {
	if (L.length == L.capacity) return false;
	L.data[L.length] = e;
	L.length++;
	return true;
}

bool initSqList(SqList &L,int capacity) {
	L.data = new ElemType[capacity];
	if (!L.data) return false;
	L.length = 0;
	return true;
}

void outSqList(SqList &L) {
	for (int i = 0; i < L.length; i++)
		std::cout << L.data[i] << "\n";
	std::cout << "\n";
}

SqList  merge2(SqList &L1, SqList &L2) {
	SqList L;
	initSqList(L, L1.length + L2.length);	
	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length) {//都没走完
		if (L1.data[i] <= L2.data[j]) {
			insert_back(L,L1.data[i]);
			i++;
		}
		else {
			insert_back(L, L2.data[j]);
			j++;
		}
	}

	while (i < L1.length) { //L1没走完，L2走完了
		insert_back(L, L1.data[i]);
		i++;
	}

	while (j < L2.length) { //L1没走完，L2走完了
		insert_back(L, L2.data[j]);
		j++;
	}
	return L;
}
int main() {
	SqList L1, L2, L;
	ElemType e;
	initSqList(L1, 100);
	initSqList(L2, 50);

	std::cout << "插入到L1:\n"; 
	while (cin >> e)
		insert_back(L1, e);
	cin.clear(); //必须清空输入缓冲

	outSqList(L1);

	std::cout << "插入到L2:\n";
	while (cin >> e)
		insert_back(L2, e);

	outSqList(L2);

	L = merge2(L1, L2);  //merge(L1, L2);
	outSqList(L);
	return 0;
}