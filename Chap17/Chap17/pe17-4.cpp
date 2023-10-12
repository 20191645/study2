/*
	문제 4:
	- 입력을 위한 2개의 텍스트 파일, 출력을 위한 1개의 텍스트 파일을 연다
	- 입력의 텍스트 파일은 서로 대응하는 행끼리 연결하고 분리자로 빈칸을 사용한다
	- 그 결과가 출력 파일에 기록된다
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
	using namespace std;

	ifstream fin1("input1.txt");
	ifstream fin2("input2.txt");
	if (!fin1.is_open() || !fin2.is_open()) {
		cerr << "파일을 여는 데 실패하였습니다.\n";
		exit(EXIT_FAILURE);
	}

	ofstream fout("pe17-04.txt");
	if (fout.is_open()) {
		char ch;
		while (!fin1.eof() || !fin2.eof()) {
			while (fin1.get(ch) && ch != '\n')
				fout << ch;
			fout << ' ';

			while (fin2.get(ch) && ch != '\n')
				fout << ch;
			fout << endl;
		}
	}

	fin1.close();
	fin2.close();
	fout.close();

	cout << "프로그램을 종료합니다.\n";
	return 0;
}