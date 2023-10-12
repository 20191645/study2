/*
	���� 1:
	- Tv, Remote Ŭ������ ��ȣ ������ ����� ����
	- Remote Ŭ������ ���� ���� ��� �߰�, ��� �޼��� �߰�
	- Tv Ŭ������ ���� ���� ���� ��� �����ϴ� �޼��� �߰�
*/

#include <iostream>
#include "pe15-1.h"

int main() {
	using std::cout;

	Tv s42;
	cout << "42\" TV�� �ʱ� ������:\n";
	s42.settings();

	s42.onoff();
	s42.chanup();
	cout << "\n42\" TV�� ����� ������:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n������ ��� �� 42\" TV�� ������:\n";
	s42.settings();

	cout << std::endl;
	grey.show_mode();
	if (s42.set_remote_mode(grey)) {
		cout << "������ ��带 �����Ͽ����ϴ�.\n";
		grey.show_mode();
	}

	return 0;
}