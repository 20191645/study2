/*
	���� 4:
	pe9-4�� �ٽ��ϵ� Sales ����ü�� ���� �Լ��� Sales Ŭ������ ����
*/

#include <iostream>
#include "pe10-4.h"

int main() {
	using SALES::Sales;

	double sales1[3] = { 1.0,2.0,3.0 };
	double sales2[5] = { 1.0,2.0,3.0,4.0,5.0 };

	Sales one(sales1, 3);
	one.showSales();

	Sales two(sales2, 5);
	two.showSales();

	two.setSales();
	two.showSales();

	return 0;
}