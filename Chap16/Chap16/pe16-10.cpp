/*
	문제 10:
	a; Review 구조체에 price 멤버 추가
	b; Review 객체의 vector 대신 shared_ptr<Review> 객체의 vector 사용
	c; 루프 내에서 입력 단계 후 선택 사항을 사용자에게 입력받기
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Review {
	std::string title;
	int rating;
	
	// a. price 멤버 추가
	double price;
};

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseRating(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool FillReview(Review& rr);
void ShowReview(const shared_ptr<Review>& rr);

bool worsePrice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);

int main() {

	// b. Review 대신 shared_ptr<Review> 객체의 vector 사용
	//vector<Review> books;
	vector<shared_ptr<Review>> books;
	Review temp;
	while (FillReview(temp)) {
		//books.push_back(temp);
		books.push_back( shared_ptr<Review>( new Review(temp) ) );
	}

	if (books.size() > 0) {
		cout << "감사합니다. 당신은 다음과 같이 "
			<< books.size() << "개의 책 등급을 입력하셨습니다.\n"
			<< "등급\t제목\t가격\n";
		for_each(books.begin(), books.end(), ShowReview);
		
		
		// c. 책 표시 방식 입력
		int how;
		cout << "책을 표시하는 방식을 선택해 주십시오:\n";
		cout << "1. 원래 순서\t\t 2. 알파벳 순서\n"
			<< "3. 증가율 순서\t\t 4. 감소율 순서\n"
			<< "5. 가격 증가 순서\t 6. 가격 감소 순서\n"
			<< "7. 작업 끝내기\n";
		cin >> how;


		switch (how) {
		case 1:
			cout << "원래 순서로 정렬:\n등급\t제목\t가격\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;
		
		case 2:
			sort(books.begin(), books.end());
			cout << "알파벳 순서로 정렬:\n등급\t제목\t가격\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;

		case 3:
			sort(books.begin(), books.end(), worseRating);
			cout << "증가율 순서로 정렬:\n등급\t제목\t가격\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;

		case 4:
			sort(books.begin(), books.end(), worseRating);
			cout << "감소율 순서로 정렬:\n등급\t제목\t가격\n";
			for_each(books.rbegin(), books.rend(), ShowReview);
			break;

		case 5:
			sort(books.begin(), books.end(), worsePrice);
			cout << "가격 증가 순서로 정렬:\n등급\t제목\t가격\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;

		case 6:
			sort(books.begin(), books.end(), worsePrice);
			cout << "가격 감소 순서로 정렬:\n등급\t제목\t가격\n";
			for_each(books.rbegin(), books.rend(), ShowReview);
			break;

		case 7:
			cout << "작업을 끝냅니다.\n";
			break;
		}

	}
	else
		cout << "프로그램을 종료합니다.\n";

	return 0;
}

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
	if (r1->title < r2->title)
		return true;
	else if (r1->title == r2->title && r1->rating < r2->rating)
		return true;
	else if (r1->rating == r2->rating && r1->price < r2->price)
		return true;
	else
		return false;
}
bool worseRating(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
	if (r1->rating < r2->rating)
		return true;
	else
		return false;
}

bool FillReview(Review& rr) {
	std::cout << "책 제목을 입력하십시오(끝내려면 quit를 입력): ";
	getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;

	std::cout << "책 등급(0-10)을 입력하십시오: ";
	std::cin >> rr.rating;

	std::cout << "책 가격을 입력하십시오: ";
	std::cin >> rr.price;

	// 적절하지 못한 입력 시
	if (!std::cin)
		return false;

	// 남은 입력줄을 제거
	while (std::cin.get() != '\n')
		continue;

	return true;
}
void ShowReview(const shared_ptr<Review>& rr) {
	std::cout << rr->rating << '\t' << rr->title
		<< "\t" << rr->price << std::endl;
}


bool worsePrice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2) {
	if (r1->price < r2->price)
		return true;
	else
		return false;
}