/*
	문제 1:
	@ 기호가 나타날때까지 입력받아 대문자와 소문자를 서로 변환하여 에코
*/

#include <iostream>
#include <cctype>

int main() {
	using namespace std;

	cout << "@ 기호로 끝나는 입력:\n";
	char ch;
	while (cin.get(ch) && ch != '@') {
		if (isdigit(ch))
			continue;

		if (isupper(ch))
			cout << (char)tolower(ch);
		else if (islower(ch))
			cout << (char)toupper(ch);
		else
			cout << ch;
	}

	cout << endl << "입력이 종료되었습니다.\n";

	return 0;
}
