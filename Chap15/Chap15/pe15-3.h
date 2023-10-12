#ifndef PE15_3_H_
#define PE15_3_H_

#include <iostream>
#include <stdexcept>
#include <string>

class bad :public std::logic_error {
private:
	double v1;
	double v2;

public:
	bad(double a = 0, double b = 0, const std::string& s = "bad 객체 에러")
		:logic_error(s), v1(a), v2(b) {}

	void show() const;
};

inline void bad::show()const {
	std::cout << "Values user: " << v1 << ", " << v2 << std::endl;
}

class bad_hmean :public bad {
public:
	bad_hmean(double a = 0, double b = 0, const std::string& s = "bad_hmean 객체 에러")
		:bad(a, b, s) {}

	const char* what() const;
};

inline const char* bad_hmean::what() const {
	return "hmean(): 잘못된 매개변수 a = -b\n";
}

class bad_gmean :public bad {
public:
	bad_gmean(double a = 0, double b = 0, const std::string& s = "bad_gmean 객체 에러")
		:bad(a, b, s) {}

	const char* what() const;
};

inline const char* bad_gmean::what() const {
	return "gmean(): 매개변수들은 >= 0 이어야 합니다.\n";
}

#endif