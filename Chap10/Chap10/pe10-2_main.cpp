/*
	���� 2:
	Person Ŭ������ ������, �޼��� ����
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