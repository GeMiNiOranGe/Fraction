#pragma once
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric>
#include <utility>

#include "fraction_exception.hpp"

class Fraction {
private:
    int numerator_, denominator_;

public:
    Fraction(int numerator = 0, int denominator = 1);
    Fraction(const Fraction &fraction);
    Fraction(Fraction &&fraction);
    ~Fraction();

    const int &get_numerator() const;
    const int &get_denominator() const;

    void set_numerator(const int &numerator);
    void set_denominator(const int &denominator);

    std::strong_ordering compare(const Fraction &fraction) const;
    void simplify();
    void inverse();

    double to_double() const;

    operator double() const;

    Fraction &operator=(const Fraction &) = default;
    Fraction &operator=(Fraction &&fraction);
};

Fraction to_fraction(double number);

std::istream &operator>>(std::istream &istr, Fraction &val);
std::ostream &operator<<(std::ostream &ostr, const Fraction &val);

#pragma region Binary Arithmetic Operators
Fraction &operator+=(Fraction &left, const Fraction &right);
Fraction &operator-=(Fraction &left, const Fraction &right);
Fraction &operator*=(Fraction &left, const Fraction &right);
Fraction &operator/=(Fraction &left, const Fraction &right);

Fraction &operator+=(Fraction &left, const int &right);
Fraction &operator-=(Fraction &left, const int &right);
Fraction &operator*=(Fraction &left, const int &right);
Fraction &operator/=(Fraction &left, const int &right);

inline Fraction operator+(const Fraction &left, const Fraction &right) {
    Fraction result = left;
    result += right;
    return result;
}
inline Fraction operator-(const Fraction &left, const Fraction &right) {
    Fraction result = left;
    result -= right;
    return result;
}
inline Fraction operator*(const Fraction &left, const Fraction &right) {
    Fraction result = left;
    result *= right;
    return result;
}
inline Fraction operator/(const Fraction &left, const Fraction &right) {
    Fraction result = left;
    result /= right;
    return result;
}

inline Fraction operator+(const Fraction &left, const int &right) {
    Fraction result = left;
    result += right;
    return result;
}
inline Fraction operator-(const Fraction &left, const int &right) {
    Fraction result = left;
    result -= right;
    return result;
}
inline Fraction operator*(const Fraction &left, const int &right) {
    Fraction result = left;
    result *= right;
    return result;
}
inline Fraction operator/(const Fraction &left, const int &right) {
    Fraction result = left;
    result /= right;
    return result;
}

inline Fraction operator+(const int &left, const Fraction &right) {
    Fraction result(left);
    result += right;
    return result;
}
inline Fraction operator-(const int &left, const Fraction &right) {
    Fraction result(left);
    result -= right;
    return result;
}
inline Fraction operator*(const int &left, const Fraction &right) {
    Fraction result(left);
    result *= right;
    return result;
}
inline Fraction operator/(const int &left, const Fraction &right) {
    Fraction result(left);
    result /= right;
    return result;
}
#pragma endregion

#pragma region Spaceship Operator
inline auto operator<=>(const Fraction &left, const Fraction &right) {
    return left.compare(right);
}
inline auto operator<=>(const Fraction &left, const int &right) {
    return left <=> Fraction(right);
}
inline auto operator<=>(const int &left, const Fraction &right) {
    return Fraction(left) <=> right;
}
#pragma endregion

#pragma region Comparison Operators
inline bool operator==(const Fraction &left, const Fraction &right) {
    return left.compare(right) == std::strong_ordering::equal;
}
inline bool operator!=(const Fraction &left, const Fraction &right) {
    return !operator==(left, right);
}
inline bool operator==(const Fraction &left, const int &right) {
    return left == Fraction(right);
}
inline bool operator!=(const Fraction &left, const int &right) {
    return !operator==(left, right);
}
inline bool operator==(const int &left, const Fraction &right) {
    return Fraction(left) == right;
}
inline bool operator!=(const int &left, const Fraction &right) {
    return !operator==(left, right);
}

inline bool operator<(const Fraction &left, const Fraction &right) {
    return left <=> right == std::strong_ordering::less;
}
inline bool operator>(const Fraction &left, const Fraction &right) {
    return left <=> right == std::strong_ordering::greater;
}
inline bool operator<=(const Fraction &left, const Fraction &right) {
    return left <=> right != std::strong_ordering::greater;
}
inline bool operator>=(const Fraction &left, const Fraction &right) {
    return left <=> right != std::strong_ordering::less;
}

inline bool operator<(const Fraction &left, const int &right) {
    return left <=> right == std::strong_ordering::less;
}
inline bool operator>(const Fraction &left, const int &right) {
    return left <=> right == std::strong_ordering::greater;
}
inline bool operator<=(const Fraction &left, const int &right) {
    return left <=> right != std::strong_ordering::greater;
}
inline bool operator>=(const Fraction &left, const int &right) {
    return left <=> right != std::strong_ordering::less;
}

inline bool operator<(const int &left, const Fraction &right) {
    return left <=> right == std::strong_ordering::less;
}
inline bool operator>(const int &left, const Fraction &right) {
    return left <=> right == std::strong_ordering::greater;
}
inline bool operator<=(const int &left, const Fraction &right) {
    return left <=> right != std::strong_ordering::greater;
}
inline bool operator>=(const int &left, const Fraction &right) {
    return left <=> right != std::strong_ordering::less;
}
#pragma endregion

#endif // end FRACTION_HPP