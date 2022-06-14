#include<iostream>

template <typename T1, typename T2, typename T3> 
class triad {
	private:
		T1 first_e;
		T2 second_e;
		T3 third_e;
	public:
		triad() = delete;
		triad(const T1& first_, const T2& second_, const T3& third_) {
			first_e = first_;
			second_e = second_;
			third_e = third_;
		}
		triad(const triad &other) {
			first_e = other.first_e;
			second_e = other.second_e;
			third_e = other.third_e;
		}
		~triad() = default;
		T1& first() {
			return first_e;
		}
		const T1& first() const {
			return first_e;
		}
		
		T2& second() {
			return second_e;
		}
		const T2& second() const {
			return second_e;
		}
		
		T3& third() {
			return third_e;
		}
		const T3& third() const {
			return third_e;
		}
};

int main() {
	triad<int, std::string, float> tri(4,"Chi",3.5);
	std::cout << tri.first() << " " << tri.second() << " " << tri.third() << std::endl; 
}
