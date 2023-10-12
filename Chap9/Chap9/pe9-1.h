// pe9-1.h -- pe9-1.cpp, pe9-1_main.cpp를 위한 헤더 파일
#ifndef PE9_1_H_
#define PE9_1_H_

const int Len = 40;
struct golf {
	char fullname[Len];
	int handicap;
};

void setgolf(golf& g, const char* name, int hc);
int setgolf(golf& g);
void handicap(golf& g, int hc);
void showgolf(const golf& g);


#endif