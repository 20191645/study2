#ifndef PE10_3_H_
#define PE10_3_H_

class Golf {
private:
	static const int Len = 40;
	char fullname[Len];
	int handicap;

public:
	Golf(const char* name = "", int hc = 0);
	int setgolf();
	void update(int hc);
	void showgolf() const;
};


#endif