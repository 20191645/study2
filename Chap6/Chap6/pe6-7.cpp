/*
	문제 7:
	q가 따로 입력될 때까지 한 단어씩 읽고
	'모음 시작 단어 수, 자음 시작 단어 수, 기타 단어 수'를 보고
*/

#include <iostream>
#include <cctype>

int main() {
	using namespace std;

	int consonants = 0, vowels = 0, others = 0;
	int flag = 0;	// 0이면 단어 첫 글자, 1이면 첫 글자 아님
	int q_flag = 0;	// 1이면 q가 첫 글자이고 뒤에 글자 없음
	char ch;
	cout << "단어들을 입력하시오 (끝내려면 q):\n";
	while (cin.get(ch)) {
		if (flag == 0) {
			if (isalpha(ch)) {
				ch = tolower(ch);
				if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
					++vowels;
				else {
					++consonants;
					if (ch == 'q')
						q_flag = 1;
				}

				flag = 1;
			}

			else if (!isspace(ch)) {
				++others;
				flag = 1;
			}
		}
		else {
			if (isspace(ch)) {
				if (q_flag == 1) {
					--consonants;
					break;
				}
				flag = 0;
			}

			q_flag = 0;
		}
	}

	cout << "모음으로 시작하는 단어 수: " << vowels << endl;
	cout << "자음으로 시작하는 단어 수: " << consonants << endl;
	cout << "기타: " << others << endl;

	return 0;
}