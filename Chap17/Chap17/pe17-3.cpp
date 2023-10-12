/*
	문제 3:
	하나의 파일을 다른 파일로 복사하며 명령행에서 파일 이름 가져오기
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	using namespace std;

	const char* filename = argv[1];
	ifstream fin(filename);
	if (!fin.is_open()) {
		cerr << filename << "에 해당하는 파일을 열 수 없습니다.";
		exit(EXIT_FAILURE);
	}

	ofstream fout("pe17-03.txt");
	if (fout.is_open()) {
		char ch;
		while (fin.get(ch)) {
			fout << ch;
		}
	}

	fin.close();
	fout.close();

	cout << "프로그램을 종료합니다.\n";
	return 0;
}