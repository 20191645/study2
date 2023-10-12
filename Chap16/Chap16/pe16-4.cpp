/*
	���� 4:
	int reduce(long ar[], int n): �迭 ����, �ߺ��� ����, ����� ���� �� ����
	- ���� ��Ÿ���� �������̽��� STL �Լ� ����Ͽ� �ۼ�
*/

#include <iostream>
#include <algorithm>
using namespace std;

int reduce(long ar[], int n);

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

	return 0;
}

int reduce(long ar[], int n) {
	sort(ar, ar + n);
	long* arr = unique(ar, ar + n);
	
	int size = (arr - ar);
	return size;
}