/*
	���� 3:
	Stock Ŭ���� ����
	- string Ŭ���� ��ü ��� ���� ���� �޸� ���
	- Show() ��� �Լ��� �����ε��� operator<<()�� ��ü
*/

#include <iostream>
#include "pe12-3.h"

const int STKS = 4;

int main() {
	Stock stocks[STKS] = {
		Stock("NanoSmart",12,20.0),
		Stock("Boffo Objects",200,2.0),
		Stock("Monolithic Obelisks",130,3.25),
		Stock("Fleep Enterprises",60,6.5)
	};

	std::cout << "���� �ֽ� ����Ʈ:\n";
	int i;
	for (i = 0; i < STKS; i++)
		std::cout << stocks[i];

	const Stock* top = &stocks[0];
	for (i = 1; i < STKS; i++)
		top = &top->topval(stocks[i]);

	std::cout << "\n�ְ� ��ġ�� �ֽ�:\n";
	std::cout << *top;

	return 0;
}