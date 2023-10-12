/*
	���� 4:
	- �Է��� ���� 2���� �ؽ�Ʈ ����, ����� ���� 1���� �ؽ�Ʈ ������ ����
	- �Է��� �ؽ�Ʈ ������ ���� �����ϴ� �ೢ�� �����ϰ� �и��ڷ� ��ĭ�� ����Ѵ�
	- �� ����� ��� ���Ͽ� ��ϵȴ�
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
	using namespace std;

	ifstream fin1("input1.txt");
	ifstream fin2("input2.txt");
	if (!fin1.is_open() || !fin2.is_open()) {
		cerr << "������ ���� �� �����Ͽ����ϴ�.\n";
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

	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}