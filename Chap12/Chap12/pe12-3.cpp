#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pe12-3.h"

Stock::Stock() {
	company = new char[8];
	strcpy(company, "no name");
	shares = 0;
	share_val = 0;
	total_val = 0;
}

Stock::Stock(const char* co, long n, double pr) {
	company = new char[strlen(co) + 1];
	strcpy(company, co);
	if (n < 0) {
		std::cout << "�ֽ� ���� ������ �� �� �����Ƿ�, "
			<< company << " shares�� 0���� �����մϴ�.\n";
		shares = 0;
	}
	else
		shares = n;
	update(pr);
}

Stock::~Stock() {

}

void Stock::buy(long num, double price) {
	if (num < 0) {
		std::cout << "���� �ֽ� ���� ������ �� �� �����Ƿ�, "
			"�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else {
		shares += num;
		update(price);
	}
}

void Stock::sell(long num, double price) {
	if (num < 0) {
		std::cout << "�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, "
			"�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else if (num > shares) {
		std::cout << "���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, "
			"�ŷ��� ��ҵǾ����ϴ�.\n";
	}
	else {
		shares -= num;
		update(price);
	}
}

void Stock::update(double price) {
	share_val = price;
	set_tot();
}

const Stock& Stock::topval(const Stock& s) const {
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

// Practice3
ostream& operator<<(ostream& os, const Stock& s) {
	using std::cout;
	using std::ios_base;

	// set format to #.###
	ios_base::fmtflags orig =
		os.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = os.precision(3);

	os << "ȸ���: " << s.company
		<< " �ֽ� ��: " << s.shares << '\n'
		<< " �ְ�: $" << s.share_val;

	// set format to #.##
	os.precision(2);
	os << " �ֽ� �� ��ġ: $" << s.total_val << '\n';

	// restore original format
	os.setf(orig, ios_base::floatfield);
	os.precision(prec);
	return os;
}