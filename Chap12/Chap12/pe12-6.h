#ifndef PE12_6_H_
#define PE12_6_H_

// 이 큐는 Customer 항목을 포함하게 된다
class Customer {
private:
	long arrive;	// 고객이 큐에 도착한 시간
	int processtime;	// 고객의 거리를 처리하는 시간

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

	Node* front;	// Queue 머리
	Node* rear;	// Queue 꼬리
	int items;	// Queue에 있는 현재 항목 수
	const int qsize;	// Queue에 넣을 수 있는 최대 항목 수

	// 얕은 복사를 방지하는 선점 정의
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