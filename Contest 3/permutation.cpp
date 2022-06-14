#include<iostream>

template <size_t n>
class permutation {
	private:
		unsigned int per[n];
		template <size_t m>
		friend bool operator<(const permutation<m>& per1, const permutation<m>& per2);
	public:
		permutation() {
			for(size_t i = 0; i < n; i++)
				per[i] = i;
		}
		
		permutation(const unsigned int *other) {
			for(size_t i = 0; i < n; i++)
				per[i] = other[i];
		}
		
		~permutation() = default;
		permutation(const permutation &p) = default;
		permutation& operator=(const permutation &p) = default;
		
		const unsigned int& operator[](const size_t i) const {
			return per[i];
		}
		
		unsigned int& operator[](const size_t i) {
			return per[i];
		}
		
		permutation& operator *= (const permutation& other) {
			unsigned int per_tmp[n];
			for(size_t i = 0; i < n; i++)
				per_tmp[i] = this->per[i];
			for(size_t i = 0; i < n; i++)
				this->per[i] = per_tmp[other.per[i]];
			return *this;
		}
		
		permutation next() const {
			unsigned int next_per[n];
			for(size_t i = 0; i < n; i++)
				next_per[i] = per[i];
			size_t i = n - 1;
			while(i > 0 && next_per[i] <= next_per[i - 1]) i--;
			if(i <= 0) {
				for(size_t j = 0; j < n; j++)
					next_per[j] = per[n - j - 1];
				return permutation<n>(next_per);
			}
			size_t j = n - 1;
			while(next_per[j] <= next_per[i - 1]) j--;
			unsigned int tmp = next_per[i- 1];
			next_per[i - 1] = next_per[j];
			next_per[j] = tmp;
			j = n - 1;
			while(i < j) {
				tmp = next_per[i];
				next_per[i] = next_per[j];
				next_per[j] = tmp;
				i++;
				j--;
			} 
			return permutation<n>(next_per);
		}
		
		permutation prev() const {
			unsigned int prev_per[n];
			for(size_t i = 0; i < n; i++)
				prev_per[i] = per[i];
			size_t i = n - 1;
			while(i > 0 && prev_per[i] >= prev_per[i - 1]) i--;
			if(i <= 0) {
				for(size_t j = 0; j < n; j++)
					prev_per[j] = per[n - j - 1];
				return permutation<n>(prev_per);
			}
			size_t j = i - 1;
			while(j + 1 <= n - 1 && prev_per[j + 1] <= prev_per[i - 1]) j++;
			unsigned int tmp = prev_per[i- 1];
			prev_per[i - 1] = prev_per[j];
			prev_per[j] = tmp;
			j = n - 1;
			while(i < j) {
				tmp = prev_per[i];
				prev_per[i] = prev_per[j];
				prev_per[j] = tmp;
				i++;
				j--;
			} 
			return permutation<n>(prev_per);
		}
		permutation& operator++() {
			size_t i = n - 1;
			while(i > 0 && per[i] <= per[i - 1]) i--;
			if(i <= 0) return *this;
			size_t j = n - 1;
			while(per[j] <= per[i - 1]) j--;
			unsigned int tmp = per[i- 1];
			per[i - 1] = per[j];
			per[j] = tmp;
			j = n - 1;
			while(i < j) {
				tmp = per[i];
				per[i] = per[j];
				per[j] = tmp;
				i++;
				j--;
			} 
			return *this;
		}
		
		const permutation operator++(int) {
			permutation tmp = *this;
			++*this;
			return tmp;
		}
		permutation& operator--() {
			size_t i = n - 1;
			while(i > 0 && per[i] >= per[i - 1]) i--;
			if(i <= 0) return *this;
			size_t j = i - 1;
			while(j + 1 <= n - 1 && per[j + 1] <= per[i - 1]) j++;
			unsigned int tmp = per[i- 1];
			per[i - 1] = per[j];
			per[j] = tmp;
			j = n - 1;
			while(i < j) {
				tmp = per[i];
				per[i] = per[j];
				per[j] = tmp;
				i++;
				j--;
			} 
			return *this;
		}
		
		const permutation operator--(int) {
			permutation tmp = *this;
			--*this;
			return tmp;
		}
		
		permutation inverse() const {
			unsigned int res_values[n];
			for(size_t i = 0; i < n; i++)
				res_values[per[i]] = i;
			return permutation<n>(res_values);
		}
		
		void operator()(unsigned int* values) const {
			unsigned int res_values[n];
			for(size_t i = 0; i < n; i++)
				res_values[per[i]] = values[i];
			for(size_t i = 0; i < n; i++)
				values[i] = res_values[i];
		}
};  

template <size_t n>
bool operator<(const permutation<n>& per1, const permutation<n>& per2) {
		for(size_t i = 0; i < n; i++)
			if(per1.per[i] < per2.per[i]) 
					return true;
				else if(per1.per[i] > per2.per[i])
					return false;
			return false;
}

template <size_t n>
bool operator>(const permutation<n>& per1, const permutation<n>& per2) {
	return per2 < per1;
}

template <size_t n>
bool operator==(const permutation<n>& per1, const permutation<n>& per2) {
	return (!(per2 < per1) && !(per1 < per2));
}

template <size_t n>
bool operator!=(const permutation<n>& per1, const permutation<n>& per2) {
	return ((per2 < per1) || (per1 < per2));
}

template <size_t n>
bool operator>=(const permutation<n>& per1, const permutation<n>& per2) {
	return !(per1 < per2);
}

template <size_t n>
bool operator<=(const permutation<n>& per1, const permutation<n>& per2) {
	return !(per2 < per1);
}

template<size_t n>
permutation<n> operator*(const permutation<n>& per1, const permutation<n>& per2) {
	return permutation<n>(per1)*=per2;
}

int main() {
	unsigned int arr[] = {1, 4, 2, 3, 5};
	permutation<5> permu1(arr);
	
	permutation<5> permu2 = permu1.inverse();
	for(size_t i = 0; i < 5; i++)
		std::cout << permu2[i] << " ";
	return 0;
}
