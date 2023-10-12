#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "pe13-3.h"
using std::cout;
using std::endl;

// DMA �޼���
DMA::DMA(const char* l, int r) {
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}
DMA::DMA(const DMA& rd) {
	label = new char[strlen(rd.label) + 1];
	strcpy(label, rd.label);
	rating = rd.rating;
}

DMA::~DMA() {
	delete[]label;
}
DMA& DMA::operator=(const DMA& rd) {
	if (this == &rd)
		return *this;
	label = new char[strlen(rd.label) + 1];
	strcpy(label, rd.label);
	rating = rd.rating;
	return *this;
}
void DMA::View() const {
	cout << "��ǥ: " << label << endl;
	cout << "���: " << rating << endl;
}
std::ostream& operator<<(std::ostream& os, const DMA& rd) {
	os << "��ǥ: " << rd.label << endl;
	os << "���: " << rd.rating << endl;
	return os;
}

// baseDMA �޼���
baseDMA::baseDMA(const char* l, int r)
	:DMA(l, r) {}
baseDMA::baseDMA(const baseDMA& rs)
	:DMA(rs) {}

baseDMA:: ~baseDMA() {}
baseDMA& baseDMA::operator=(const baseDMA& rs) {
	if (this == &rs)
		return *this;
	DMA::operator=(rs);
	return *this;
}
std::ostream& operator<<(std::ostream& os, const baseDMA& rs) {
	os << (const DMA&)rs;
	return os;
}
void baseDMA::View() const {
	DMA::View();
}


// lacksDMA �޼���
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	:DMA(l, r)
{
	strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
lacksDMA::lacksDMA(const char* c, const DMA& rs)
	:DMA(rs)
{
	strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}
std::ostream& operator<<(std::ostream& os, const lacksDMA& rs) {
	os << (const DMA&)rs;
	os << "����: " << rs.color << endl;
	return os;
}
void lacksDMA::View() const {
	DMA::View();
	cout << "����: " << color << endl;
}


// hasDMA �޼���
hasDMA::hasDMA(const char* s, const char* l, int r)
	:DMA(l, r)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}
hasDMA::hasDMA(const char* s, const DMA& rs)
	:DMA(rs)
{
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA& hs)
	:DMA(hs)
{
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
}

hasDMA::~hasDMA() {
	delete[]style;
}
hasDMA& hasDMA::operator=(const hasDMA& hs) {
	if (this == &hs)
		return *this;
	delete[]style;
	DMA::operator=(hs);
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
	return *this;
}
std::ostream& operator<<(std::ostream& os, const hasDMA& hs) {
	os << (const DMA&)hs;
	os << "��Ÿ��: " << hs.style << endl;
	return os;
}
void hasDMA::View() const {
	DMA::View();
	cout << "��Ÿ��: " << style << endl;
}