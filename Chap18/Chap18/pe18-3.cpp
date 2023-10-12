/*
	문제 3:
	가변인자 템플릿 함수 sum_values() 구현
*/

#include <iostream>

// 매개변수가 없을 때 - 호출 종료
long double sum_values() { return 0; }

template <typename T, typename... Args>
long double sum_values(const T& value, const Args&... args) {
	long double sum = value;
	sum += sum_values(args...);
	return sum;
}

int main() {
	int n = 300;
	double d = 3.5;
	char ch = 'A';
	long l = 20000;
	std::cout << "합계: " << sum_values(n,d,ch,l) << std::endl;
}