
#include "SqList_Op.h"

SqList::SqList(int capacity) {
	this->data = new ElemType[capacity];
	this->capacity = capacity;
	this->length = 0;
}

bool SqList::push_back(ElemType e) {
	if (length >= capacity) return false;
	data[length] = e;
	length++;
}


ElemType& SqList::operator[](int i) {
	return data[i];
}

