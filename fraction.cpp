#include "fraction.hpp"

Fraction::Fraction(int _numerator, int _denominator) {
    this->numerator = _numerator;
    this->denominator = _denominator;
}
Fraction::Fraction(const Fraction &_fraction) {
    this->numerator = _fraction.numerator;
    this->denominator = _fraction.denominator;
}
Fraction::Fraction(Fraction &&_fraction) {
    this->numerator = _fraction.numerator;
    this->denominator = _fraction.denominator;
    _fraction = Fraction();
}
Fraction::~Fraction() {
}

int Fraction::get_numerator() {
    return this->numerator;
}
int Fraction::get_denominator() {
    return this->denominator;
}

void Fraction::set_numerator(int _numerator) {
    this->numerator = _numerator;
}
void Fraction::set_denominator(int _denominator) {
    this->denominator = _denominator;
}

Fraction Fraction::inverse() {
    std::swap(this->denominator, this->numerator);
    return *this;
}
Fraction Fraction::simplify() {
    int temp = std::gcd(this->numerator, this->denominator);
    this->numerator /= temp;
    this->denominator /= temp;
    return *this;
}

double Fraction::to_double() {
    return static_cast<double>(this->numerator) / static_cast<double>(this->denominator);
}
Fraction to_fraction(double _number) {
    Fraction result;
    result.denominator = 1;
    while (static_cast<double>(static_cast<int>(_number)) != _number) {
        _number *= 10;
        result.denominator *= 10;
    }
    result.numerator = static_cast<int>(_number);
    return result.simplify();
}

std::istream &operator>>(std::istream &_istr, Fraction &_val) {
    _istr >> _val.numerator >> _val.denominator;
    return _istr;
}
std::ostream &operator<<(std::ostream &_ostr, Fraction _val) {
    _val.denominator == 1
        ? _ostr << _val.numerator
        : _ostr << _val.numerator << '/' << _val.denominator;
    return _ostr;
}

#pragma region Fraction vs Fraction
Fraction operator+(Fraction _left, Fraction _right) {
    int numerator = _left.numerator * _right.denominator + _left.denominator * _right.numerator;
    int denominator = _left.denominator * _right.denominator;
    return Fraction(numerator, denominator).simplify();
}
Fraction operator-(Fraction _left, Fraction _right) {
    int numerator = _left.numerator * _right.denominator - _left.denominator * _right.numerator;
    int denominator = _left.denominator * _right.denominator;
    return Fraction(numerator, denominator).simplify();
}
Fraction operator*(Fraction _left, Fraction _right) {
    int numerator = _left.numerator * _right.numerator;
    int denominator = _left.denominator * _right.denominator;
    return Fraction(numerator, denominator).simplify();
}
Fraction operator/(Fraction _left, Fraction _right) {
    return (_left * _right.inverse()).simplify();
}

Fraction &operator+=(Fraction &_left, Fraction _right) {
    _left = _left + _right;
    return _left;
}
Fraction &operator-=(Fraction &_left, Fraction _right) {
    _left = _left - _right;
    return _left;
}
Fraction &operator*=(Fraction &_left, Fraction _right) {
    _left = _left * _right;
    return _left;
}
Fraction &operator/=(Fraction &_left, Fraction _right) {
    _left = _left / _right;
    return _left;
}

bool operator>(Fraction _left, Fraction _right) {
    int left_side = _left.numerator * _right.denominator;
    int right_side = _left.denominator * _right.numerator;
    return left_side > right_side;
}
bool operator<(Fraction _left, Fraction _right) {
    int left_side = _left.numerator * _right.denominator;
    int right_side = _left.denominator * _right.numerator;
    return left_side < right_side;
}
bool operator==(Fraction _left, Fraction _right) {
    int left_side = _left.numerator * _right.denominator;
    int right_side = _left.denominator * _right.numerator;
    return left_side == right_side;
}
bool operator>=(Fraction _left, Fraction _right) {
    int left_side = _left.numerator * _right.denominator;
    int right_side = _left.denominator * _right.numerator;
    return left_side >= right_side;
}
bool operator<=(Fraction _left, Fraction _right) {
    int left_side = _left.numerator * _right.denominator;
    int right_side = _left.denominator * _right.numerator;
    return left_side <= right_side;
}
bool operator!=(Fraction _left, Fraction _right) {
    return !(_left == _right);
}
#pragma endregion

#pragma region Fraction vs Number
Fraction operator+(Fraction _left, int _right) {
    int numerator = _left.numerator + _left.denominator * _right;
    return Fraction(numerator, _left.denominator).simplify();
}
Fraction operator-(Fraction _left, int _right) {
    int numerator = _left.numerator - _left.denominator * _right;
    return Fraction(numerator, _left.denominator).simplify();
}
Fraction operator*(Fraction _left, int _right) {
    int numerator = _left.numerator * _right;
    return Fraction(numerator, _left.denominator).simplify();
}
Fraction operator/(Fraction _left, int _right) {
    int denominator = _left.denominator * _right;
    return Fraction(_left.numerator, denominator).simplify();
}

Fraction &operator+=(Fraction &_left, int _right) {
    _left = _left + _right;
    return _left;
}
Fraction &operator-=(Fraction &_left, int _right) {
    _left = _left - _right;
    return _left;
}
Fraction &operator*=(Fraction &_left, int _right) {
    _left = _left * _right;
    return _left;
}
Fraction &operator/=(Fraction &_left, int _right) {
    _left = _left / _right;
    return _left;
}

bool operator>(Fraction _left, int _right) {
    return _left.numerator > (_left.denominator * _right);
}
bool operator<(Fraction _left, int _right) {
    return _left.numerator < (_left.denominator * _right);
}
bool operator==(Fraction _left, int _right) {
    return _left.numerator == (_left.denominator * _right);
}
bool operator>=(Fraction _left, int _right) {
    return _left.numerator >= (_left.denominator * _right);
}
bool operator<=(Fraction _left, int _right) {
    return _left.numerator <= (_left.denominator * _right);
}
bool operator!=(Fraction _left, int _right) {
    return !(_left == _right);
}
#pragma endregion
