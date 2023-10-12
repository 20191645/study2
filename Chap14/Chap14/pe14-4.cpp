#include <iostream>
#include <ctime>
#include <cstdlib>
#include "pe14-4.h"
using std::cout;
using std::endl;
using std::cin;

// Person 메서드
Person::Person(const std::string& fn, const std::string& ln)
	:firstname(fn), lastname(ln) {}

void Person::Show() {
	cout << "이름: " << lastname << " " << firstname << endl;
}

void Person::Set() {
	cout << "성을 입력하십시오: ";
	getline(cin, lastname);
	cout << "이름을 입력하십시오: ";
	getline(cin, firstname);
}

// Gunslinger 메서드
Gunslinger::Gunslinger(const std::string& fn, const std::string& ln, double t, int n)
	:Person(fn, ln), time(t), notch(n) {}
Gunslinger::Gunslinger(const Person& p, double t, int n)
	:Person(p), time(t), notch(n) {}

void Gunslinger::Show() {
	cout << "직업: 건슬링어\n";
	Person::Show();
	cout << "권총을 빼내는 시간: " << time << endl;
	cout << "권총에 새겨진 금 수: " << notch << endl;
}

void Gunslinger::Set() {
	Person::Set();
	cout << "권총을 빼내는 시간을 입력하시오: ";
	cin >> time;
	cout << "권총에 새겨진 금 수를 입력하시오: ";
	cin >> notch;
}


// PokerPlayer 메서드
PokerPlayer::PokerPlayer(const std::string& fn, const std::string& ln, double c)
	:Person(fn, ln), card(c) {}
PokerPlayer::PokerPlayer(const Person& p, double c)
	:Person(p), card(c) {}

void PokerPlayer::Show() {
	cout << "직업: 포커선수\n";
	Person::Show();
	cout << "카드 값: " << card << endl;
}
double PokerPlayer::Draw() {
	srand(time(0));
	card = double(rand() % 52 + 1);
	return card;
}

void PokerPlayer::Set() {
	Person::Set();
	Draw();
}


// BadDude 메서드
BadDude::BadDude(const std::string& fn, const std::string& ln, double t, int n, double c)
	:Person(fn, ln), Gunslinger(fn, ln, t, n), PokerPlayer(fn, ln, c) {}
BadDude::BadDude(const Person& p, double t, int n, double c)
	:Person(p), Gunslinger(p, t, n), PokerPlayer(p, c) {}
BadDude::BadDude(const Gunslinger& g, double c)
	:Person(g), Gunslinger(g), PokerPlayer(g, c) {}
BadDude::BadDude(const PokerPlayer& pp, double t, int n)
	:Person(pp), Gunslinger(pp, t, n), PokerPlayer(pp) {}

void BadDude::Show() {
	cout << "직업: 건슬링어 겸 포커선수\n";
	Person::Show();
	cout << "권총을 빼내는 시간: " << Gdraw() << endl;
	cout << "권총에 새겨진 금 수: " << Gunslinger::Notch() << endl;
	cout << "카드 값: " << Cdraw() << endl;
}

void BadDude::Set() {
	Gunslinger::Set();
	Cdraw();
}