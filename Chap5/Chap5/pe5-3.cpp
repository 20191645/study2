/*
	���� 3:
	���� �Է¹��� ������ �׶����� �Էµ� ������ ���� ���
*/

#include <iostream>

int main() {
	using namespace std;

	int n;
	int sum = 0;

	cin >> n;
	while (n) {
		sum += n;
		cout << "����: " << sum << endl;
		cin >> n;
	}

	return 0;
}