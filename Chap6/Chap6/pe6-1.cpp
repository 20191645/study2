/*
	���� 1:
	@ ��ȣ�� ��Ÿ�������� �Է¹޾� �빮�ڿ� �ҹ��ڸ� ���� ��ȯ�Ͽ� ����
*/

#include <iostream>
#include <cctype>

int main() {
	using namespace std;

	cout << "@ ��ȣ�� ������ �Է�:\n";
	char ch;
	while (cin.get(ch) && ch != '@') {
		if (isdigit(ch))
			continue;

		if (isupper(ch))
			cout << (char)tolower(ch);
		else if (islower(ch))
			cout << (char)toupper(ch);
		else
			cout << ch;
	}

	cout << endl << "�Է��� ����Ǿ����ϴ�.\n";

	return 0;
}
