/*
	문제 4:
	int reduce(long ar[], int n): 배열 정렬, 중복값 삭제, 단축된 원소 수 리턴
	- 구식 스타일의 인터페이스로 STL 함수 사용하여 작성
*/

#include <iostream>
#include <algorithm>
using namespace std;

int reduce(long ar[], int n);

int main() {
	
	int i;
	long ar[15] = { 2,2,3,1,5,7,4,1,6,7,3,3,5,4,1 };
	cout << "배열 정렬 전:\n";
	for (i = 0; i < 15; i++) {
		cout << ar[i] << ' ';
	}
	cout << endl;

	int n = reduce(ar, 15);
	cout << "배열 정렬 결과:\n";
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