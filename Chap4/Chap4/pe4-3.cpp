/*
	문제 3:
	이름, 성을 입력받아 "성, 이름" 형식의 제3의 문자열을 구성하여 출력
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

int main() {
	using namespace std;

	char firstName[20], lastName[20], name[40];

	cout << "퍼스트 네임(이름)을 입력하시오: ";
	cin.getline(firstName, 19);
	cout << "라스트 네임(성)을 입력하시오: ";
	cin.getline(lastName, 19);
	strcpy(name, lastName);
	strcat(name, ", ");
	strcat(name, firstName);
	cout << "하나의 문자열로 만들면: " << name << endl;

	return 0;
}