/*
	���� 5:
	���� �α��� �̱� �α��� �Է¹ް� ������ ����ϱ�
*/

#include <iostream>

int main() {
	using namespace std;

	long long world, america;
	cout << "���� �α����� �Է��Ͻÿ�: ";
	cin >> world;
	cout << "�̱��� �α����� �Է��Ͻÿ�: ";
	cin >> america;

	cout << "���� �α������� �̱��� �����ϴ� ������ ";
	cout << 100.0 * america / world << "%�̴�.\n";

	return 0;
}