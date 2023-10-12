/*
	문제 3:
	QueueTp 템플릿 정의하여 Worker 클래스 포인터의 큐 생성
*/

#include <iostream>
#include <cstring>
#include "pe14-3_1.h"
#include "pe14-3_2.h"

const int SIZE = 5;

int main() {
	using std::cout;
	using std::endl;
	using std::cin;
	using std::strchr;

	QueueTp<Worker*> queue;
	int ct;
	for (ct = 0; ct < SIZE; ct++) {
		char choice;
		cout << "직종을 입력하십시오:\n"
			<< "w: 웨이터\ts: 가수\t"
			<< "t: 가수 겸 웨이터\tq: 종료\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL) {
			cout << "w, s, t, q 중에서 하나를 선택하십시오: ";
			cin >> choice;
		}

		if (choice == 'q')
			break;
		switch (choice) {
		case 'w':
			queue.enqueue(new Waiter);
			break;
		case 's':
			queue.enqueue(new Singer);
			break;
		case 't':
			queue.enqueue(new SingingWaiter);
			break;
		}

		cin.get();
		queue.rear_item()->Set();
	}

	cout << "\n사원 현황은 다음과 같습니다:\n";
	int i;
	Worker* temp;
	for (i = 0; i < ct; i++) {
		cout << endl;
		if (queue.dequeue(temp))
			temp->Show();
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}