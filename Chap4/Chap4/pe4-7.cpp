/*
	���� 7:
	'���� ȸ�� �̸�, ���� ����, ���� �߷�'�� ����ϴ� ����ü ���ø� ����
*/

#include <iostream>

struct Pizza {
	char name[20];
	double diameter;
	double weight;
};

int main() {
	using namespace std;

	Pizza pizza;
	cout << "���� ȸ���� �̸��� �Է��Ͻÿ�: ";
	cin.getline(pizza.name, 19);
	cout << "������ ������ �Է��Ͻÿ�: ";
	cin >> pizza.diameter;
	cout << "������ �߷��� �Է��Ͻÿ�: ";
	cin >> pizza.weight;
	cout << endl;

	cout << "���� ȸ���� �̸�: " << pizza.name << endl;
	cout << "������ ����: " << pizza.diameter << endl;
	cout << "������ �߷�: " << pizza.weight << endl;

	return 0;
}