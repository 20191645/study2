/*
	���� 8:
	char�� �迭�� ����Ͽ� 'done'�� �Էµ� ������ �� �ܾ �д� ����
*/

#include <iostream>
#include <cstring>

int main() {
	using namespace std;

	int count = -1;
	char word[20];

	cout << "���� �ܾ���� �Է��Ͻʽÿ�(�������� done�� �Է�):\n";
	while (strcmp(word, "done")) {
		cin >> word;
		++count;
	}

	cout << "�� " << count << " �ܾ �ԷµǾ����ϴ�.\n";

	return 0;
}