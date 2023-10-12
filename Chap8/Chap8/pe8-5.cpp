/*
	���� 5:
	max5(): T�� �׸� 5�� �迭���� ���� ū �׸� �����ϴ� ���ø� �Լ�
*/

#include <iostream>
using namespace std;

template <typename T>
T max5(T* arr);

int main() {
	int iarr[5] = { 1,5,2,3,4 };
	double darr[5] = { 2.0,7.0,3.0,4.2,9.8 };
	cout << max5(iarr) << endl;
	cout << max5(darr) << endl;
}

template <typename T>
T max5(T* arr) {
	T max = arr[0];
	for (int i = 1; i < 5; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}