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

const int &Fraction::get_numerator() const {
    return this->numerator;
}
const int &Fraction::get_denominator() const {
    return this->denominator;
}

void Fraction::set_numerator(const int &_numerator) {
    this->numerator = _numerator;
}
void Fraction::set_denominator(const int &_denominator) {
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
Fraction &operator+=(Fraction &_left, const Fraction &_right) {
    _left.set_numerator(_left.get_numerator() * _right.get_denominator() + _left.get_denominator() * _right.get_numerator());
    _left.set_denominator(_left.get_denominator() * _right.get_denominator());
    _left.simplify();
    return _left;
}
Fraction &operator-=(Fraction &_left, const Fraction &_right) {
    _left.set_numerator(_left.get_numerator() * _right.get_denominator() - _left.get_denominator() * _right.get_numerator());
    _left.set_denominator(_left.get_denominator() * _right.get_denominator());
    _left.simplify();
    return _left;
}
Fraction &operator*=(Fraction &_left, const Fraction &_right) {
    _left.set_numerator(_left.get_numerator() * _right.get_numerator());
    _left.set_denominator(_left.get_denominator() * _right.get_denominator());
    _left.simplify();
    return _left;
}
Fraction &operator/=(Fraction &_left, const Fraction &_right) {
    _left.set_numerator(_left.get_numerator() * _right.get_denominator());
    _left.set_denominator(_left.get_denominator() * _right.get_numerator());
    _left.simplify();
    return _left;
}
#pragma endregion

#pragma region Fraction vs Number
Fraction &operator+=(Fraction &_left, const int &_right) {
    _left.set_numerator(_left.get_numerator() + _left.get_denominator() * _right);
    _left.simplify();
    return _left;
}
Fraction &operator-=(Fraction &_left, const int &_right) {
    _left.set_numerator(_left.get_numerator() - _left.get_denominator() * _right);
    _left.simplify();
    return _left;
}
Fraction &operator*=(Fraction &_left, const int &_right) {
    _left.set_numerator(_left.get_numerator() * _right);
    _left.simplify();
    return _left;
}
Fraction &operator/=(Fraction &_left, const int &_right) {
    _left.set_denominator(_left.get_denominator() * _right);
    _left.simplify();
    return _left;
}
#pragma endregion
