/*
	문제 1:
	은행 계좌를 나타내는 클래스를 위한 메서드 정의
*/

#include "pe10-1.h"

int main() {
	Account account("My name is you", "012345-67890");
	account.show();
	account.deposit(-5000);
	account.show();
	account.withdraw(10000);
	account.show();
	account.deposit(10000);
	account.show();
	account.withdraw(7000);
	account.show();

	return 0;
}