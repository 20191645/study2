/*
	문제 5:
	세계 인구와 미국 인구를 입력받고 비중을 출력하기
*/

#include <iostream>

int main() {
	using namespace std;

	long long world, america;
	cout << "세계 인구수를 입력하시오: ";
	cin >> world;
	cout << "미국의 인구수를 입력하시오: ";
	cin >> america;

	cout << "세계 인구수에서 미국이 차지하는 비중은 ";
	cout << 100.0 * america / world << "%이다.\n";

	return 0;
}