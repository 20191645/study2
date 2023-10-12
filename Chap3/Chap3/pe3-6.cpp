/*
	문제 6:
	주행한 거리를 마일, 휘발유 양을 갤런으로 입력받고 갤런당 마일 수를 보고
*/

#include <iostream>

int main() {
	using namespace std;

	int mile, gallon;
	cout << "주행한 거리를 마일 단위로 입력하시오: ";
	cin >> mile;
	cout << "소비한 휘발유의 양을 갤런 단위로 입력하시오: ";
	cin >> gallon;

	cout << "갤런당 마일 수: " << (double)mile / gallon << endl;
	
	return 0;
}