/*
	���� 8:
	������ ����Ʈ Ŭ���� ����
*/

#include <iostream>
#include "pe10-8.h"

int main() {
	List list;
	list.show();
	if (list.isempty())
		std::cout << "����Ʈ�� ��� �ֽ��ϴ�.\n";

	Item arr[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; i++) {
		if (!list.add(arr[i]))
			std::cout << "����Ʈ�� �� �ֽ��ϴ�.\n";
	}
	list.show();

	list.update(arr[3], 3);
	list.show();
	list.update(arr[3], 2);
	list.show();

	return 0;
}