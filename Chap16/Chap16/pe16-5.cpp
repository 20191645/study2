/*
	���� 5:
	pe16-4�� �ٽ� �ϵ� ���ø� �Լ��� �����
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

template <class T>
int reduce(T ar[], int n);

int main() {

	int i;
	long ar[15] = { 2,2,3,1,5,7,4,1,6,7,3,3,5,4,1 };
	cout << "�迭 ���� ��:\n";
	for (i = 0; i < 15; i++) {
		cout << ar[i] << ' ';
	}
	cout << endl;

	int n = reduce(ar, 15);
	cout << "�迭 ���� ���:\n";
	for (i = 0; i < n; i++)
		cout << ar[i] << ' ';
	cout << endl;

	string sar[5] = { "banana","banana","apple","cow","apple" };
	cout << "�迭 ���� ��:\n";
	for (i = 0; i < 5; i++) {
		cout << sar[i] << ' ';
	}
	cout << endl;

	n = reduce(sar, 5);
	cout << "�迭 ���� ���:\n";
	for (i = 0; i < n; i++)
		cout << sar[i] << ' ';
	cout << endl;

	return 0;
}

template <class T>
int reduce(T ar[], int n) {
	sort(ar, ar + n);
	T* arr = unique(ar, ar + n);

	int size = (arr - ar);
	return size;
}