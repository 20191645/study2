/*
	문제 3:
	위도를 도, 분, 초 단위로 요청하여 10진수 형식으로 출력
*/

#include <iostream>

int main() {
	using namespace std;

	int degree, minute, second;
	cout << "위도를 도, 분, 초 단위로 입력하시오: \n";
	cout << "먼저, 도각을 입력하시오: ";
	cin >> degree;
	cout << "다음에, 분각을 입력하시오: ";
	cin >> minute;
	cout << "끝으로, 초각을 입력하시오: ";
	cin >> second;

	const double RADIAN = 60.0;
	double radian = degree + (minute / RADIAN) + (second / RADIAN / RADIAN);
	cout << degree << "도, " << minute << "분, " << second << "초 = " << radian << "도\n";

	return 0;
}