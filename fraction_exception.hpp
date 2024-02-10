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

#endif // end FRACTION_EXCEPTION_HPP