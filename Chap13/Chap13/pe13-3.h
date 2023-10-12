#ifndef PE13_3_H_
#define PE13_3_H_

#include <iostream>

// 세 클래스의 추상화 기초 클래스
class DMA {
private:
	char* label;
	int rating;

public:
	DMA(const char* l = "null", int r = 0);
	DMA(const DMA& rd);

	virtual ~DMA();
	DMA& operator=(const DMA& rd);
	friend std::ostream& operator<<(std::ostream& os, const DMA& rd);
	virtual void View() const = 0;
};


class baseDMA : public DMA {
public:
	baseDMA(const char* l = "null", int r = 0);
	baseDMA(const baseDMA& rs);

	~baseDMA();
	baseDMA& operator=(const baseDMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
	void View() const;
};

// DMA를 사용하지 않는 파생 클래스
// -> 파괴자, 복사 생성자, 대입 연산자 (암시적)
class lacksDMA : public DMA {
private:
	enum { COL_LEN = 40 };
	char color[COL_LEN];

public:
	lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
	lacksDMA(const char* c, const DMA& rs);
	friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
	void View() const;
};

// DMA를 사용하는 파생 클래스
class hasDMA :public DMA {
private:
	char* style;

public:
	hasDMA(const char* s = "none", const char* l = "null", int r = 0);
	hasDMA(const char* s, const DMA& rs);
	hasDMA(const hasDMA& hs);

	~hasDMA();
	hasDMA& operator=(const hasDMA& hs);
	friend std::ostream& operator<<(std::ostream& os, const hasDMA& hs);
	void View() const;
};

#endif