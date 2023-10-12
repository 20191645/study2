/*
	문제 1:
	- Tv, Remote 클래스를 상호 프렌드 관계로 구현
	- Remote 클래스에 상태 변수 멤버 추가, 출력 메서드 추가
	- Tv 클래스에 위의 상태 변수 멤버 변경하는 메서드 추가
*/

#include <iostream>
#include "pe15-1.h"

int main() {
	using std::cout;

	Tv s42;
	cout << "42\" TV의 초기 설정값:\n";
	s42.settings();

	s42.onoff();
	s42.chanup();
	cout << "\n42\" TV의 변경된 설정값:\n";
	s42.settings();

	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	cout << "\n리모콘 사용 후 42\" TV의 설정값:\n";
	s42.settings();

	cout << std::endl;
	grey.show_mode();
	if (s42.set_remote_mode(grey)) {
		cout << "리모콘 모드를 변경하였습니다.\n";
		grey.show_mode();
	}

	return 0;
}