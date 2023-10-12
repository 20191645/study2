#include <iostream>
#include "pe10-4.h"

namespace SALES {
	Sales::Sales(const double ar[], int n) {
		int i;
		average = 0;
		for (i = 0; i < QUARTERS && n > i; i++) {
			sales[i] = ar[i];
			average += sales[i];
		}
		for (int j = i; j < QUARTERS; j++) {
			sales[j] = 0;
		}

		average /= QUARTERS;
		max = sales[0];
		min = sales[0];
		for (i = 1; i < QUARTERS; i++) {
			if (sales[i] > max)
				max = sales[i];
			if (sales[i] < min)
				min = sales[i];
		}
	}

	void Sales::setSales() {
		using namespace std;

		double ar[QUARTERS];
		for (int i = 0; i < QUARTERS; i++) {
			cout << (i + 1) << "분기 판매액을 입력하십시오: ";
			cin >> ar[i];
		}
		cout << endl;

		Sales temp(ar, QUARTERS);
		*this = temp;
	}

	void Sales::showSales() const {
		using namespace std;
		cout << "분기별 판매액:\n";
		for (int i = 0; i < 4; i++)
			cout << (i + 1) << "분기: " << sales[i] << endl;
		cout << "평균값: " << average << endl;
		cout << "최대값: " << max << endl;
		cout << "최소값: " << min << endl << endl;
	}
}