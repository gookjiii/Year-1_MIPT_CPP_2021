#include<iostream>

template <typename vt, size_t height, size_t width> 
class matrix {
	private:
		size_t row = height;
		size_t col = width;
		vt a[height][width];
		typedef matrix<vt, (height <= 1 ? 1 : height - 1),(width <= 1 ? 1 : width - 1)> matrix_minor;
		template<typename v, size_t M, size_t N, size_t P>
		friend matrix<v, M, P> operator*(const matrix<v, M, N>& m1, const matrix<v, N, P>& m2);
	public:
		matrix() {
			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] = 0;
		}
		matrix(const vt& num) {
			row = height;
			col = width;
			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] = num;
		}
		matrix(const matrix &other) {
			row = other.row;
			col = other.col;
			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] = other.a[i][j];
		}
		template<size_t M, size_t N>
		matrix<vt,M,N>& operator=(const matrix<vt,M,N> &other){
			row = other.row;
			col = other.col;
			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] = other.a[i][j];
			return *this;
		}
		~matrix() = default;
		vt& at(const size_t& i, const size_t& j) {
			return a[i][j];
		}
		const vt& at(const size_t& i, const size_t& j) const {
			return a[i][j];
		}
		bool operator==(const matrix& other) const {
			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					if(a[i][j] != other.a[i][j]) return false;
			return true;
 		}
 		
 		bool operator!=(const matrix& other) const {
			return !(*this == other);
 		}
 		
 		const matrix operator-() const
	    {
	        matrix res;
	        res.row = row;
	        res.col = col;
	        for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					res.a[i][j]  = -a[i][j];
	        return res;
	    }
	    
	    const matrix operator+() const
	    {
	        matrix res;
	        res.row = row;
	        res.col = col;
	        for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					res.a[i][j]  = a[i][j];
	        return res;
	    }
 		
 		matrix& operator+=(const matrix& other) {
 			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] += other.a[i][j];
			return *this;
		}
		
		matrix operator+(const matrix& other) const {
 			matrix res = (*this);
 			res += other;
			return res;
		}
		
		matrix& operator-=(const matrix& other) {
 			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] -= other.a[i][j];
			return *this;
		}
		
		matrix operator-(const matrix& other) const {
 			matrix res = (*this);
 			res -= other;
			return res;
		}
		
		matrix& operator+=(const vt& num) {
 			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] += num;
			return *this;
		}
		
		matrix operator+(const vt& num) const {
 			matrix res = (*this);
 			res += num;
			return res;
		}
		
		matrix& operator-=(const vt& num) {
 			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] -= num;
			return *this;
		}
		
		matrix operator-(const vt& num) const {
 			matrix res = (*this);
 			res -= num;
			return res;
		}
		
		matrix& operator*=(const vt& num) {
 			for(size_t i = 0; i < row; i++)
				for(size_t j = 0; j < col; j++)
					a[i][j] *= num;
			return *this;
		}
		
		matrix operator*(const vt& num) const {
 			matrix res = (*this);
 			res *= num;
			return res;
		}

	    matrix<vt,height,width>& operator*=(const matrix<vt,width,width>& other) {
	    	matrix<vt,height,width> res = *this * other;
	    	*this = res;
			return *this;
		}
		
		matrix<vt,width,height> transposed() const {
			matrix<vt,width,height> res;
			for(size_t i = 0; i < width; i++)
				for(size_t j = 0; j < height; j++)
					res.at(i,j) = a[j][i];
			return res;
		}
		
		vt trace() const {
			vt res = 0;
			for(size_t i = 0; i < width; i++)			
				res += a[i][i];
			return res;
		}
		vt det() const {
			vt res = 0;
			if(height == 1 && width == 1) return a[0][0];
			for(size_t i = 0; i < width; i++) {
				matrix_minor m;
				for(size_t p = 1; p < height; p++) {
					if(i > 0)
					for(size_t q = 0; q <= i - 1; q++)
						m.at(p - 1,q) = a[p][q];
					for(size_t q = i + 1; q < width; q++)
						m.at(p - 1,q - 1) = a[p][q];	
				}
				vt tmp =  m.det();
				res += (i % 2 == 0 ? 1 : -1) * a[0][i] * tmp;
			}

			return res;
		}
};

template <typename vt, size_t height, size_t width> 
matrix<vt,height,width> operator+(const vt& num, const matrix<vt,height,width>& m2) {
	matrix<vt,height,width> res = m2;
	res += num;
	return res;
}

template <typename vt, size_t height, size_t width> 
matrix<vt,height,width> operator-(const vt& num, const matrix<vt,height,width>& m2) {
	matrix<vt,height,width> res = m2;
	res -= num;
	res = -res;
	return res;
}

template <typename vt, size_t height, size_t width> 
matrix<vt,height,width> operator*(const vt& num, const matrix<vt,height,width>& m2) {
	matrix<vt,height,width> res = m2;
	res *= num;
	return res;
}

template<typename vt, size_t M, size_t N, size_t P>
matrix<vt, M, P> operator*(const matrix<vt, M, N>& m1, const matrix<vt, N, P>& m2) {
    matrix<vt,M,P> res;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            res.a[i][j]= 0;
            for (int k = 0; k < N; k++) {
                res.a[i][j] += m1.a[i][k] * m2.a[k][j];
            }
        }
    }
    return res;
}

int main() {
	matrix<int,3,4> a(4);
	matrix<int,3,3> b(6);
	//a *= b;
	//matrix<int,4,4> c = (a * b);
	std::cout << b.det();
	return 0;
}
