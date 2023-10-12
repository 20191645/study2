/*
	문제 1:
	회문 검사하는 함수 구현하되 대소문자 구분, 빈칸, 구두점 신경쓰지 않는다
*/

#include <iostream>
#include <string>
using namespace std;

bool palindrome(string& str);

int main() {
	string str;
	cout << "회문 검사를 진행할 문자열을 입력하십시오(끝내려면 quit):\n";
	while (cin >> str && str != "quit") {
		if (palindrome(str))
			cout << "해당 문자열은 회문입니다.\n";
		else
			cout << "해당 문자열은 회문이 아닙니다.\n";

		cout << "회문 검사를 진행할 문자열을 입력하십시오(끝내려면 quit):\n";
	}

	return 0;
}

bool palindrome(string& str) {
	string temp = str;
	// 문자열을 뒤집는 함수
	reverse(temp.begin(), temp.end());

	if (str == temp)
		return true;
	else
		return false;
}