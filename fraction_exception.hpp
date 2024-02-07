#pragma once
#ifndef FRACTION_EXCEPTION_HPP
#define FRACTION_EXCEPTION_HPP

#include <stdexcept>

class invalid_denominator : public std::invalid_argument {
public:
    invalid_denominator() : invalid_argument("denominator must not be zero") {}
};

#endif // end FRACTION_EXCEPTION_HPP