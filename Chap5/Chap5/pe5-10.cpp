/*
	���� 10:
	����� �� ���� �Է¹ް� ��ø ������ ����Ͽ� ���
*/

#include <iostream>

int main() {
	using namespace std;

	int num;
	cout << "����� �� ���� �Է��Ͻʽÿ�: ";
	cin >> num;

	for (int i = 1; i <= num; ++i) {
		for (int j = num; j > i; --j) {
			cout << '.';
		}
		for (int k = 0; k < i; ++k) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}