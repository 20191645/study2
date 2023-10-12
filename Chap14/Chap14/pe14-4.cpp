#include <iostream>
#include <ctime>
#include <cstdlib>
#include "pe14-4.h"
using std::cout;
using std::endl;
using std::cin;

// Person �޼���
Person::Person(const std::string& fn, const std::string& ln)
	:firstname(fn), lastname(ln) {}

void Person::Show() {
	cout << "�̸�: " << lastname << " " << firstname << endl;
}

void Person::Set() {
	cout << "���� �Է��Ͻʽÿ�: ";
	getline(cin, lastname);
	cout << "�̸��� �Է��Ͻʽÿ�: ";
	getline(cin, firstname);
}

// Gunslinger �޼���
Gunslinger::Gunslinger(const std::string& fn, const std::string& ln, double t, int n)
	:Person(fn, ln), time(t), notch(n) {}
Gunslinger::Gunslinger(const Person& p, double t, int n)
	:Person(p), time(t), notch(n) {}

void Gunslinger::Show() {
	cout << "����: �ǽ�����\n";
	Person::Show();
	cout << "������ ������ �ð�: " << time << endl;
	cout << "���ѿ� ������ �� ��: " << notch << endl;
}

void Gunslinger::Set() {
	Person::Set();
	cout << "������ ������ �ð��� �Է��Ͻÿ�: ";
	cin >> time;
	cout << "���ѿ� ������ �� ���� �Է��Ͻÿ�: ";
	cin >> notch;
}


// PokerPlayer �޼���
PokerPlayer::PokerPlayer(const std::string& fn, const std::string& ln, double c)
	:Person(fn, ln), card(c) {}
PokerPlayer::PokerPlayer(const Person& p, double c)
	:Person(p), card(c) {}

void PokerPlayer::Show() {
	cout << "����: ��Ŀ����\n";
	Person::Show();
	cout << "ī�� ��: " << card << endl;
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


// BadDude �޼���
BadDude::BadDude(const std::string& fn, const std::string& ln, double t, int n, double c)
	:Person(fn, ln), Gunslinger(fn, ln, t, n), PokerPlayer(fn, ln, c) {}
BadDude::BadDude(const Person& p, double t, int n, double c)
	:Person(p), Gunslinger(p, t, n), PokerPlayer(p, c) {}
BadDude::BadDude(const Gunslinger& g, double c)
	:Person(g), Gunslinger(g), PokerPlayer(g, c) {}
BadDude::BadDude(const PokerPlayer& pp, double t, int n)
	:Person(pp), Gunslinger(pp, t, n), PokerPlayer(pp) {}

void BadDude::Show() {
	cout << "����: �ǽ����� �� ��Ŀ����\n";
	Person::Show();
	cout << "������ ������ �ð�: " << Gdraw() << endl;
	cout << "���ѿ� ������ �� ��: " << Gunslinger::Notch() << endl;
	cout << "ī�� ��: " << Cdraw() << endl;
}

void BadDude::Set() {
	Gunslinger::Set();
	Cdraw();
}