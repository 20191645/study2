/*
	문제 3:
	pe11-1에서 N번 시도했을 때의 최고, 최저, 평균 걸음 수 보고
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pe11-3.h"

int main() {
	using std::cout;
	using std::cin;
	using std::endl;
	using VECTOR::Vector;

	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	// 추가
	int n;
	double max = 0.0;
	double min = DBL_MAX;
	double avg = 0.0;

	cout << "시도 횟수를 입력하십시오: ";
	cin >> n;
	cout << "목표 거리를 입력하십시오: ";
	cin >> target;
	cout << "보폭을 입력하십시오: ";
	cin >> dstep;

	for (int i = 0; i < n; i++) {
		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}

		if (steps > max)
			max = steps;
		if (steps < min)
			min = steps;
		avg += steps;

		steps = 0;
		result.reset(0.0, 0.0);
	}

	cout << "최고 걸음 수: " << max << endl;
	cout << "최저 걸음 수: " << min << endl;
	cout << n << "번 시도했을 때 평균 걸음 수: " << avg / n << endl;

	cout << "프로그램을 종료합니다.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}