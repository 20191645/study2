/*
	���� 1:
	���ڿ� �ּҸ� �Ű������� ����ϴ� �Լ�
*/

#include <iostream>
using namespace std;

int CALL = 0;

void print(const char* str, int n = 0);

int main() {
	print("Hello");
	print("Hi, Good");
	print("I'm your father", 5);
	print("Umm.....");
	print("World", 1);

	return 0;
}

void print(const char* str, int n) {
	if (n != 0) {
		for (int i = 0; i < CALL; i++)
			cout << str << endl;
	}
	else {
		cout << str << endl;
	}
	CALL++;
}