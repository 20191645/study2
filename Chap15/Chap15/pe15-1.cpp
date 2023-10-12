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
		cout << "불륨 = " << volume << endl;
		cout << "채널 = " << channel << endl;
		cout << "모드 = "
			<< (mode == Antenna ? "지상파 방송" : "케이블 방송") << endl;
		cout << "입력 = " << (input == TV ? "TV" : "DVD") << endl;
	}
}


// 추가된 메서드
void Remote::show_mode() {
	using std::cout;
	using std::endl;

	cout << "리모콘 모드 = "
		<< (remote_mode == Normal ? "일반 모드" : "대화 모드")
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

