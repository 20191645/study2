#ifndef PE13_1_H_
#define PE13_1_H_

class Cd {
private:
	char performers[50];
	char label[20];
	int selections;	// 수록 곡목 수
	double playtime;	// 분 단위의 연주 시간

public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	~Cd();

	void Report() const;	// CD의 모든 데이터 보고
	Cd& operator=(const Cd& d);
};

class Classic :public Cd {
private:
	char song[50];

public:
	Classic(const char* s, const char* s1, const char* s2, int n, double x);
	Classic(const Classic& c);
	Classic();
	~Classic();

	void Report() const;
	Classic& operator=(const Classic& c);
};

#endif