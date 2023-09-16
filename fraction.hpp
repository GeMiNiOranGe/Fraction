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

    double to_double();
    Fraction inverse();
    Fraction simplify();

    Fraction &operator=(const Fraction &) = default;
    Fraction &operator=(Fraction &&_fraction);

    friend std::istream &operator>>(std::istream &_istr, Fraction &_val);
    friend std::ostream &operator<<(std::ostream &_ostr, Fraction _val);
};
Fraction to_fraction(double _number);

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

inline bool operator<(const Fraction &_left, const Fraction &_right) {
    int left_side = _left.get_numerator() * _right.get_denominator();
    int right_side = _left.get_denominator() * _right.get_numerator();
    return left_side < right_side;
}
inline bool operator>(const Fraction &_left, const Fraction &_right) {
    return operator<(_right, _left);
}
inline bool operator<=(const Fraction &_left, const Fraction &_right) {
    return !operator>(_left, _right);
}
inline bool operator>=(const Fraction &_left, const Fraction &_right) {
    return !operator<(_left, _right);
}
inline bool operator==(const Fraction &_left, const Fraction &_right) {
    int left_side = _left.get_numerator() * _right.get_denominator();
    int right_side = _left.get_denominator() * _right.get_numerator();
    return left_side == right_side;
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

inline bool operator<(const Fraction &_left, const int &_right) {
    return _left.get_numerator() < (_left.get_denominator() * _right);
}
inline bool operator>(const Fraction &_left, const int &_right) {
    return operator<(_right, _left);
}
inline bool operator<=(const Fraction &_left, const int &_right) {
    return !operator>(_left, _right);
}
inline bool operator>=(const Fraction &_left, const int &_right) {
    return !operator<(_left, _right);
}
inline bool operator==(const Fraction &_left, const int &_right) {
    return _left.get_numerator() == (_left.get_denominator() * _right);
}
inline bool operator!=(const Fraction &_left, const int &_right) {
    return !operator==(_left, _right);
}
#pragma endregion

#endif // end FRACTION_HPP