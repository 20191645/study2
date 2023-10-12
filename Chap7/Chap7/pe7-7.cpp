/*
	���� 7:
	������ ��Ÿ���� 2���� ������ �Ű������� ����ϴ� �迭 ó�� �Լ� ����
*/

#include <iostream>
using namespace std;

const int ArSize = 5;
double* fill_array(double* start, double* end);
void show_array(const double ar[], double* end);
void revalue(double ar[], double r, double* end);

int main() {
	double ar[ArSize];
	double* end = fill_array(ar, ar+ArSize);
	show_array(ar, end);

	if (end - ar > 0) {
		double r;
		cout << "�������� �Է����ֽʽÿ�: ";
		while (!(cin >> r) || r < 0) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "�ٽ� �Է����ֽʽÿ�: ";
		}
		revalue(ar, r, end);
		show_array(ar, end);
	}
	cout << "���α׷��� �����մϴ�.\n";

	return 0;
}

double* fill_array(double* start, double* end) {
	int i = 1;
	double temp;
	double* ptr;
	
	for (ptr = start; ptr != end; ptr++) {
		cout << i << "�� �ε����� ����: $";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "�Է� �ҷ�; �Է� ������ �����ڽ��ϴ�.\n";
			break;
		}
		else if (temp < 0) {
			cout << "�Է°��� �����Դϴ�; �Է� ������ �����ڽ��ϴ�.\n";
			break;
		}
		else {
			*ptr = temp;
			++i;
		}
	}

	return ptr;
}

void show_array(const double ar[], double* end) {
	int i = 1;
	for (const double* ptr = ar; ptr != end; ptr++) {
		cout << i << "�� �ε���: $" << *ptr << endl;
	}
}

void revalue(double ar[], double r, double* end) {
	for (double* ptr = ar; ptr != end; ptr++)
		*ptr *= r;
}