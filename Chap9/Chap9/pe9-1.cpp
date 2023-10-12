#include <iostream>
#include "pe9-1.h"

int main() {
	using namespace std;

	golf arr[3];
	int i;
	for (i = 0; i < 3; i++) {
		if (!setgolf(arr[i]))
			break;
	}
	for (int j = 0; j < i; j++)
		showgolf(arr[j]);

	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	handicap(ann, 20);
	showgolf(ann);

	return 0;
}