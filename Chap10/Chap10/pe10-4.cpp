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
			cout << (i + 1) << "�б� �Ǹž��� �Է��Ͻʽÿ�: ";
			cin >> ar[i];
		}
		cout << endl;

		Sales temp(ar, QUARTERS);
		*this = temp;
	}

	void Sales::showSales() const {
		using namespace std;
		cout << "�б⺰ �Ǹž�:\n";
		for (int i = 0; i < 4; i++)
			cout << (i + 1) << "�б�: " << sales[i] << endl;
		cout << "��հ�: " << average << endl;
		cout << "�ִ밪: " << max << endl;
		cout << "�ּҰ�: " << min << endl << endl;
	}
}