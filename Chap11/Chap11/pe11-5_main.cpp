/*
	���� 5:
	- ����, ���� �Ŀ��, �ε��Ҽ��� �Ŀ�� ���� �� �ؼ� �����ϴ� ���� ��� �߰�
	- <<, +, -, * ������ �����ε�
*/

#include <iostream>
using std::cout;
using std::endl;
#include "pe11-5.h"

int main() {
	Stonewt pavarotti = 275;
	Stonewt wolfe(285.7);
	Stonewt taft(21, 8);
	Stonewt bird(12, 9);

	cout << "�׳� ������ ������: " << pavarotti;
	cout << "Ž���� ������: " << wolfe;
	cout << "������� ������: " << taft;
	cout << "���� ������: " << bird;
	cout << endl;

	cout << "taft + wolfe = " << taft + wolfe;
	cout << "wolfe + taft = " << wolfe + taft;
	cout << "wolfe - pavarotti = " << wolfe - pavarotti;
	cout << "taft - bird = " << taft - bird;
	cout << "taft * 1.2 = " << taft * 1.2;
	cout << "1.2 * taft = " << 1.2 * taft;

	return 0;
}