/*
	문제 4:
	이름 있는 람다, 익명 람다 표현식 사용
*/

#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main() {
	using std::list;
	using std::cout;
	using std::endl;

	int vals[10] = { 50,100,90,180,60,210,415,88,188,201 };
	list<int> yadayada(vals, vals + 10);
	list<int> etcetera(vals, vals + 10);

	// 이름 있는 람다
	auto outint = [](int n) {std::cout << n << " "; };

	cout << "원래의 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	// 익명 람다 표현식 사용
	yadayada.remove_if([](int x) {return x > 100; });
	etcetera.remove_if([](int x) {return x > 200; });

	cout << "정비된 리스트:\n";
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	return 0;
}