/*
	문제 3:
	파일로부터 단어를 얻어 행맨 게임을 구현
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	srand(time(0));

	// 파일에서 단어 목록 얻어오기
	ifstream input;
	input.open("words.txt");

	// 단어 목록 저장할 vector<string>
	vector<string> worldlist;
	string temp;
	while (input >> temp) {
		worldlist.push_back(temp);
	}
	int NUM = worldlist.size();

	char play;
	cout << "영어 단어 게임을 하시겠습니까? <y/n> ";
	cin >> play;
	play = tolower(play);

	while (play == 'y') {
		string target = worldlist[rand() % NUM];
		int length = target.size();
		string attempt(length, '-');
		string badchars;	// 추측 틀린 문자들
		int guesses = 6;	// 기회

		cout << "수수께끼 단어를 추측해 보십시오.\n"
			<< length << "개의 문자로 이루어져 있습니다.\n"
			<< "한 번에 한 문자씩 추측하십시오.\n"
			<< "틀릴 수 있는 기회: " << guesses << "번\n";
		cout << "추측하는 단어: " << attempt << endl;

		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "문자를 추측하십시오: ";
			cin >> letter;

			// find() -> 매개변수 문자열이 발견되지 않으면 string::npos 리턴
			if (badchars.find(letter) != string::npos ||
				attempt.find(letter) != string::npos) {
				cout << "이미 추측한 문자입니다. 다시 하십시오.\n";
				continue;
			}

			// 추측 문자의 인덱스
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "땡! 틀렸습니다.\n";
				--guesses;
				// 틀린 추측 문자 추가
				badchars += letter;
			}
			else {
				cout << "딩동댕! 맞았습니다.\n";
				attempt[loc] = letter;

				// 동일한 문자가 다른 위치에 있는지 찾기
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}

			cout << "추측하는 단어: " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0)
					cout << "틀리게 추측한 문자들: " << badchars << endl;

				cout << "틀릴 수 있는 기회: " << guesses << "번\n";
			}
		}

		// 기회 다쓰거나 성공함
		if (guesses > 0)
			cout << "그렇습니다. 그것이 수수께끼 단어입니다.\n";
		else
			cout << "안타깝습니다. 수수께끼 단어는 " << target << "입니다.\n";

		cout << "게임을 다시 하시겠습니까? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "프로그램을 종료합니다.\n";
	return 0;
}