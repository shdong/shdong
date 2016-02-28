#include <iostream>
#include <malloc.h>

typedef struct {
	int id;
	double score;
}student;

typedef student ElemType;
typedef int KeyType;

typedef struct h_lnode {
	ElemType data;
	struct h_lnode *next;
}HLNode;

typedef struct {
	// int *array = (int *) malloc(100 * sizeof(int))
	HLNode* *table; // HLNode*  table[100]
	int size;
}HashTable;

int table_size = 13;

int Hash(KeyType key) {	
	return key%table_size;
}

bool InitHashTable(HashTable &hashT) {
	hashT.table = (HLNode* *)malloc(table_size*sizeof(HLNode*));
	if (hashT.table == 0) return false;

	hashT.size = table_size;
	for (int i = 0; i < hashT.size; i++)
		hashT.table[i] = 0;
	return true;
}

bool InsertHashTable(HashTable &hashT,ElemType data) {
	int address = Hash(data.id);
	HLNode *p = new HLNode;
	if (!p) return false;
	p->data = data; 
	p->next = hashT.table[address];
	hashT.table[address] = p;
	return true;
}

bool FindHashTable(HashTable &hashT, KeyType key,ElemType &e) {
	int a = Hash(key);
	HLNode *p = hashT.table[a];
	while (p) {
		if (p->data.id = key) {
			e = p->data;
			return true;
		}
		else p = p->next;
	}
	return false;
}

#include <fstream>
bool readHashTable(HashTable &hT,const char *file) {
//	std::ofstream oF("sss.txt");	oF.close();

	std::ifstream iF(file);
	if (!iF) return false;
	int size;
	iF >> size;
	table_size = size;
	InitHashTable(hT);

	ElemType data; //student
	
	while (iF >> data.id) {
		iF >> data.score;
		InsertHashTable(hT, data);
	}

	return true;
}
int main() {
	HashTable hT;
	ElemType data;
	KeyType k;	
	readHashTable(hT,"data.txt");
//	InsertHashTable(hT,data);

	k = 17;
	if( FindHashTable(hT, k, data))
		std::cout << data.id << " " << data.score << "\n";
	else std::cout << "Î´ÕÒµ½\n";
}