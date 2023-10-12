/*
	���� 7:
	Ű���� �Է��� string ��ü�� ���ͷ� �о�鿩 ���Ͽ� �����ϰ�,
	���� ������ �ٽ� string ��ü�� ���ͷ� ����
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;

void ShowStr(const string& s);
void GetStrs(ifstream& fin, vector<string>& vistr);

class Store {
private:
	ofstream& os;
public:
	Store(ofstream& f) :os(f) {
		// �Ű������� ���� ofstream ��ü�� ����� �����Ϸ���
		// private ��������� ofstream& ������ �����ؾ��Ѵ�
		// ofstream ������ �����ϸ� �۵�X
	}
	void operator()(const string& s) {
		size_t len = s.size();
		os.write((char*)&len, sizeof size_t);
		os.write(s.data(), len);
	}
};

int main() {
	vector<string> vostr;
	string temp;

	// ���ڿ��� �д´�
	cout << "���ڿ����� �Է��Ͻʽÿ�(�������� �� �� �Է�):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "������ ���� �Է��ϼ̽��ϴ�.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	// ���Ͽ� �����Ѵ�
	ofstream fout("pe17-07.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	// ���� ������ �����Ѵ�
	vector<string> vistr;
	ifstream fin("pe17-07.dat", ios_base::in || ios_base::binary);
	if (!fin.is_open()) {
		cerr << "�Է��� ���� ������ �� �� �����ϴ�.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\n���Ϸκ��� ���� ���ڿ����� ������ �����ϴ�:\n";
	for_each(vistr.begin(), vistr.end(), ShowStr);

	return 0;
}

void ShowStr(const string& s) {
	cout << s << endl;
}

void GetStrs(ifstream& fin, vector<string>& vistr) {
	size_t len;
	char* temp = 0;

	while (fin.read((char*)&len, sizeof(std::size_t))) {
		temp = new char[len+1];
		fin.read(&temp[0], len);
		temp[len] = '\0';
		vistr.push_back(temp);
	}

	delete[] temp;
}