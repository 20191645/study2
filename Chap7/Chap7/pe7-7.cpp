/*
	문제 7:
	범위를 나타내는 2개의 포인터 매개변수를 사용하는 배열 처리 함수 정의
*/

#include <iostream>
using namespace std;

const int ArSize = 5;
double* fill_array(double* start, double* end);
void show_array(const double ar[], double* end);
void revalue(double ar[], double r, double* end);

int main() {
	double ar[ArSize];
	double* end = fill_array(ar, ar+ArSize);
	show_array(ar, end);

	if (end - ar > 0) {
		double r;
		cout << "재평가율을 입력해주십시오: ";
		while (!(cin >> r) || r < 0) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "다시 입력해주십시오: ";
		}
		revalue(ar, r, end);
		show_array(ar, end);
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}

double* fill_array(double* start, double* end) {
	int i = 1;
	double temp;
	double* ptr;
	
	for (ptr = start; ptr != end; ptr++) {
		cout << i << "번 부동산의 가격: $";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "입력 불량; 입력 과정을 끝내겠습니다.\n";
			break;
		}
		else if (temp < 0) {
			cout << "입력값이 음수입니다; 입력 과정을 끝내겠습니다.\n";
			break;
		}
		else {
			*ptr = temp;
			++i;
		}
	}

	return ptr;
}

void show_array(const double ar[], double* end) {
	int i = 1;
	for (const double* ptr = ar; ptr != end; ptr++) {
		cout << i << "번 부동산: $" << *ptr << endl;
	}
}

void revalue(double ar[], double r, double* end) {
	for (double* ptr = ar; ptr != end; ptr++)
		*ptr *= r;
}