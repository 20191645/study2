/*
	���� 8:
	�ؽ�Ʈ ������ ���� ������ ������ ���� ������ �о� ���� ����
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
	
	cout << "�� ���ڵ��� ��: " << words << endl;

	return 0;
}