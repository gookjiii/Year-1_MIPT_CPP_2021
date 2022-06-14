#include <iostream>
#include <cmath>

struct segment {
	segment (): segment(0, 0) {}
	segment (const double c, const double l): c(c), l(l) {}
	segment (const segment& other) = default;
    segment& operator= (const segment& other) = default;
    ~segment () = default;
 
    double c;
    double l;
};

double common_segment(const segment s1, const segment s2) {
	double  s1left = s1.c - s1.l / double(2), 
			s1right = s1.c + s1.l / double(2),
			s2left = s2.c - s2.l / double(2),
			s2right = s2.c + s2.l / double(2);
	if ((s1.c < s2.c && s1right < s2left) || (s1.c > s2.c && s2right < s1left)) {
		return 0;
	} else if (s1left < s2left && s1right > s2right) {
		return s2.l;
	} else if (s1left > s2left && s1right < s2right) {
		return s1.l;
	} else if (s2left < s1right && s2.c > s1.c) {
		return s1right - s2left;
	} else
		return s2right - s1left;
}


int main() {
	segment s1, s2;
	std::cin >> s1.c >> s1.l >> s2.c >> s2.l;
	std::cout << common_segment(s1,s2);
	return 0;
}
