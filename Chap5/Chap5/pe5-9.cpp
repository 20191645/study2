/*
	���� 9:
	pe5-8.cpp�� ���� ������ string Ŭ������ �̿��Ͽ� �ۼ�
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	int count = -1;
	string word;

	cout << "���� �ܾ���� �Է��Ͻʽÿ�(�������� done�� �Է�):\n";
	while (word != "done") {
		cin >> word;
		++count;
	}

	cout << "�� " << count << " �ܾ �ԷµǾ����ϴ�.\n";

	return 0;
}