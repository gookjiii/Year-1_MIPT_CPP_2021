#include<iostream>
#include<vector>
#include<string>

class BigInt {
    std::string value;
    char sign;

    public:
        // Constructors:
        BigInt();
        BigInt(const BigInt&);
        BigInt(const long long&);
        BigInt(const std::string&);

        // Assignment operators:
        BigInt& operator=(const BigInt&);
        BigInt& operator=(const long long&);
        BigInt& operator=(const std::string&);

        // Unary arithmetic operators:
        BigInt operator+() const;   // unary +
        BigInt operator-() const;   // unary -

        // Binary arithmetic operators:
        BigInt operator+(const BigInt&) const;
        BigInt operator-(const BigInt&) const;
        BigInt operator*(const BigInt&) const;
        BigInt operator+(const long long&) const;
        BigInt operator-(const long long&) const;
        BigInt operator*(const long long&) const;
        BigInt operator+(const std::string&) const;
        BigInt operator-(const std::string&) const;
        BigInt operator*(const std::string&) const;

        // Arithmetic-assignment operators:
        BigInt& operator+=(const BigInt&);
        BigInt& operator-=(const BigInt&);
        BigInt& operator*=(const BigInt&);
        BigInt& operator+=(const long long&);
        BigInt& operator-=(const long long&);
        BigInt& operator*=(const long long&);
        BigInt& operator+=(const std::string&);
        BigInt& operator-=(const std::string&);
        BigInt& operator*=(const std::string&);

        // Increment and decrement operators:
        BigInt& operator++();       // pre-increment
        BigInt& operator--();       // pre-decrement
        BigInt operator++(int);     // post-increment
        BigInt operator--(int);     // post-decrement

        // Relational operators:
        bool operator<(const BigInt&) const;
        bool operator>(const BigInt&) const;
        bool operator<=(const BigInt&) const;
        bool operator>=(const BigInt&) const;
        bool operator==(const BigInt&) const;
        bool operator!=(const BigInt&) const;
        bool operator<(const long long&) const;
        bool operator>(const long long&) const;
        bool operator<=(const long long&) const;
        bool operator>=(const long long&) const;
        bool operator==(const long long&) const;
        bool operator!=(const long long&) const;
        bool operator<(const std::string&) const;
        bool operator>(const std::string&) const;
        bool operator<=(const std::string&) const;
        bool operator>=(const std::string&) const;
        bool operator==(const std::string&) const;
        bool operator!=(const std::string&) const;

        friend std::istream& operator>>(std::istream&, BigInt&);
        friend std::ostream& operator<<(std::ostream&, const BigInt&);

        std::string to_string() const;
        int to_int() const;
        long to_long() const;
        long long to_long_long() const;
};
