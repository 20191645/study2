#include <iostream>
using namespace std;
#include "pe14-5.h"

// abstr_emp �޼���
abstr_emp::abstr_emp()
	:fname("first"), lname("last"), job("no job") {}
abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
	:fname(fn), lname(ln), job(j) {}

void abstr_emp::ShowAll() const {
	cout << "�̸�: " << lname << " " << fname << endl;
	cout << "����: " << job << endl;
}
void abstr_emp::SetAll() {
	getline(cin, fname);
	cout << "���� �Է��Ͻÿ�: ";
	getline(cin, lname);
	cout << "������ �Է��Ͻÿ�: ";
	getline(cin, job);
}
std::ostream& operator<<(std::ostream& os, const abstr_emp& e) {
	os << "�̸�: " << e.lname << " " << e.fname << ", ";
	os << "����: " << e.job << endl;
	return os;
}
abstr_emp::~abstr_emp() {}



// employee �޼���
employee::employee()
	:abstr_emp() {}
employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
	:abstr_emp(fn, ln, j) {}

void employee::ShowAll() const {
	cout << "employee�� ����:\n";
	abstr_emp::ShowAll();
	cout << endl;
}
void employee::SetAll() {
	cout << "employee�� �̸��� �Է��Ͻÿ�: ";
	abstr_emp::SetAll();
}



// manager �޼���
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
	cout << "manager�� ����:\n";
	abstr_emp::ShowAll();
	cout << "�����ϴ� abstr_emp�� ��: " << inchargeof << endl;
	cout << endl;
}
void manager::SetAll() {
	cout << "manager�� �̸��� �Է��Ͻÿ�: ";
	abstr_emp::SetAll();
	cout << "�����ϴ� abstr_emp�� ���� �Է��Ͻÿ�: ";
	cin >> inchargeof;
}



// fink �޼���
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
	cout << "fink�� ����:\n";
	abstr_emp::ShowAll();
	cout << "�����ϴ� ���: " << reportsto << endl;
	cout << endl;
}
void fink::SetAll() {
	cout << "fink�� �̸��� �Է��Ͻÿ�: ";
	abstr_emp::SetAll();
	cout << "�����ϴ� ����� �Է��Ͻÿ�: ";
	cin >> reportsto;
}



//highfink �޼���
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
	cout << "highfink�� ����:\n";
	abstr_emp::ShowAll();
	cout << "�����ϴ� abstr_emp�� ��: " << manager::InChargeOf() << endl;
	cout << "�����ϴ� ���: " << highfink::ReportsTo() << endl;
	cout << endl;
}
void highfink::SetAll() {
	cout << "highfink�� �̸��� �Է��Ͻÿ�: ";
	abstr_emp::SetAll();
	cout << "�����ϴ� abstr_emp�� ���� �Է��Ͻÿ�: ";
	cin >> manager::InChargeOf();
	cout << "�����ϴ� ����� �Է��Ͻÿ�: ";
	getline(cin, highfink::ReportsTo());
}