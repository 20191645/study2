/*
	���� 3:
	�ϳ��� ������ �ٸ� ���Ϸ� �����ϸ� ����࿡�� ���� �̸� ��������
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	using namespace std;

	const char* filename = argv[1];
	ifstream fin(filename);
	if (!fin.is_open()) {
		cerr << filename << "�� �ش��ϴ� ������ �� �� �����ϴ�.";
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

	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}