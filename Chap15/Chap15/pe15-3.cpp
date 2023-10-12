/*
	문제 3:
	- pe14-2에서의 두 예외 클래스를 기초 클래스에서 파생되도록 수정
	- 예외들이 함수 이름과 값을 보고하는 메서드 추가
	- 하나의 catch 블록으로 두 예외 처리
*/

#include <iostream>
#include <cmath>
#include "pe15-3.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	double x, y, z;
	cout << "두 수를 입력하십시오: ";
	while (cin >> x >> y) {
		try {
			z = hmean(x, y);
			cout << x << ", " << y << "의 조화평균은 "
				<< z << "입니다.\n";
			z = gmean(x, y);
			cout << x << ", " << y << "의 기하평균은 "
				<< z << "입니다.\n";
			cout << "다른 두 수를 입력하십시오(끝내려면 q): ";
		}
		catch (bad& b) {
			cout << b.what();
			b.show();
			continue;
		}
	}

	cout << "프로그램을 종료합니다.\n";
	return 0;
}

double hmean(double a, double b) throw(bad_hmean) {
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) throw(bad_gmean) {
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}