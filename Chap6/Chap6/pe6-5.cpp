/*
	���� 5:
	�ҵ��� �Է��ϸ� ���� �� �ҵ漼�� ����
*/

#include <iostream>
int main() {
	using namespace std;

	double tvap;
	double tax;
	cout << "����� �ҵ��� Ʈ���� ������ �Է��Ͻÿ�: ";
	while ((cin >> tvap) && tvap >= 0) {
		tax = 0;
		if (tvap > 5000 && tvap <= 15000) {
			tax += (tvap - 5000) * 0.1;
		}
		else if (tvap > 15000 && tvap <= 35000) {
			tax += 10000 * 0.1;
			tvap -= 15000;
			tax += tvap * 0.15;
		}
		else if (tvap > 35000) {
			tax += 10000 * 0.1;
			tax += 20000 * 0.15;
			tvap -= 35000;
			tax += tvap * 0.2;
		}
		cout << "����� �ҵ漼: " << tax << endl;
		cout << "����� �ҵ��� Ʈ���� ������ �Է��Ͻÿ�: ";
	}

	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}