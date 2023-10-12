#ifndef PE10_1_H_
#define PE10_1_H_

#include <string>

class Account {
private:
	std::string name;
	std::string number;
	double balance;

public:
	Account(const std::string& nm, const std::string& num, double bal = 0.0);
	void show() const;
	void deposit(double money);
	void withdraw(double money);
};

#endif