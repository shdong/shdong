#include <iostream>

template < class Type>
class SqList {
	Type *data;
	int length;
	int capacity;
public:
	SqList(int capacity = 10); //InitSqList();
	bool push_back(Type e) {
		if (length >= capacity) return false;
		data[length] = e;
		length++;
	}
	int size() { return length; }

	Type& operator[](int i) {
		return data[i];
	}
};

template < class Type>
SqList<Type>::SqList(int capacity) {
	this->data = new Type[capacity];
	this->capacity = capacity;
	this->length = 0;
}


#include <iostream>
struct student {
	std::string name;
	double score;
};


int main() {
	SqList<double> L;
	double e;
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

	SqList<int> M;
	M.push_back(3);
	M.push_back(4);
	M.push_back(5);
	for (int i = 0; i < M.size(); i++)
		std::cout << M[i] << "\n";

	SqList<student> S;
	student stu;

	stu.name = "Li"; stu.score  = 35.5;
	S.push_back(stu);

	stu.name = "Zhang"; stu.score = 65.5;
	S.push_back(stu);

	for (int i = 0; i < S.size(); i++)
		std::cout << S[i].name.c_str()<<" "<<S[i].score << "\n";

	return 0;
}