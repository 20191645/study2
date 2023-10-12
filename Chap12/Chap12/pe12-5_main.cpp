/*
	문제 5:
	Queue 클래스를 이용하여 ATM 시뮬레이션 구현
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pe12-5.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "사례 연구: 히서 은행의 ATM\n";
	int qs;
	cout << "큐의 최대 길이를 입력하십시오: ";
	cin >> qs;
	Queue line(qs);

	int hours;
	cout << "시뮬레이션 시간 수를 입력하십시오: ";
	cin >> hours;
	// 시뮬레이션은 1분에 1주기를 실행한다
	long cyclelimit = MIN_PER_HR * hours;

	double perhour;
	cout << "시간당 평균 고객 수를 입력하십시오: ";
	cin >> perhour;
	// 평균 고객 도착 간격 (분 단위)
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;	// Customer 클래스 객체
	long turnaways = 0;	// 큐 가득차서 발 돌린 고객 수
	long customers = 0;	// 큐에 줄 선 고객 수
	long served = 0;	// 시뮬레이션에서 거래 처리한 고객 수
	long sum_line = 0;	// 큐의 누적 길이
	long wait_time = 0;	// ATM이 빌 때까지 대기하는 시간
	long line_wait = 0;	// 고객들이 줄 서서 대기한 누적 시간

	// 시뮬레이션을 실행한다
	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		// 새 고객이 도착했다
		if (newcustomer(min_per_cust)) {
			if (line.isfull())
				turnaways++;
			else {
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}

		if (wait_time <= 0 && !line.isempty()) {
			// 다음 고객을 받는다
			line.dequeue(temp);
			// 대기 시간 = 현재 고객 처리 시간
			wait_time = temp.ptime();
			// 현재 시간 - 도착 시간
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;

		sum_line += line.queuecount();
	}

	// 시뮬레이션 결과를 출력한다
	if (customers > 0) {
		cout << " 큐에 줄을 선 고객 수: " << customers << endl;
		cout << "거래를 처리한 고객 수: " << served << endl;
		cout << " 발길을 돌린 고객 수: " << turnaways << endl;

		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);

		cout << "\t\t평균 큐의 길이: ";
		cout << (double)sum_line / cyclelimit << endl;
		cout << "\t\t평균 대기 시간: ";
		cout << (double)line_wait / served << "분\n";
	}
	else
		cout << "고객이 한 명도 없습니다!\n";
	cout << "완료!\n";

	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}