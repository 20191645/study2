/*
	문제 3:
	메뉴 방식으로 운영되는 샘플 프로그램
*/

#include <iostream>

int main() {
	using namespace std;

	char ch;
	cout << "다음 선택 사항 중에서 하나를 선택하십시오. (끝내려면 q)" << endl;
	cout << "c) camera " << "p) pianist" << endl;
	cout << "t) tree " << "g) game" << endl;
	cin.get(ch);
	while (ch != 'q') {
		cin.get();
		switch (ch) {
		case 'c':
			cout << "카메라는 비쌉니다.\n";
			break;
		case 'p':
			cout << "피아니스트는 손이 큽니다.\n";
			break;
		case 't':
			cout << "단풍나무는 잎이 별처럼 생겼습니다.\n";
			break;
		case 'g':
			cout << "게임은 정말 재밌습니다.\n";
			break;
		}
		cout << "c, p, t, g 중에서 하나를 선택하십시오. (끝내려면 q): ";
		cin.get(ch);
	}
	cout << "프로그램을 종료합니다.\n";

	return 0;
}