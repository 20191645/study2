/*
	���� 2:
	Ű���� �Է��� ����࿡�� ������ ���Ϸ� ����
*/

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
	using namespace std;

	ofstream fout("pe17-02.txt");
	if (fout.is_open()) {
		for (int i = 1; i < argc; i++) {
			fout << argv[i] << endl;
		}
	}
	fout.close();

	return 0;
}