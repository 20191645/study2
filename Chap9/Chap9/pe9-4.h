// pe9-4.h -- pe9-4.cpp, pe9-4_main.cpp를 위한 헤더 파일
#ifndef PE9_4_H
#define PE9_4_H

namespace SALES {
	const int QUARTERS = 4;

	struct Sales {
		double sales[QUARTERS];
		double average;
		double max;
		double min;
	};

	void setSales(Sales& s, const double ar[], int n);
	void setSales(Sales& s);
	void showSales(const Sales& s);
}

#endif