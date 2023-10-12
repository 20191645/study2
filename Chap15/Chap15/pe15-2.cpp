/*
	���� 2:
	�� ���� ���������� logic_error Ŭ������ �Ļ� Ŭ������ �ǵ��� ����
*/

#include <iostream>
#include <cmath>
#include "pe15-2.h"

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main() {
	using std::cout;
	using std::endl;
	using std::cin;

	double x, y, z;
	cout << "�� ���� �Է��Ͻʽÿ�: ";
	while (cin >> x >> y) {
		try {
			z = hmean(x, y);
			cout << x << ", " << y << "�� ��ȭ����� "
				<< z << "�Դϴ�.\n";
			z = gmean(x, y);
			cout << x << ", " << y << "�� ��������� "
				<< z << "�Դϴ�.\n";
			cout << "�ٸ� �� ���� �Է��Ͻʽÿ�(�������� q): ";
		}
		catch (bad_hmean& bg) {
			cout << bg.what();
			continue;
		}
		catch (bad_gmean& hg) {
			cout << hg.what();
			cout << "Values user: " << hg.v1 << ", " << hg.v2 << endl;
			cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
			break;
		}
	}

	cout << "���α׷��� �����մϴ�.\n";
	return 0;
}

double hmean(double a, double b) throw(bad_hmean) {
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}
double gmean(double a, double b) throw(bad_gmean) {
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}