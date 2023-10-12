/*
	문제 8:
	char형 배열을 사용하여 'done'이 입력될 때까지 한 단어씩 읽는 루프
*/

#include <iostream>
#include <cstring>

int main() {
	using namespace std;

	int count = -1;
	char word[20];

	cout << "영어 단어들을 입력하십시오(끝내려면 done을 입력):\n";
	while (strcmp(word, "done")) {
		cin >> word;
		++count;
	}

	cout << "총 " << count << " 단어가 입력되었습니다.\n";

	return 0;
}