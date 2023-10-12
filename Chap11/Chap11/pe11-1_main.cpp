/*
	문제 1:
	- 구현한 Vector 클래스를 이용하여 목표 거리에 도달할 때까지의 걸음 수와 현재 위치를 보고
	- 연속적인 위치를 파일에 기록
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "pe11-1.h"

int main() {
	using namespace std;
	using VECTOR::Vector;

	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	// 파일 입력을 위한 추가 부분
	ofstream os;
	os.open("randwalk1.txt");

	cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	while (cin >> target) {
		cout << "보폭을 입력하십시오: ";
		if (!(cin >> dstep))
			break;

		os << "목표 거리: " << target << ", 보폭: " << dstep << endl;
		os << steps << ": " << result << endl;

		while (result.magval() < target) {
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
			os << steps << ": " << result << endl;
		}

		os << steps << " 걸음을 걸은 후 술고래의 현재 위치:\n";
		os << result << endl;
		result.polar_mode();
		os << " 또는\n" << result << endl;
		os << "걸음당 기둥에서 벗어난 평균 거리 = "
			<< result.magval() / steps << endl;

		steps = 0;
		result.reset(0.0, 0.0);
		cout << "목표 거리를 입력하십시오(끝내려면 q): ";
	}
	cout << "프로그램을 종료합니다.\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;
	os.close();

	return 0;
}