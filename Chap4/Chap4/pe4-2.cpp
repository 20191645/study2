/*
	문제 2:
	char형 배열 대신 string 클래스 이용
*/

#include <iostream>
#include <string>

int main() {
	using namespace std;

	cout << "지금 사시는 아파트에 언제 입주하셨습니까?\n";
	int year;
	cin >> year;

	cout << "사시는 도시를 말씀해 주시겠습니까?\n";
	string address;
	cin.get();
	getline(cin, address);

	cout << "아파트 입주 연도: " << year << endl;
	cout << "도시: " << address << endl;
	cout << "등록이 완료되었습니다!\n";

	return 0;
}