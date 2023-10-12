/*
	���� 9:
	list�� �迭 ���� �ð� ��
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// a. ��ü ���� �� rand() ����Ͽ� �ʱⰪ ����
	srand(time(0));
	vector<int> vi0;
	int i;
	for (i = 0; i < 1000000; i++)
		vi0.push_back(rand());


	// b. vi, li ���� �� vi0 ������ �ʱ�ȭ
	vector<int> vi(vi0);
	list<int> li(vi0.size());
	copy(vi0.begin(), vi0.end(), li.begin());

	// c. sort() ����� �� ���ĵǴ� �ð� ����
	clock_t start, finish;
	// vi ���Ŀ� �ɸ��� �ð�
	cout << "vector<int> ���Ŀ� �ɸ��� �ð�:";
	start = clock();
	sort(vi.begin(), vi.end());
	finish = clock();
	cout << (double)(finish - start) / CLOCKS_PER_SEC << endl;
	// li ���Ŀ� �ɸ��� �ð�
	cout << "list<int> ���Ŀ� �ɸ��� �ð�: ";
	start = clock();
	// STL�� sort() �˰����� ���ؼ� list�� �����ϸ� ���� ��
	li.sort();
	finish = clock();
	cout << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	
	// d. vi0�� ������ li �ʱ�ȭ, li�� vi�� ����, vi ����, ��� �ٽ� li�� ����
	cout << "list ����, ����, ���翡 �ɸ��� �ð�: ";
	copy(vi0.begin(), vi0.end(), li.begin());
	start = clock();
	copy(li.begin(), li.end(), vi.begin());
	sort(vi.begin(), vi.end());
	copy(vi.begin(), vi.end(), li.begin());
	finish = clock();
	cout << (double)(finish - start) / CLOCKS_PER_SEC << endl;

	return 0;
}

