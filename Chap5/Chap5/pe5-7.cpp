/*
	���� 7:
	- '���۾�ü, ���۳⵵'�� �����ϴ� car ����ü ����
	- new�� ����Ͽ� car ����ü ���� �迭 �����
*/

#include <iostream>

struct car {
	char name[20];
	int year;
};

int main() {
	using namespace std;

	int n;
	cout << "�� ���� ���� ������� �����ϰڽ��ϱ�? ";
	cin >> n;
	car* cars = new car[n];
	
	for (int i = 0; i < n; i++) {
		cin.get();
		cout << "�ڵ��� #" << (i + 1) << ":\n";
		cout << "���۾�ü: ";
		cin.getline(cars[i].name, 20);
		cout << "���۳⵵: ";
		cin >> cars[i].year;
	}

	cout << "���� ���ϰ� �����ϰ� �ִ� �ڵ��� ����� ������ �����ϴ�.\n";
	for (int i = 0; i < n; i++) {
		cout << cars[i].year << "���� " << cars[i].name << endl;
	}

	delete[]cars;

	return 0;
}