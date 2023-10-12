#ifndef PE10_6_H_
#define PE10_6_H_

class Move {
private:
	double x;
	double y;

public:
	Move(double a = 0, double b = 0);
	void showmove() const;
	Move add(const Move& m)const;
	void reset(double a = 0, double b = 0);
};

#endif