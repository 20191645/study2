#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "pe13-3.h"
using std::cout;
using std::endl;

// DMA 메서드
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
	cout << "상표: " << label << endl;
	cout << "등급: " << rating << endl;
}
std::ostream& operator<<(std::ostream& os, const DMA& rd) {
	os << "상표: " << rd.label << endl;
	os << "등급: " << rd.rating << endl;
	return os;
}

// baseDMA 메서드
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


// lacksDMA 메서드
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
	os << "색상: " << rs.color << endl;
	return os;
}
void lacksDMA::View() const {
	DMA::View();
	cout << "색상: " << color << endl;
}


// hasDMA 메서드
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
	os << "스타일: " << hs.style << endl;
	return os;
}
void hasDMA::View() const {
	DMA::View();
	cout << "스타일: " << style << endl;
}