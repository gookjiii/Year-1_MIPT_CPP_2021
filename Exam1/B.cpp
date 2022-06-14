#include <iostream>
#include <cstddef>
#include <algorithm>

size_t min(size_t a, size_t b) {
	return (a < b) ? a : b;
}

class matrix {
	private:
		size_t n;
	public:
		int **vals;
		matrix() = delete;
		matrix(size_t n);
		~matrix();
		matrix(const matrix &m);
		matrix& operator=(const matrix &m);
		int get_sum(size_t x1, size_t y1, size_t x2, size_t y2) const;
};

matrix::~matrix() {
	for (size_t i = 0; i < n; i++)
		delete vals[i];
	delete vals;
}

matrix::matrix(size_t matrix_size) {
	n = matrix_size;
	vals = new int*[n + 1];
	for (size_t i = 0; i <= n; i++)
		vals[i] = new int[n];
	int** a;
	a = new int*[n];
	for (size_t i = 0; i < n; i++)
		a[i] = new int[n];
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			a[i][j] = i * n + j + 1;
	size_t count = 0;
	size_t travel[50000];
	int row = 0, col = 0;
    bool row_inc = 0;
    int mn = min(n, n);
    for (int len = 1; len <= mn; ++len) {
        for (int i = 0; i < len; ++i) {
            travel[count] = a[row][col];
            count++;
            if (i + 1 == len)
                break;
            if (row_inc)
                ++row, --col;
            else
                --row, ++col;
        }
        if (len == mn)
            break;
        if (row_inc)
            ++row, row_inc = false;
        else
            ++col, row_inc = true;
    }
    if (row == 0) {
        if (col == n - 1)
            ++row;
        else
            ++col;
        row_inc = 1;
    }
    else {
        if (row == n - 1)
            ++col;
        else
            ++row;
        row_inc = 0;
    }
    int MAX = std::max(n, n) - 1;
    for (int len, diag = MAX; diag > 0; --diag) {
 
        if (diag > mn)
            len = mn;
        else
            len = diag;
 
        for (int i = 0; i < len; ++i) {
            travel[count] = a[row][col];
 			count++;
            if (i + 1 == len)
                break;
            if (row_inc)
                ++row, --col;
            else
                ++col, --row;
        }
        if (row == 0 || col == n - 1) {
            if (col == n - 1)
                ++row;
            else
                ++col;
 
            row_inc = true;
        }
        else if (col == 0 || row == n - 1) {
            if (row == n - 1)
                ++col;
            else
                ++row;
 
            row_inc = false;
        }
    }
    int res[50000];
    for (size_t i = 0; i < count; i++){
    	res[travel[i]] = i + 1;
	}
	for (size_t i = 1; i <= count; i++) {
		std::cout << res[i] << " ";
		if(i % n == 0) std::cout << "\n";
	}
}

matrix::matrix(const matrix &m) : n(m.n) {
	vals = new int*[n];
	for (size_t i = 0; i < n; i++) 
		vals[i] = new int[n];
	for (size_t i = 0; i < n; i++)
		for(size_t j = 0; j < n; j++)
			vals[i][j] = m.vals[i][j];
}

matrix& matrix::operator=(const matrix &m) {
	n = m.n;
	vals = new int*[n];
	for (size_t i = 0; i < n; i++)
		vals[i] = new int[n];
	for (size_t i = 0; i < n; i++)
		for(size_t j = 0; j < n; j++)
			vals[i][j] = m.vals[i][j];
	return *this;	
}

int main() {
	size_t n;
	std::cin >> n;
	matrix m1(n);
	return 0;
}

