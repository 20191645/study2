#ifndef PE14_5_H_
#define PE14_5_H_

#include <iostream>
#include <string>

class abstr_emp {
private:
	std::string fname;
	std::string lname;
	std::string job;

public:
	abstr_emp();
	abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);

	virtual void ShowAll() const;	// 모든 데이터를 보여준다
	virtual void SetAll();	// 사용자에게 값을 입력하라고 요구한다
	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);

	virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp {
public:
	employee();
	employee(const std::string& fn, const std::string& ln, const std::string& j);

	virtual void ShowAll() const;
	virtual void SetAll();
};

class manager :virtual public abstr_emp {
private:
	int inchargeof;	// 관리하는 abstr_emps의 수

protected:
	int InChargeOf() const { return inchargeof; }	// 출력용
	int& InChargeOf() { return inchargeof; }	// 입력용

public:
	manager();
	manager(const std::string& fn, const std::string& ln,
		const std::string& j, int ico = 0);
	manager(const abstr_emp& e, int ico);
	manager(const manager& m);

	virtual void ShowAll() const;
	virtual void SetAll();
};

class fink :virtual public abstr_emp {
private:
	std::string reportsto;

protected:
	const std::string ReportsTo() const { return reportsto; }
	std::string& ReportsTo() { return reportsto; }

public:
	fink();
	fink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo);
	fink(const abstr_emp& e, const std::string& rpo);
	fink(const fink& e);

	virtual void ShowAll() const;
	virtual void SetAll();
};

class highfink :public manager, public fink {
public:
	highfink();
	highfink(const std::string& fn, const std::string& ln,
		const std::string& j, const std::string& rpo, int ico);
	highfink(const abstr_emp& e, const std::string& rpo, int ico);
	highfink(const fink& f, int ico);
	highfink(const manager& m, const std::string& rpo);
	highfink(const highfink& h);

	virtual void ShowAll() const;
	virtual void SetAll();
};

#endif