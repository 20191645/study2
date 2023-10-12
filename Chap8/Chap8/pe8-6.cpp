/*
	문제 6:
	maxn(): T형 배열에서 가장 큰 항목 리턴 - char 포인터 특수화 제공
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template <typename T>
T maxn(T arr[], int n);

template<> const char* maxn(const char* arr[], int n);

int main() {
	int iarr[6] = { 3,2,67,1,92,0 };
	double darr[4] = { 34.6,22,1.67,8.9 };
	const char* carr[5] = {"Hello","World","Hi",",,,","454"};

	cout << maxn(iarr, 6) << endl;
	cout << maxn(darr, 4) << endl;
	cout << maxn(carr, 5) << endl;
	return 0;
}

template <typename T>
T maxn(T arr[], int n) {
	T max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

template<> const char* maxn(const char* arr[], int n) {
	const char* max = arr[0];
	for (int i = 1; i < n; i++) {
		if (strlen(arr[i]) > strlen(max))
			max = arr[i];
	}
	return max;
}