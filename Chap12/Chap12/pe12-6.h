#ifndef PE12_6_H_
#define PE12_6_H_

// �� ť�� Customer �׸��� �����ϰ� �ȴ�
class Customer {
private:
	long arrive;	// ���� ť�� ������ �ð�
	int processtime;	// ���� �Ÿ��� ó���ϴ� �ð�

public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue {
private:
	enum { Q_SIZE = 10 };
	struct Node { Item item; struct Node* next; };

	Node* front;	// Queue �Ӹ�
	Node* rear;	// Queue ����
	int items;	// Queue�� �ִ� ���� �׸� ��
	const int qsize;	// Queue�� ���� �� �ִ� �ִ� �׸� ��

	// ���� ���縦 �����ϴ� ���� ����
	Queue(const Queue& q) :qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }

public:
	Queue(int qs = Q_SIZE);
	~Queue();

	bool isempty() const;
	bool isfull() const;

	int queuecount() const;

	bool enqueue(const Item& item);
	bool dequeue(Item& item);
};

#endif