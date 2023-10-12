/*
	문제 6:
	거리를 매개변수로 전달받아 천문 단위로 환산하여 리턴하는 함수 작성
*/

#include <iostream>
using namespace std;

double Years(double);

int main() {
	double light;
	cout << "광년 수를 입력하고 Enter 키를 누르십시오: ";
	cin >> light;
	cout << light << " 광년은 " << Years(light) << " 천문 단위입니다." << endl;

	return 0;
}

double Years(double light) {
	return light * 63240;
}