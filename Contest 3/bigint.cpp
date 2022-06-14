#include<iostream>
#include<vector>
#include<string>

const int base = 10000;
const int base_digits = 4;

class bigint {
	private:
		std::vector<int> a;
		int sign;
		friend bool operator<(const bigint &v1, const int &num);
		friend bool operator<(const int &num, const bigint &v2);
	public:
		bigint() { 
			sign = 1;
		}
		bigint(int v) {
			if(v < 0) sign = -1; 
				else sign = 1;
			a.push_back(std::abs(v));
		}
		
    	bigint(const bigint &other) {
    		sign = other.sign;
	        a = other.a;
		};
    	
    	bigint& operator=(const bigint &other) {
	        sign = other.sign;
	        a = other.a;
	        return *this;
    	}
    	
    	~bigint() {
    		a.clear();
    		sign = 1;
		};
		
		std::string to_string() const {
			std::string s = "";
			if(a.empty()) {
				s = "0";
				return s;
			}
			for (int i = (int) a.size() - 1; i >= 0; --i) {
				std::string s_tmp = std::to_string(a[i]);
				while(s_tmp.size() < base_digits && i != (int) a.size() - 1) s_tmp = '0' + s_tmp;
				s += s_tmp;
			}
			if(sign < 0)
				s = '-' + s;
			return s;
		}
		
		void fix() {
    		while (!a.empty() && !a.back())
	            a.pop_back();
	        if (a.empty())
	            sign = 1;
		}
		
		operator bool() const
		{
		    return !(a.size() == 0);
		}
		
		bigint abs() const 
	    {
	        bigint res = *this;
	        res.sign *= res.sign;
	        return res;
	    }
		
		bigint operator-() const
	    {
	        bigint res = *this;
	        res.sign = -sign;
	        return res;
	    }
	    
	    bigint operator+() const
	    {
	        bigint res = *this;
	        res.sign = sign;
	        return res;
	    }
	    
		bigint operator+(const bigint &v) const            
	    {
	        if (sign == v.sign) 
	        {
	            bigint res = v;
	            for (int i = 0, carry = 0; i < (int) std::max(a.size(), v.a.size()) || carry; ++i) 
	            {
	                if (i == (int) res.a.size())
	                    res.a.push_back(0);
	                res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
	                carry = res.a[i] >= base;
	                if (carry)
	                    res.a[i] -= base;
	            }
	            return res;
	    	}
	        return *this - (-v);
	    }
	    
