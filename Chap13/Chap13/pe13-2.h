#ifndef PE13_2_H_
#define PE13_2_H_

class Cd {
private:
	char* performers;
	char* label;
	int selections;	// ���� ��� ��
	double playtime;	// �� ������ ���� �ð�

public:
	Cd(const char* s1, const char* s2, int n, double x);
	Cd(const Cd& d);
	Cd();
	virtual ~Cd();

	void Report() const;	// CD�� ��� ������ ����
	Cd& operator=(const Cd& d);
};

class Classic :public Cd {
private:
	char* song;

public:
	Classic(const char* s, const char* s1, const char* s2, int n, double x);
	Classic(const Classic& c);
	Classic();
	~Classic();

	void Report() const;
	Classic& operator=(const Classic& c);
};

#endif