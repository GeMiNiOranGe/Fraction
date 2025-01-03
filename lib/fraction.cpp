#include "fraction.hpp"

#pragma region Class Fraction
Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw InvalidFraction();
    }
    this->numerator_ = numerator;
    this->denominator_ = denominator;
}
Fraction::Fraction(const Fraction &fraction) {
    this->numerator_ = fraction.numerator_;
    this->denominator_ = fraction.denominator_;
}
Fraction::Fraction(Fraction &&fraction) {
    this->numerator_ = std::exchange(fraction.numerator_, 0);
    this->denominator_ = std::exchange(fraction.denominator_, 1);
}
Fraction::~Fraction() {
}

const int &Fraction::get_numerator() const {
    return this->numerator_;
}
const int &Fraction::get_denominator() const {
    return this->denominator_;
}

void Fraction::set_numerator(const int &numerator) {
    this->numerator_ = numerator;
}
void Fraction::set_denominator(const int &denominator) {
    if (denominator == 0) {
        throw InvalidDenominator();
    }
    this->denominator_ = denominator;
}

std::strong_ordering Fraction::compare(const Fraction &fraction) const {
    // A type of unify the denominator
    const int _GCD = std::gcd(this->denominator_, fraction.denominator_);
    int left = this->numerator_ * (fraction.denominator_ / _GCD);
    int right = fraction.numerator_ * (this->denominator_ / _GCD);

    if (left < right) {
        return std::strong_ordering::less;
    }
    if (left > right) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}
void Fraction::simplify() {
    const int _GCD = std::gcd(this->numerator_, this->denominator_);
    if (_GCD > 1) {
        this->numerator_ /= _GCD;
        this->denominator_ /= _GCD;
    }
}
void Fraction::inverse() {
    std::swap(this->denominator_, this->numerator_);
}

double Fraction::to_double() const {
    return static_cast<double>(this->numerator_) / this->denominator_;
}

Fraction::operator double() const {
    return this->to_double();
}

Fraction &Fraction::operator=(Fraction &&fraction) {
    if (this == &fraction) {
        return *this;
    }
    this->numerator_ = std::exchange(fraction.numerator_, 0);
    this->denominator_ = std::exchange(fraction.denominator_, 1);
    return *this;
}

std::istream &operator>>(std::istream &istr, Fraction &val) {
    int numerator, denominator;
    istr >> numerator >> denominator;
    val.set_numerator(numerator);
    val.set_denominator(denominator);
    return istr;
}
std::ostream &operator<<(std::ostream &ostr, const Fraction &val) {
    val.get_denominator() == 1
        ? ostr << val.get_numerator()
        : ostr << val.get_numerator() << '/' << val.get_denominator();
    return ostr;
}
#pragma endregion

Fraction to_fraction(double number) {
    int new_denominator = 1;
    while (static_cast<double>(static_cast<int>(number)) != number) {
        number *= 10;
        new_denominator *= 10;
    }
    Fraction result(static_cast<int>(number), new_denominator);
    result.simplify();
    return result;
}

#pragma region Implement binary arithmetic operators
Fraction &operator+=(Fraction &left, const Fraction &right) {
    if (left.get_denominator() == right.get_denominator()) {
        left.set_numerator(left.get_numerator() + right.get_numerator());
    } else {
        left.set_numerator(left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator());
        left.set_denominator(left.get_denominator() * right.get_denominator());
    }
    left.simplify();
    return left;
}
Fraction &operator-=(Fraction &left, const Fraction &right) {
    if (left.get_denominator() == right.get_denominator()) {
        left.set_numerator(left.get_numerator() - right.get_numerator());
    } else {
        left.set_numerator(left.get_numerator() * right.get_denominator() - left.get_denominator() * right.get_numerator());
        left.set_denominator(left.get_denominator() * right.get_denominator());
    }
    left.simplify();
    return left;
}
Fraction &operator*=(Fraction &left, const Fraction &right) {
    left.set_numerator(left.get_numerator() * right.get_numerator());
    left.set_denominator(left.get_denominator() * right.get_denominator());
    left.simplify();
    return left;
}
Fraction &operator/=(Fraction &left, const Fraction &right) {
    if (right.get_numerator() == 0) {
        throw DivideByZero();
    }
    left.set_numerator(left.get_numerator() * right.get_denominator());
    left.set_denominator(left.get_denominator() * right.get_numerator());
    ;
    left.simplify();
    return left;
}

Fraction &operator+=(Fraction &left, const int &right) {
    left.set_numerator(left.get_numerator() + left.get_denominator() * right);
    left.simplify();
    return left;
}
Fraction &operator-=(Fraction &left, const int &right) {
    left.set_numerator(left.get_numerator() - left.get_denominator() * right);
    left.simplify();
    return left;
}
Fraction &operator*=(Fraction &left, const int &right) {
    left.set_numerator(left.get_numerator() * right);
    left.simplify();
    return left;
}
Fraction &operator/=(Fraction &left, const int &right) {
    if (right == 0) {
        throw DivideByZero();
    }
    left.set_denominator(left.get_denominator() * right);
    left.simplify();
    return left;
}
#pragma endregion
