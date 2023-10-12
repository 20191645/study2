#ifndef PE12_2_H_
#define PE12_2_H_

#include <iostream>
using std::ostream;
using std::istream;

class String {
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;	// cin 입력 한계

public:
	String();	// 디폴트 생성자
	String(const char* s);	// 생성자
	String(const String& st);	// 복사 생성자
	~String();
	int length() const { return len; }

	// 오버로딩 연산자 메서드
	String& operator=(const String& st);
	String& operator=(const char* s);
	char& operator[](int i);
	const char& operator[](int i) const;

	// 오버로딩 연산자 프렌드
	friend bool operator<(const String& st1, const String& st2);
	friend bool operator>(const String& st1, const String& st2);
	friend bool operator==(const String& st1, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);

	// Practice2 추가 메서드
	friend String operator+(const String& st1, const String& st2);
	void stringlow();
	void stringup();
	int has(char ch) const;

	// static 함수
	static int HowMany();
};

#endif