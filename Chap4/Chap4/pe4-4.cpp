/*
	문제 4:
	pe4-3.cpp와 같은 내용을 string 객체를 이용하여 구현
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	string firstName, lastName, name;

	cout << "퍼스트 네임(이름)을 입력하시오: ";
	getline(cin, firstName);
	cout << "라스트 네임(성)을 입력하시오: ";
	getline(cin, lastName);
	name = lastName;
	name += ", ";
	name += firstName;
	cout << "하나의 문자열로 만들면: " << name << endl;

	return 0;
}