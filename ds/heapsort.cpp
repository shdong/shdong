#include<iostream>
typedef double ElemType;

bool LT(ElemType &a, ElemType &b){
	return a < b;
}

void HeapAdjust(ElemType H[], int s, int m){
	ElemType rc = H[s]; //��ʱ��������Ƶ�����
	for (int j = 2 * s; j <= m; j *= 2) {
		if (j < m && LT(H[j], H[j + 1]) )
			j++;    //jָ��s�ϴ�ġ����ӡ�
		if (!LT(rc, H[j]))
			break;  //��j��ֵ��rcС��˵���ҵ���s��λ��
		H[s] = H[j]; //����Ԫ��j����
		s = j;
	}
	H[s] = rc;   //д��s
}

void swap(ElemType &a, ElemType &b){
	ElemType  t = a; a = b; b = t;
}


int main(){
	ElemType a[9];   //a[1], a[2],...a[8]
	int  n = 8;
	a[1] = 23; a[2] = 2; a[3] = 45; 
	a[4] = 31; a[5] = 24; a[6] = 78;
	a[7] = 53; a[8] = 69; 

	for (int i = 1; i <= n;i++)
		std::cout << a[i] << " ";
    std::cout << "\n";


	for (int i = n / 2; i >= 1; i--){
		HeapAdjust(a, i, n);
	}

	for (int j = n; j>1; j--){
		swap(a[1], a[j]);
		HeapAdjust(a, 1, j - 1);
	}

	for (int i = 1; i <= n; i++)
		std::cout << a[i] << " ";
	std::cout << "\n";

}