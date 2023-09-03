#include "fraction.hpp"

Fraction::Fraction(int _numerator, int _denominator) {
    this->numerator = _numerator;
    this->denominator = _denominator;
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

std::istream &operator>>(std::istream &_in, Fraction &_fraction) {
    _in >> _fraction.numerator >> _fraction.denominator;
    return _in;
}
std::ostream &operator<<(std::ostream &_out, Fraction _fraction) {
    _fraction.denominator == 1
        ? _out << _fraction.numerator
        : _out << _fraction.numerator << '/' << _fraction.denominator;
    return _out;
}

#pragma region Fraction vs Fraction
Fraction operator+(Fraction _first, Fraction _second) {
    int numerator = _first.numerator * _second.denominator + _first.denominator * _second.numerator;
    int denominator = _first.denominator * _second.denominator;
    return Fraction(numerator, denominator).simplify();
}
Fraction operator-(Fraction _first, Fraction _second) {
    int numerator = _first.numerator * _second.denominator - _first.denominator * _second.numerator;
    int denominator = _first.denominator * _second.denominator;
    return Fraction(numerator, denominator).simplify();
}
Fraction operator*(Fraction _first, Fraction _second) {
    int numerator = _first.numerator * _second.numerator;
    int denominator = _first.denominator * _second.denominator;
    return Fraction(numerator, denominator).simplify();
}
Fraction operator/(Fraction _first, Fraction _second) {
    return (_first * _second.inverse()).simplify();
}

Fraction &operator+=(Fraction &_first, Fraction _second) {
    _first = _first + _second;
    return _first;
}
Fraction &operator-=(Fraction &_first, Fraction _second) {
    _first = _first - _second;
    return _first;
}
Fraction &operator*=(Fraction &_first, Fraction _second) {
    _first = _first * _second;
    return _first;
}
Fraction &operator/=(Fraction &_first, Fraction _second) {
    _first = _first / _second;
    return _first;
}

bool operator>(Fraction _first, Fraction _second) {
    int left_side = _first.numerator * _second.denominator;
    int right_side = _first.denominator * _second.numerator;
    return left_side > right_side;
}
bool operator<(Fraction _first, Fraction _second) {
    int left_side = _first.numerator * _second.denominator;
    int right_side = _first.denominator * _second.numerator;
    return left_side < right_side;
}
bool operator==(Fraction _first, Fraction _second) {
    int left_side = _first.numerator * _second.denominator;
    int right_side = _first.denominator * _second.numerator;
    return left_side == right_side;
}
bool operator>=(Fraction _first, Fraction _second) {
    int left_side = _first.numerator * _second.denominator;
    int right_side = _first.denominator * _second.numerator;
    return left_side >= right_side;
}
bool operator<=(Fraction _first, Fraction _second) {
    int left_side = _first.numerator * _second.denominator;
    int right_side = _first.denominator * _second.numerator;
    return left_side <= right_side;
}
bool operator!=(Fraction _first, Fraction _second) {
    return !(_first == _second);
}
#pragma endregion

#pragma region Fraction vs Number
Fraction operator+(Fraction _fraction, int _number) {
    int numerator = _fraction.numerator + _fraction.denominator * _number;
    return Fraction(numerator, _fraction.denominator).simplify();
}
Fraction operator-(Fraction _fraction, int _number) {
    int numerator = _fraction.numerator - _fraction.denominator * _number;
    return Fraction(numerator, _fraction.denominator).simplify();
}
Fraction operator*(Fraction _fraction, int _number) {
    int numerator = _fraction.numerator * _number;
    return Fraction(numerator, _fraction.denominator).simplify();
}
Fraction operator/(Fraction _fraction, int _number) {
    int denominator = _fraction.denominator * _number;
    return Fraction(_fraction.numerator, denominator).simplify();
}

Fraction &operator+=(Fraction &_fraction, int _number) {
    _fraction = _fraction + _number;
    return _fraction;
}
Fraction &operator-=(Fraction &_fraction, int _number) {
    _fraction = _fraction - _number;
    return _fraction;
}
Fraction &operator*=(Fraction &_fraction, int _number) {
    _fraction = _fraction * _number;
    return _fraction;
}
Fraction &operator/=(Fraction &_fraction, int _number) {
    _fraction = _fraction / _number;
    return _fraction;
}

bool operator>(Fraction _fraction, int _number) {
    return _fraction.numerator > (_fraction.denominator * _number);
}
bool operator<(Fraction _fraction, int _number) {
    return _fraction.numerator < (_fraction.denominator * _number);
}
bool operator==(Fraction _fraction, int _number) {
    return _fraction.numerator == (_fraction.denominator * _number);
}
bool operator>=(Fraction _fraction, int _number) {
    return _fraction.numerator >= (_fraction.denominator * _number);
}
bool operator<=(Fraction _fraction, int _number) {
    return _fraction.numerator <= (_fraction.denominator * _number);
}
bool operator!=(Fraction _fraction, int _number) {
    return !(_fraction == _number);
}
#pragma endregion