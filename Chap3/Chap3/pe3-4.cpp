/*
	문제 4:
	초 수를 정수 값으로 입력받고 일, 시, 분, 초로 출력하기
*/

#include <iostream>

int main() {
	using namespace std;

	long seconds;
	cout << "초 수를 입력하시오: ";
	cin >> seconds;

	const int DAY = 24;
	const int HOUR = 60;
	const int MINUTE = 60;

	int second = seconds % MINUTE;
	int minute = (seconds / MINUTE) % HOUR;
	int hour = (seconds / MINUTE / HOUR) % DAY;
	int day = seconds / MINUTE / HOUR / DAY;

	cout << seconds << "초 = " << day << "일, " << hour << "시간, ";
	cout << minute << "분, " << second << "초" << endl;

	return 0;
}