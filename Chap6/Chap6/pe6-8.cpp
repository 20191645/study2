/*
	문제 8:
	텍스트 파일을 열고 파일의 끝까지 문자 단위로 읽어 수를 보고
*/

#include <iostream>
#include <fstream>
#include <cctype>

int main() {
	using namespace std;

	ifstream inFile;
	inFile.open("Practice8.txt");

	int words = 0;
	char ch;
	while (inFile.get(ch)) {
		++words;
	}
	inFile.close();
	
	cout << "총 문자들의 수: " << words << endl;

	return 0;
}