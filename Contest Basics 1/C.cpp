#include <iostream>
#include <math.h> 

unsigned int n,p;
double sum;

int main(){
	std::cin >> n >> p;
	while(n--) {
		double x;
		std::cin >> x;
		sum += pow(abs(x), (double)p);
	}
	double res = pow(sum, ((double)1)/p);
	std::cout << res;
	return 0;
}
