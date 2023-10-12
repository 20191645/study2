#ifndef PE11_1_H_
#define PE11_1_H_

#include <iostream>

namespace VECTOR {
	class Vector {
	public:
		enum Mode { RECT, POL };

	private:
		double x;
		double y;
		double mag;	// 벡터의 길이
		double ang;	// 벡터의 방향
		Mode mode;	// enum 값

		// POL - RECT 값을 이용해 서로의 값을 설정하는 메서드
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();

	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();

		double xval() const { return x; }
		double yval() const { return y; }
		double magval() const { return mag; }
		double angval() const { return ang; }
		void polar_mode();
		void rect_mode();

		Vector operator+(const Vector& b) const;
		Vector operator-(const Vector& b) const;
		Vector operator-() const;
		Vector operator*(double n) const;

		friend Vector operator*(double n, const Vector& a);
		friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	};
}

#endif