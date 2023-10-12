#include <iostream>
#include "pe10-5.h"

Stack::Stack() {
	top = 0;
}

bool Stack::isempty() const {
	return top == 0;
}

bool Stack::isfull() const {
	return top == MAX;
}

bool Stack::push(const Item& item) {
	if (isfull())
		return false;
	else
		items[top++] = item;
}

bool Stack::pop(Item& item) {
	if (isempty())
		return false;
	else
		item = items[--top];
}