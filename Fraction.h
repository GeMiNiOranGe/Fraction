#ifndef FRACTION_H
#define FRACTION_H
#pragma once

#include <iostream>
#include <numeric> // C++17 to use gcd

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction(int = 0, int = 1);
    int get_numerator();
    int get_denominator();
    void set_numerator(int);
    void set_denominator(int);
    friend Fraction operator+(Fraction, Fraction);
    friend Fraction operator-(Fraction, Fraction);
    friend Fraction operator*(Fraction, Fraction);
    friend Fraction operator/(Fraction, Fraction);
    // Fraction& operator+=(Fraction&);
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
    friend std::istream &operator>>(std::istream &, Fraction &);
    friend std::ostream &operator<<(std::ostream &, Fraction);
    Fraction inverse();
    Fraction simplify();
};

#endif