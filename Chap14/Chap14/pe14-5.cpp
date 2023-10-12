#include <iostream>
using namespace std;
#include "pe14-5.h"

// abstr_emp 메서드
abstr_emp::abstr_emp()
	:fname("first"), lname("last"), job("no job") {}
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
	:fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const {
	cout << "이름: " << lname << " " << fname << endl;
	cout << "직업: " << job << endl;
}
void abstr_emp::SetAll() {
	getline(cin, fname);
	cout << "성을 입력하시오: ";
	getline(cin, lname);
	cout << "직업을 입력하시오: ";
	getline(cin, job);
}
std::ostream& operator<<(std::ostream& os, const abstr_emp& e) {
	os << "이름: " << e.lname << " " << e.fname << ", ";
	os << "직업: " << e.job << endl;
	return os;
}
abstr_emp::~abstr_emp() {}



// employee 메서드
employee::employee()
	:abstr_emp() {}
employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
	:abstr_emp(fn, ln, j) {}

void employee::ShowAll() const {
	cout << "employee의 정보:\n";
	abstr_emp::ShowAll();
	cout << endl;
}
void employee::SetAll() {
	cout << "employee의 이름을 입력하시오: ";
	abstr_emp::SetAll();
}



// manager 메서드
manager::manager()
	:abstr_emp(), inchargeof(0) {}
manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico)
	:abstr_emp(fn, ln, j), inchargeof(ico) {}
manager::manager(const abstr_emp& e, int ico)
	:abstr_emp(e), inchargeof(ico) {}
manager::manager(const manager& m)
	:abstr_emp(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const {
	cout << "manager의 정보:\n";
	abstr_emp::ShowAll();
	cout << "관리하는 abstr_emp의 수: " << inchargeof << endl;
	cout << endl;
}
void manager::SetAll() {
	cout << "manager의 이름을 입력하시오: ";
	abstr_emp::SetAll();
	cout << "관리하는 abstr_emp의 수를 입력하시오: ";
	cin >> inchargeof;
}



// fink 메서드
fink::fink()
	:abstr_emp(), reportsto("no report") {}
fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	:abstr_emp(fn, ln, j), reportsto(rpo) {}
fink::fink(const abstr_emp& e, const std::string& rpo)
	:abstr_emp(e), reportsto(rpo) {}
fink::fink(const fink& e)
	:abstr_emp(e), reportsto(e.reportsto) {}

void fink::ShowAll() const {
	cout << "fink의 정보:\n";
	abstr_emp::ShowAll();
	cout << "보고하는 대상: " << reportsto << endl;
	cout << endl;
}
void fink::SetAll() {
	cout << "fink의 이름을 입력하시오: ";
	abstr_emp::SetAll();
	cout << "보고하는 대상을 입력하시오: ";
	cin >> reportsto;
}



//highfink 메서드
highfink::highfink()
	:abstr_emp(), manager(), fink() {}
highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo, int ico)
	:abstr_emp(), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
	:abstr_emp(e), manager(e, ico), fink(e, rpo) {}
highfink::highfink(const fink& f, int ico)
	:abstr_emp(f), manager(f, ico), fink(f) {}
highfink::highfink(const manager& m, const std::string& rpo)
	:abstr_emp(m), manager(m), fink(m, rpo) {}
highfink::highfink(const highfink& h)
	:abstr_emp(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
	cout << "highfink의 정보:\n";
	abstr_emp::ShowAll();
	cout << "관리하는 abstr_emp의 수: " << manager::InChargeOf() << endl;
	cout << "보고하는 대상: " << highfink::ReportsTo() << endl;
	cout << endl;
}
void highfink::SetAll() {
	cout << "highfink의 이름을 입력하시오: ";
	abstr_emp::SetAll();
	cout << "관리하는 abstr_emp의 수를 입력하시오: ";
	cin >> manager::InChargeOf();
	cout << "보고하는 대상을 입력하시오: ";
	getline(cin, highfink::ReportsTo());
}