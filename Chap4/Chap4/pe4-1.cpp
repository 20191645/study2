/*
	문제 1:
	정보를 읽어 화면에 다시 출력하는데 학점을 한 단계씩 하향 조정
*/

#include <iostream>

int main() {
	using namespace std;
	
	char firstName[20], lastName[20];
	char grade;
	int age;

	cout << "영문 퍼스트 네임(이름): ";
	cin.getline(firstName, 19);
	cout << "영문 라스트 네임(성): ";
	cin.getline(lastName, 19);
	cout << "학생이 원하는 학점: ";
	cin >> grade;
	grade += 1;
	cout << "나이: ";
	cin >> age;

	cout << "성명: " << lastName << ", " << firstName << endl;
	cout << "학점: " << grade << endl;
	cout << "나이: " << age << endl;

	return 0;
}