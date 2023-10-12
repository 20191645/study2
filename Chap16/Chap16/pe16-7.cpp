/*
	문제 7:
	random_suffle()을 사용하여 Lotto() 함수 구현
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<int> Lotto(int range, int n);
void show(int n);

int main() {
	vector<int> winners;
	winners = Lotto(51, 6);
	cout << "복권 내용:\n";
	for_each(winners.begin(), winners.end(), show);
	cout << endl;

	winners = Lotto(100, 10);
	cout << "복권 내용:\n";
	for_each(winners.begin(), winners.end(), show);
	cout << endl;

	return 0;
}

vector<int> Lotto(int range, int n) {
	vector<int> lotto(range);
	for (int i = 1; i <= range; i++)
		lotto[i - 1] = i;
	random_shuffle(lotto.begin(), lotto.end());
	lotto.erase(lotto.begin() + n, lotto.end());
	sort(lotto.begin(), lotto.end());

	return lotto;
}

void show(int n) {
	cout << n << " ";
}