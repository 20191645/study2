/*
	문제 1:
	void setgolf(): 매개변수로 전달된 값으로 golf 구조체 설정
	int setgolf(): 대화형으로 입력받은 값으로 golf 구조체 설정
	void handicap(): handicap 값 설정
	void showgolf(): golf 구조체 내용 출력
*/

// pe9-1.cpp와 함께 컴파일한다
#include <iostream>
#include "pe9-1.h"

int main() {
	using namespace std;

	golf arr[3];
	int i;
	for (i = 0; i < 3; i++) {
		if (!setgolf(arr[i]))
			break;
	}
	for (int j = 0; j < i; j++)
		showgolf(arr[j]);

	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	handicap(ann, 20);
	showgolf(ann);

	return 0;
}