#include "pe15-4.h"
using std::string;


// Sales::bad_index 메서드
Sales::bad_index::bad_index(int ix, const std::string& s)
	:bi(ix), std::logic_error(s) {}

// Sales 메서드
Sales::Sales(int yy)
	:year(yy) {
	for (int i = 0; i < MONTHS; i++)
		gross[i] = 0;
}
Sales::Sales(int yy, const double* gr, int n)
	:year(yy) {
	int limit = (MONTHS > n) ? n : MONTHS;
	int i;
	for (i = 0; i < limit; i++)
		gross[i] = gr[i];
	for (; i < MONTHS; i++)
		gross[i] = 0;
}

double Sales::operator[](int i) const {
	if (i < 0 || i >= MONTHS)
		throw new bad_index(i);
	return gross[i];
}
double& Sales::operator[](int i) {
	if (i < 0 || i >= MONTHS)
		throw new bad_index(i);
	return gross[i];
}


// LabeledSales::nbad_index 메서드
LabeledSales::nbad_index::nbad_index(const std::string& lb, int ix, const std::string& s)
	:bad_index(ix, s), lbl(lb) {}

// LabeledSales 메서드
LabeledSales::LabeledSales(const std::string& lb, int yy)
	:Sales(yy), label(lb) {}
LabeledSales::LabeledSales(const std::string& lb, int yy, const double* gr, int n)
	:Sales(yy, gr, n), label(lb) {}

double LabeledSales::operator[](int i) const {
	// dynamic_cast를 사용하기 위해 catch()에서 예외 클래스를 포인터로 변경했기 때문에
	// "throw 생성자" 에서 "throw new 생성자"로 수정해줘야 한다

	if (i < 0 || i >= MONTHS)
		throw new nbad_index(Label(), i);
	return Sales::operator[](i);
}
double& LabeledSales::operator[](int i) {
	if (i < 0 || i >= MONTHS)
		throw new nbad_index(Label(), i);
	return Sales::operator[](i);
}