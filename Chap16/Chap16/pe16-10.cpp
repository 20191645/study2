/*
	���� 10:
	a; Review ����ü�� price ��� �߰�
	b; Review ��ü�� vector ��� shared_ptr<Review> ��ü�� vector ���
	c; ���� ������ �Է� �ܰ� �� ���� ������ ����ڿ��� �Է¹ޱ�
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Review {
	std::string title;
	int rating;
	
	// a. price ��� �߰�
	double price;
};

bool operator<(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool worseRating(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);
bool FillReview(Review& rr);
void ShowReview(const shared_ptr<Review>& rr);

bool worsePrice(const shared_ptr<Review>& r1, const shared_ptr<Review>& r2);

int main() {

	// b. Review ��� shared_ptr<Review> ��ü�� vector ���
	//vector<Review> books;
	vector<shared_ptr<Review>> books;
	Review temp;
	while (FillReview(temp)) {
		//books.push_back(temp);
		books.push_back( shared_ptr<Review>( new Review(temp) ) );
	}

	if (books.size() > 0) {
		cout << "�����մϴ�. ����� ������ ���� "
			<< books.size() << "���� å ����� �Է��ϼ̽��ϴ�.\n"
			<< "���\t����\t����\n";
		for_each(books.begin(), books.end(), ShowReview);
		
		
		// c. å ǥ�� ��� �Է�
		int how;
		cout << "å�� ǥ���ϴ� ����� ������ �ֽʽÿ�:\n";
		cout << "1. ���� ����\t\t 2. ���ĺ� ����\n"
			<< "3. ������ ����\t\t 4. ������ ����\n"
			<< "5. ���� ���� ����\t 6. ���� ���� ����\n"
			<< "7. �۾� ������\n";
		cin >> how;


		switch (how) {
		case 1:
			cout << "���� ������ ����:\n���\t����\t����\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;
		
		case 2:
			sort(books.begin(), books.end());
			cout << "���ĺ� ������ ����:\n���\t����\t����\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;

		case 3:
			sort(books.begin(), books.end(), worseRating);
			cout << "������ ������ ����:\n���\t����\t����\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;

		case 4:
			sort(books.begin(), books.end(), worseRating);
			cout << "������ ������ ����:\n���\t����\t����\n";
			for_each(books.rbegin(), books.rend(), ShowReview);
			break;

		case 5:
			sort(books.begin(), books.end(), worsePrice);
			cout << "���� ���� ������ ����:\n���\t����\t����\n";
			for_each(books.begin(), books.end(), ShowReview);
			break;

		case 6:
			sort(books.begin(), books.end(), worsePrice);
			cout << "���� ���� ������ ����:\n���\t����\t����\n";
			for_each(books.rbegin(), books.rend(), ShowReview);
			break;

		case 7:
			cout << "�۾��� �����ϴ�.\n";
			break;
		}

	}
	else
		cout << "���α׷��� �����մϴ�.\n";

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
	std::cout << "å ������ �Է��Ͻʽÿ�(�������� quit�� �Է�): ";
	getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;

	std::cout << "å ���(0-10)�� �Է��Ͻʽÿ�: ";
	std::cin >> rr.rating;

	std::cout << "å ������ �Է��Ͻʽÿ�: ";
	std::cin >> rr.price;

	// �������� ���� �Է� ��
	if (!std::cin)
		return false;

	// ���� �Է����� ����
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