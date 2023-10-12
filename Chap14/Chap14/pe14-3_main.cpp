/*
	���� 3:
	QueueTp ���ø� �����Ͽ� Worker Ŭ���� �������� ť ����
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
		cout << "������ �Է��Ͻʽÿ�:\n"
			<< "w: ������\ts: ����\t"
			<< "t: ���� �� ������\tq: ����\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL) {
			cout << "w, s, t, q �߿��� �ϳ��� �����Ͻʽÿ�: ";
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

	cout << "\n��� ��Ȳ�� ������ �����ϴ�:\n";
	int i;
	Worker* temp;
	for (i = 0; i < ct; i++) {
		cout << endl;
		if (queue.dequeue(temp))
			temp->Show();
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}