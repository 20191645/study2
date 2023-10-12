/*
	문제 5:
	pe16-8과 같은 내용을 구현하되 이름 목록을 각각 텍스트 파일로부터 입력받고
	그 결과 역시 텍스트 파일에 저장한다
*/

#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void show(string& s);

int main() {
	string name;
	
	// mat.dat 파일로부터 이름 리스트 읽기
	ifstream fin("mat.dat");
	if (!fin.is_open()) {
		cerr << "파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}
	vector<string> mat;
	while (fin >> name && name != "quit")
		mat.push_back(name);
	fin.close();

	cout << "Mat의 친구들 이름 목록:\n";
	sort(mat.begin(), mat.end());
	for_each(mat.begin(), mat.end(), show);
	cout << endl;

	// pat.dat 파일로부터 이름 리스트 읽기
	fin.open("pat.dat");
	if (!fin.is_open()) {
		cerr << "파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}
	vector<string> pat;
	while (fin >> name && name != "quit")
		pat.push_back(name);
	fin.close();

	cout << "Pat의 친구들 이름 목록:\n";
	sort(pat.begin(), pat.end());
	for_each(pat.begin(), pat.end(), show);
	cout << endl;
	
	// 리스트 합병 결과 matnpat.dat 파일에 저장
	ofstream fout("matnpat.dat");
	vector<string> mat_pat(mat.size() + pat.size());
	merge(mat.begin(), mat.end(), pat.begin(), pat.end(), mat_pat.begin());
	vector<string>::iterator it = unique(mat_pat.begin(), mat_pat.end());
	mat_pat.erase(it, mat_pat.end());
	fout << "Mat와 Pat의 친구들 이름 목록:\n";
	for (auto it = mat_pat.begin(); it != mat_pat.end(); it++)
		fout << *it << ' ';
	fout << endl;

	fout.close();

	return 0;
}

void show(string& s) {
	cout << s << " ";
}