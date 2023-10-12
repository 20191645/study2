#ifndef PE10_7_H
#define PE10_7_H

class Plorg {
private:
	char name[19];
	int ci;

public:
	Plorg();
	Plorg(const char* nm);
	void setCi(int n);
	void show() const;
};

#endif