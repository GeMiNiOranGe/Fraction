#pragma once
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric> // C++17 to use gcd

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction(int _numerator = 0, int _denominator = 1);
    ~Fraction();

    int get_numerator();
    int get_denominator();

    void set_numerator(int _numerator);
    void set_denominator(int _denominator);

    Fraction inverse();
    Fraction simplify();

    double to_double();
    friend Fraction to_fraction(double _number);

    friend std::istream &operator>>(std::istream &_istr, Fraction &_val);
    friend std::ostream &operator<<(std::ostream &_ostr, Fraction _val);

    friend Fraction operator+(Fraction _left, Fraction _right);
    friend Fraction operator-(Fraction _left, Fraction _right);
    friend Fraction operator*(Fraction _left, Fraction _right);
    friend Fraction operator/(Fraction _left, Fraction _right);
    friend Fraction &operator+=(Fraction &_left, Fraction _right);
    friend Fraction &operator-=(Fraction &_left, Fraction _right);
    friend Fraction &operator*=(Fraction &_left, Fraction _right);
    friend Fraction &operator/=(Fraction &_left, Fraction _right);
    friend bool operator>(Fraction _left, Fraction _right);
    friend bool operator<(Fraction _left, Fraction _right);
    friend bool operator==(Fraction _left, Fraction _right);
    friend bool operator>=(Fraction _left, Fraction _right);
    friend bool operator<=(Fraction _left, Fraction _right);
    friend bool operator!=(Fraction _left, Fraction _right);

    friend Fraction operator+(Fraction _left, int _right);
    friend Fraction operator-(Fraction _left, int _right);
    friend Fraction operator*(Fraction _left, int _right);
    friend Fraction operator/(Fraction _left, int _right);
    friend Fraction &operator+=(Fraction &_left, int _right);
    friend Fraction &operator-=(Fraction &_left, int _right);
    friend Fraction &operator*=(Fraction &_left, int _right);
    friend Fraction &operator/=(Fraction &_left, int _right);
    friend bool operator>(Fraction _left, int _right);
    friend bool operator<(Fraction _left, int _right);
    friend bool operator==(Fraction _left, int _right);
    friend bool operator>=(Fraction _left, int _right);
    friend bool operator<=(Fraction _left, int _right);
    friend bool operator!=(Fraction _left, int _right);
};
Fraction to_fraction(double _number);

#endif // end FRACTION_HPP