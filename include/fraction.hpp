#pragma once
#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <numeric>
#include <utility>

#include "fraction_exception.hpp"

/**
 * @brief Represents a mathematical fraction and provides arithmetic operations.
 *
 * The Fraction class supports operations such as addition, subtraction,
 * multiplication, division, comparison, and normalization. It ensures
 * that fractions are always kept in reduced form.
 */
class Fraction {
private:
    int numerator_, denominator_;

public:
    /**
     * @brief Constructs a Fraction with the given numerator and denominator.
     *
     * @param numerator The numerator of the fraction.
     * @param denominator The denominator of the fraction. Must not be zero.
     * @throws InvalidFraction If the denominator is zero.
     */
    Fraction(int numerator = 0, int denominator = 1);

    /**
     * @brief Copy constructor. Creates a new Fraction as a copy of another.
     *
     * @param fraction The Fraction instance to copy from.
     */
    Fraction(const Fraction &fraction);

    /**
     * @brief Move constructor. Initializes the Fraction by taking resources
     * from another.
     *
     * @param fraction The Fraction instance to move from.
     */
    Fraction(Fraction &&fraction);

    /**
     * @brief Destructor for the Fraction class.
     */
    ~Fraction();

    const int &get_numerator() const;

    const int &get_denominator() const;

    void set_numerator(const int &numerator);

    void set_denominator(const int &denominator);

    /**
     * @brief Compares this fraction with another fraction.
     *
     * The comparison is performed by unifying denominators using the GCD
     * to avoid precision loss. The result is one of:
     *
     * - std::strong_ordering::less
     *
     * - std::strong_ordering::greater
     *
     * - std::strong_ordering::equal
     *
     * @param fraction The fraction to compare with.
     * @return The result of the comparison.
     */
    std::strong_ordering compare(const Fraction &fraction) const;

    /**
     * @brief Reduces the fraction to its simplest form.
     *
     * Uses the greatest common divisor (GCD) to divide both numerator
     * and denominator. Only applies if the GCD is greater than 1.
     */
    void simplify();

    /**
     * @brief Inverts the fraction by swapping numerator and denominator.
     */
    void inverse();

    /**
     * @brief Converts the fraction to a double-precision floating-point number.
     *
     * @return The floating-point representation of the fraction.
     */
    double to_double() const;

    operator double() const;

    Fraction &operator=(const Fraction &) = default;

    Fraction &operator=(Fraction &&fraction);
};

/**
 * @brief Converts a double-precision floating-point number to a Fraction.
 *
 * @param number The double value to convert.
 * @return The corresponding Fraction representation.
 */
Fraction to_fraction(double number);

std::istream &operator>>(std::istream &istr, Fraction &val);

std::ostream &operator<<(std::ostream &ostr, const Fraction &val);

#pragma region Binary arithmetic operators with another fraction
Fraction &operator+=(Fraction &left, const Fraction &right);

Fraction &operator-=(Fraction &left, const Fraction &right);

Fraction &operator*=(Fraction &left, const Fraction &right);

Fraction &operator/=(Fraction &left, const Fraction &right);

inline Fraction operator+(const Fraction &left, const Fraction &right) {
    Fraction result = left;
    result += right;
    return result;
}

inline Fraction operator-(const Fraction &left, const Fraction &right) {
    Fraction result = left;
    result -= right;
    return result;
}

inline Fraction operator*(const Fraction &left, const Fraction &right) {
    Fraction result = left;
    result *= right;
    return result;
}

inline Fraction operator/(const Fraction &left, const Fraction &right) {
    Fraction result = left;
    result /= right;
    return result;
}
#pragma endregion

#pragma region Binary arithmetic operators with a number on the right-hand side
Fraction &operator+=(Fraction &left, const int &right);

Fraction &operator-=(Fraction &left, const int &right);

Fraction &operator*=(Fraction &left, const int &right);

Fraction &operator/=(Fraction &left, const int &right);

inline Fraction operator+(const Fraction &left, const int &right) {
    Fraction result = left;
    result += right;
    return result;
}

inline Fraction operator-(const Fraction &left, const int &right) {
    Fraction result = left;
    result -= right;
    return result;
}

inline Fraction operator*(const Fraction &left, const int &right) {
    Fraction result = left;
    result *= right;
    return result;
}

inline Fraction operator/(const Fraction &left, const int &right) {
    Fraction result = left;
    result /= right;
    return result;
}
#pragma endregion

#pragma region Binary arithmetic operators with a number on the left-hand side
inline Fraction operator+(const int &left, const Fraction &right) {
    Fraction result(left);
    result += right;
    return result;
}

inline Fraction operator-(const int &left, const Fraction &right) {
    Fraction result(left);
    result -= right;
    return result;
}

inline Fraction operator*(const int &left, const Fraction &right) {
    Fraction result(left);
    result *= right;
    return result;
}

inline Fraction operator/(const int &left, const Fraction &right) {
    Fraction result(left);
    result /= right;
    return result;
}
#pragma endregion

#pragma region Spaceship operator
inline auto operator<=>(const Fraction &left, const Fraction &right) {
    return left.compare(right);
}

inline auto operator<=>(const Fraction &left, const int &right) {
    return left <=> Fraction(right);
}

inline auto operator<=>(const int &left, const Fraction &right) {
    return Fraction(left) <=> right;
}
#pragma endregion

#pragma region Comparison operators with another fraction
inline bool operator==(const Fraction &left, const Fraction &right) {
    return left.compare(right) == std::strong_ordering::equal;
}

inline bool operator!=(const Fraction &left, const Fraction &right) {
    return !operator==(left, right);
}

inline bool operator<(const Fraction &left, const Fraction &right) {
    return left <=> right == std::strong_ordering::less;
}

inline bool operator<=(const Fraction &left, const Fraction &right) {
    return left <=> right != std::strong_ordering::greater;
}

inline bool operator>(const Fraction &left, const Fraction &right) {
    return left <=> right == std::strong_ordering::greater;
}

inline bool operator>=(const Fraction &left, const Fraction &right) {
    return left <=> right != std::strong_ordering::less;
}
#pragma endregion

#pragma region Comparison operators with a number on the right-hand side
inline bool operator==(const Fraction &left, const int &right) {
    return left == Fraction(right);
}

inline bool operator!=(const Fraction &left, const int &right) {
    return !operator==(left, right);
}

inline bool operator<(const Fraction &left, const int &right) {
    return left <=> right == std::strong_ordering::less;
}

inline bool operator<=(const Fraction &left, const int &right) {
    return left <=> right != std::strong_ordering::greater;
}

inline bool operator>(const Fraction &left, const int &right) {
    return left <=> right == std::strong_ordering::greater;
}

inline bool operator>=(const Fraction &left, const int &right) {
    return left <=> right != std::strong_ordering::less;
}
#pragma endregion

#pragma region Comparison operators with a number on the left-hand side
inline bool operator==(const int &left, const Fraction &right) {
    return Fraction(left) == right;
}

inline bool operator!=(const int &left, const Fraction &right) {
    return !operator==(left, right);
}

inline bool operator<(const int &left, const Fraction &right) {
    return left <=> right == std::strong_ordering::less;
}

inline bool operator<=(const int &left, const Fraction &right) {
    return left <=> right != std::strong_ordering::greater;
}

inline bool operator>(const int &left, const Fraction &right) {
    return left <=> right == std::strong_ordering::greater;
}

inline bool operator>=(const int &left, const Fraction &right) {
    return left <=> right != std::strong_ordering::less;
}
#pragma endregion

#endif // end FRACTION_HPP
