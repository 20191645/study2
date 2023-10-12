/*
	���� 8:
	- ��1 �����̳ʿ� ��2 �����̳ʿ� ���� �̸� ����� �Է��ϰ� ���ĵ� ������ ���
	- �� ����� �պ��� ��3 �����̳ʸ� ����� �ߺ��Ǵ� �̸� ���� �� ���
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

void show(const string& s);

int main() {
	vector<string> mat;
	cout << "Mat�� ģ���� �̸��� �Է��մϴ�(�������� quit):\n";
	string name;
	while (cin >> name && name != "quit")
		mat.push_back(name);
	cout << "Mat�� ģ���� �̸� ���:\n";
	for_each(mat.begin(), mat.end(), show);
	cout << endl;

	vector<string> pat;
	cout << "Pat�� ģ���� �̸��� �Է��մϴ�(�������� quit):\n";
	while (cin >> name && name != "quit")
		pat.push_back(name);
	cout << "Pat�� ģ���� �̸� ���:\n";
	for_each(pat.begin(), pat.end(), show);
	cout << endl;

	// mat_pat���� ����� �ʱ�ȭ������ ������ merge���� ���� �Ͼ
	vector<string> mat_pat(mat.size() + pat.size());
	sort(mat.begin(), mat.end());
	sort(pat.begin(), pat.end());
	merge(mat.begin(), mat.end(), pat.begin(), pat.end(), mat_pat.begin());
	vector<string>::iterator it = unique(mat_pat.begin(), mat_pat.end());
	mat_pat.erase(it, mat_pat.end());
	cout << "Mat�� Pat�� ģ���� �̸� ���:\n";
	for_each(mat_pat.begin(), mat_pat.end(), show);
	cout << endl;

	return 0;
}

void show(const string& s) {
	cout << s << " ";
}