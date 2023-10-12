/*
	문제 9:
	list와 배열 정렬 시간 비교
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// a. 객체 생성 후 rand() 사용하여 초기값 제공
	srand(time(0));
	vector<int> vi0;
	int i;
	for (i = 0; i < 1000000; i++)
		vi0.push_back(rand());


	// b. vi, li 생성 후 vi0 값으로 초기화
	vector<int> vi(vi0);
	list<int> li(vi0.size());
	copy(vi0.begin(), vi0.end(), li.begin());

	// c. sort() 사용할 때 정렬되는 시간 측정
	clock_t start, finish;
	// vi 정렬에 걸리는 시간
	cout << "vector<int> 정렬에 걸리는 시간:";
	start = clock();
	sort(vi.begin(), vi.end());
	finish = clock();
	cout << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	// li 정렬에 걸리는 시간
	cout << "list<int> 정렬에 걸리는 시간: ";
	start = clock();
	// STL의 sort() 알고리즘을 통해서 list를 정렬하면 에러 뜸
	li.sort();
	finish = clock();
	cout << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	
	// d. vi0의 값으로 li 초기화, li를 vi에 복사, vi 정렬, 결과 다시 li로 복사
	cout << "list 복사, 정렬, 복사에 걸리는 시간: ";
	copy(vi0.begin(), vi0.end(), li.begin());
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	finish = clock();
	cout << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	return 0;
}

