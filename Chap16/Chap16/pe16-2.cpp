/*
	문제 2:
	pe16-1과 같은 문제를 풀되 대소문자, 빈칸, 구두점 등을 따진다
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool palindrome(string& str);

int main() {
	string str;
	cout << "회문 검사를 진행할 문자열을 입력하십시오(끝내려면 quit):\n";
	while (getline(cin, str) && str != "quit") {
		if (palindrome(str))
			cout << "해당 문자열은 회문입니다.\n";
		else
			cout << "해당 문자열은 회문이 아닙니다.\n";

		cout << "회문 검사를 진행할 문자열을 입력하십시오(끝내려면 quit):\n";
	}

	return 0;
}

bool palindrome(string& str) {
	// 대소문자, 빈칸, 구두점 등 처리
	string::iterator it = copy_if(str.begin(), str.end(), str.begin(), isalpha);
	str.erase(it, str.end());
	transform(str.begin(), str.end(), str.begin(), tolower);

	// str을 뒤집은 문자열 복사
	string rts = str;
	reverse(rts.begin(), rts.end());

	if (rts == str)
		return true;
	else
		return false;
}