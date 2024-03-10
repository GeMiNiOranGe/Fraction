#pragma once
#ifndef FRACTION_EXCEPTION_HPP
#define FRACTION_EXCEPTION_HPP

#include <stdexcept>

class invalid_denominator : public std::invalid_argument {
public:
    invalid_denominator() : invalid_argument("denominator must not be zero") {}
};

class invalid_fraction : public std::invalid_argument {
public:
    invalid_fraction() : invalid_argument("cannot create fraction with denominator of zero") {}
};

class divide_by_zero : public std::overflow_error {
public:
    divide_by_zero() : overflow_error("division by zero") {}
};

#endif // end FRACTION_EXCEPTION_HPP