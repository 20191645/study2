#include <iostream>
#include "pe15-1.h"

bool Tv::volup() {
	if (volume != MaxVal) {
		volume++;
		return true;
	}
	return false;
}
bool Tv::voldown() {
	if (volume != Minval) {
		volume--;
		return true;
	}
	return false;
}
void Tv::chanup() {
	if (channel == maxchannel)
		channel = 1;
	else
		channel++;
}
void Tv::chandown() {
	if (channel == 1)
		channel = maxchannel;
	else
		channel--;
}
void Tv::settings() const {
	using std::cout;
	using std::endl;

	cout << "TV = " << (state == Off ? "OFF" : "ON") << endl;
	if (state == On) {
		cout << "�ҷ� = " << volume << endl;
		cout << "ä�� = " << channel << endl;
		cout << "��� = "
			<< (mode == Antenna ? "������ ���" : "���̺� ���") << endl;
		cout << "�Է� = " << (input == TV ? "TV" : "DVD") << endl;
	}
}


// �߰��� �޼���
void Remote::show_mode() {
	using std::cout;
	using std::endl;

	cout << "������ ��� = "
		<< (remote_mode == Normal ? "�Ϲ� ���" : "��ȭ ���")
		<< endl;
}

bool Tv::set_remote_mode(Remote& r) {
	if (state == Off)
		return false;
	else {
		r.remote_mode = (r.remote_mode == Remote::Normal) ?
			Remote::Conversation : Remote::Normal;
		return true;
	}
}

