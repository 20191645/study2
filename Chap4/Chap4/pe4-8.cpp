/*
	���� 8:
	pe4-7.cpp�� ���� ������ new�� ����Ͽ� ����ü ����
*/

#include <iostream>

struct Pizza {
	char name[20];
	double diameter;
	double weight;
};

int main() {
	using namespace std;

	Pizza* pizza = new Pizza;
	cout << "������ ������ �Է��Ͻÿ�: ";
	cin >> pizza->diameter;
	cout << "���� ȸ���� �̸��� �Է��Ͻÿ�: ";
	cin.get();
	cin.getline(pizza->name, 19);
	cout << "������ �߷��� �Է��Ͻÿ�: ";
	cin >> pizza->weight;
	cout << endl;

	cout << "������ ����: " << pizza->diameter << endl;
	cout << "���� ȸ���� �̸�: " << pizza->name << endl;
	cout << "������ �߷�: " << pizza->weight << endl;
	delete pizza;

	return 0;
}