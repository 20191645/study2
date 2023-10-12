/*
	문제 10:
	달리기 결과를 3번 입력하고 횟수와 평균을 출력[array 객체 사용]
*/

#include <iostream>
#include <array>

int main() {
	using namespace std;

	array<double, 3> arr;
	cout << "첫 번째 달리기 결과: ";
	cin >> arr[0];
	cout << "두 번째 달리기 결과: ";
	cin >> arr[1];
	cout << "세 번째 달리기 결과: ";
	cin >> arr[2];

	double avg = (arr[0] + arr[1] + arr[2]) / 3;
	cout << "달리기 횟수: " << arr.size() << endl;
	cout << "달리기 평균: " << avg << endl;

	return 0;
}