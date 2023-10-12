#ifndef PE14_2_H_
#define PE14_2_H_

#include <iostream>
#include <string>
#include <valarray>

template <typename T1, typename T2>
class Pair {
private:
	T1 year;
	T2 bottle;

public:
	Pair() {}
	Pair(T1& t1, T2& t2) :year(t1), bottle(t2) {}
	~Pair() {}
	T1& Year() { return year; }
	T2& Bottle() { return bottle; }
};

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private PairArray {
private:
	std::string label;
	int years;

public:
	Wine() :PairArray(), label("no label"), years(0) {}
	Wine(const char* l, int y, const int yr[], const int bot[]);
	Wine(const char* l, int y);

	void GetBottles();
	std::string& Label();
	int sum();
	void Show();
};

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	:PairArray(), label(l), years(y)
{
	ArrayInt year(y);
	ArrayInt bottle(y);
	for (int i = 0; i < y; i++) {
		year[i] = yr[i];
		bottle[i] = bot[i];
	}
	PairArray::Year() = year;
	PairArray::Bottle() = bottle;
}
Wine::Wine(const char* l, int y)
	:PairArray(), label(l), years(y)
{
	ArrayInt year(y);
	ArrayInt bottle(y);
	PairArray::Year() = year;
	PairArray::Bottle() = bottle;
}

void Wine::GetBottles() {
	using namespace std;

	cout << years << "�� ���� " << label << " �����͸� �Է��Ͻÿ�:\n";
	for (int i = 0; i < years; i++) {
		cout << "�⵵�� �Է��Ͻÿ�: ";
		cin >> PairArray::Year()[i];
		cout << "������ �Է��Ͻÿ�: ";
		cin >> PairArray::Bottle()[i];
	}
}
std::string& Wine::Label() {
	return label;
}
int Wine::sum() {
	return PairArray::Bottle().sum();
}
void Wine::Show() {
	using namespace std;

	cout << "����: " << label << endl;
	cout << "\t�⵵ \t����\n";
	for (int i = 0; i < years; i++) {
		cout << "\t" << PairArray::Year()[i]
			<< " \t" << PairArray::Bottle()[i] << endl;
	}
}

#endif