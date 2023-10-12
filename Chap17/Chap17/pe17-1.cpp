/*
	문제 1:
	- 입력에서 $가 나올 때까지의 문자 수 카운트
	- $를 입력 스트림에 남겨 두기
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	string str;
	cout << "문자열을 입력하십시오: ";
	getline(cin, str, '$');
	int count = str.size();
	cin.putback('$');

	cout << "입력한 문자열: " << str << endl;
	cout << "$가 나오기 전까지의 문자 수: " << count << endl;

	return 0;
}