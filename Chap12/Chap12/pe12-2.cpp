#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cctype>
#include "pe12-2.h"
using std::cout;
using std::cin;

int String::num_strings = 0;
// static 함수
int String::HowMany() {
	return num_strings;
}

String::String() {
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}
String::String(const char* s) {
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	num_strings++;
}
String::String(const String& st) {
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	num_strings++;
}
String::~String() {
	num_strings--;
	delete[]str;
}

// 오버로딩 연산자 메서드
String& String::operator=(const String& st) {
	if (this == &st) {
		return *this;
	}
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}
String& String::operator=(const char* s) {
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
char& String::operator[](int i) {
	return str[i];
}
const char& String::operator[](int i) const {
	return str[i];
}

// 오버로딩 연산자 프렌드
bool operator<(const String& st1, const String& st2) {
	return (std::strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String& st1, const String& st2) {
	return st2 < st1;
}
bool operator==(const String& st1, const String& st2) {
	return !(std::strcmp(st1.str, st2.str));
}
ostream& operator<<(ostream& os, const String& st) {
	os << st.str;
	return os;
}
istream& operator>>(istream& is, String& st) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

// Practice2 추가 메서드
String operator+(const String& st1, const String& st2) {
	char* temp = new char[st1.len + st2.len + 1];
	strcpy(temp, st1.str);
	strcat(temp, st2.str);
	String st = temp;
	delete[]temp;
	return st;
}
void String::stringlow() {
	for (int i = 0; i < len; i++) {
		str[i] = tolower(str[i]);
	}
}
void String::stringup() {
	for (int i = 0; i < len; i++) {
		str[i] = toupper(str[i]);
	}
}
int String::has(char ch) const {
	int result = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == ch)
			result++;
	}
	return result;
}