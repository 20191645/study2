/*
	���� 3:
	�������� ���ø� �Լ� sum_values() ����
*/

#include <iostream>

// �Ű������� ���� �� - ȣ�� ����
long double sum_values() { return 0; }

template <typename T, typename... Args>
long double sum_values(const T& value, const Args&... args) {
	long double sum = value;
	sum += sum_values(args...);
	return sum;
}

int main() {
	int n = 300;
	double d = 3.5;
	char ch = 'A';
	long l = 20000;
	std::cout << "�հ�: " << sum_values(n,d,ch,l) << std::endl;
}