	    bigint operator-(const bigint &v) const              
	    {
	        if (sign == v.sign) {
	        	bigint num1 = abs(), num2 = v.abs();
	            if (num1 >= num2) {
	                bigint res = *this;
	                for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) 
	                {
	                    res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
	                    carry = res.a[i] < 0;
	                    if (carry)
	                        res.a[i] += base;
	                }
	                res.fix();
	                return res;
	            }
	            return -(v - *this);
	        }
	        return *this + (-v);
	    }
	    
	    bigint& operator+=(const bigint &v) {
	    	bigint res = *this + v;
	    	*this = res;
	    	return *this;
		}
	    
	    bigint& operator-=(const bigint &v) {
	    	bigint res = *this - v;
	    	*this = res;
	    	return *this;
		}
		
		void normalize() {
            int rem = 0;
            for(int i = 0; i < a.size(); ++i) {
                int temp = rem + a[i];
                a[i] = temp % base;
                rem = temp / base;
            }
            while(rem != 0)
                a.push_back(rem % base) , rem /= base;
        }
        
        bigint& operator *= (int v){
		    if (v < 0)
	            sign = -sign, v = -v;
	        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) 
	        {
	            if (i == (int) a.size())
	                a.push_back(0);
	            long long cur = a[i] * (long long) v + carry;
	            carry = (int) (cur / base);
	            a[i] = (int) (cur % base);
	        }
	        fix();
	        return *this;
		}
		
		bigint operator *(int v) const{
			bigint res = *this;
			res *= v;
			return res;
		}
		
		bigint operator * (const bigint &v) const {
            bigint res;
            if(sign != v.sign) res.sign = -1;
            while(res.a.size() < a.size() + v.a.size() + 10) res.a.push_back(0);
			for(int i = 0; i < a.size(); i++)
                for(int j = 0; j < v.a.size(); j++)
                    res.a[i+j] += a[i] * v.a[j],
                    res.normalize();
            res.fix();
            return res;
        }
        
        bigint& operator *=(const bigint &v) {
            bigint res = *this * v;
            *this = res;
            return *this;
        }
        
        bigint& operator++() {
			*this += bigint(1);
			return *this;
		}
		
		const bigint operator++(int) {
			bigint tmp = *this;
			++*this;
			return tmp;
		}
		
		bigint& operator--() {
			*this -= bigint(1);
			return *this;
		}
		
		const bigint operator--(int) {
			bigint tmp = *this;
			--*this;
			return tmp;
		}
	    
	    void read(const std::string &s)                                 
	    {
	        sign = 1;
	        a.clear();
	        int pos = 0;
	        while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) 
	        {
	            if (s[pos] == '-')
	                sign = -sign;
	            ++pos;
	        }
	        for (int i = s.size() - 1; i >= pos; i -= base_digits) 
	        {
	            int x = 0;
	            for (int j = std::max(pos, i - base_digits + 1); j <= i; j++) {
	                x = x * 10 + s[j] - '0';
	        	}
	            a.push_back(x);
	            normalize();
	        }
	        fix();
	    }
	    
	    bool operator<(const bigint &v) const 
	    {
	        if (sign != v.sign)
	            return sign < v.sign;
	        if (a.size() != v.a.size())
	            return a.size() * sign < v.a.size() * v.sign;
	        for (int i = a.size() - 1; i >= 0; i--)
	            if (a[i] != v.a[i])
	                return a[i] * sign < v.a[i] * sign;
	        return false;
	    }
	 
	    bool operator>(const bigint &v) const 
	    {
	        return v < *this;
	    }
	    bool operator<=(const bigint &v) const 
	    {
	        return !(v < *this);
	    }
	    bool operator>=(const bigint &v) const 
	    {
	        return !(*this < v);
	    }
	    bool operator==(const bigint &v) const 
	    {
	        return !(*this < v) && !(v < *this);
	    }
	    bool operator!=(const bigint &v) const 
	    {
	        return *this < v || v < *this;
	    }	
	    
	    friend std::istream& operator>>(std::istream &stream, bigint &v) 
	    {
	        std::string s;
	        stream >> s;
	        v.read(s);
	        return stream;
	    }
	 
	    friend std::ostream& operator<<(std::ostream &stream, const bigint &v) 
	    {
	    	std::string s = v.to_string(); 
	    	stream << s;
	        return stream;
	    }
};
		bool operator<(const bigint &v1, const int &num)  
	    {
	    	bigint v2(num);
	        return v1 < v2;
	    }
	    
	    bool operator>(const bigint &v1, const int &num)  
	    {
	    	bigint v2(num);
	        return v2 < v1;
	    }
	    bool operator<=(const bigint &v1, const int &num)   
	    {
	    	bigint v2(num);
	        return !(v2 < v1);
	    }
	    bool operator>=(const bigint &v1, const int &num)  
	    {
	    	bigint v2(num);
	        return !(v1 < v2);
	    }
	    bool operator==(const bigint &v1, const int &num)   
	    {
	    	bigint v2(num);
	        return !(v1 < v2) && !(v2 < v1);
	    }
	    bool operator!=(const bigint &v1, const int &num)    
	    {
	    	bigint v2(num);
	        return v1 < v2 || v2 < v1;
	    }
		bool operator<(const int &num, const bigint &v2)  
	    {
	    	bigint v1(num);
	        return v1 < v2;
	    }
	    
	    bool operator>(const int &num, const bigint &v2) 
	    {
	    	bigint v1(num);
	        return v2 < v1;
	    }
	    bool operator<=(const int &num, const bigint &v2)   
	    {
	    	bigint v1(num);
	        return !(v2 < v1);
	    }
	    bool operator>=(const int &num, const bigint &v2)   
	    {
	    	bigint v1(num);
	        return !(v1 < v2);
	    }
	    bool operator==(const int &num, const bigint &v2)    
	    {
	    	bigint v1(num);
	        return !(v1 < v2) && !(v2 < v1);
	    }
	    bool operator!=(const int &num, const bigint &v2)    
	    {
	    	bigint v1(num);
	        return v1 < v2 || v2 < v1;
	    }    
bigint operator+ (const int &num, const bigint &v2) {
	bigint v1(num);
	return v1 + v2;
}

bigint operator- (const int &num, const bigint &v2) {
	bigint v1(num);
	return v1 - v2;
}

bigint operator+ (const bigint &v1, const int &num) {
	bigint v2(num);
	return v1 + v2;
}

bigint operator- (const bigint &v1, const int &num) {
	bigint v2(num);
	return v1 - v2;
}

bigint operator* (const int &num, const bigint &v2) {
	bigint v1(num);
	return v1 * v2;
}

bigint operator* (const bigint &v1, const int &num) {
	bigint v2(num);
	return v1 * v2;
}

int main() {
	bigint s1;
	bigint s2;
	std::cin >> s1 >> s2;
	std::cout << (s1 * s2);
	return 0;
}
