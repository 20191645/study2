#include <iostream>
#include "pe10-1.h"

Account::Account(const std::string& nm, const std::string& num, double bal) {
	name = nm;
	number = num;
	balance = bal;
}

void Account::show() const {
	using namespace std;
	cout << "�̸�: " << name << endl;
	cout << "���¹�ȣ: " << number << endl;
	cout << "�ܾ�: " << balance << endl;
}

void Account::deposit(double money) {
	if (money < 0)
		std::cout << "0���� ���� ���� �Ա��� �� �����ϴ�.\n";
	else {
		balance += money;
		std::cout << money << "���� �Ա��Ͽ����ϴ�.\n";
	}
}

void Account::withdraw(double money) {
	if (money < 0)
		std::cout << "0���� ���� ���� ����� �� �����ϴ�.\n";
	else if (money > balance)
		std::cout << "�ܾ׺��� ū ���� ����� �� �����ϴ�.\n";
	else {
		balance -= money;
		std::cout << money << "���� ����Ͽ����ϴ�.\n";
	}
}