#include <matho/fraction.hpp>

namespace matho {

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

int Fraction::get_numerator() const {
    return this->numerator_;
}

int Fraction::get_denominator() const {
    return this->denominator_;
}

void Fraction::set_numerator(int numerator) {
    this->numerator_ = numerator;
}

void Fraction::set_denominator(int denominator) {
    if (denominator == 0) {
        throw InvalidDenominator();
    }
    this->denominator_ = denominator;
}

std::strong_ordering Fraction::compare(const Fraction &fraction) const {
    // A type of unify the denominator
    const int GCD_VALUE = std::gcd(this->denominator_, fraction.denominator_);
    int left = this->numerator_ * (fraction.denominator_ / GCD_VALUE);
    int right = fraction.numerator_ * (this->denominator_ / GCD_VALUE);

    if (left < right) {
        return std::strong_ordering::less;
    }
    if (left > right) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}

void Fraction::simplify() {
    const int GCD_VALUE = std::gcd(this->numerator_, this->denominator_);
    if (GCD_VALUE > 1) {
        this->numerator_ /= GCD_VALUE;
        this->denominator_ /= GCD_VALUE;
    }
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
    left.simplify();
    return left;
}

Fraction &operator+=(Fraction &left, int right) {
    left.set_numerator(left.get_numerator() + left.get_denominator() * right);
    left.simplify();
    return left;
}

Fraction &operator-=(Fraction &left, int right) {
    left.set_numerator(left.get_numerator() - left.get_denominator() * right);
    left.simplify();
    return left;
}

Fraction &operator*=(Fraction &left, int right) {
    left.set_numerator(left.get_numerator() * right);
    left.simplify();
    return left;
}

Fraction &operator/=(Fraction &left, int right) {
    if (right == 0) {
        throw DivideByZero();
    }
    left.set_denominator(left.get_denominator() * right);
    left.simplify();
    return left;
}

}  // namespace matho
