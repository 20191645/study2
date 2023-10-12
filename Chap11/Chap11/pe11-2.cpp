#include <cmath>
#include "pe11-2.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR {
	// 1 ���� ���� ����
	const double Rad_to_deg = 45.0 / atan(1.0);

	Vector::Vector() {
		x = y = 0.0;
		mode = RECT;
	}
	Vector::Vector(double n1, double n2, Mode form) {
		mode = form;

		if (form == RECT) {
			x = n1;
			y = n2;
		}
		else if (form == POL) {
			x = n1 * cos(n2);
			y = n1 * sin(n2);
		}
		else {
			cout << "Vector()�� ���޵� �� 3�� �Ű������� �߸��Ǿ���.\n";
			cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	void Vector::reset(double n1, double n2, Mode form) {
		mode = form;

		if (form == RECT) {
			x = n1;
			y = n2;
		}
		else if (form == POL) {
			x = n1 * cos(n2);
			y = n1 * sin(n2);
		}
		else {
			cout << "Vector()�� ���޵� �� 3�� �Ű������� �߸��Ǿ���.\n";
			cout << "�׷��� ���͸� 0���� �����Ͽ���.\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	Vector::~Vector() {

	}

	double Vector::magval() const {
		double mag = sqrt(x * x + y * y);
		return mag;
	}
	double Vector::angval() const {
		double ang;
		if (x == 0.0 && y == 0.0)
			ang = 0;
		else
			ang = atan2(y, x);
		return ang;
	}

	void Vector::polar_mode() {
		mode = POL;
	}
	void Vector::rect_mode() {
		mode = RECT;
	}

	Vector Vector::operator+(const Vector& b) const {
		return Vector(x + b.x, y + b.y);
	}
	Vector Vector::operator-(const Vector& b) const {
		return Vector(x - b.x, y - b.y);
	}
	Vector Vector::operator-() const {
		return Vector(-x, -y);
	}
	Vector Vector::operator*(double n) const {
		return Vector(n * x, n * y);
	}


	Vector operator*(double n, const Vector& a) {
		return a * n;
	}

	std::ostream& operator<<(std::ostream& os, const Vector& v) {
		if (v.mode == Vector::RECT)
			os << "(x, y) = (" << v.x << ", " << v.y << ")";
		else if (v.mode == Vector::POL) {
			os << "(m, a) = (" << v.magval() << ", "
				<< v.angval() * Rad_to_deg << ")";
		}
		else
			os << "Vector ��ü�� ��� ������ Ʋ�Ƚ��ϴ�.\n";

		return os;
	}
}


