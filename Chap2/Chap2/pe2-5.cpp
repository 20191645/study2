/*
	문제 5:
	섭씨 온도를 매개변수로 전달받아 화씨 온도로 환산하여 리턴하는 함수 작성
*/

#include <iostream>
using namespace std;

double CelToFah(double);

int main() {
	double celsius;
	cout << "섭씨 온도를 입력하고 Enter 키를 누르십시오: ";
	cin >> celsius;
	cout << "섭씨 온도는 화씨로 " << CelToFah(celsius) << "입니다" << endl;

	return 0;
}

double CelToFah(double cel)
{
	return 1.8 * cel + 32.0;
}