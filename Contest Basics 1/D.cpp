#include<iostream>
#include<math.h>

double xt1,yt1,xt2,yt2,r1,r2;

bool equal(double x, double y) {
	return fabs(x - y) <= 1e-6;
}

int main(){
	std::cin >> xt1 >> yt1 >> r1 >> xt2 >> yt2 >> r2;
	double d = hypot((xt1-xt2),(yt1-yt2));
	if (xt1 == xt2 && yt1 == yt2 && fabs(r1 - r2) <= 1e-6)
    {
		std::cout << "infinity";
		return 0;
	}
	if (fabs(d - fabs(r1-r2)) <= 1e-6  || fabs((d - (r1+r2)) <= 1e-6))
	{
		std::cout << 1;
		return 0;
	}
	if (d > r1 + r2)
    {
    	std::cout << 0;
        return 0;
    }
    if (d < fabs(r1 - r2))
    {
    	std::cout << 0;
        return 0;
    }
	std::cout << 2;
	return 0;
}
