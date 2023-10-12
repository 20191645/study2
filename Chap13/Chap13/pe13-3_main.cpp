/*
	문제 3:
	- baseDMA, lacksDMA, hasDMA 클래스가 하나의 추상화 기초 클래스로부터 파생되도록 수정
	- 추상화 기초 클래스 포인터의 배열 사용하여 결과 테스트
	- 데이터 출력하는 가상 메서드 View() 추가
*/

#include <iostream>
#include "pe13-3.h"

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	DMA* p_dma[4];
	char label[40];
	int rating;

	char kind;
	for (int i = 0; i < 4; i++) {
		cout << "라벨을 입력하십시오: ";
		cin.getline(label, 39);
		cout << "평가를 입력하십시오: ";
		cin >> rating;
		cout << "baseDMA 객체는 1, lacksDMA 객체는 2, hasDMA 객체는 3을 입력하십시오: ";
		while (cin >> kind && (kind != '1' && kind != '2' && kind != '3'))
			cout << "1 아니면 2, 3을 입력하십시오: ";

		if (kind == '1') {
			p_dma[i] = new baseDMA(label, rating);
			cin.get();
		}
		else if (kind == '2') {
			char color[40];
			cin.get();
			cout << "색깔을 입력하십시오: ";
			cin.getline(color, 39);
			p_dma[i] = new lacksDMA(color, label, rating);
		}
		else {
			char style[40];
			cin.get();
			cout << "스타일을 입력하십시오: ";
			cin.getline(style, 39);
			p_dma[i] = new hasDMA(style, label, rating);
		}
	}
	cout << endl;

	for (int i = 0; i < 4; i++) {
		p_dma[i]->View();
		cout << endl;
	}

	for (int i = 0; i < 4; i++)
		delete p_dma[i];
	cout << "프로그램을 종료합니다.\n";
	return 0;
}