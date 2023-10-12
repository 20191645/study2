#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <fstream>
#include <string>

// ��ü�� ������ ���� ����
enum classkind { Employee = 1, Manager, Fink, Highfink };

class employee {
private:
	std::string fname;
	std::string lname;
	std::string job;

public:
	employee();
	employee(const std::string& fn, const std::string& ln, const std::string& j);

	virtual void ShowAll() const;	// ��� �����͸� �����ش�
	virtual void SetAll();	// ����ڿ��� ���� �Է��϶�� �䱸�Ѵ�
	friend std::ostream& operator<<(std::ostream& os, const employee& e);
	
	virtual void WriteAll(std::ofstream& fout);
	virtual void GetAll(std::ifstream& fin);
	virtual void WriteType(std::ofstream& fout);

	virtual ~employee() {}
};

class manager :virtual public employee {
private:
	int inchargeof;	// �����ϴ� abstr_emps�� ��

protected:
	int InChargeOf() const { return inchargeof; }	// ��¿�
	int& InChargeOf() { return inchargeof; }	// �Է¿�

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