#include <iostream>
#include <malloc.h>

#include <iostream>
#include <malloc.h>

int main() {
	int a[100], c;
	int *b;
	b = &c;
	*b = 45;
	std::cout << "b=:" << b << "\n";
	std::cout << "c=:" << c << "\n";

	b = new int[20];
	for (int i = 0; i < 20; i++)
		b[i] = 3 * (i + 1);
	for (int i = 0; i < 20; i++)
		std::cout << b[i] << " ";
	std::cout << "\n\n";

	int * *p;
	p = (int* *)malloc(5 * sizeof(int *));
	for (int i = 0; i < 5; i++)
		p[i] = new int[3];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 3; j++)
			p[i][j] = i * 3 + j;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << p[i][j] << " ";
		std::cout << "\n";
	}

	return 0;
}