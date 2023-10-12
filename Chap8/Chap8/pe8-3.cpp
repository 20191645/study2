/*
	문제 3:
	string 객체의 내용을 대문자로 변환하는 함수
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void up(string& str);

int main() {
	string str;
	cout << "문자열을 입력하시오 (끝내려면 q): ";
	while (getline(cin, str) && str != "q") {
		up(str);
		cout << str << endl;
		cout << "다음 문자열을 입력하시오 (끝내려면 q): ";
	}
	cout << "끝.\n";

	return 0;
}

void up(string& str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
}