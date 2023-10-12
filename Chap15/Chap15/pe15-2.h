#ifndef PE15_2_H_
#define PE15_2_H_

#include <iostream>
#include <stdexcept>
#include <string>

class bad_hmean :public std::logic_error {
private:
	double v1;
	double v2;

public:
	bad_hmean(double a = 0, double b = 0, const std::string& s = "bad_hmean ��ü ����")
		:logic_error(s), v1(a), v2(b) {}

	const char* what() const;
};

inline const char* bad_hmean::what() const {
	return "hmean(): �߸��� �Ű�����: a = -b\n";
}

class bad_gmean :public std::logic_error {
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0, const std::string& s = "bad_gmean ��ü ����")
		:logic_error(s), v1(a), v2(b) {}

	const char* what() const;
};

inline const char* bad_gmean::what() const {
	return "gmean(): �Ű��������� >= 0 �̾�� �մϴ�.\n";
}

#endif