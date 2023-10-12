/*
	문제 4:
	void setSales(Sales&, const double...): 배열로부터 Sales 멤버로 복사
	void setSales(Sales&): 대화식으로 획득한 내용을 Sales 멤버에 저장
	void showSales(): Sales 구조체 내용 출력
*/

#include <iostream>
#include "pe9-4.h"

int main() {
	using SALES::Sales;
	using SALES::setSales;
	using SALES::showSales;

	Sales one;
	Sales two;
	double sales1[3] = { 1.0,2.0,3.0 };
	double sales2[5] = { 1.0,2.0,3.0,4.0,5.0 };

	setSales(one, sales1, 3);
	showSales(one);
	setSales(one, sales2, 5);
	showSales(one);

	setSales(two);
	showSales(two);

	return 0;
}