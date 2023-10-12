#include "pe12-6.h"
#include <cstdlib>

void Customer::set(long when) {
	processtime = std::rand() % 3 + 1;
	arrive = when;
}


Queue::Queue(int qs) : qsize(qs), items(0), front(NULL), rear(NULL) {

}
Queue::~Queue() {
	Node* temp;
	while (front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty() const {
	return items == 0;
}
bool Queue::isfull() const {
	return items == qsize;
}

int Queue::queuecount() const {
	return items;
}

bool Queue::enqueue(const Item& item) {
	if (isfull())
		return false;

	Node* add = new Node;
	add->item = item;
	add->next = NULL;

	if (front == NULL) {
		front = add;
	}
	else {
		rear->next = add;
	}
	rear = add;
	items++;

	return true;
}
bool Queue::dequeue(Item& item) {
	if (isempty())
		return false;

	Node* temp = front;
	item = temp->item;
	front = temp->next;
	delete temp;
	items--;

	if (front == NULL)
		rear = NULL;

	return true;
}