#include <iostream>
#include <cstddef>
#include <algorithm>

class layered_matrix {
	private:
		size_t n;
		int **vals;
	public:
		layered_matrix() = delete;
		layered_matrix(size_t n);
		~layered_matrix();
		layered_matrix(const layered_matrix &m);
		layered_matrix& operator=(const layered_matrix &m);
		int get_sum(size_t x1, size_t y1, size_t x2, size_t y2) const;
};

layered_matrix::~layered_matrix() {
	for (size_t i = 0; i < n; i++)
		delete vals[i];
	delete vals;
}

layered_matrix::layered_matrix(size_t matrix_size) {
	n = matrix_size;
	vals = new int*[n];
	for (size_t i = 0; i < n; i++)
		vals[i] = new int[n];
	int *a;
	a = new int[2*n];
	for (size_t i = 1; i < 2*n; i++)
		a[i] = (i <= n ? (n - i + 1) : i - n + 1);
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			vals[i][j] = a[n - i + j] - 1;
	delete[] a;
}

layered_matrix::layered_matrix(const layered_matrix  &m) : n(m.n) {
	vals = new int*[n];
	for (size_t i = 0; i < n; i++) 
		vals[i] = new int[n];
	for (size_t i = 0; i < n; i++)
		for(size_t j = 0; j < n; j++)
			vals[i][j] = m.vals[i][j];
}

layered_matrix& layered_matrix::operator=(const layered_matrix &m) {
	n = m.n;
	vals = new int*[n];
	for (size_t i = 0; i < n; i++)
		vals[i] = new int[n];
	for (size_t i = 0; i < n; i++)
		for(size_t j = 0; j < n; j++)
			vals[i][j] = m.vals[i][j];
	return *this;	
}

int layered_matrix::get_sum(size_t x1, size_t y1, size_t x2, size_t y2) const {
	int result = 0;
	for (size_t i = std::min(x1,x2); i <= std::max(x1,x2); i++) 
		for (size_t j = std::min(y1,y2); j <= std::max(y1,y2); j++)
			if (i == x1 || i == x2 || j == y1 || j == y2)
				result += vals[i][j];
	return result;	
}

int main() {
	size_t n;
	std::cin >> n;
	layered_matrix m1(n);
	std::cout << m1.get_sum(0,1,2,2);
	return 0;
}

