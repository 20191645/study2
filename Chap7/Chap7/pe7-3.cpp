/*
	문제 3:
	- box 구조체를 값으로 전달받아 출력
	- box 구조체 주소를 전달받아 volume 설정
*/

#include <iostream>
using namespace std;

struct box {
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void print(box);
void set(box*);

int main() {
	box box1 = { "maker",1.0,2.0,3.0,4.0 };
	print(box1);
	set(&box1);
	print(box1);

	return 0;
}

void print(box box1) {
	cout << "maker: " << box1.maker << endl;
	cout << "height: " << box1.height << endl;
	cout << "width: " << box1.width << endl;
	cout << "length: " << box1.length << endl;
	cout << "volume: " << box1.volume << endl;
	cout << endl;
}

void set(box* box1) {
	box box2 = *box1;
	box1->height = box2.width * box2.length * box2.volume;
	box1->width = box2.height * box2.length * box2.volume;
	box1->length = box2.height * box2.width * box2.volume;
	box1->volume = box2.height * box2.width * box2.length;
}