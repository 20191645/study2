/*
	문제 8:
	- 제1 컨테이너와 제2 컨테이너에 각각 이름 목록을 입력하고 정렬된 순서로 출력
	- 두 목록을 합병한 제3 컨테이너를 만들고 중복되는 이름 삭제 후 출력
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void show(const string& s);

int main() {
	vector<string> mat;
	cout << "Mat의 친구들 이름을 입력합니다(끝내려면 quit):\n";
	string name;
	while (cin >> name && name != "quit")
		mat.push_back(name);
	cout << "Mat의 친구들 이름 목록:\n";
	for_each(mat.begin(), mat.end(), show);
	cout << endl;

	vector<string> pat;
	cout << "Pat의 친구들 이름을 입력합니다(끝내려면 quit):\n";
	while (cin >> name && name != "quit")
		pat.push_back(name);
	cout << "Pat의 친구들 이름 목록:\n";
	for_each(pat.begin(), pat.end(), show);
	cout << endl;

	// mat_pat에서 사이즈를 초기화해주지 않으면 merge에서 에러 일어남
	vector<string> mat_pat(mat.size() + pat.size());
	sort(mat.begin(), mat.end());
	sort(pat.begin(), pat.end());
	merge(mat.begin(), mat.end(), pat.begin(), pat.end(), mat_pat.begin());
	vector<string>::iterator it = unique(mat_pat.begin(), mat_pat.end());
	mat_pat.erase(it, mat_pat.end());
	cout << "Mat와 Pat의 친구들 이름 목록:\n";
	for_each(mat_pat.begin(), mat_pat.end(), show);
	cout << endl;

	return 0;
}

void show(const string& s) {
	cout << s << " ";
}