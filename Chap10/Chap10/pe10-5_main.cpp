/*
	문제 5:
	customer 구조체를 직접 선언한 Stack 클래스에 추가하고 삭제
*/

#include <iostream>
#include <cctype>
#include "pe10-5.h"

int main() {
	Stack st;
	Item arr[5] = {
		{"Hello World",35000},
		{"Marry",2000},
		{"Gold",10000},
		{"Bin",5000},
		{"Last",45000}
	};

	for (int i = 0; i < 5; i++) {
		if (!st.push(arr[i]))
			std::cout << "스택이 가득 차 있습니다.\n";
		else
			std::cout << "push 성공\n";
	}

	double total = 0.0;
	Item temp;
	for (int i = 0; i < 5; i++) {
		if (!st.pop(temp))
			std::cout << "스택이 비어 있습니다.\n";
		else
			std::cout << "pop 성공\n";
		total += temp.payment;
	}
	std::cout << "총 수입: " << total << std::endl;
	std::cout << "프로그램을 종료합니다.\n";

	return 0;
}