#ifndef PE11_6_H_
#define PE11_6_H_

class Stonewt {
private:
	enum { Lps_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;

public:
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	Stonewt();
	~Stonewt();

	void show_lbs() const;
	void show_stn() const;

	// 관계 연산자 오버로딩
	bool operator==(const Stonewt& st) const { return pounds == st.pounds; }
	bool operator!=(const Stonewt& st) const { return pounds != st.pounds; }
	bool operator<(const Stonewt& st) const { return pounds < st.pounds; }
	bool operator<=(const Stonewt& st) const { return pounds <= st.pounds; }
	bool operator>(const Stonewt& st) const { return pounds > st.pounds; }
	bool operator>=(const Stonewt& st) const { return pounds >= st.pounds; }

};

#endif