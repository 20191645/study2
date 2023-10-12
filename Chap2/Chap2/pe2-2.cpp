/*
	문제 2:
	거리에 대해 마일 단위로 입력 요구,
	킬로미터 단위로 환산하여 출력
*/

#include <iostream>
using namespace std;

int main() {
	double mile;
	cout << "거리를 마일 단위로 입력하시오: ";
	cin >> mile;
	cout << "킬로미터 단위로 환산하면 다음과 같습니다: " << (mile * 1.60934);

	return 0;
}