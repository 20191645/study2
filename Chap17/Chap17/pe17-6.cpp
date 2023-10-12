#include <iostream>
#include <fstream>
#include <string>
#include "pe17-6.h"
using namespace std;

// employee 메서드
employee::employee()
	:fname("first"), lname("last"), job("no job") {}
employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
	:fname(fn), lname(ln), job(j) {}

void employee::ShowAll() const {
	cout << "employee의 정보:\n";
	cout << "이름: " << lname << " " << fname << endl;
	cout << "직업: " << job << endl;
}
void employee::SetAll() {
	cout << "이름을 입력하시오: ";
	getline(cin, fname);
	cout << "성을 입력하시오: ";
	getline(cin, lname);
	cout << "직업을 입력하시오: ";
	getline(cin, job);
}
std::ostream& operator<<(std::ostream& os, const employee& e) {
	os << "이름: " << e.lname << " " << e.fname << ", ";
	os << "직업: " << e.job << endl;
	return os;
}

void employee::WriteAll(std::ofstream& fout) {
	fout << fname << endl;
	fout << lname << endl;
	fout << job << endl;
}
void employee::GetAll(std::ifstream& fin) {
	getline(fin, fname);
	getline(fin, lname);
	getline(fin, job);
}
void employee::WriteType(std::ofstream& fout) {
	fout << Employee << endl;
}


// manager 메서드
manager::manager()
	:employee(), inchargeof(0) {}
manager::manager(const std::string& fn, const std::string& ln,
	const std::string& j, int ico)
	:employee(fn, ln, j), inchargeof(ico) {}
manager::manager(const employee& e, int ico)
	:employee(e), inchargeof(ico) {}
manager::manager(const manager& m)
	:employee(m), inchargeof(m.inchargeof) {}

void manager::ShowAll() const {
	cout << "manager의 정보:\n";
	cout << (employee)*this;
	cout << "관리하는 abstr_emp의 수: " << inchargeof << endl;
}
void manager::SetAll() {
	employee::SetAll();
	cout << "관리하는 abstr_emp의 수를 입력하시오: ";
	cin >> inchargeof;
}

void manager::WriteAll(std::ofstream& fout) {
	employee::WriteAll(fout);
	fout << inchargeof << endl;
}
void manager::GetAll(std::ifstream& fin) {
	employee::GetAll(fin);
	fin >> inchargeof;
}
void manager::WriteType(std::ofstream& fout) {
	fout << Manager << endl;
}


// fink 메서드
fink::fink()
	:employee(), reportsto("no report") {}
fink::fink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo)
	:employee(fn, ln, j), reportsto(rpo) {}
fink::fink(const employee& e, const std::string& rpo)
	:employee(e), reportsto(rpo) {}
fink::fink(const fink& e)
	:employee(e), reportsto(e.reportsto) {}

void fink::ShowAll() const {
	cout << "fink의 정보:\n";
	cout << (employee)*this;
	cout << "보고하는 대상: " << reportsto << endl;
}
void fink::SetAll() {
	employee::SetAll();
	cout << "보고하는 대상을 입력하시오: ";
	cin >> reportsto;
}

void fink::WriteAll(std::ofstream& fout) {
	employee::WriteAll(fout);
	fout << reportsto << endl;
}
void fink::GetAll(std::ifstream& fin) {
	employee::GetAll(fin);
	getline(fin, reportsto);
}
void fink::WriteType(std::ofstream& fout) {
	fout << Fink << endl;
}



//highfink 메서드
highfink::highfink()
	:employee(), manager(), fink() {}
highfink::highfink(const std::string& fn, const std::string& ln,
	const std::string& j, const std::string& rpo, int ico)
	:employee(), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {}
highfink::highfink(const employee& e, const std::string& rpo, int ico)
	:employee(e), manager(e, ico), fink(e, rpo) {}
highfink::highfink(const fink& f, int ico)
	:employee(f), manager(f, ico), fink(f) {}
highfink::highfink(const manager& m, const std::string& rpo)
	:employee(m), manager(m), fink(m, rpo) {}
highfink::highfink(const highfink& h)
	:employee(h), manager(h), fink(h) {}

void highfink::ShowAll() const {
	cout << "highfink의 정보:\n";
	cout << (employee)*this;
	cout << "관리하는 abstr_emp의 수: " << manager::InChargeOf() << endl;
	cout << "보고하는 대상: " << highfink::ReportsTo() << endl;
}
void highfink::SetAll() {
	employee::SetAll();
	cout << "관리하는 abstr_emp의 수를 입력하시오: ";
	cin >> manager::InChargeOf();
	cin.get();
	cout << "보고하는 대상을 입력하시오: ";
	getline(cin, highfink::ReportsTo());
}

void highfink::WriteAll(std::ofstream& fout) {
	employee::WriteAll(fout);
	fout << InChargeOf() << endl;
	fout << ReportsTo() << endl;
}
void highfink::GetAll(std::ifstream& fin) {
	employee::GetAll(fin);
	(fin >> manager::InChargeOf()).get();
	getline(fin, highfink::ReportsTo());
}
void highfink::WriteType(std::ofstream& fout) {
	fout << Highfink << endl;
}