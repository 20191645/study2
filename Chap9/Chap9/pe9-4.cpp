#include <iostream>
#include "pe9-4.h"

namespace SALES {
	void setSales(Sales& s, const double ar[], int n) {
		int i;
		s.average = 0;
		for (i = 0; i < QUARTERS && n > i; i++) {
			s.sales[i] = ar[i];
			s.average += s.sales[i];
		}
		for (int j = i; j < QUARTERS; j++) {
			s.sales[j] = 0;
		}

		s.average /= QUARTERS;
		s.max = s.sales[0];
		s.min = s.sales[0];
		for (i = 1; i < QUARTERS; i++) {
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			if (s.sales[i] < s.min)
				s.min = s.sales[i];
		}
	}

	void setSales(Sales& s) {
		using namespace std;

		s.average = 0;
		for (int i = 0; i < QUARTERS; i++) {
			cout << (i + 1) << "�б� �Ǹž��� �Է��Ͻʽÿ�: ";
			cin >> s.sales[i];
			s.average += s.sales[i];
		}
		cout << endl;

		s.average /= QUARTERS;
		s.max = s.sales[0];
		s.min = s.sales[0];
		for (int i = 1; i < QUARTERS; i++) {
			if (s.sales[i] > s.max)
				s.max = s.sales[i];
			if (s.sales[i] < s.min)
				s.min = s.sales[i];
		}
	}

	void showSales(const Sales& s) {
		using namespace std;
		cout << "�б⺰ �Ǹž�:\n";
		for (int i = 0; i < 4; i++)
			cout << (i + 1) << "�б�: " << s.sales[i] << endl;
		cout << "��հ�: " << s.average << endl;
		cout << "�ִ밪: " << s.max << endl;
		cout << "�ּҰ�: " << s.min << endl << endl;
	}
}