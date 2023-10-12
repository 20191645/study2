/*
	문제 10:
	calculate(): 첫 번째, 두 번째 매개변수는 double형,
	세 번째 매개변수는 double형 매개변수 2개를 취하여 double형을 리턴하는 함수 포인터
*/

#include <iostream>

double calculate(double, double, double (*pt)(double, double));
double add(double, double);
double min(double, double);
double mul(double, double);

int main() {
	using namespace std;

	double q = calculate(2.5, 10.4, add);
	cout << q << endl;
	double p = calculate(2.5, 10.4, min);
	cout << p << endl;

	double (*pt[3])(double, double) = {add,min,mul};
	double r;
	for (int i = 0; i < 3; i++) {
		r = calculate(4, 2, pt[i]);
		cout << r << endl;
	}

	return 0;
}

double calculate(double x, double y, double (*pt)(double, double)) {
	return pt(x, y);
}

double add(double x, double y) {
	return x + y;
}

double min(double x, double y) {
	return x - y;
}

double mul(double x, double y) {
	return x * y;
}