/*
	���� 7:
	q�� ���� �Էµ� ������ �� �ܾ �а�
	'���� ���� �ܾ� ��, ���� ���� �ܾ� ��, ��Ÿ �ܾ� ��'�� ����
*/

#include <iostream>
#include <cctype>

int main() {
	using namespace std;

	int consonants = 0, vowels = 0, others = 0;
	int flag = 0;	// 0�̸� �ܾ� ù ����, 1�̸� ù ���� �ƴ�
	int q_flag = 0;	// 1�̸� q�� ù �����̰� �ڿ� ���� ����
	char ch;
	cout << "�ܾ���� �Է��Ͻÿ� (�������� q):\n";
	while (cin.get(ch)) {
		if (flag == 0) {
			if (isalpha(ch)) {
				ch = tolower(ch);
				if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
					++vowels;
				else {
					++consonants;
					if (ch == 'q')
						q_flag = 1;
				}

				flag = 1;
			}

			else if (!isspace(ch)) {
				++others;
				flag = 1;
			}
		}
		else {
			if (isspace(ch)) {
				if (q_flag == 1) {
					--consonants;
					break;
				}
				flag = 0;
			}

			q_flag = 0;
		}
	}

	cout << "�������� �����ϴ� �ܾ� ��: " << vowels << endl;
	cout << "�������� �����ϴ� �ܾ� ��: " << consonants << endl;
	cout << "��Ÿ: " << others << endl;

	return 0;
}