/*
	문제 2:
	Person 클래스의 생성자, 메서드 구현
*/

#include <iostream>
#include "pe10-2.h"

int main() {
	using namespace std;

	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	one.FormalShow();
	cout << endl;
	two.Show();
	two.FormalShow();
	cout << endl;
	three.Show();
	three.FormalShow();
	cout << endl;

	return 0;
}