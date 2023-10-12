/*
	문제 3:
	수를 입력받을 때마다 그때까지 입력된 수들의 누계 출력
*/

#include <iostream>

int main() {
	using namespace std;

	int n;
	int sum = 0;

	cin >> n;
	while (n) {
		sum += n;
		cout << "누계: " << sum << endl;
		cin >> n;
	}

	return 0;
}