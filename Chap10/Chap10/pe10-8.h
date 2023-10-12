#ifndef PE10_8_H
#define PE10_8_H

typedef int Item;

class List {
private:
	static const int MAX = 3;
	Item items[MAX];
	int end;

public:
	List();
	bool isempty() const;
	bool isfull() const;
	bool add(Item& item);
	void show() const;
	void update(const Item& item, int n);
};

#endif