/*
	���� 6:
	pe5-5.cpp�� �����Ͽ� 3�� ���� ���� �Ǹŷ��� 2���� �迭�� ����
*/

#include <iostream>

int main() {
	using namespace std;

	string months[12] =
	{ "January","February","March","April",
		"May","June","July","August",
		"September","October","November","December" };
	int sales[3][12];
	int sum[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		cout << (i + 1) << "��° �Ǹŷ�: " << endl;
		for (int j = 0; j < 12; j++) {
			cout << months[j] << ": ";
			cin >> sales[i][j];
			sum[i] += sales[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++)
		cout << (i + 1) << "��° ���� �Ǹŷ�: " << sum[i] << endl;
	
	cout << endl;
	cout << "2��° ���� �Ǹŷ�: " << sum[0] + sum[1] << endl;
	cout << "3��° ���� �Ǹŷ�: " << sum[0] + sum[1] + sum[2] << endl;

	return 0;
}