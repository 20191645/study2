/*
	���� 10:
	�޸��� ����� 3�� �Է��ϰ� Ƚ���� ����� ���[array ��ü ���]
*/

#include <iostream>
#include <array>

int main() {
	using namespace std;

	array<double, 3> arr;
	cout << "ù ��° �޸��� ���: ";
	cin >> arr[0];
	cout << "�� ��° �޸��� ���: ";
	cin >> arr[1];
	cout << "�� ��° �޸��� ���: ";
	cin >> arr[2];

	double avg = (arr[0] + arr[1] + arr[2]) / 3;
	cout << "�޸��� Ƚ��: " << arr.size() << endl;
	cout << "�޸��� ���: " << avg << endl;

	return 0;
}