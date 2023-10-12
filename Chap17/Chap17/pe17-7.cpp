/*
	문제 7:
	키보드 입력을 string 객체의 벡터로 읽어들여 파일에 저장하고,
	파일 내용을 다시 string 객체의 벡터로 복사
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
		// 매개변수로 받은 ofstream 객체를 제대로 참조하려면
		// private 멤버변수를 ofstream& 형으로 선언해야한다
		// ofstream 형으로 선언하면 작동X
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

	// 문자열을 읽는다
	cout << "문자열들을 입력하십시오(끝내려면 빈 줄 입력):\n";
	while (getline(cin, temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "다음과 같이 입력하셨습니다.\n";
	for_each(vostr.begin(), vostr.end(), ShowStr);

	// 파일에 저장한다
	ofstream fout("pe17-07.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Store(fout));
	fout.close();

	// 파일 내용을 복원한다
	vector<string> vistr;
	ifstream fin("pe17-07.dat", ios_base::in || ios_base::binary);
	if (!fin.is_open()) {
		cerr << "입력을 위한 파일을 열 수 없습니다.\n";
		exit(EXIT_FAILURE);
	}
	GetStrs(fin, vistr);
	cout << "\n파일로부터 읽은 문자열들은 다음과 같습니다:\n";
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