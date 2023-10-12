/*
	���� 5:
	pe16-8�� ���� ������ �����ϵ� �̸� ����� ���� �ؽ�Ʈ ���Ϸκ��� �Է¹ް�
	�� ��� ���� �ؽ�Ʈ ���Ͽ� �����Ѵ�
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
	
	// mat.dat ���Ϸκ��� �̸� ����Ʈ �б�
	ifstream fin("mat.dat");
	if (!fin.is_open()) {
		cerr << "������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}
	vector<string> mat;
	while (fin >> name && name != "quit")
		mat.push_back(name);
	fin.close();

	cout << "Mat�� ģ���� �̸� ���:\n";
	sort(mat.begin(), mat.end());
	for_each(mat.begin(), mat.end(), show);
	cout << endl;

	// pat.dat ���Ϸκ��� �̸� ����Ʈ �б�
	fin.open("pat.dat");
	if (!fin.is_open()) {
		cerr << "������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}
	vector<string> pat;
	while (fin >> name && name != "quit")
		pat.push_back(name);
	fin.close();

	cout << "Pat�� ģ���� �̸� ���:\n";
	sort(pat.begin(), pat.end());
	for_each(pat.begin(), pat.end(), show);
	cout << endl;
	
	// ����Ʈ �պ� ��� matnpat.dat ���Ͽ� ����
	ofstream fout("matnpat.dat");
	vector<string> mat_pat(mat.size() + pat.size());
	merge(mat.begin(), mat.end(), pat.begin(), pat.end(), mat_pat.begin());
	vector<string>::iterator it = unique(mat_pat.begin(), mat_pat.end());
	mat_pat.erase(it, mat_pat.end());
	fout << "Mat�� Pat�� ģ���� �̸� ���:\n";
	for (auto it = mat_pat.begin(); it != mat_pat.end(); it++)
		fout << *it << ' ';
	fout << endl;

	fout.close();

	return 0;
}

void show(string& s) {
	cout << s << " ";
}