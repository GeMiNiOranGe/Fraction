#pragma once
#ifndef FRACTION_EXCEPTION_HPP
#define FRACTION_EXCEPTION_HPP

#include <stdexcept>

class InvalidDenominator : public std::invalid_argument {
public:
    InvalidDenominator() : invalid_argument("denominator must not be zero") {}
};

class InvalidFraction : public std::invalid_argument {
public:
    InvalidFraction() : invalid_argument("cannot create fraction with denominator of zero") {}
};

class DivideByZero : public std::overflow_error {
public:
    DivideByZero() : overflow_error("division by zero") {}
};

#endif // end FRACTION_EXCEPTION_HPP