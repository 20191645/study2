/*
	���� 3:
	pe9-1�� �ٽ� �ϵ� golf ����ü�� golf Ŭ������ ����
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