const double eps = 1e-6;

bool equal (double a, double b) {
	return std::fabs(a - b) < eps;
}

struct vector {
	double x, y;
	public:
		vector(double _x, double _y): x(_x), y(_y) {};
		vector() = default;
		vector& operator =(const vector& other) = default;
		~vector() = default; 
		bool operator ==(const vector& other) {
			return (equal(x,other.x) && equal(y,other.y));
		}
		
		bool operator !=(const vector& other) {
			return !(*this == other);
		}
		
		vector& operator +=(const vector& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
		
		vector operator +(const vector& other) const {
			vector res = *this;
			res += other;
			return res;
		}
		
		vector& operator -=(const vector& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		
		vector operator -(const vector& other) const {
			vector res = *this;
			res -= other;
			return res;
		}
		
		vector& operator *=(const double num) {
			x *= num;
			y *= num;
			return *this;
		}
		
		vector operator *(const double num) const {
			vector res = *this;
			res *= num;
			return res;
		}
		
		vector& operator /=(const double num) {
			x /= num;
			y /= num;
			return *this;
		}
		
		vector operator /(const double num) const {
			vector res = *this;
			res /= num;
			return res;
		}	
		
		vector operator +() const {
			return *this;
		}
		
		vector operator -() const {
			vector res = *this * (-1);
			return res;
		}
		
		double length() const {
			return sqrt(x * x + y * y);
		}
};

double dot_product (const vector& lhs, const vector& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

double cross_product (const vector& lhs, const vector& rhs) {
	return lhs.x * rhs.y - rhs.x * lhs.y;
}

bool collinear (const vector& lhs, const vector& rhs) {
	return equal(lhs.x/rhs.x,lhs.y/rhs.y);
}


