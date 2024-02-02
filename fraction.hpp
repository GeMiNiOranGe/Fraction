#pragma once
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric> // C++17 to use gcd
#include <utility>

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction(int _numerator = 0, int _denominator = 1);
    Fraction(const Fraction &_fraction);
    Fraction(Fraction &&_fraction);
    ~Fraction();

    const int &get_numerator() const;
    const int &get_denominator() const;

    void set_numerator(const int &_numerator);
    void set_denominator(const int &_denominator);

    double to_double() const;
    void simplify();
    Fraction inverse();

    operator double() const;

    Fraction &operator=(const Fraction &) = default;
    Fraction &operator=(Fraction &&_fraction);
};
Fraction to_fraction(double _number);

std::istream &operator>>(std::istream &_istr, Fraction &_val);
std::ostream &operator<<(std::ostream &_ostr, const Fraction &_val);

#pragma region Fraction vs Fraction
Fraction &operator+=(Fraction &_left, const Fraction &_right);
Fraction &operator-=(Fraction &_left, const Fraction &_right);
Fraction &operator*=(Fraction &_left, const Fraction &_right);
Fraction &operator/=(Fraction &_left, const Fraction &_right);

inline Fraction operator+(const Fraction &_left, const Fraction &_right) {
    Fraction result = _left;
    result += _right;
    return result;
}
inline Fraction operator-(const Fraction &_left, const Fraction &_right) {
    Fraction result = _left;
    result -= _right;
    return result;
}
inline Fraction operator*(const Fraction &_left, const Fraction &_right) {
    Fraction result = _left;
    result *= _right;
    return result;
}
inline Fraction operator/(const Fraction &_left, const Fraction &_right) {
    Fraction result = _left;
    result /= _right;
    return result;
}

inline auto operator<=>(const Fraction &_left, const Fraction &_right) {
    int left, right;

    if (_left.get_denominator() == _right.get_denominator()) {
        left = _left.get_numerator();
        right = _right.get_numerator();
    } else if (_left.get_denominator() == 1) {
        left = _left.get_numerator() * _right.get_denominator();
        right = _right.get_numerator();
    } else if (_right.get_denominator() == 1) {
        left = _left.get_numerator();
        right = _right.get_numerator() * _left.get_denominator();
    } else {
        left = _left.get_numerator() * _right.get_denominator();
        right = _right.get_numerator() * _left.get_denominator();
    }

    if (left < right)
        return std::strong_ordering::less;
    if (left > right)
        return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}
inline bool operator<(const Fraction &_left, const Fraction &_right) {
    return _left <=> _right == std::strong_ordering::less;
}
inline bool operator>(const Fraction &_left, const Fraction &_right) {
    return _left <=> _right == std::strong_ordering::greater;
}
inline bool operator<=(const Fraction &_left, const Fraction &_right) {
    return _left <=> _right != std::strong_ordering::greater;
}
inline bool operator>=(const Fraction &_left, const Fraction &_right) {
    return _left <=> _right != std::strong_ordering::less;
}
inline bool operator==(const Fraction &_left, const Fraction &_right) {
    int left, right;

    if (_left.get_denominator() == _right.get_denominator()) {
        left = _left.get_numerator();
        right = _right.get_numerator();
    } else {
        left = _left.get_numerator() * _right.get_denominator();
        right = _right.get_numerator() * _left.get_denominator();
    }

    return left == right;
}
inline bool operator!=(const Fraction &_left, const Fraction &_right) {
    return !operator==(_left, _right);
}
#pragma endregion

#pragma region Fraction vs Number
Fraction &operator+=(Fraction &_left, const int &_right);
Fraction &operator-=(Fraction &_left, const int &_right);
Fraction &operator*=(Fraction &_left, const int &_right);
Fraction &operator/=(Fraction &_left, const int &_right);

inline Fraction operator+(Fraction _left, const int &_right) {
    _left += _right;
    return _left;
}
inline Fraction operator-(Fraction _left, const int &_right) {
    _left -= _right;
    return _left;
}
inline Fraction operator*(Fraction _left, const int &_right) {
    _left *= _right;
    return _left;
}
inline Fraction operator/(Fraction _left, const int &_right) {
    _left /= _right;
    return _left;
}

inline auto operator<=>(const Fraction &_left, const int &_right) {
    return _left <=> Fraction(_right);
}
inline bool operator<(const Fraction &_left, const int &_right) {
    return _left <=> _right == std::strong_ordering::less;
}
inline bool operator>(const Fraction &_left, const int &_right) {
    return _left <=> _right == std::strong_ordering::greater;
}
inline bool operator<=(const Fraction &_left, const int &_right) {
    return _left <=> _right != std::strong_ordering::greater;
}
inline bool operator>=(const Fraction &_left, const int &_right) {
    return _left <=> _right != std::strong_ordering::less;
}
inline bool operator==(const Fraction &_left, const int &_right) {
    return _left == Fraction(_right);
}
inline bool operator!=(const Fraction &_left, const int &_right) {
    return !operator==(_left, _right);
}
#pragma endregion

#endif // end FRACTION_HPP