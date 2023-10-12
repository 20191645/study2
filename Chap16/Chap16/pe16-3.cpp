/*
	���� 3:
	���Ϸκ��� �ܾ ��� ��� ������ ����
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

	// ���Ͽ��� �ܾ� ��� ������
	ifstream input;
	input.open("words.txt");

	// �ܾ� ��� ������ vector<string>
	vector<string> worldlist;
	string temp;
	while (input >> temp) {
		worldlist.push_back(temp);
	}
	int NUM = worldlist.size();

	char play;
	cout << "���� �ܾ� ������ �Ͻðڽ��ϱ�? <y/n> ";
	cin >> play;
	play = tolower(play);

	while (play == 'y') {
		string target = worldlist[rand() % NUM];
		int length = target.size();
		string attempt(length, '-');
		string badchars;	// ���� Ʋ�� ���ڵ�
		int guesses = 6;	// ��ȸ

		cout << "�������� �ܾ ������ ���ʽÿ�.\n"
			<< length << "���� ���ڷ� �̷���� �ֽ��ϴ�.\n"
			<< "�� ���� �� ���ھ� �����Ͻʽÿ�.\n"
			<< "Ʋ�� �� �ִ� ��ȸ: " << guesses << "��\n";
		cout << "�����ϴ� �ܾ�: " << attempt << endl;

		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "���ڸ� �����Ͻʽÿ�: ";
			cin >> letter;

			// find() -> �Ű����� ���ڿ��� �߰ߵ��� ������ string::npos ����
			if (badchars.find(letter) != string::npos ||
				attempt.find(letter) != string::npos) {
				cout << "�̹� ������ �����Դϴ�. �ٽ� �Ͻʽÿ�.\n";
				continue;
			}

			// ���� ������ �ε���
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "��! Ʋ�Ƚ��ϴ�.\n";
				--guesses;
				// Ʋ�� ���� ���� �߰�
				badchars += letter;
			}
			else {
				cout << "������! �¾ҽ��ϴ�.\n";
				attempt[loc] = letter;

				// ������ ���ڰ� �ٸ� ��ġ�� �ִ��� ã��
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}

			cout << "�����ϴ� �ܾ�: " << attempt << endl;
			if (attempt != target) {
				if (badchars.length() > 0)
					cout << "Ʋ���� ������ ���ڵ�: " << badchars << endl;

				cout << "Ʋ�� �� �ִ� ��ȸ: " << guesses << "��\n";
			}
		}

		// ��ȸ �پ��ų� ������
		if (guesses > 0)
			cout << "�׷����ϴ�. �װ��� �������� �ܾ��Դϴ�.\n";
		else
			cout << "��Ÿ�����ϴ�. �������� �ܾ�� " << target << "�Դϴ�.\n";

		cout << "������ �ٽ� �Ͻðڽ��ϱ�? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}