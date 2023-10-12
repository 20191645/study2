/*
	문제 3:
	pe9-1을 다시 하되 golf 구조체를 golf 클래스로 변경
*/

#include <iostream>
#include "pe10-3.h"

int main() {
	using namespace std;

	Golf arr[3];
	int i;
	for (i = 0; i < 3; i++) {
		if (!arr[i].setgolf())
			break;
	}
	for (int j = 0; j < i; j++)
		arr[j].showgolf();

	Golf ann("Ann Birdfree", 24);
	ann.showgolf();
	ann.update(20);
	ann.showgolf();

	return 0;
}