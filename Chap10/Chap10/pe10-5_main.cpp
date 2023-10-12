/*
	���� 5:
	customer ����ü�� ���� ������ Stack Ŭ������ �߰��ϰ� ����
*/

#include <iostream>
#include <cctype>
#include "pe10-5.h"

int main() {
	Stack st;
	Item arr[5] = {
		{"Hello World",35000},
		{"Marry",2000},
		{"Gold",10000},
		{"Bin",5000},
		{"Last",45000}
	};

	for (int i = 0; i < 5; i++) {
		if (!st.push(arr[i]))
			std::cout << "������ ���� �� �ֽ��ϴ�.\n";
		else
			std::cout << "push ����\n";
	}

	double total = 0.0;
	Item temp;
	for (int i = 0; i < 5; i++) {
		if (!st.pop(temp))
			std::cout << "������ ��� �ֽ��ϴ�.\n";
		else
			std::cout << "pop ����\n";
		total += temp.payment;
	}
	std::cout << "�� ����: " << total << std::endl;
	std::cout << "���α׷��� �����մϴ�.\n";

	return 0;
}