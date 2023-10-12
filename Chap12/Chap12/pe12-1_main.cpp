/*
	문제 1:
	Cow 클래스의 메서드 구현
*/

#include <iostream>
#include "pe12-1.h"

int main() {
	Cow c1;
	c1.ShowCow();
	Cow c2("c2", "hobby2", 2);
	c2.ShowCow();
	Cow c3(c1);
	c3.ShowCow();
	Cow c4 = c2;
	c4.ShowCow();

	return 0;
}