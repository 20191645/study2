/*
	문제 5:
	- 스톤, 정수 파운드, 부동소수점 파운드 형식 중 해석 선택하는 상태 멤버 추가
	- <<, +, -, * 연산자 오버로딩
*/

#include <iostream>
using std::cout;
using std::endl;
#include "pe11-5.h"

int main() {
	Stonewt pavarotti = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);
	Stonewt bird(12, 9);

	cout << "테너 가수의 몸무게: " << pavarotti;
	cout << "탐정의 몸무게: " << wolfe;
	cout << "대통령의 몸무게: " << taft;
	cout << "새의 몸무게: " << bird;
	cout << endl;

	cout << "taft + wolfe = " << taft + wolfe;
	cout << "wolfe + taft = " << wolfe + taft;
	cout << "wolfe - pavarotti = " << wolfe - pavarotti;
	cout << "taft - bird = " << taft - bird;
	cout << "taft * 1.2 = " << taft * 1.2;
	cout << "1.2 * taft = " << 1.2 * taft;

	return 0;
}