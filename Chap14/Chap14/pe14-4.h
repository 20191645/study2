#ifndef PE14_4_H_
#define PE14_4_H_

#include <string>

class Person {
private:
	std::string firstname;
	std::string lastname;

public:
	Person(const std::string& fn = "first", const std::string& ln = "last");
	virtual ~Person() {}

	virtual void Show();
	virtual void Set();
};

class Gunslinger :virtual public Person {
private:
	double time;
	int notch;

public:
	Gunslinger(const std::string& fn = "first", const std::string& ln = "last",
		double t = 0, int n = 0);
	Gunslinger(const Person& p, double t = 0, int n = 0);
	~Gunslinger() {}

	void Show();
	double Draw() const { return time; }
	int Notch() const { return notch; }
	void Set();
};

class PokerPlayer :virtual public Person {
private:
	double card;

public:
	PokerPlayer(const std::string& fn = "first", const std::string& ln = "last", double c = 0);
	PokerPlayer(const Person& p, double c = 0);
	~PokerPlayer() {}

	void Show();
	double Draw();
	void Set();
};

class BadDude :public Gunslinger, public PokerPlayer {
public:
	BadDude(const std::string& fn = "first", const std::string& ln = "last",
		double t = 0, int n = 0, double c = 0);
	BadDude(const Person& p, double t = 0, int n = 0, double c = 0);
	BadDude(const Gunslinger& g, double c = 0);
	BadDude(const PokerPlayer& pp, double t = 0, int n = 0);
	~BadDude() {}

	void Show();
	double Gdraw() const { return Gunslinger::Draw(); }
	double Cdraw() { return PokerPlayer::Draw(); }
	void Set();
};

#endif