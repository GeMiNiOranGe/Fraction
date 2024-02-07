#include "fraction.hpp"

#pragma region Class Fraction
Fraction::Fraction(int _numerator, int _denominator) {
    this->numerator = _numerator;
    this->denominator = _denominator;
}
Fraction::Fraction(const Fraction &_fraction) {
    this->numerator = _fraction.numerator;
    this->denominator = _fraction.denominator;
}
Fraction::Fraction(Fraction &&_fraction) {
    this->numerator = std::exchange(_fraction.numerator, 0);
    this->denominator = std::exchange(_fraction.denominator, 1);
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

std::strong_ordering Fraction::compare(const Fraction &_fraction) const {
    // A type of unify the denominator
    const int _GCD = std::gcd(this->denominator, _fraction.denominator);
    int left = this->numerator * (_fraction.denominator / _GCD);
    int right = _fraction.numerator * (this->denominator / _GCD);

    if (left < right)
        return std::strong_ordering::less;
    if (left > right)
        return std::strong_ordering::greater;
    return std::strong_ordering::equal;
}
void Fraction::simplify() {
    if (this->denominator == 0)
        return;

    const int _GCD = std::gcd(this->numerator, this->denominator);
    if (_GCD > 1) {
        this->numerator /= _GCD;
        this->denominator /= _GCD;
    }
}
void Fraction::inverse() {
    std::swap(this->denominator, this->numerator);
}

double Fraction::to_double() const {
    return static_cast<double>(this->numerator) / this->denominator;
}

Fraction::operator double() const {
    return this->to_double();
}

Fraction &Fraction::operator=(Fraction &&_fraction) {
    if (this == &_fraction)
        return *this;
    this->numerator = std::exchange(_fraction.numerator, 0);
    this->denominator = std::exchange(_fraction.denominator, 1);
    return *this;
}

std::istream &operator>>(std::istream &_istr, Fraction &_val) {
    int _numerator, _denominator;
    _istr >> _numerator >> _denominator;
    _val = {_numerator, _denominator};
    return _istr;
}
std::ostream &operator<<(std::ostream &_ostr, const Fraction &_val) {
    _val.get_denominator() == 1
        ? _ostr << _val.get_numerator()
        : _ostr << _val.get_numerator() << '/' << _val.get_denominator();
    return _ostr;
}
#pragma endregion

bool is_valid_fraction(Fraction _fraction) {
    try {
        if (_fraction.get_denominator() == 0)
            throw invalid_denominator();
    } catch (const std::invalid_argument &e) {
        std::cerr << '(' << _fraction << "): " << e.what() << '\n';
        return false;
    }
    return true;
}
Fraction to_fraction(double _number) {
    int new_denominator = 1;
    while (static_cast<double>(static_cast<int>(_number)) != _number) {
        _number *= 10;
        new_denominator *= 10;
    }
    Fraction result(static_cast<int>(_number), new_denominator);
    result.simplify();
    return result;
}

#pragma region Implement binary arithmetic operators
Fraction &operator+=(Fraction &_left, const Fraction &_right) {
    if (_left.get_denominator() == _right.get_denominator())
        _left.set_numerator(_left.get_numerator() + _right.get_numerator());
    else {
        _left.set_numerator(_left.get_numerator() * _right.get_denominator() + _left.get_denominator() * _right.get_numerator());
        _left.set_denominator(_left.get_denominator() * _right.get_denominator());
    }
    _left.simplify();
    return _left;
}
Fraction &operator-=(Fraction &_left, const Fraction &_right) {
    if (_left.get_denominator() == _right.get_denominator())
        _left.set_numerator(_left.get_numerator() - _right.get_numerator());
    else {
        _left.set_numerator(_left.get_numerator() * _right.get_denominator() - _left.get_denominator() * _right.get_numerator());
        _left.set_denominator(_left.get_denominator() * _right.get_denominator());
    }
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
