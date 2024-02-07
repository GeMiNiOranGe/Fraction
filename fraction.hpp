#pragma once
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric>
#include <utility>

#include "fraction_exception.hpp"

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

    std::strong_ordering compare(const Fraction &_fraction) const;
    void simplify();
    void inverse();

    double to_double() const;

    operator double() const;

    Fraction &operator=(const Fraction &) = default;
    Fraction &operator=(Fraction &&_fraction);
};

bool is_valid_fraction(Fraction _fraction);
Fraction to_fraction(double _number);

std::istream &operator>>(std::istream &_istr, Fraction &_val);
std::ostream &operator<<(std::ostream &_ostr, const Fraction &_val);

#pragma region Binary Arithmetic Operators
Fraction &operator+=(Fraction &_left, const Fraction &_right);
Fraction &operator-=(Fraction &_left, const Fraction &_right);
Fraction &operator*=(Fraction &_left, const Fraction &_right);
Fraction &operator/=(Fraction &_left, const Fraction &_right);

Fraction &operator+=(Fraction &_left, const int &_right);
Fraction &operator-=(Fraction &_left, const int &_right);
Fraction &operator*=(Fraction &_left, const int &_right);
Fraction &operator/=(Fraction &_left, const int &_right);

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

inline Fraction operator+(const Fraction &_left, const int &_right) {
    Fraction result = _left;
    result += _right;
    return result;
}
inline Fraction operator-(const Fraction &_left, const int &_right) {
    Fraction result = _left;
    result -= _right;
    return result;
}
inline Fraction operator*(const Fraction &_left, const int &_right) {
    Fraction result = _left;
    result *= _right;
    return result;
}
inline Fraction operator/(const Fraction &_left, const int &_right) {
    Fraction result = _left;
    result /= _right;
    return result;
}

inline Fraction operator+(const int &_left, const Fraction &_right) {
    Fraction result(_left);
    result += _right;
    return result;
}
inline Fraction operator-(const int &_left, const Fraction &_right) {
    Fraction result(_left);
    result -= _right;
    return result;
}
inline Fraction operator*(const int &_left, const Fraction &_right) {
    Fraction result(_left);
    result *= _right;
    return result;
}
inline Fraction operator/(const int &_left, const Fraction &_right) {
    Fraction result(_left);
    result /= _right;
    return result;
}
#pragma endregion

#pragma region Spaceship Operator
inline auto operator<=>(const Fraction &_left, const Fraction &_right) {
    return _left.compare(_right);
}
inline auto operator<=>(const Fraction &_left, const int &_right) {
    return _left <=> Fraction(_right);
}
inline auto operator<=>(const int &_left, const Fraction &_right) {
    return Fraction(_left) <=> _right;
}
#pragma endregion

#pragma region Comparison Operators
inline bool operator==(const Fraction &_left, const Fraction &_right) {
    return _left.compare(_right) == std::strong_ordering::equal;
}
inline bool operator!=(const Fraction &_left, const Fraction &_right) {
    return !operator==(_left, _right);
}
inline bool operator==(const Fraction &_left, const int &_right) {
    return _left == Fraction(_right);
}
inline bool operator!=(const Fraction &_left, const int &_right) {
    return !operator==(_left, _right);
}
inline bool operator==(const int &_left, const Fraction &_right) {
    return Fraction(_left) == _right;
}
inline bool operator!=(const int &_left, const Fraction &_right) {
    return !operator==(_left, _right);
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

inline bool operator<(const int &_left, const Fraction &_right) {
    return _left <=> _right == std::strong_ordering::less;
}
inline bool operator>(const int &_left, const Fraction &_right) {
    return _left <=> _right == std::strong_ordering::greater;
}
inline bool operator<=(const int &_left, const Fraction &_right) {
    return _left <=> _right != std::strong_ordering::greater;
}
inline bool operator>=(const int &_left, const Fraction &_right) {
    return _left <=> _right != std::strong_ordering::less;
}
#pragma endregion

#endif // end FRACTION_HPP