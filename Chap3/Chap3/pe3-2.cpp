/*
	문제 2:
	키를 피트, 인치 단위로 묻고 체중을 파운드 단위로 묻는다
	이를 토대로 BMI를 계산하여 출력
*/

#include <iostream>
#include <cmath>

int main() {
	using namespace std;

	int feet, inch, pound;
	cout << "키를 피트와 인치 단위로 입력하십시오: ";
	cin >> feet >> inch;
	cout << "체중을 파운드 단위로 입력하십시오: ";
	cin >> pound;

	const int INCH = 12;
	const double HEIGHT = 0.0254;
	const double WEIGHT = 2.2;

	double height = (feet * INCH + inch) * HEIGHT;
	double weight = pound / WEIGHT;
	double bmi = weight / pow(height, 2);
	cout << "당신의 BMI: " << bmi << endl;

	return 0;
}