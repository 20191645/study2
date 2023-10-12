#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pe13-2.h"
using std::cout;
using std::endl;

// Cd 메서드
Cd::Cd(const char* s1, const char* s2, int n, double x) {
	performers = new char[strlen(s1) + 1];
	strcpy(performers, s1);
	label = new char[strlen(s2) + 1];
	strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd& d) {
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::Cd() {
	performers = new char[11];
	strcpy(performers, "performers");
	label = new char[6];
	strcpy(label, "label");
	selections = playtime = 0;
}
Cd::~Cd() {
	delete[]performers;
	delete[]label;
}

void Cd::Report() const {
	cout << "연주자: " << performers << ", 라벨: " << label << endl;
	cout << "수록 곡목 수: " << selections << ", 연주 시간: " << playtime << "분" << endl;
}
Cd& Cd::operator=(const Cd& d) {
	if (this == &d)
		return *this;
	delete[]performers;
	delete[]label;
	performers = new char[strlen(d.performers) + 1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}


// Classic 메서드
Classic::Classic(const char* s, const char* s1, const char* s2, int n, double x)
	:Cd(s1, s2, n, x)
{
	song = new char[strlen(s) + 1];
	strcpy(song, s);
}
Classic::Classic(const Classic& c)
	:Cd(c)
{
	song = new char[strlen(c.song) + 1];
	strcpy(song, c.song);
}
Classic::Classic()
	:Cd()
{
	song = new char[5];
	strcpy(song, "song");
}
Classic::~Classic() {
	delete[] song;
}

void Classic::Report() const {
	Cd::Report();
	cout << "대표곡: " << song << endl;
}
Classic& Classic::operator=(const Classic& c) {
	if (this == &c)
		return *this;
	delete[]song;
	Cd::operator=(c);
	song = new char[strlen(c.song) + 1];
	strcpy(song, c.song);
	return *this;
}