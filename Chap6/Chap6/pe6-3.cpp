/*
	���� 3:
	�޴� ������� ��Ǵ� ���� ���α׷�
*/

#include <iostream>

int main() {
	using namespace std;

	char ch;
	cout << "���� ���� ���� �߿��� �ϳ��� �����Ͻʽÿ�. (�������� q)" << endl;
	cout << "c) camera " << "p) pianist" << endl;
	cout << "t) tree " << "g) game" << endl;
	cin.get(ch);
	while (ch != 'q') {
		cin.get();
		switch (ch) {
		case 'c':
			cout << "ī�޶�� ��Դϴ�.\n";
			break;
		case 'p':
			cout << "�ǾƴϽ�Ʈ�� ���� Ů�ϴ�.\n";
			break;
		case 't':
			cout << "��ǳ������ ���� ��ó�� ������ϴ�.\n";
			break;
		case 'g':
			cout << "������ ���� ��ս��ϴ�.\n";
			break;
		}
		cout << "c, p, t, g �߿��� �ϳ��� �����Ͻʽÿ�. (�������� q): ";
		cin.get(ch);
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}