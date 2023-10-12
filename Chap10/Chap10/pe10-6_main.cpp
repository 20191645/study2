/*
	문제 6:
	Move 클래스의 메서드 정의
*/

#include <iostream>
#include "pe10-6.h"

int main() {
	using namespace std;

	Move m1;
	m1.showmove();
	m1.reset(4, 5);
	m1.showmove();

	Move m2(2, 3);
	m2.showmove();

	Move m3 = m2.add(m1);
	m3.showmove();

	return 0;
}