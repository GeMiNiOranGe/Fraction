#pragma once
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric> // C++17 to use gcd

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction(int = 0, int = 1);
    ~Fraction();

    int get_numerator();
    int get_denominator();

    void set_numerator(int);
    void set_denominator(int);

    Fraction inverse();
    Fraction simplify();

    friend std::istream &operator>>(std::istream &, Fraction &);
    friend std::ostream &operator<<(std::ostream &, Fraction);

    friend Fraction operator+(Fraction, Fraction);
    friend Fraction operator-(Fraction, Fraction);
    friend Fraction operator*(Fraction, Fraction);
    friend Fraction operator/(Fraction, Fraction);
    friend Fraction &operator+=(Fraction &, Fraction);
    friend Fraction &operator-=(Fraction &, Fraction);
    friend Fraction &operator*=(Fraction &, Fraction);
    friend Fraction &operator/=(Fraction &, Fraction);
    friend bool operator>(Fraction, Fraction);
    friend bool operator<(Fraction, Fraction);
    friend bool operator==(Fraction, Fraction);
    friend bool operator>=(Fraction, Fraction);
    friend bool operator<=(Fraction, Fraction);
    friend bool operator!=(Fraction, Fraction);

    friend Fraction operator+(Fraction, int);
    friend Fraction operator-(Fraction, int);
    friend Fraction operator*(Fraction, int);
    friend Fraction operator/(Fraction, int);
    friend Fraction &operator+=(Fraction &, int);
    friend Fraction &operator-=(Fraction &, int);
    friend Fraction &operator*=(Fraction &, int);
    friend Fraction &operator/=(Fraction &, int);
    friend bool operator>(Fraction, int);
    friend bool operator<(Fraction, int);
    friend bool operator==(Fraction, int);
    friend bool operator>=(Fraction, int);
    friend bool operator<=(Fraction, int);
    friend bool operator!=(Fraction, int);
};

#endif // end FRACTION_HPP