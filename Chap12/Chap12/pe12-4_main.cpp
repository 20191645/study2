/*
	���� 4:
	Stack Ŭ���� ����
*/

// stacker.cpp�� �Ȱ��� ����
#include <iostream>
#include <cctype>
#include "pe12-4.h"

int main() {
	using namespace std;

	Stack st;
	char ch;
	unsigned long po;
	cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P,\n"
		<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}

		switch (toupper(ch)) {
		case 'A':
			cout << "�߰��� �ֹ����� ��ȣ�� �Է��Ͻʽÿ�: ";
			cin >> po;
			if (st.isfull())
				cout << "������ ���� �� �ֽ��ϴ�.\n";
			else
				st.push(po);
			break;

		case 'P':
			if (st.isempty())
				cout << "������ ��� �ֽ��ϴ�.\n";
			else {
				st.pop(po);
				cout << "#" << po << " �ֹ����� ó���߽��ϴ�.\n";
			}
			break;
		}

		cout << "�ֹ����� �߰��Ϸ��� A, �ֹ����� ó���Ϸ��� P\n"
			<< "�����Ϸ��� Q�� �Է��Ͻʽÿ�.\n";
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}