#include <iostream>
#include <math.h>

double xt1,yt1,xt2,yt2,r1,r2;

bool equal(double x, double y) {
	return fabs(x - y) <= 1e-6;
}

int main(){
	std::cin >> xt1 >> yt1 >> r1 >> xt2 >> yt2 >> r2;
	double d = hypot((xt1-xt2),(yt1-yt2));
	if (d <= 1e-6 && equal(r1,r2) && not equal(r1,0) && not equal(r2,0)) {
		std::cout << "infinity";
		return 0;
		
	}
	if (equal(d,fabs(r1-r2)) || equal(d,(r1+r2))) {
		std::cout << 1;
		return 0;
	}
	if (d > r1 + r2 || d < fabs(r1 - r2)) {
    	std::cout << 0;
        return 0;
    }
	std::cout << 2;
	return 0;
}
