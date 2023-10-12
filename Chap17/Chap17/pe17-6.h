#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <fstream>
#include <string>

// 객체형 구분을 위한 정수
enum classkind { Employee = 1, Manager, Fink, Highfink };

class employee {
private:
	std::string fname;
	std::string lname;
	std::string job;

public:
	employee();
	employee(const std::string& fn, const std::string& ln, const std::string& j);

	virtual void ShowAll() const;	// 모든 데이터를 보여준다
	virtual void SetAll();	// 사용자에게 값을 입력하라고 요구한다
	friend std::ostream& operator<<(std::ostream& os, const employee& e);
	
	virtual void WriteAll(std::ofstream& fout);
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteType(std::ofstream& fout);

	virtual ~employee() {}
};

class manager :virtual public employee {
private:
	int inchargeof;	// 관리하는 abstr_emps의 수

protected:
	int InChargeOf() const { return inchargeof; }	// 출력용
	int& InChargeOf() { return inchargeof; }	// 입력용

public:
	manager();
	manager(const std::string& fn, const std::string& ln,
		const std::string& j, int ico = 0);
	manager(const employee& e, int ico);
	manager(const manager& m);

	virtual void ShowAll() const;
	virtual void SetAll();

	virtual void WriteAll(std::ofstream& fout);
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteType(std::ofstream& fout);
};

class fink :virtual public employee {
private:
	std::string reportsto;

protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }

public:
	fink();
	fink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo);
	fink(const employee& e, const std::string& rpo);
	fink(const fink& e);

	virtual void ShowAll() const;
	virtual void SetAll();

	virtual void WriteAll(std::ofstream& fout);
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteType(std::ofstream& fout);
};

class highfink :public manager, public fink {
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo, int ico);
	highfink(const employee& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);

	virtual void ShowAll() const;
	virtual void SetAll();

	virtual void WriteAll(std::ofstream& fout);
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteType(std::ofstream& fout);
};

#endif