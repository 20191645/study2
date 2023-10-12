#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "pe13-1.h"
using std::cout;
using std::endl;

// Cd �޼���
Cd::Cd(const char* s1, const char* s2, int n, double x) {
	strncpy(performers, s1, 49);
	strncpy(label, s2, 19);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd& d) {
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
Cd::Cd() {
	strcpy(performers, "performers");
	strcpy(label, "label");
	selections = playtime = 0;
}
Cd::~Cd() {}

void Cd::Report() const {
	cout << "������: " << performers << ", ��: " << label << endl;
	cout << "���� ��� ��: " << selections << ", ���� �ð�: " << playtime << "��" << endl;
}
Cd& Cd::operator=(const Cd& d) {
	if (this == &d)
		return *this;
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}


// Classic �޼���
Classic::Classic(const char* s, const char* s1, const char* s2, int n, double x)
	:Cd(s1, s2, n, x)
{
	strncpy(song, s, 49);
}
Classic::Classic(const Classic& c)
	:Cd(c)
{
	strcpy(song, c.song);
}
Classic::Classic()
	:Cd()
{
	strcpy(song, "song");
}
Classic::~Classic() {}

void Classic::Report() const {
	Cd::Report();
	cout << "��ǥ��: " << song << endl;
}
Classic& Classic::operator=(const Classic& c) {
	if (this == &c)
		return *this;
	Cd::operator=(c);
	strcpy(song, c.song);
	return *this;
}