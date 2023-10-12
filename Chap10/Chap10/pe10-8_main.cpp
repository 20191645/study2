/*
	문제 8:
	간단한 리스트 클래스 구현
*/

#include <iostream>
#include "pe10-8.h"

int main() {
	List list;
	list.show();
	if (list.isempty())
		std::cout << "리스트가 비어 있습니다.\n";

	Item arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		if (!list.add(arr[i]))
			std::cout << "리스트가 차 있습니다.\n";
	}
	list.show();

	list.update(arr[3], 3);
	list.show();
	list.update(arr[3], 2);
	list.show();

	return 0;
}