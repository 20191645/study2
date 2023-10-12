/*
	문제 9:
	pe5-8.cpp와 같은 내용을 string 클래스를 이용하여 작성
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	int count = -1;
	string word;

	cout << "영어 단어들을 입력하십시오(끝내려면 done을 입력):\n";
	while (word != "done") {
		cin >> word;
		++count;
	}

	cout << "총 " << count << " 단어가 입력되었습니다.\n";

	return 0;
}