/*
	���� 5:
	Queue Ŭ������ �̿��Ͽ� ATM �ùķ��̼� ����
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "pe12-5.h"

const int MIN_PER_HR = 60;

bool newcustomer(double x);

int main() {
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	std::srand(std::time(0));

	cout << "��� ����: ���� ������ ATM\n";
	int qs;
	cout << "ť�� �ִ� ���̸� �Է��Ͻʽÿ�: ";
	cin >> qs;
	Queue line(qs);

	int hours;
	cout << "�ùķ��̼� �ð� ���� �Է��Ͻʽÿ�: ";
	cin >> hours;
	// �ùķ��̼��� 1�п� 1�ֱ⸦ �����Ѵ�
	long cyclelimit = MIN_PER_HR * hours;

	double perhour;
	cout << "�ð��� ��� �� ���� �Է��Ͻʽÿ�: ";
	cin >> perhour;
	// ��� �� ���� ���� (�� ����)
	double min_per_cust;
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;	// Customer Ŭ���� ��ü
	long turnaways = 0;	// ť �������� �� ���� �� ��
	long customers = 0;	// ť�� �� �� �� ��
	long served = 0;	// �ùķ��̼ǿ��� �ŷ� ó���� �� ��
	long sum_line = 0;	// ť�� ���� ����
	long wait_time = 0;	// ATM�� �� ������ ����ϴ� �ð�
	long line_wait = 0;	// ������ �� ���� ����� ���� �ð�

	// �ùķ��̼��� �����Ѵ�
	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		// �� ���� �����ߴ�
		if (newcustomer(min_per_cust)) {
			if (line.isfull())
				turnaways++;
			else {
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}

		if (wait_time <= 0 && !line.isempty()) {
			// ���� ���� �޴´�
			line.dequeue(temp);
			// ��� �ð� = ���� �� ó�� �ð�
			wait_time = temp.ptime();
			// ���� �ð� - ���� �ð�
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;

		sum_line += line.queuecount();
	}

	// �ùķ��̼� ����� ����Ѵ�
	if (customers > 0) {
		cout << " ť�� ���� �� �� ��: " << customers << endl;
		cout << "�ŷ��� ó���� �� ��: " << served << endl;
		cout << " �߱��� ���� �� ��: " << turnaways << endl;

		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);

		cout << "\t\t��� ť�� ����: ";
		cout << (double)sum_line / cyclelimit << endl;
		cout << "\t\t��� ��� �ð�: ";
		cout << (double)line_wait / served << "��\n";
	}
	else
		cout << "���� �� �� �����ϴ�!\n";
	cout << "�Ϸ�!\n";

	return 0;
}

bool newcustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);
}