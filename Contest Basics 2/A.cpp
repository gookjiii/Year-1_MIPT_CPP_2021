#include <iostream>
#include <cmath>
#include <cstddef>

double dot_product (const double x1, const double y1, const double x2, const double y2) {
	return x1 * x2 + y1 * y2;
}

double cross_product (const double x1, const double y1, const double x2, const double y2) {
	return x1 * y2 - y1 * x2;
}

double area (const size_t n, const double* const x, const double* const y) {
	double sum = 0;
	if (n >= 3)
		for (int i = 0; i < n; i ++) 
			sum += x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
	sum /= (double)2;
	return (sum > 0 ? sum : - sum);		
}

double perimeter (const size_t n, const double* const x, const double* const y) {
	double sum = 0;
	if (n >= 3)
		for (int i = 0; i < n; i ++) {
			const double v_x = x[(i + 1) % n] - x[i];
			const double v_y = y[(i + 1) % n] - y[i];
			sum += sqrt(dot_product(v_x, v_y, v_x, v_y));
		}
	return sum;
}


int main() {
	size_t n;
	std::cin >> n;
	double* const x = new double[n];
	double* const y = new double[n];
	for (int i = 0; i < n; i ++)
		std::cin >> x[i] >> y[i];
		
	std::cout << perimeter(n, x, y) << " " << area(n, x, y);
	
	return 0;
}
