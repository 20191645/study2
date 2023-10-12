/*
	문제 2:
	Cpmv 클래스 구현
*/

#include <iostream>
#include <string>
using std::cout;
using std::endl;

class Cpmv {
public:
	struct Info {
		std::string qcode;
		std::string zcode;
	};

private:
	Info* pi;

public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv);
	~Cpmv();

	Cpmv& operator=(const Cpmv& cp);
	Cpmv& operator=(Cpmv&& mv);
	Cpmv operator+(const Cpmv& obj) const;

	void Display() const;
};

Cpmv::Cpmv() {
	cout << "기본 생성자 호출\n";
	pi = new Info;
	pi->qcode = "qcode";
	pi->zcode = "zcode";
}
Cpmv::Cpmv(std::string q, std::string z) {
	cout << "Cpmv(string, string) 생성자 호출\n";
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}
Cpmv::Cpmv(const Cpmv& cp) {
	cout << "복사 생성자 호출\n";
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}
Cpmv::Cpmv(Cpmv&& mv) {
	cout << "이동 생성자 호출\n";
	pi = mv.pi;
	mv.pi = nullptr;
}
Cpmv::~Cpmv() {
	cout << "파괴자 호출\n";
	delete pi;
}

Cpmv& Cpmv::operator=(const Cpmv& cp) {
	cout << "복사 대입 연산자 호출\n";
	if (this == &cp)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
	return *this;
}
Cpmv& Cpmv::operator=(Cpmv&& mv) {
	cout << "이동 대입 연산자 호출\n";
	if (this == &mv)
		return *this;
	delete pi;
	pi = mv.pi;
	mv.pi = nullptr;
	return *this;
}
Cpmv Cpmv::operator+(const Cpmv& obj) const {
	cout << "+ 연산자 호출\n";
	Cpmv temp = Cpmv(pi->qcode + obj.pi->qcode,
		pi->zcode + obj.pi->zcode);
	return temp;
}

void Cpmv::Display() const {
	cout << "qcode: " << pi->qcode << endl;
	cout << "zcode: " << pi->zcode << endl;
}


int main() {
	Cpmv one;
	one.Display();
	cout << endl;

	Cpmv two("first","second");
	two.Display();
	cout << endl;

	Cpmv three(two);
	three.Display();
	cout << endl;

	Cpmv four(one + one);
	four.Display();
	cout << endl;

	four = one;
	four.Display();
	cout << endl;

	four = one + two;
	four.Display();
	cout << endl;

	return 0;
}