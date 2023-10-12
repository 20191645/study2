// QueueTp 클래스 구현
#ifndef PE14_3_1H
#define PE14_3_1_H

template <typename T>
class QueueTp {
private:
	enum { Q_SIZE = 5 };
	struct Node { T item; Node* next; };

	Node* front;
	Node* rear;
	int items;
	const int qsize;

	QueueTp(const QueueTp& q) :qsize(0) {}
	QueueTp& operator=(const QueueTp& q) { return *this; }

public:
	QueueTp(int size = Q_SIZE);
	~QueueTp();

	bool isempty() const { return items == 0; }
	bool isfull() const { return items == qsize; }

	bool enqueue(const T& item);
	bool dequeue(T& item);

	T& rear_item() { return rear->item; }
};

template <typename T>
QueueTp<T>::QueueTp(int size)
	:qsize(size), items(0)
{
	front = rear = NULL;
}

template <typename T>
QueueTp<T>::~QueueTp() {
	Node* temp;
	while (front != NULL) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

template <typename T>
bool QueueTp<T>::enqueue(const T& item) {
	if (items < qsize) {
		Node* temp = new Node;
		temp->item = item;
		temp->next = NULL;

		if (front == NULL)
			front = temp;
		else
			rear->next = temp;

		rear = temp;
		items++;

		return true;
	}
	else
		return false;
}

template <typename T>
bool QueueTp<T>::dequeue(T& item) {
	if (items > 0) {
		Node* temp = front;
		item = temp->item;
		front = front->next;
		delete temp;
		items--;

		if (front == NULL)
			rear = NULL;

		return true;
	}
	else
		return false;
}


#endif