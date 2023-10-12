#include <iostream>
#include "pe10-1.h"

Account::Account(const std::string& nm, const std::string& num, double bal) {
	name = nm;
	number = num;
	balance = bal;
}

void Account::show() const {
	using namespace std;
	cout << "이름: " << name << endl;
	cout << "계좌번호: " << number << endl;
	cout << "잔액: " << balance << endl;
}

void Account::deposit(double money) {
	if (money < 0)
		std::cout << "0보다 작은 값은 입금할 수 없습니다.\n";
	else {
		balance += money;
		std::cout << money << "원을 입금하였습니다.\n";
	}
}

void Account::withdraw(double money) {
	if (money < 0)
		std::cout << "0보다 작은 값은 출금할 수 없습니다.\n";
	else if (money > balance)
		std::cout << "잔액보다 큰 값은 출금할 수 없습니다.\n";
	else {
		balance -= money;
		std::cout << money << "원을 출금하였습니다.\n";
	}
}