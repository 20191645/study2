/*
	���� 3:
	��ġ ���� new�� ����Ͽ� chaff ����ü �迭�� ���ۿ� �ֱ�
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <new>

struct chaff {
	char dross[20];
	int slag;
};

int main() {
	char buffer[512];
	chaff* arr = new(buffer)chaff[2];
	strcpy(arr[0].dross, "hello, world!");
	arr[0].slag = 10;
	strcpy(arr[1].dross, "1234567890");
	arr[1].slag = 2;

	for (int i = 0; i < 2; i++) {
		std::cout << "dross: " << arr[i].dross << std::endl;
		std::cout << "slag: " << arr[i].slag << std::endl;
	}

	return 0;
}