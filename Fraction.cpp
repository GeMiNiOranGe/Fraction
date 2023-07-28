#include "Fraction.h"

Fraction::Fraction(int _numerator, int _denominator) {
    this->numerator = _numerator;
    this->denominator = _denominator;
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

Fraction operator+(Fraction first, Fraction second) {
    int _numerator = first.numerator * second.denominator + first.denominator * second.numerator;
    int _denominator = first.denominator * second.denominator;
    return Fraction(_numerator, _denominator).simplify();
}
Fraction operator-(Fraction first, Fraction second) {
    int _numerator = first.numerator * second.denominator - first.denominator * second.numerator;
    int _denominator = first.denominator * second.denominator;
    return Fraction(_numerator, _denominator).simplify();
}
Fraction operator*(Fraction first, Fraction second) {
    int _numerator = first.numerator * second.numerator;
    int _denominator = first.denominator * second.denominator;
    return Fraction(_numerator, _denominator).simplify();
}
Fraction operator/(Fraction first, Fraction second) {
    return (first * second.inverse()).simplify();
}

/*Method 1: don't use friend function
Fraction& Fraction::operator+=(Fraction& first) {
    *this = *this + first;
    return *this;
}
Method 2: use friend function*/
Fraction &operator+=(Fraction &first, Fraction second) {
    first = first + second;
    return first;
}
Fraction &operator-=(Fraction &first, Fraction second) {
    first = first - second;
    return first;
}
Fraction &operator*=(Fraction &first, Fraction second) {
    first = first * second;
    return first;
}
Fraction &operator/=(Fraction &first, Fraction second) {
    first = first / second;
    return first;
}

bool operator>(Fraction first, Fraction second) {
    int left_side = first.numerator * second.denominator;
    int right_side = first.denominator * second.numerator;
    return left_side > right_side;
}
bool operator<(Fraction first, Fraction second) {
    int left_side = first.numerator * second.denominator;
    int right_side = first.denominator * second.numerator;
    return left_side < right_side;
}
bool operator==(Fraction first, Fraction second) {
    int left_side = first.numerator * second.denominator;
    int right_side = first.denominator * second.numerator;
    return left_side == right_side;
}
bool operator>=(Fraction first, Fraction second) {
    int left_side = first.numerator * second.denominator;
    int right_side = first.denominator * second.numerator;
    return left_side >= right_side;
}
bool operator<=(Fraction first, Fraction second) {
    int left_side = first.numerator * second.denominator;
    int right_side = first.denominator * second.numerator;
    return left_side <= right_side;
}
bool operator!=(Fraction first, Fraction second) {
    return !(first == second);
}

std::istream &operator>>(std::istream &in, Fraction &_fraction) {
    in >> _fraction.numerator >> _fraction.denominator;
    return in;
}
std::ostream &operator<<(std::ostream &out, Fraction _fraction) {
    if (_fraction.denominator == 1)
        out << _fraction.numerator;
    else
        out << _fraction.numerator << '/' << _fraction.denominator;
    return out;
}

Fraction Fraction::inverse() {
    return Fraction(this->denominator, this->numerator);
}
// Method 1: use pointer
Fraction Fraction::simplify() {
    int temp = std::gcd(this->numerator, this->denominator);
    this->numerator /= temp;
    this->denominator /= temp;
    return *this;
}
// Method 2: don't use pointer
// Fraction Fraction::simplify() {
//	int temp = gcd(numerator, denominator);
//	return Fraction(numerator / temp, denominator / temp);
// }