#include <iostream>
#include "pe10-8.h"

List::List() {
	end = 0;
}

bool List::isempty() const {
	return end == 0;
}

bool List::isfull() const {
	return end == MAX;
}

bool List::add(Item& item) {
	if (isfull())
		return false;
	else {
		items[end++] = item;
		return true;
	}
}

void List::show() const {
	for (int i = 0; i < end; i++) {
		std::cout << (i + 1) << "��° ����: "
			<< items[i] << std::endl;
	}
}

void List::update(const Item& item, int n) {
	if (n < 0 || n >= end)
		std::cout << "����Ʈ ������ ����ϴ�.\n";
	else {
		std::cout << n + 1 << "��° ���Ҹ� �����Ͽ����ϴ�.\n";
		items[n] = item;
	}
}