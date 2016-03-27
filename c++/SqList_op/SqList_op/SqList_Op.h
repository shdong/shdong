#pragma once
typedef double ElemType;

class SqList {
	ElemType *data;
	int length;
	int capacity;
public:
	SqList(int capacity = 10); //InitSqList();
	bool push_back(ElemType e);
	int size() { return length; }
	ElemType& operator[](int i);
};